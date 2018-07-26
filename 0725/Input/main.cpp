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

     * 범위 조정 위젯

     - 숫자로 되어 있는 범위 내의 값 입력 및 표시
       > 사용자가 미리 정해 놓은 특정 범위의 값들을 선택하기 위해서 사용
       > 기본 값의 범위 : 0 ~ 99 사이 -> setRange() 메소드를 통해 변경가능
     - 원형 순환으로 만들고 싶으면 setWrapping() 메소드를 이용
     - QDoublespinBox, QSpinBox 위젯 : QAbstractSpinBox클래스를 상속
       > 정확한 값의 입력 및 표시
     - Qslider, QScrollBar 및 QDial 위젯 : QAbstractSlider클래스를 상속

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
