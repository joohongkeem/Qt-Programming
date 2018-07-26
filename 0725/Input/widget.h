#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// class 지시어
// - 현재의 파일에서 아용하는 클래스가 다른곳에서 정의되어 있다고 지정
// -> class의 헤더파일을 다른곳에서 불러와야 한다.
// -> 컴파일시 동일한 헤더파일가 여러번 불러지지 않아서 컴파이 시간 절약
//
class QRadioButton;
class QButtonGroup;
class QCheckBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QRadioButton *radioButton[4];
    QCheckBox *checkBox[4];
    QButtonGroup *buttonGroup1;
    QButtonGroup *buttonGroup2;

public slots:
    void selectButton(int id);
};

#endif // WIDGET_H
