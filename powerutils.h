#ifndef POWERUTILS_H
#define POWERUTILS_H

#include <QObject>

class PowerUtils : public QObject
{
    Q_OBJECT
public:
    explicit PowerUtils(QObject *parent = 0);

signals:

public slots:
    void shutdown();
    void reboot();
};

#endif // POWERUTILS_H
