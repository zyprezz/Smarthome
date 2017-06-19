#include "filehandler.h"
#include <QDebug>
#include <QFile>

namespace FileHandler{

QFile *_logLight = new QFile("timeparameter/lightPara.txt");
QFile *_logCurtain = new QFile("timeparameter/curtainPara.txt");
QFile *_logHeat = new QFile("timeparameter/heatPara.txt");

void createDir()
{
    QString logDirPath = "timeparameter";
    QDir logDir(logDirPath);
    if(!logDir.exists())
    {
        QDir().mkdir(logDirPath);
    }
}


void saveTimeTo(FileHandler::Data data,int startHour,int startMin,int endHour,int endMin)
{

    QTextStream ts;


    switch (data) {
    case lightPara:
        _logLight->open(QIODevice::ReadWrite | QIODevice::Text);
        ts.setDevice(_logLight);
        ts << startHour <<":"<<startMin<< "," << endHour <<":"<< endMin << endl;
        _logLight->close();
        qDebug()<<"lyyyys";
        break;
    case curtainPara:
        _logCurtain->open(QIODevice::ReadWrite | QIODevice::Text);
        ts.setDevice(_logCurtain);
        ts << startHour <<":"<<startMin<< "," << endHour <<":"<< endMin << endl;
        _logCurtain->close();
        qDebug()<<"gaaardin";
        break;
    case heatPara:
        _logHeat->open(QIODevice::ReadWrite | QIODevice::Text);
        ts.setDevice(_logHeat);
        ts << startHour <<":"<<startMin<< "," << endHour <<":"<< endMin << endl;
        _logHeat->close();
        qDebug()<<"vaaaaarm";
        break;
    }
}

int getStartHourFrom(Data data)
{

    int startHour;

    switch (data) {
    case lightPara:

        if(_logLight->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logLight);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startHour = paralist[0].toInt();

        }
        _logLight->close();
        return startHour;
        break;
    case curtainPara:

        if(_logCurtain->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logCurtain);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startHour = paralist[0].toInt();

        }
        _logCurtain->close();
        return startHour;
        break;
    case heatPara:

        if(_logHeat->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logHeat);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startHour = paralist[0].toInt();

        }
        _logHeat->close();
        return startHour;
        break;
    }
    return 0;
}

int getStartMinFrom(Data data)
{
    int startMin;

    switch (data) {
    case lightPara:

        if(_logLight->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logLight);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startMin = paralist[1].toInt();

        }
        _logLight->close();
        return startMin;
        break;
    case curtainPara:

        if(_logCurtain->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logCurtain);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startMin = paralist[1].toInt();

        }
        _logCurtain->close();
        return startMin;
        break;
    case heatPara:

        if(_logHeat->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logHeat);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            startMin = paralist[1].toInt();

        }
        _logHeat->close();
        return startMin;
        break;
    }
    return 0;

}

int getEndHourFrom(Data data)
{
    int endHour;

    switch (data) {
    case lightPara:

        if(_logLight->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logLight);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endHour = paralist[2].toInt();

        }
        _logLight->close();
        return endHour;
        break;
    case curtainPara:

        if(_logCurtain->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logCurtain);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endHour = paralist[2].toInt();

        }
        _logCurtain->close();
        return endHour;
        break;
    case heatPara:

        if(_logHeat->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logHeat);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endHour = paralist[2].toInt();

        }
        _logHeat->close();
        return endHour;
        break;
    }
    return 0;
}

int getEndMinFrom(Data data)
{
    int endMin;

    switch (data) {
    case lightPara:

        if(_logLight->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logLight);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endMin = paralist[3].toInt();

        }
        _logLight->close();
        return endMin;
        break;
    case curtainPara:

        if(_logCurtain->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logCurtain);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endMin = paralist[3].toInt();

        }
        _logCurtain->close();
        return endMin;
        break;
    case heatPara:

        if(_logHeat->open(QIODevice::ReadOnly))
        {
            QTextStream in(_logHeat);
            QStringList paralist;
            QString mt = in.readLine();
            QRegExp separator("(,|:)");
            paralist = mt.split(separator);

            endMin = paralist[3].toInt();

        }
        _logHeat->close();
        return endMin;
        break;
    }
    return 0;
}

}
