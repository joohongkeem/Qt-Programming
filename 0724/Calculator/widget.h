#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    QString sNum = "0";
    QString cOp ="";
    QLabel *lLabel;
    QLabel *lOp;
    Widget(QWidget *parent = 0);
    ~Widget();
    float nLeft;
    float nRight;


public slots:
    void slotZero();
    void slotOne();
    void slotTwo();
    void slotThree();
    void slotFour();
    void slotFive();
    void slotSix();
    void slotSeven();
    void slotEight();
    void slotNine();
    void slotAdd();
    void slotSub();
    void slotDiv();
    void slotMul();
    void slotClear();
    void slotResult();
};

#endif // WIDGET_H
