#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include <QWindow>
#include <QSystemTrayIcon>

class TrayIcon : public QObject
{
    Q_OBJECT
public:
    explicit TrayIcon(QWindow* mainWindow, QObject *parent = 0);

signals:

public slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);
    void hide();
private:
    QWindow* mainWindow_;
    QSystemTrayIcon* trayIcon_;
};

#endif // TRAYICON_H
