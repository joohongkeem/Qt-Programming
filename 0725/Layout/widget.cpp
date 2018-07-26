#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 인자가 없으므로 초기값 parent = 0 이 들어간다. -> 최상위위젯(별도의 창으로 떠야함)
    QPushButton* pushButton1 = new QPushButton();
    pushButton1->setText("Button 1");
    // 위의 과정을 하나로 합친것
    QPushButton* pushButton2 = new QPushButton("Button 2");
    QPushButton* pushButton3 = new QPushButton("Button 3",this);

    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addWidget(pushButton2);
    hBoxLayout->addWidget(pushButton3);

    // 이렇게하면 버튼1,2 는 칸을 늘리면 버튼도 늘어나,
    // 버튼3는 크기가 늘어나지 않는다!!!
    //
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();


    // 이걸 주석처리하면 창이하나만들어지는데 Button 3만 출력된다 !!
    // Why? 'this' 덕분 !!
    //
    //setLayout(hBoxLayout);


    // 위젯을 추가시 처음부터 부모를 지정해주는 것이 좋다!!
    //
    // [주의] 위젯과 클래스의 관계를 잘생각해보면서 주석처리하고 결과를 살펴보자 !!!!!!
    //
    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setSpacing(6);
    vBoxLayout->addWidget(pushButton1);
    vBoxLayout->addWidget(pushButton2);
    vBoxLayout->addWidget(pushButton3);
    //setLayout(vBoxLayout);


}

Widget::~Widget()
{

}
