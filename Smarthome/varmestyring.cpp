#include "varmestyring.h"
#include "ui_varmestyring.h"

VarmeStyring::VarmeStyring(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VarmeStyring)
{
    ui->setupUi(this);
    //myslider->setTooltip(QString::number(myslider->sliderposition()));

    ui->verticalSlider->setToolTip(QString::number(ui->verticalSlider->sliderPosition()));


    connect(ui->verticalSlider,SIGNAL(sliderMoved(int)),this,SLOT(sliderMoved(int)));
    //showText(ui->verticalSlider->mapToGlobal( QPoint( 0, 0 ) ), errorString );

    connect(ui->verticalSlider,SIGNAL(valueChanged(int)), this, SLOT(setValueToTheLabel(int)));

}

VarmeStyring::~VarmeStyring()
{
    delete ui;
}

void VarmeStyring::sliderMoved(int position)
{
    ui->verticalSlider->setToolTip(QString::number(position));
}

void VarmeStyring::setValueToTheLabel(int value)
{
    ui->TempLabel->setText(QString::number(value));
    ui->verticalSlider->setToolTip(QString::number(value));
}
