#include "widget.h"
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDial* dial = new QDial(this);
    dial->resize(100,100);
    dial->setRange(0,2);


    QLabel* label = new QLabel("STACK 1",this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this);
    QTextEdit* textEdit = new QTextEdit("STACK 3",this);

    // new QStackedLayout(this);
    // 라고 this를 넣는다면 깨지게된다.
    QStackedLayout* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial, SIGNAL(valueChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));

    // HBox는 위젯이 아닌, 클래스기때문에!! this를 넣어도 되고 안넣어도 된다!!!!
    // -> Layout에는 this를 써지 않는 습관을 들이자 !!
    // -> Layout은 위젯과 다르다!!!! this를 쓰지말자 !!!
    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    // 2개의 레이아웃 중 사용자 정의 위젯에 연결할 레이아웃을 setLayout() 메소드로 설정
    setLayout(hBoxLayout);
}

Widget::~Widget()
{

}
