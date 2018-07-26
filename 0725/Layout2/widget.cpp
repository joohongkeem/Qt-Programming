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
    // ��� this�� �ִ´ٸ� �����Եȴ�.
    QStackedLayout* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial, SIGNAL(valueChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));

    // HBox�� ������ �ƴ�, Ŭ�����⶧����!! this�� �־ �ǰ� �ȳ־ �ȴ�!!!!
    // -> Layout���� this�� ���� �ʴ� ������ ������ !!
    // -> Layout�� ������ �ٸ���!!!! this�� �������� !!!
    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    // 2���� ���̾ƿ� �� ����� ���� ������ ������ ���̾ƿ��� setLayout() �޼ҵ�� ����
    setLayout(hBoxLayout);
}

Widget::~Widget()
{

}
