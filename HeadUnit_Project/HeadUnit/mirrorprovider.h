#ifndef MIRRORPROVIDER_H
#define MIRRORPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QLocale>
#include <QWindow>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickWindow>
#include <QThread>
#include <QTimer>

enum MODE{
    TEST, EXECUTION
};

enum STATE{
    LOADING, UNCONNECTED, CONNECTED
};

class MirrorProvider : public QObject{
    Q_OBJECT

    Q_PROPERTY(bool isLoaded READ getisLoaded NOTIFY stateChanged)

private:
    QProcess * scrcpyProcess;
    QProcess * xwindowProcess;
    QString window_title = "Trash";
    MODE mode = EXECUTION;

    QWindow * scrcpyWindow;
    bool isloaded;
    bool isInitialized = false;

signals:
    void stateChanged();



public:
    explicit MirrorProvider(QObject *parent = nullptr):QObject(parent), isloaded(false){
        scrcpyProcess = new QProcess();
        xwindowProcess = new QProcess();
        window_title = (mode == TEST) ? "Trash" : "Seungjuphone";
    }

    ~MirrorProvider(){
        this->end();
    }

    Q_INVOKABLE void init(QQuickWindow * parent){
        if (mode == EXECUTION){
            scrcpyProcess->start("scrcpy", QStringList() << "--window-title" << window_title);
        }
        else if (mode == TEST){
            scrcpyProcess->start("nautilus", QStringList() <<"trash:///");
        }

        qDebug() << scrcpyProcess->waitForStarted();
        qDebug() << "init() function called";

        WId scrcpyWindowId = 0;
        bool windowOpened = false;
        int i = 0;
        int waituntil = 3;
        while (!windowOpened && i < waituntil) {
            xwindowProcess->start("xdotool", QStringList() << "search" << "--name" << window_title);
            xwindowProcess->waitForFinished();
            QString output = xwindowProcess->readAllStandardOutput();

            if (!output.isEmpty()) {
                windowOpened = true;
                scrcpyWindowId = output.toULongLong();
                qDebug() << "Window ID found: " << scrcpyWindowId;
            }
            else {
                qDebug() << "Window not found, retrying...";
                QThread::sleep(1);  // Wait 1 second before polling again
                i++;
            }
        }

        if (!windowOpened){
            qDebug() << "failed to load";
            isloaded = false;
        }
        else{
            qDebug() << "successfully loaded!";
            qDebug() << parent;

            QObject::connect(scrcpyProcess, &QProcess::stateChanged, this, &MirrorProvider::changeState);

            scrcpyWindow = QWindow::fromWinId(scrcpyWindowId);
            scrcpyWindow->setFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
            scrcpyWindow->setTransientParent(parent);
            QTimer::singleShot(100, [this, parent]() {
                qDebug() << parent->x() << parent->y() << parent->width() << parent->height();
                scrcpyWindow->setGeometry(parent->x(), parent->y(), parent->width() - 150, parent->height());
                scrcpyWindow->show();
                scrcpyWindow->requestUpdate();
           });
            isloaded = true;
        }

        emit stateChanged();
    }

    Q_INVOKABLE void end(){
        scrcpyProcess->kill();
        xwindowProcess->kill();
        qDebug() << "so long";
    }



public slots:
    bool getisLoaded(){return isloaded;}

public slots:
    void changeState(QProcess::ProcessState newState){
        if (newState == QProcess::NotRunning){
            qDebug() << "disconnected with state" << newState;
            isloaded = false;
            emit stateChanged();
        }
    }
};

#endif // MIRRORPROVIDER_H
