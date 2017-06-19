#include "mainwindow.h"
#include <QApplication>
#include "calendar.h"
#include "filehandler.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();
    w.show();

    return a.exec();
}
