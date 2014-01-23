#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include "myapplication.h"

/* This example shows how to display a splash screen during the initialization of you application.
 * In this exemple, the application is implemented in the class "MyApplication".
 * The method MyApplication::start() starts the application. First, it displays a splash screen,
 * then, it runs method MyApplication::init(). The splash screen will be displayed during the execution
 * of this method. When it's finished, the main QML file (main.qml) will be loaded. Once this is done,
 * this file will be displayed instead of the splashscreen */
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;

    /* Instantiate the application class */
    MyApplication* myApp = new MyApplication(&viewer);

    /* Run, baby run! */
    myApp->start();

    /* Call the QT event loop */
    return app.exec();
}
