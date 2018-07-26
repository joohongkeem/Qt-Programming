#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // ���ڰ� �����Ƿ� �ʱⰪ parent = 0 �� ����. -> �ֻ�������(������ â���� ������)
    QPushButton* pushButton1 = new QPushButton();
    pushButton1->setText("Button 1");
    // ���� ������ �ϳ��� ��ģ��
    QPushButton* pushButton2 = new QPushButton("Button 2");
    QPushButton* pushButton3 = new QPushButton("Button 3",this);

    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addWidget(pushButton2);
    hBoxLayout->addWidget(pushButton3);

    // �̷����ϸ� ��ư1,2 �� ĭ�� �ø��� ��ư�� �þ,
    // ��ư3�� ũ�Ⱑ �þ�� �ʴ´�!!!
    //
    pushButton1->show();
    pushButton2->show();
    pushButton3->show();


    // �̰� �ּ�ó���ϸ� â���ϳ���������µ� Button 3�� ��µȴ� !!
    // Why? 'this' ���� !!
    //
    //setLayout(hBoxLayout);


    // ������ �߰��� ó������ �θ� �������ִ� ���� ����!!
    //
    // [����] ������ Ŭ������ ���踦 �߻����غ��鼭 �ּ�ó���ϰ� ����� ���캸�� !!!!!!
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
