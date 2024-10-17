#ifndef MIRRORPROVIDER_H
#define MIRRORPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QLocale>
#include <QWindow>
#include <QQmlApplicationEngine>
#include <QQuickView>

class MirrorProvider : public QQuickView{
    Q_OBJECT

    Q_PROPERTY(bool isLoaded READ init NOTIFY stateChanged)

private:
    QProcess * scrcpyProcess;
    QProcess * xwindowProcess;
    QString window_title = "Trash";

signals:
    void stateChanged();

public:
    explicit MirrorProvider(QQuickView *parent = nullptr):QQuickView(parent){
        scrcpyProcess = new QProcess();
        xwindowProcess = new QProcess();
        this->init();
        qDebug() << "Constructor of Mirrorprivider";
    }

    ~MirrorProvider(){
        this->end();
    }

    Q_INVOKABLE bool init(QQuickItem* parent){
        // scrcpyProcess->start("scrcpy", QStringList() << "--window-title" << window_title);
        xwindowProcess->start("xdotool", QStringList() << "search" <<"--name" << window_title);
        xwindowProcess->waitForFinished();
        QString output = xwindowProcess->readAllStandardOutput();
        WId scrcpyWindowId = output.toULongLong();

        emit stateChanged();

        if (scrcpyWindowId == 0){
            return false;
        }
        else{
            QWindow *scrcpyWindow = QWindow::fromWinId(scrcpyWindowId);

            scrcpyWindow->setParent(this);
            scrcpyWindow->setGeometry(0, 0, this->width(), this->height());
            scrcpyWindow->show();
            return true;
        }
    }

    Q_INVOKABLE void end(){
        scrcpyProcess->kill();
        xwindowProcess->kill();
    }

};

#endif // MIRRORPROVIDER_H
