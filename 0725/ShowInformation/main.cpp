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
    // setHexMode, setBinMode, setOctMode, SetDetMode로 바꿔보면
    // 2진수는 제대로 출력되지 않는다 -> 최대 8자리의 숫자만 출력가!!!!!

    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(2002);
    lcd->show();

// -----------------------------------------------------------------------------------------------------

    // Q. 아래의 코드에서 setRange() 메소드를 사용해 범위를 조정해서 40%가 표시되게 수정해보자!!
    //

    QProgressBar *progBar = new QProgressBar();
    progBar->setValue(20);
    //progBar->setInvertedAppearance(true);     // 오른쪽에서 왼쪽으로 가도록 설정!
    progBar->show();


 // -----------------------------------------------------------------------------------------------------


    return a.exec();
}
