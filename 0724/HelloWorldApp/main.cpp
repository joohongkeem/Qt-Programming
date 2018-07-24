#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
// 헤더 파일 포함(#include 프리프로세서)
// Qt3 이전은 대부분 '클래스명의 소문자' +'.h'
// Qt4 이후부터 대부분 클래스명을 그대로 사용

// Qt에서 메소드는 카멜 표기법, 클래스는 파스칼 표기법을 사용
// 카멜표기법 : camelCase, 파스칼표기법 : CamelCase


int main(int argc, char *argv[])
{
// 프로그램의 시작인 main()함수를 정의
// - 매개변수로 argc와 argv(명령행 인자)를 정의
// - argv[0]은 자기자신, 즉 argc는 최소 1

    //QApplication a(argc, argv);
    // QApplication 클래스의 인스턴스 app생성
    // - 애플리케이션의 초기화와 이벤트 루프 등의 담당
    // - Qt의 애플리케이션은 QApplication 클래스의 객체가 반드시 필요

    //QLabel *hello = new QLabel("<font color = blue>""Hello <i> Qt! </i> </font>",0);
    // "Hello Qt!" 레이블(Label) 위젯의 인스턴스 생성
    // - 탑 레벨 위젯 / 윈도우 : 2번째 인자(부모)가 0
    // - 리치 텍스트(Rich Text) : QLabel 위젯에 HTML 태그를 이용하여 서식 지정
    // - C언어에서 한줄의 문장을 2줄로 나눠쓸때 마지막에 '\' 사용
    // - <i>~~~</i> 는 ~~~를 '이태리체'로 출력
    // - 문자열을 두줄로 나눠 쓸 때에는 큰 따옴표("")로 나눠쓰고 중간에 콤마는 사용하지 않는다.


    //hello->resize(200, 100);
    // Help -> Index선택 -> Look for:QWidget입력
    // -> Properties(속성)에서 크기(Size)를 확인 -> 3개의 접근 지정자(Access Functions)제공
    // - getter함수&setter함수
    // QSize -> size() const [getter]
    // void resize(int w, int h) [setter]
    // void resize(const QSize &) [setter]

    //hello->show();
    // 레이블을 화면에 표시, QWidget::show() 메소드

// -----------------------------------------------------------------------------------------------------

    //QApplication a(argc, argv);
    // QApplication 클래스의 인스턴스 app생성
    // - 애플리케이션의 초기화와 이벤트 루프 등의 담당
    // - Qt의 애플리케이션은 QApplication 클래스의 객체가 반드시 필요

    //QPushButton *quit = new QPushButton("Quit",0);
    // QPushButton 위젯은 리치 텍스트를 사용할 수 없다.
    //QObject::connect(quit, SIGNAL(clicked()), &a, SLOT(quit()));

    // 시그널 : 마우스 버튼을 클릭하거나 키보드 키를 누를때 발생
    // - 어떤 일(event)이 발생했다는 것을 알리는 역할
    // 슬롯 : 사용자의 요구에 응답하는 이 코드
    // - 특정 시그널과 연결되어서 사용자의 요구를 처리하는 역할
    // QObject::connect() 함수 : 시그널과 슬롯을 연결
    // -> QObject:;connect(sender, SIGNAL(signal), receiver, SLOT(slot));
    //      sender : 시그널을 발생시킬 객체의 포인터를 지정
    //      signal : 첫 번째 매개변수로 지정된 객체(sender)가 발생시키는 시그널을 지정
    //               ex) clicked, pressed, released, toggled
    //      receiver : 시그널을 받을 객체의 포인터를 지정
    //      slot : 세 번째 매개변수에 지정된 객체(receiver)에 정의된 슬롯을 지정
    //
    // QPushBotton 위젯은 QAbstractButton 클래스를 상속
    // - 버튼의 기본적인 성질과 함수들을 제공
    // - clicked()시그널 사용
    // QApplication 클래스
    // - QCoreApplication 클래스를 상속
    //   -> quit() 슬롯 사용 (Public Slots)

    //quit->resize(200,100);
    //quit->show();
    // 버튼자체가 윈도우? 위젯? 이므로 화면의 크기를 늘리면 버튼도 같이 커진다\
    // [Case 1] QPushButton 위젯 자체를 윈도우(탑레벨 위젯)인 경우
    // - 탑 레벨 위젯 : 위젯 자체가 윈도우, 위젯 생성시 parent를 0으로 설정
    // - 윈도우 크기 변화시 버튼의 크기도 함께 변경


// -----------------------------------------------------------------------------------------------------

    // 사용자 정의 위젯
    // widget.h 파일과 widget.cpp 파일을 수정!
    // - 사용자 정의 위젯에 위젯을 배치하기 위해서는 부모로 현재의 위젯(this)을 설정
    // main.cpp에서는 사용자 정의 위젯 클래스(Widget)로 인스턴스 생성 및 표시

    QApplication a(argc, argv);

    Widget w;
    w.show();
    // 이 경우에는 위와 다르게 화면의 크기를 늘려도 버튼의 크기가 늘어나지 않는다.
    // Why?
    // 부모라는 Widget객체를 show하면서 자식의 객체도 함께 보여주기 때문에!!!
    // [Case 2] 사용자 정의 위젯
    // - 크기 변경시 윈도우의 크기만 변경
    // - 위젯은 윈도우의 안에 배치
    // - 윈도우의 크기 조정시 자식 위젯들도 함께 변경시키려면 별도의 코드나 레이아웃 매니저를 사용

// ----------------------------------------------------------------------------------------------------

    /*
     * C++에 대한 Qt의 확장
     - 표준 C++ 객체 모델은 객체 패러다임에 대해서 매우 효율적으로 런타임 자원을 지원
       -> 일부 영역에서는 정적 측면에서 유연성 부족 -> QObject 클래스
     - gui 프로그램은 실행 시의 효율성과 유연성 양쪽 모두 필요
       1. 강력한 시그널/슬롯 구조 : 상호 관계 없는 객체 간의 통신을 지원
       2. 객체 속성(Object Property) : 질의가 가능한 디자인 가능
          - metaObject() 메소드와 QMetaObject 클래스
       3. 강력한 이벤트와 이벤트 필터
       4. 국제화를 위한 문자 번역
       5. 타이머(Timer) : 이벤트 구동 gui에서 많은 작업(Task)을 간결한 처리가 가능하도록 동일 간격으로 동작
       6. 계층적인 객체 트리 (Object Tree) : 객체 간의 상관관계 구성
       7. 보호 첨부 포인터 (QPointer 클래스)
          : 참조하는 객체가 망가졌을 때 자동적으로 NULL 포인터(Q_NULLPTR)가 설정

     * QObject 클래스
     - Qt에서의 대부분의 클래스는 표준 c++기능을 이용하라 수 있도록 QObject 클래스를 상속
     - QObject 클래스는 대부분의 Qt 객체의 기본(Base) 클래스
       - 시그널과 슬롯을 구현하는 객체(위젯)들은 모두 QObject 클래스를 계승
       - 타이머와 관련된 메소드 제공
       - 디버그 관련 객체 정보에 관한 메소드도 제공
       - 문자 번역과 같은 국제화 관련 메소드를 제공
       - 이벤트와 관련된 메소드를 제공
       - 객체의 구조와 관련된 메소드를 제공

     * 사용자 정의 슬롯
     - 사용자 정의 슬롯을 위한 3가지 조건
       1. 부모 클래스는 QObject 클래스를 직/간접적으로 상속
       2. 헤더파일(.h)에서 클래스의 정의부분 아래에 Q_OBJECT 지시어 필요
         - 메타 오브젝트 코드(moc)가 생성될 수 있도록 지정
         - qmake가 moc 컴파일러를 수행할 수 있도록 해준다.
       3. 클래스 내에 시그널과 슬롯을 선언
         - 슬롯 : 헤더파일(.h)에서 '접근 지정자(public, private 등) + slots:' 아래에 선언하고
                 소스코드(.cpp)에서 구현
         - 시그널 : 'signals:' 아래에 선언
         - 시그널을 선언할 뿐 구현할 필요가 없다
           -> moc 유틸리티가 메타 오브젝트 코드에 자동으로 구현

     * 시그널 / 슬롯 관련 유틸리티
     - moc(Meta Object Compiler)
       > 사용자 정의의 시그널 / 슬롯을 사용하는 소스코드를 컴파일 할 수 있도록 메타 오브젝트 코드를 생성
         $ moc -o moc_widget.cpp widget.h
     - qmake : Qt의 프로젝트 파일과 make 파일을 생성
       > 프로젝트 파일의 생성 : qmake -project widget.cpp
       > makefile의 생성 : Qt Creator의 메뉴에서 Build > Run qmake 클릭 or $qmake [-makefile]

    */


    return a.exec();
    // 애플리케이션의 이벤트 루프를 실행, QApplication::exec() 메소드
    // 이걸 주석처리하면 'Hello Qt'창이 아주 잠깐 떴다가 사라짐(맨위소스코드기준)

}
