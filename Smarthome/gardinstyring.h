#ifndef GARDINSTYRING_H
#define GARDINSTYRING_H

#include <QDialog>
#include "calendar.h"

namespace Ui {
class GardinStyring;
}

class GardinStyring : public QDialog
{
    Q_OBJECT

public:
    explicit GardinStyring(QWidget *parent = 0);
    ~GardinStyring();

private:
    Ui::GardinStyring *ui;

    QThread *thread;
    Calendar *calendar;

protected:
    void resizeEvent(QResizeEvent *);
private slots:
    void on_gemPushButton_clicked();
    void on_OnOffButton_clicked();
    void on_pushButton_clicked();
};

#endif // GARDINSTYRING_H
