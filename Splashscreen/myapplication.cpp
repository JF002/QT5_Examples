#include "myapplication.h"
#include <QDir>
#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include <QThread>

MyApplication::MyApplication(QQuickView* viewer)
{
    this->viewer = viewer;
}

void MyApplication::start()
{
    // Search for the directory of the executable file
    QDir directory(QCoreApplication::applicationDirPath());

    // Build the path to the splash.qml file
    QString path = directory.absoluteFilePath("../qml/Splashscreen/splash.qml");

    // Give a reference to this object to the splash.qml file. This will
    // allow it to call the method init()
    this->viewer->engine()->rootContext()->setContextProperty("myapplication", this);

    // Load splash.qml
    this->viewer->setSource(QUrl::fromLocalFile(path));

    // And display it
    this->viewer->show();
}


void MyApplication::init()
{
    // Add any initialization instruction here.

    QThread::msleep(5000); // Blocks (sleeps) during 5 seconds
}
