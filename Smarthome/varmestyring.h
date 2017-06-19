#ifndef VARMESTYRING_H
#define VARMESTYRING_H

#include <QDialog>

namespace Ui {
class VarmeStyring;
}

class VarmeStyring : public QDialog
{
    Q_OBJECT

public:
    explicit VarmeStyring(QWidget *parent = 0);
    ~VarmeStyring();

private:
    Ui::VarmeStyring *ui;
    //void sliderMoved(int position);
private slots:
    void sliderMoved(int position);
    void setValueToTheLabel( int value);

};

#endif // VARMESTYRING_H
