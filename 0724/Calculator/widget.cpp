#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    const char ButtonChar[16][2] = {
        "7","8","9","/",
        "4","5","6","*",
        "1","2","3","-",
        "0","C","=","+",};



    this->lLabel = new QLabel(this->sNum, this);
    lLabel->resize(160,35);
    lLabel->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    // 우측정렬(AlignRight) + 위아래기준중앙정렬(AlignVCenter)

    this->lOp = new QLabel("",this);
    lOp->resize(10,10);
    lOp->move(10,10);
    lOp->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    for(int y=0; y<4; y++)
        for(int x=0; x<4; x++)
        {
            QPushButton *button = new QPushButton(ButtonChar[x+y*4],this);
            button->setGeometry(42*x, 35+42*y,40,40);
            if(strcmp(ButtonChar[x+y*4],"1")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotOne()));
            if(strcmp(ButtonChar[x+y*4],"2")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotTwo()));
            if(strcmp(ButtonChar[x+y*4],"3")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotThree()));
            if(strcmp(ButtonChar[x+y*4],"4")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotFour()));
            if(strcmp(ButtonChar[x+y*4],"5")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotFive()));
            if(strcmp(ButtonChar[x+y*4],"6")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotSix()));
            if(strcmp(ButtonChar[x+y*4],"7")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotSeven()));
            if(strcmp(ButtonChar[x+y*4],"8")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotEight()));
            if(strcmp(ButtonChar[x+y*4],"9")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotNine()));
            if(strcmp(ButtonChar[x+y*4],"0")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotZero()));
            if(strcmp(ButtonChar[x+y*4],"+")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotAdd()));
            if(strcmp(ButtonChar[x+y*4],"-")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotSub()));
            if(strcmp(ButtonChar[x+y*4],"/")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotDiv()));
            if(strcmp(ButtonChar[x+y*4],"*")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotMul()));
            if(strcmp(ButtonChar[x+y*4],"C")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotClear()));
            if(strcmp(ButtonChar[x+y*4],"=")==0)
                connect(button,SIGNAL(clicked()),this, SLOT(slotResult()));
        }

}

Widget::~Widget()
{

}

void Widget::slotZero()
{

    if(this->sNum == "0");
    else
    {
        this->sNum.append("0");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotOne()
{
    if(this->sNum == "0") this->sNum = "1";
    else
    {
       this->sNum.append("1");
    }

    this->lLabel->setText(this->sNum);

}
void Widget::slotTwo()
{
    if(this->sNum == "0")this->sNum = "2";
    else
    {
        this->sNum.append("2");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotThree()
{
    if(this->sNum == "0")this->sNum = "3";
    else
    {
        this->sNum.append("3");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotFour()
{
    if(this->sNum == "0")this->sNum = "4";
    else
    {
        this->sNum.append("4");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotFive()
{
    if(this->sNum == "0")this->sNum = "5";
    else
    {
        this->sNum.append("5");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotSix()
{
    if(this->sNum == "0")this->sNum = "6";
    else
    {
        this->sNum.append("6");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotSeven()
{
    if(this->sNum == "0")this->sNum = "7";
    else
    {
        this->sNum.append("7");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotEight()
{
    if(this->sNum == "0")this->sNum = "8";
    else
    {
        this->sNum.append("8");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotNine()
{
    if(this->sNum == "0")this->sNum = "9";
    else
    {
        this->sNum.append("9");
    }
    this->lLabel->setText(this->sNum);
}
void Widget::slotClear()
{
    this -> nLeft = 0;
    this -> nRight = 0;
    this -> sNum = "0";
    this->lLabel->setText(this->sNum);
    this -> cOp = "";
}
void Widget::slotAdd()
{
    if(this->cOp == 0)this->nLeft = this->sNum.toFloat();
    this->sNum = "0";
    this->cOp = "+";
    this->lOp->setText(this->cOp);

}
void Widget::slotSub()
{
    if(this->cOp == 0)this->nLeft = this->sNum.toFloat();
    this->sNum = "0";
    this->cOp = "-";
    this->lOp->setText(this->cOp);
}
void Widget::slotDiv()
{
    if(this->cOp == 0)this->nLeft = this->sNum.toFloat();
    this->sNum = "0";
    this->cOp = "/";
    this->lOp->setText(this->cOp);
}
void Widget::slotMul()
{
    if(this->cOp == 0)this->nLeft = this->sNum.toFloat();
    this->sNum = "0";
    this->cOp = "*";
    this->lOp->setText(this->cOp);
}
void Widget::slotResult()
{

    if(this->cOp=="+")
    {
        this->nRight = this->sNum.toFloat();
        this->sNum.setNum(this->nLeft + this->nRight, 'g',6);
        this->lLabel->setText(this->sNum);
    }
    if(this->cOp=="-")
    {
        this->nRight = this->sNum.toFloat();
        this->sNum.setNum(this->nLeft - this->nRight, 'g',6);
        this->lLabel->setText(this->sNum);
    }
    if(this->cOp=="/")
    {
        this->nRight = this->sNum.toFloat();
        if(this->nRight == 0) sNum = "Can't Devide by 0";
        else this->sNum.setNum(this->nLeft / this->nRight, 'g',6);
        this->lLabel->setText(this->sNum);
    }
    if(this->cOp=="*")
    {
        this->nRight = this->sNum.toFloat();
        this->sNum.setNum(this->nLeft * this->nRight, 'g',6);
        this->lLabel->setText(this->sNum);
    }
    this->nLeft = this->sNum.toFloat();

    this->cOp ="";
    this->lOp->setText(this->cOp);
}
