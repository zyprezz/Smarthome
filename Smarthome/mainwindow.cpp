#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lysWindow = new Lysstyring(this);
    gardinWindow = new GardinStyring(this);
}

MainWindow::~MainWindow()
{
//    calendar->abort();
//    thread->wait();

//    qDebug()<<"Deleting thread and worker in Thread "<< this->QObject::thread()->currentThreadId();

//    delete thread;

//    delete calendar;

    delete ui;
}


void MainWindow::on_lysButton_clicked()
{
    lysWindow->showMaximized();
}

void MainWindow::on_varmeButton_clicked()
{
    VarmeStyring varme;
    varme.setModal(true);
    varme.exec();
}

void MainWindow::on_gardinButton_clicked()
{
//    GardinStyring gardin;
//    gardin.setModal(true);
//    gardin.exec();

    gardinWindow->showMaximized();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QFont f = ui->lysButton->font();
    QFontMetrics metrics(f);
    QSize size = metrics.size(0,ui->lysButton->text());
    float factorw = ui->lysButton->width()/(float)size.width();
    float factorh = ui->lysButton->height()/(float)size.height();

    float factor = qMin(factorw, factorh);

    f.setPointSizeF((f.pointSizeF()*factor) *0.6);
    ui->lysButton->setFont(f);
    ui->gardinButton->setFont(f);
    ui->varmeButton->setFont(f);

    ui->statuslabel->setFont(f);

}
