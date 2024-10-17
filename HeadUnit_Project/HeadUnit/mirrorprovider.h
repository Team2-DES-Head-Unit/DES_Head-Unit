#ifndef MIRRORPROVIDER_H
#define MIRRORPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QLocale>
#include <QWindow>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>

class MirrorProvider : public QQuickView{
    Q_OBJECT

    Q_PROPERTY(bool isLoaded READ getisLoaded NOTIFY stateChanged)

private:
    QProcess * scrcpyProcess;
    QProcess * xwindowProcess;
    QString window_title = "seungjuphone";
    bool isloaded;

signals:
    void stateChanged();

public slots:
    bool getisLoaded(){return isloaded;}

public:
    explicit MirrorProvider(QQuickView *parent = nullptr):QQuickView(parent){
        scrcpyProcess = new QProcess();
        xwindowProcess = new QProcess();
        qDebug() << "Constructor of Mirrorprivider";
    }

    ~MirrorProvider(){
        this->end();
    }

    Q_INVOKABLE void init(QQuickItem* parent){
        scrcpyProcess->start("scrcpy", QStringList() << "--window-title" << window_title);
        xwindowProcess->start("xdotool", QStringList() << "search" <<"--name" << window_title);
        xwindowProcess->waitForFinished();
        QString output = xwindowProcess->readAllStandardOutput();
        WId scrcpyWindowId = output.toULongLong();

        emit stateChanged();

        qDebug() << "init() function called";

        if (scrcpyWindowId == 0){
            qDebug() << "failed to load";
            isloaded = false;
        }
        else{
            qDebug() << "successfully loaded!";
            QWindow *qmlWindow = parent->window();
            QWindow *scrcpyWindow = QWindow::fromWinId(scrcpyWindowId);
            scrcpyWindow->setParent(qmlWindow);
            scrcpyWindow->setGeometry(parent->x(), parent->y(), parent->width(), parent->height());
            scrcpyWindow->show();
            isloaded = true;
        }

    }

    Q_INVOKABLE void end(){
        scrcpyProcess->kill();
        xwindowProcess->kill();
    }

};

#endif // MIRRORPROVIDER_H
