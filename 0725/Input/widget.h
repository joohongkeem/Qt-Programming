#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// class ���þ�
// - ������ ���Ͽ��� �ƿ��ϴ� Ŭ������ �ٸ������� ���ǵǾ� �ִٰ� ����
// -> class�� ��������� �ٸ������� �ҷ��;� �Ѵ�.
// -> �����Ͻ� ������ ������ϰ� ������ �ҷ����� �ʾƼ� ������ �ð� ����
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
