#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit",this);

    quit->resize(200,100);
    quit->move(50,50);      // quit->setGeometry(50, 50, 200, 100);
                            // setGeometry는 resized와 move를 한번에 할 수 있다.

    QLabel *label = new QLabel("<font color=blue>Hello Qt!</font>",this);
    label -> setGeometry(100,200,200,100);


    // - QWidget은 QObject를 상속받고, public으로 상속받기때문에 connect함수 앞에 QObject::를 적어주지 않아도 된다.
    // - QApplication은 main문에 선언되어있는데 어떻게 이 함수에서 접근할 수 있을까?
    //   -> qApp는 QApplication 클래스의 전역 인스턴스!!!!!!
    //connect(quit, SIGNAL(clicked(bool)),qApp, SLOT(quit()));      // 무조건 종료하는 SLOT
    connect(quit, SIGNAL(clicked(bool)), this, SLOT(slotQuit()));   // 사용자 정의 슬롯!!!! -> 반드시 구현이 필요하다!!
}

Widget::~Widget()
{

}

void Widget::slotQuit()
{
    qDebug("slotQuit");     // 로그메시지 출력
    qApp->quit();
}
