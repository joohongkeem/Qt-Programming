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



    lLabel = new QLabel(sNum, this);
    lLabel->resize(160,35);
    lLabel->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    // 우측정렬(AlignRight) + 위아래기준중앙정렬(AlignVCenter)

    lOp = new QLabel("",this);
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

    if(sNum == "0");
    else
    {
        sNum.append("0");
    }
    lLabel->setText(sNum);
}
void Widget::slotOne()
{
    if(sNum == "0")sNum = "1";
    else
    {
       sNum.append("1");
    }

    lLabel->setText(sNum);

}
void Widget::slotTwo()
{
    if(sNum == "0")sNum = "2";
    else
    {
        sNum.append("2");
    }
    lLabel->setText(sNum);
}
void Widget::slotThree()
{
    if(sNum == "0")sNum = "3";
    else
    {
        sNum.append("3");
    }
    lLabel->setText(sNum);
}
void Widget::slotFour()
{
    if(sNum == "0")sNum = "4";
    else
    {
        sNum.append("4");
    }
    lLabel->setText(sNum);
}
void Widget::slotFive()
{
    if(sNum == "0")sNum = "5";
    else
    {
        sNum.append("5");
    }
    lLabel->setText(sNum);
}
void Widget::slotSix()
{
    if(sNum == "0")sNum = "6";
    else
    {
        sNum.append("6");
    }
    lLabel->setText(sNum);
}
void Widget::slotSeven()
{
    if(sNum == "0")sNum = "7";
    else
    {
        sNum.append("7");
    }
    lLabel->setText(sNum);
}
void Widget::slotEight()
{
    if(sNum == "0")sNum = "8";
    else
    {
        sNum.append("8");
    }
    lLabel->setText(sNum);
}
void Widget::slotNine()
{
    if(sNum == "0")sNum = "9";
    else
    {
        sNum.append("9");
    }
    lLabel->setText(sNum);
}
void Widget::slotClear()
{
    this -> nLeft = 0;
    this -> nRight = 0;
    this -> sNum = "0";
    lLabel->setText(sNum);
    this -> cOp = "";
}
void Widget::slotAdd()
{
    if(cOp == 0)nLeft = sNum.toFloat();
    sNum = "0";
    cOp = "+";
    lOp->setText(cOp);

}
void Widget::slotSub()
{
    if(cOp == 0)nLeft = sNum.toFloat();
    sNum = "0";
    cOp = "-";
    lOp->setText(cOp);
}
void Widget::slotDiv()
{
    if(cOp == 0)nLeft = sNum.toFloat();
    sNum = "0";
    cOp = "/";
    lOp->setText(cOp);
}
void Widget::slotMul()
{
    if(cOp == 0)nLeft = sNum.toFloat();
    sNum = "0";
    cOp = "*";
    lOp->setText(cOp);
}
void Widget::slotResult()
{

    if(cOp=="+")
    {
        nRight = sNum.toFloat();
        sNum.setNum(nLeft + nRight, 'g',6);
        lLabel->setText(sNum);
    }
    if(cOp=="-")
    {
        nRight = sNum.toFloat();
        sNum.setNum(nLeft - nRight, 'g',6);
        lLabel->setText(sNum);
    }
    if(cOp=="/")
    {
        nRight = sNum.toFloat();
        if(nRight == 0)
        {
            sNum = "Can't Devide by 0";
        }
        else sNum.setNum(nLeft / nRight, 'g',6);
        lLabel->setText(sNum);
    }
    if(cOp=="*")
    {
        nRight = sNum.toFloat();
        sNum.setNum(nLeft * nRight, 'g',6);
        lLabel->setText(sNum);
    }
    nLeft = sNum.toFloat();

    cOp ="";
    lOp->setText(cOp);
}
