#include "calendar.h"
#include <QTimer>
#include <QtCore>
#include <QEventLoop>
#include <QThread>
#include <QDebug>
#include "filehandler.h"

Calendar::Calendar(Object obj, QObject *parent) :
    QObject(parent)
{
    if(obj == Light)
    {
        _light = true;
        _curtain = false;
        qDebug()<< "liiiiiighty";
    }
    else if(obj == Curtain)
    {
        _light = false;
        _curtain = true;
        qDebug() << "cuurtaino";
    }

//    _abort = false;
    _interrupt = false;

}

void Calendar::requestMethod(Calendar::Method method)
{
    qDebug()<< "Request worker Method"<<method<<"in Thread "<<thread()->currentThreadId();
    QMutexLocker locker(&mutex);
    _interrupt = true;
    _method = method;
    condition.wakeOne();
}

//void Calendar::abort()
//{
//    qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
//    QMutexLocker locker(&mutex);
//    _abort = true;
//    condition.wakeOne();
//}


void Calendar::CheckTime()
{
    qDebug()<<"Starting CheckTime in Thread "<<thread()->currentThreadId();

    time_t currenTime;

    QMutex mutex;
    while (true)
    {
        mutex.lock();
//        bool abort = _abort;
        bool interrupt = _interrupt;
        mutex.unlock();

        if (/*abort || */interrupt) {
            qDebug()<<"Interrupting CheckTime in Thread "<<thread()->currentThreadId();
            break;
        }

        time(&currenTime);
        time_t stime;
        time_t etime;
        struct tm *startTime = localtime(&currenTime);
        struct tm *endTime = localtime(&currenTime);




        if(_light)
        {
            startHour = FileHandler::getStartHourFrom(FileHandler::lightPara);
            startMin = FileHandler::getStartMinFrom(FileHandler::lightPara);
            endHour = FileHandler::getEndHourFrom(FileHandler::lightPara);
            endMin = FileHandler::getEndMinFrom(FileHandler::lightPara);

            startTime->tm_hour = FileHandler::getStartHourFrom(FileHandler::lightPara);
            startTime->tm_min = FileHandler::getStartMinFrom(FileHandler::lightPara);
            startTime->tm_sec = 0;

            stime = mktime(startTime);

            endTime->tm_hour = FileHandler::getEndHourFrom(FileHandler::lightPara);
            endTime->tm_min = FileHandler::getEndMinFrom(FileHandler::lightPara);
            endTime->tm_sec = 0;


            etime = mktime(endTime);


        }
        else if(_curtain)
        {
//            startHour = FileHandler::getStartHourFrom(FileHandler::curtainPara);
//            startMin = FileHandler::getStartMinFrom(FileHandler::curtainPara);
//            endHour = FileHandler::getEndHourFrom(FileHandler::curtainPara);
//            endMin = FileHandler::getEndMinFrom(FileHandler::curtainPara);

            startHour = FileHandler::getStartHourFrom(FileHandler::curtainPara);
            startMin = FileHandler::getStartMinFrom(FileHandler::curtainPara);
            endHour = FileHandler::getEndHourFrom(FileHandler::curtainPara);
            endMin = FileHandler::getEndMinFrom(FileHandler::curtainPara);

            startTime->tm_hour = FileHandler::getStartHourFrom(FileHandler::curtainPara);
            startTime->tm_min = FileHandler::getStartMinFrom(FileHandler::curtainPara);
            startTime->tm_sec = 0;

            stime = mktime(startTime);

            endTime->tm_hour = FileHandler::getEndHourFrom(FileHandler::curtainPara);
            endTime->tm_min = FileHandler::getEndMinFrom(FileHandler::curtainPara);
            endTime->tm_sec = 0;


            etime = mktime(endTime);
        }

        //qDebug()<<endTime->tm_min;

        double diff1 = difftime(stime,currenTime);
        double diff2 = difftime(stime,etime);


//            qDebug() << startTime << "   " << endTime;


        QEventLoop loop;
        QTimer::singleShot(1000,&loop,SLOT(quit()));
        loop.exec();

        if(diff1<0 && diff1>diff2)
        {
            qDebug()<< "Disabled";
            // send i2c command OFF


        }
        else
        {
            qDebug()<< "Active";
            // send i2c command ON

        }
    }
}

void Calendar::ManualActivate()
{
    qDebug()<<"Starting ManualActivate in Thread "<<thread()->currentThreadId();
    mutex.lock();
//    bool abort = _abort;
    bool interrupt = _interrupt;
    mutex.unlock();

    if (/*abort || */interrupt) {
        qDebug()<<"Interrupting ManualActivate in Thread "<<thread()->currentThreadId();

    }

    qDebug()<< "Manual Activated";
    // send i2c command ON

}

void Calendar::ManualDisable()
{
    qDebug()<<"Starting ManualDisable in Thread "<<thread()->currentThreadId();
    mutex.lock();
//    bool abort = _abort;
    bool interrupt = _interrupt;
    mutex.unlock();

    if (/*abort || */interrupt) {
        qDebug()<<"Interrupting ManualDisable in Thread "<<thread()->currentThreadId();

    }

    qDebug()<< "Manual disabled";
    // send i2c command OFF

}

void Calendar::mainLoop()
{
    qDebug()<<"Starting worker mainLoop in Thread "<<thread()->currentThreadId();

    while (true) {
        mutex.lock();
        if (!_interrupt /*&& !_abort*/) {
            condition.wait(&mutex);
        }
        _interrupt = false;

//        if (_abort) {
//            qDebug()<<"Aborting worker mainLoop in Thread "<<thread()->currentThreadId();
//            mutex.unlock();
//            emit finished();
//            return;
//        }

        Method method = _method;
        mutex.unlock();

        switch(method){
        case Auto:
            CheckTime();
            break;
        case ManActivate:
            ManualActivate();
            break;
        case ManDisable:
            ManualDisable();
            break;
        }
    }
}




