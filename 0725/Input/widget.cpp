#include "widget.h"
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(140,220);
    // buttonGroup1은 포인터형이므로 new로 할당
    //
    buttonGroup1 = new QButtonGroup(this);
    for(int i=0; i<4; i++)
    {
        // str은 포인터형 변수가 아니므로 new로 할당하면 절대 안된다!!!!
        //
        QString str = QString("RadioButton%1").arg(i+1);
        radioButton[i] = new QRadioButton(str, this);
        radioButton[i]->move(10, 10+20*i);
        buttonGroup1->addButton(radioButton[i]);
    }

   // buttonGroup으로 묶으면 시그널슬롯으로 한번에 처리할 수 있다는 큰 장점이있다!!
   //
   buttonGroup2 = new QButtonGroup(this);

   // 이 속성을 주지않으면 중복선택이 불가능하게 된다!!
   //
   buttonGroup2->setExclusive(false);

   connect(buttonGroup2, SIGNAL(buttonClicked(int)), SLOT(selectButton(int)));
   //
   // this를 안써줘도 잘된다....?!
   // --> receiver인자가 'this'인 경우에만 생략이 가능하다!!!

   for(int i=0; i<4; i++)
   {
       QString str = QString("CheckBox%1").arg(i+1);
       checkBox[i] = new QCheckBox(str,this);
       checkBox[i]-> move(10, 90+20*i);
       buttonGroup2->addButton(checkBox[i],i);
   }
}

Widget::~Widget()
{

}

void Widget::selectButton(int id)
{
    QButtonGroup* buttonGroup  = (QButtonGroup*)sender();
    QCheckBox* button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)",id+1, (button->isChecked())?"On":"Off");
    //
    // isChecked() 메소드 : 버튼이 선택되었는지 안되었는지 확인
    // setChecked() 메소드 : 버튼을 원하는 상태값으로 설정
}
