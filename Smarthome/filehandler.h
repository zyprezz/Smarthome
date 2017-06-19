#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QtCore>


namespace FileHandler{



enum Data{
    lightPara = 1,
    curtainPara = 2,
    heatPara = 3
};

void createDir();
void saveTimeTo(Data,int startHour,int startMin,int endHour,int endMin);
int getStartHourFrom(Data);
int getStartMinFrom(Data);
int getEndHourFrom(Data);
int getEndMinFrom(Data);


extern QFile *_logLight;
extern QFile *_logCurtain;
extern QFile *_logHeat;



//void saveDataTo(FileHandler::Data data,int start,int end);

}
#endif // FILEHANDLER_H
