#ifndef MIRRORPROVIDER_H
#define MIRRORPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QLocale>

enum STATE{
    LOADING, ERROR, PLAYING
};


class MirrorProvider : public QObject
{
    Q_OBJECT
private:
    QProcess * scrcpyProcess;
    STATE state = LOADING;

public:
    explicit MirrorProvider(QObject *parent = nullptr){
        scrcpyProcess = new QProcess();
    }

    ~MirrorProvider(){
        this->end();
    }

    Q_INVOKABLE void init(){
        scrcpyProcess->start("scrcpy", QStringList() << "--output" << "tcp://localhost:8080");
        connect(scrpyProcess, &QProcess::readyReadStandardOutput, this, &MirrorProvider::state);
    }

    Q_INVOKABLE void end(){
        scrcpyProcess->kill();
    }

signals:

public slots:
    STATE state(){
        QByteArray output = process->readAllStandardOutput();
        QString outputString = QString(output);

        qDebug() << outputString;

                if (outputString.contains("Connected to")) {
                    qDebug() << "Device detected and connected.";
                } else if (outputString.contains("No devices found")) {
                    qDebug() << "No device found. Please connect a phone.";
                }
    }

};

#endif // MIRRORPROVIDER_H
