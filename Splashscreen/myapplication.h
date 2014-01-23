#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QObject>
#include <QtQuick/QQuickView>

/* This class implements the application class.
 * The main constructor takes pointer to a QQuickView object. This is
 * the viewer class the will display the QML files.
 * In order to run the application, call the method start(). This method will load
 * a splashscreen QML file, then initialize the application (it can take a long time).
 * When the init is done, the main.qml file will be loaded and displayed.
 *
 * When you call start(), the file splash.qml will be loaded. Once it is displayed, it
 * will call the slot init(), which is the method that initializes the application and takes
 * a long time to execute.
 * When this function return, the file splash.qml will load the file main.qml and display it. */
class MyApplication : public QObject
{
    Q_OBJECT
public:
    MyApplication(QQuickView* viewer);
    void start();

public slots:
    void init();

private :
    QQuickView* viewer;
};

#endif // MYAPPLICATION_H
