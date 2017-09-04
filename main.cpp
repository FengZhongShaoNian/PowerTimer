#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include "powerutils.h"
#include "trayicon.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/res/power.png"));

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("power", new PowerUtils(&app));

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    auto getApplicationWindow = [&]()->QWindow*{
            QList<QObject*> objects= engine.rootObjects();
            QWindow* result = nullptr;
            for(auto iter : objects){
                if(iter->objectName() == "applicationWindow"){
                    result = static_cast<QWindow*>(iter);
                }
            }
            return result;
     };
    QWindow* mainWindow = getApplicationWindow();
    TrayIcon* trayIcon = new TrayIcon(mainWindow, &app);
    trayIcon->connect(&app, SIGNAL(quit()), trayIcon, SLOT(hide()));

    return app.exec();
}
