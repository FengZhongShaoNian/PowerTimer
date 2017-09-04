#include "trayicon.h"
#include <assert.h>
#include <QApplication>
#include <QMenu>

TrayIcon::TrayIcon(QWindow *mainWindow, QObject *parent) : QObject(parent)
{
    mainWindow_ = mainWindow;
    assert(mainWindow_);

    trayIcon_ = new QSystemTrayIcon(QIcon(":/res/power.png"), this);
    QMenu* popupMenu = new QMenu((QWidget*)QApplication::desktop());
    popupMenu->addAction("退出", QApplication::instance(), SLOT(quit()));
    trayIcon_->setContextMenu(popupMenu);
    connect(trayIcon_, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
    trayIcon_->show();
}

void TrayIcon::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::ActivationReason::DoubleClick){
        mainWindow_->show();
        mainWindow_->requestActivate();
    }
}

void TrayIcon::hide()
{
    trayIcon_->hide();
}
