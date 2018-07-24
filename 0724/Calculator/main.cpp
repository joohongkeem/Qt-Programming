/*
 * 20180724 made by joohongkeem

 * 사칙 연산 계산기 프로그래밍
 - 사용자 정의 슬롯의 사용
 - 버튼과 레이블을 사용
 - 16개의 버튼 : 10개의 숫자, 사칙 연산, 결과, 초기화(Clear)

 * QWidget의 배치 관련 메소드
 - move()와 resize() 메소드
 - setGeometry() 메소드

 * QLabel 위젯
 - text() 메소드와 setText() 메소드
   > Qstring 형의 데이터 / 문자 추가시 append() 메소드
 - 문자열 숫자 변환 : QString 클래스 toInt(), toFloat() 메소드
 - 계산기는 일반적으로 오른쪽 정렬을 사용

 * 문자와 문자열
 - Qt는 유니코드를 지원함으로써 국제화를 지원
   > QChar 클래스 : 16비트의 유니코드(UTF)를 문자
   > QString 클래스 : 16비트의 QChar형의 유니코드 문자열
 - QString 클래스
   > 문자열을 위한 기본 클래스
   > Qt의 위젯들에 문자를 표시할 때 내부적으로도 사용한다.
   > 정수형이나 실수형으로 변환해서 사용 가능
    (toShort(), toInt(), toLong(), toFloat(), toDouble(),toLongLong(),
     toUShort(), toUInt(), toULong(), toULongLong())
   > 묵시적 공유(Implicit Sharing)를 사용
    - 메모리의 사용량을 줄이고 불필요한 데이터의 복사를 회피
    - 기록시 복사(Copy-on-write)는 8비트 문자 대신에
      16비트의 문자를 사용함에 따라 발생하는 과부하를 감소 !
*/

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
