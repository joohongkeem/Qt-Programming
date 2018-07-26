#include "widget.h"
#include <QApplication>
#include <QLineEdit>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit *lineEdit = new QLineEdit();
    //lineEdit->setEchoMode(QLineEdit::Password);

    // �Է¹޴� ���¸� ����
    //
    lineEdit->setInputMask("009999");
    lineEdit->setPlaceholderText("input the number");
    lineEdit->show();


    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("joohong");
    comboBox->addItem("eunji");
    comboBox->addItem("dimsum");
    comboBox->addItem("hippo");
    comboBox->setEditable(true);
    comboBox->show();



    return a.exec();
}
