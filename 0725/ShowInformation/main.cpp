#include "widget.h"
#include <QApplication>
#include <QLCDNumber>
#include <QProgressBar>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLCDNumber *lcd = new QLCDNumber();

    lcd->setHexMode();
    //
    // setHexMode, setBinMode, setOctMode, SetDetMode�� �ٲ㺸��
    // 2������ ����� ��µ��� �ʴ´� -> �ִ� 8�ڸ��� ���ڸ� ��°�!!!!!

    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(2002);
    lcd->show();

// -----------------------------------------------------------------------------------------------------

    // Q. �Ʒ��� �ڵ忡�� setRange() �޼ҵ带 ����� ������ �����ؼ� 40%�� ǥ�õǰ� �����غ���!!
    //

    QProgressBar *progBar = new QProgressBar();
    progBar->setValue(20);
    //progBar->setInvertedAppearance(true);     // �����ʿ��� �������� ������ ����!
    progBar->show();


 // -----------------------------------------------------------------------------------------------------


    return a.exec();
}
