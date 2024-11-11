#ifndef MIRRORPROVIDER_H
#define MIRRORPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QWindow>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

enum STATE {
    LOADING, UNCONNECTED, CONNECTED
};

enum MODE{
    TEST, EXECUTE
};

class MirrorProvider : public QObject {
    Q_OBJECT

    Q_PROPERTY(int state READ getState NOTIFY mirroringStateChanged)

private:
    QProcess *scrcpyProcess;
    QProcess *ffmpegProcess;
    STATE state = LOADING;
    MODE mode = EXECUTE;

signals:
    void mirroringStateChanged();

public:
    explicit MirrorProvider(QObject *parent = nullptr) : QObject(parent) {
        scrcpyProcess = new QProcess(this);
        ffmpegProcess = new QProcess(this);

        // Connect signals to capture standard output and errors asynchronously
        connect(scrcpyProcess, &QProcess::readyReadStandardError, this, &MirrorProvider::handleScrcpyError);
        connect(scrcpyProcess, &QProcess::readyReadStandardOutput, this, &MirrorProvider::handleScrcpyOutput);
        connect(scrcpyProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &MirrorProvider::processFinished);

        connect(ffmpegProcess, &QProcess::readyReadStandardError, this, &MirrorProvider::handleFfmpegError);
        connect(ffmpegProcess, &QProcess::readyReadStandardOutput, this, &MirrorProvider::handleFfmpegOutput);
        connect(ffmpegProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &MirrorProvider::processFinished);
    }

    ~MirrorProvider() {
        end();
    }

    Q_INVOKABLE void init(QQuickWindow *parent) {
        state = LOADING;
        emit mirroringStateChanged();

        if (mode == EXECUTE){
            // Start scrcpy and capture the output into a pipe
            scrcpyProcess->setProgram("scrcpy");
            scrcpyProcess->setArguments(QStringList() << "--no-display" << "--no-clipboard-autosync" << "--record" << "-" << "--record-format" << "mkv");
            scrcpyProcess->setStandardOutputProcess(ffmpegProcess);  // Pipe scrcpy output to ffmpeg input

            // Start ffmpeg to capture scrcpy’s output from the pipe and stream it over UDP
            ffmpegProcess->setProgram("ffmpeg");
            ffmpegProcess->setArguments(QStringList() << "-re" << "-f" <<  "lavfi" << "-i" << "-" << "-f" << "mpegts" << "udp://127.0.0.1:1234");

            // Start both processes
            scrcpyProcess->start();
            ffmpegProcess->start();
        }
        else if(mode == TEST){
            scrcpyProcess->setProgram("ffmpeg");
            scrcpyProcess->setArguments(QStringList() << "-re" << "-f" <<  "lavfi" << "-i" << "testsrc=size=640x480:rate=30" <<  "-f" <<  "mpegts" <<  "udp://127.0.0.1:1234" );
            scrcpyProcess->start();
        }
    }

    Q_INVOKABLE void end() {
        if (scrcpyProcess->state() != QProcess::NotRunning) {
            scrcpyProcess->kill();
            scrcpyProcess->waitForFinished();
        }
        if (ffmpegProcess->state() != QProcess::NotRunning) {
            ffmpegProcess->kill();
            ffmpegProcess->waitForFinished();
        }
        state = UNCONNECTED;
        emit mirroringStateChanged();
    }

    STATE getState() const {
        return state;
    }

private slots:
    void handleScrcpyOutput() {
        QByteArray output = scrcpyProcess->readAllStandardOutput();
        qDebug() << "scrcpy Output:" << output;
    }

    void handleScrcpyError() {
        QByteArray error = scrcpyProcess->readAllStandardError();
        qDebug() << "scrcpy Error:" << error;

        if (scrcpyProcess->state() == QProcess::Running && state != CONNECTED) {
              state = CONNECTED;
              emit mirroringStateChanged();
              qDebug() << "connected";
        }
    }

    void handleFfmpegOutput() {
        QByteArray output = ffmpegProcess->readAllStandardOutput();
        qDebug() << "ffmpeg Output:" << output;
    }

    void handleFfmpegError() {
        QByteArray error = ffmpegProcess->readAllStandardError();
        qDebug() << "ffmpeg Error:" << error;
    }

    void processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
        if (exitStatus == QProcess::CrashExit) {
            qDebug() << "Process crashed with exit code:" << exitCode;
            state = UNCONNECTED;
        }
        else {
            qDebug() << "Process finished with errors, exit code:" << exitCode;
            state = UNCONNECTED;
        }
        emit mirroringStateChanged();
    }
};

#endif // MIRRORPROVIDER_H
