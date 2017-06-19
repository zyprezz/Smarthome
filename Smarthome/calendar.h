#ifndef CALENDAR_H
#define CALENDAR_H

#include <QtCore>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <time.h>


class Calendar : public QObject
{
   Q_OBJECT

public:

    enum Object{
        Light,
        Curtain,
        Null
    };

    explicit Calendar(Object = Null, QObject *parent = 0);

    enum Method{
        Auto = 1,
        ManActivate = 2,
        ManDisable = 3
    };



    void requestMethod(Method);

    void abort();

private:
    Method _method;
    bool _abort;
    bool _interrupt;
    QMutex mutex;
    QWaitCondition condition;
    void CheckTime();
    void ManualActivate();
    void ManualDisable();

    bool _light;
    bool _curtain;


    int startHour;
    int startMin;
    int endHour;
    int endMin;


signals:
   // void textChanged(QString);
    void finished();

public slots:
    void mainLoop();

};

#endif // CALENDAR_H
