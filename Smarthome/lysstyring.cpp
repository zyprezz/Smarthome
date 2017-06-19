#include "lysstyring.h"
#include "ui_lysstyring.h"
#include "filehandler.h"

Lysstyring::Lysstyring(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lysstyring)
{
    ui->setupUi(this);

    //ui->statuslabel->setText("<font color = 'green'> Auto: On</font>");
    ui->statuslabel->setText("<font color = 'red'>Auto: Off</font> - Tryk Gem for at aktivere");

    ui->startTimeEdit->setDisplayFormat("HH:mm");
    int startH = FileHandler::getStartHourFrom(FileHandler::lightPara);
    int startM = FileHandler::getStartMinFrom(FileHandler::lightPara);
    int endH = FileHandler::getEndHourFrom(FileHandler::lightPara);
    int endM = FileHandler::getEndMinFrom(FileHandler::lightPara);
    ui->startTimeEdit->setTime(QTime(startH,startM));

    ui->slutTimeEdit->setDisplayFormat("HH:mm");
    ui->slutTimeEdit->setTime(QTime(endH,endM));



    thread = new QThread();
    calendar = new Calendar(Calendar::Light);

    calendar->moveToThread(thread);

    connect(thread,SIGNAL(started()),calendar,SLOT(mainLoop()));
    connect(calendar,SIGNAL(finished()),thread,SLOT(quit()),Qt::DirectConnection);
    qDebug()<<"Starting thread in Thread "<< this->QObject::thread()->currentThreadId();

    thread->start();

    //calendar->requestMethod(Calendar::Auto);


}

Lysstyring::~Lysstyring()
{
    delete ui;
}

void Lysstyring::on_gemPushButton_clicked()
{
    ui->statuslabel->setText("<font color = 'green'> Auto: On</font>");

    int sHour = ui->startTimeEdit->time().hour(); //henter time værdi
    int sMin = ui->startTimeEdit->time().minute(); // henter min værdi

    int eHour = ui->slutTimeEdit->time().hour(); //henter time værdi
    int eMin = ui->slutTimeEdit->time().minute(); // henter min værdi

    FileHandler::saveTimeTo(FileHandler::lightPara,sHour,sMin,eHour,eMin);

    calendar->requestMethod(Calendar::Auto);

}

void Lysstyring::resizeEvent(QResizeEvent *)
{
    QFont f = ui->gemPushButton->font();
    QFontMetrics metrics(f);
    QSize size = metrics.size(0,ui->gemPushButton->text());
    float factorw = ui->gemPushButton->width()/(float)size.width();
    float factorh = ui->gemPushButton->height()/(float)size.height();
    float factor = qMin(factorw, factorh);

    f.setPointSizeF((f.pointSizeF()*factor) *0.6);

    QFont g = ui->startlabel->font();
    QFontMetrics metricsG(g);
    QSize sizeg = metricsG.size(0,ui->startlabel->text());
    float factorwG = ui->startlabel->width()/(float)sizeg.width();
    float factorhG = ui->startlabel->height()/(float)sizeg.height();
    float factorG = qMin(factorwG,factorhG);

    g.setPointSizeF((g.pointSizeF()*factorG)*0.45);

    ui->gemPushButton->setFont(f);
    ui->startTimeEdit->setFont(f);
    ui->slutTimeEdit->setFont(f);

    ui->statuslabel->setFont(g);
    ui->startlabel->setFont(g);
    ui->slutlabel->setFont(g);
    ui->SensorLabel->setFont(f);

    ui->label_2->setFont(f);
    ui->label->setFont(f);
}

void Lysstyring::on_OnOffButton_clicked()
{
    ui->statuslabel->setText("<font color = 'red'>Auto: Off</font> - Tryk Gem for at aktivere");

    if(ui->OnOffButton->isChecked())
    {
        calendar->requestMethod(Calendar::ManActivate);
    }
    else
    {
        calendar->requestMethod(Calendar::ManDisable);
    }
    ui->pushButton->setChecked(false);
    ui->gemPushButton->setEnabled(true);
}

void Lysstyring::on_pushButton_clicked()
{
    if(ui->pushButton->isChecked())
    {
        ui->gemPushButton->setDisabled(true);
    }
    else
    {
        ui->gemPushButton->setEnabled(true);
    }
}
