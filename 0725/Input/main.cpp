#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QStyleFactory>
#include <QDial>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton *pushButton = new QPushButton("Push&Button",0);
    QObject::connect(pushButton, SIGNAL(clicked(bool)), &a, SLOT(quit()));

    pushButton->show();

// -----------------------------------------------------------------------------------------------------

    // QRadioButton, QCheckBox
    //

    Widget w;
    w.show();

// -----------------------------------------------------------------------------------------------------

    /*

     * ���� ���� ����

     - ���ڷ� �Ǿ� �ִ� ���� ���� �� �Է� �� ǥ��
       > ����ڰ� �̸� ���� ���� Ư�� ������ ������ �����ϱ� ���ؼ� ���
       > �⺻ ���� ���� : 0 ~ 99 ���� -> setRange() �޼ҵ带 ���� ���氡��
     - ���� ��ȯ���� ����� ������ setWrapping() �޼ҵ带 �̿�
     - QDoublespinBox, QSpinBox ���� : QAbstractSpinBoxŬ������ ���
       > ��Ȯ�� ���� �Է� �� ǥ��
     - Qslider, QScrollBar �� QDial ���� : QAbstractSliderŬ������ ���

                  QtObject
                      |
                  QObject       QPaintDevice
                      |______   _______|
                             | |
                           QWidget
                         _____|_____
                        |           |
                QAbstractSpinBox  QAbstaractSlider
                 |  |   |                 | | |
    QDateTimeEdit QDoubleSpinBox QSpinBox    QDial QScrollBar QSlider
         |  |
 QDateEdit QTimeEdit
    */


    QSpinBox *spinBox = new QSpinBox();
    spinBox -> setRange(0,200);
    spinBox->setSuffix("%");
    spinBox->setWrapping(true);
    spinBox->setSpecialValueText("Percent");
    spinBox->show();

// -----------------------------------------------------------------------------------------------------
    QSlider *slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setStyle(QStyleFactory::create("Fusion"));
    slider->show();


// -----------------------------------------------------------------------------------------------------

    QDial *dial = new QDial();
    dial->setWrapping(true);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(10);
    dial->show();

// -----------------------------------------------------------------------------------------------------
    return a.exec();
}
