#include "mirrorprovider.h"
#include <QObject>
#include <QProcess>
#include <QDebug>

MirrorProvider::MirrorProvider(QObject *parent) : QObject(parent)
{

}

bool MirrorProvider::init(){
    QProcess *scrcpyProcess = new QProcess();
    scrcpyProcess->start("scrcpy", QStringList() << "--output" << "tcp://localhost:8080");
    qDebug() << "sex";

    return true;
}
