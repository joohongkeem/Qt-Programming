#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// Qt의 위젯들은 QWidget클래스를 상속
// - QWidget을 상속받는 클래스를 생성하고 생성자에서 화면을 구성

// private으로 상속받으면 아버지 지갑은 아버지꺼, 내지갑은 내꺼
// protected로 상속받으면 냉장고안의 물. 우리가족은 먹을수 있지만 다른집사람이 맘대로먹을순없다
// public으로 상속받으면 집앞의 가로등. 외부사람들도 맘대로 사용가능
class Widget : public QWidget
{
    Q_OBJECT

public:
    // 생성자
    Widget(QWidget *parent = 0);
    // 소멸자
    ~Widget();

public slots:
    void slotQuit();        // 반드시 반환이 있어야한다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                            // 슬롯은 일반 함수와 같이 호출이 가능하다!
                            // -> slot을 사용할 때는 일반적으로 void형의 반환형을 사용!!
};

#endif // WIDGET_H
