#include "widget.h"
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(140,220);
    // buttonGroup1�� ���������̹Ƿ� new�� �Ҵ�
    //
    buttonGroup1 = new QButtonGroup(this);
    for(int i=0; i<4; i++)
    {
        // str�� �������� ������ �ƴϹǷ� new�� �Ҵ��ϸ� ���� �ȵȴ�!!!!
        //
        QString str = QString("RadioButton%1").arg(i+1);
        radioButton[i] = new QRadioButton(str, this);
        radioButton[i]->move(10, 10+20*i);
        buttonGroup1->addButton(radioButton[i]);
    }

   // buttonGroup���� ������ �ñ׳ν������� �ѹ��� ó���� �� �ִٴ� ū �������ִ�!!
   //
   buttonGroup2 = new QButtonGroup(this);

   // �� �Ӽ��� ���������� �ߺ������� �Ұ����ϰ� �ȴ�!!
   //
   buttonGroup2->setExclusive(false);

   connect(buttonGroup2, SIGNAL(buttonClicked(int)), SLOT(selectButton(int)));
   //
   // this�� �Ƚ��൵ �ߵȴ�....?!
   // --> receiver���ڰ� 'this'�� ��쿡�� ������ �����ϴ�!!!

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
    // isChecked() �޼ҵ� : ��ư�� ���õǾ����� �ȵǾ����� Ȯ��
    // setChecked() �޼ҵ� : ��ư�� ���ϴ� ���°����� ����
}
