#ifndef LYSSTYRING_H
#define LYSSTYRING_H

#include <QDialog>
#include <QThread>
#include "calendar.h"

namespace Ui {
class Lysstyring;
}

class Lysstyring : public QDialog
{
    Q_OBJECT

public:
    explicit Lysstyring(QWidget *parent = 0);
    ~Lysstyring();

private slots:

    void on_gemPushButton_clicked();

    void on_OnOffButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Lysstyring *ui;

    QThread *thread;
    Calendar *calendar;

protected:
    void resizeEvent(QResizeEvent *);
};

#endif // LYSSTYRING_H
