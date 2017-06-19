#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "calendar.h"
#include "lysstyring.h"
#include "varmestyring.h"
#include "gardinstyring.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_lysButton_clicked();

    void on_varmeButton_clicked();

    void on_gardinButton_clicked();

private:
    Ui::MainWindow *ui;

//    QThread *thread;

//    Calendar *calendar;

    Lysstyring *lysWindow;
    GardinStyring *gardinWindow;

protected:
    void resizeEvent(QResizeEvent *);

};

#endif // MAINWINDOW_H
