/*
 * 20180724 made by joohongkeem

 * ��Ģ ���� ���� ���α׷���
 - ����� ���� ������ ���
 - ��ư�� ���̺��� ���
 - 16���� ��ư : 10���� ����, ��Ģ ����, ���, �ʱ�ȭ(Clear)

 * QWidget�� ��ġ ���� �޼ҵ�
 - move()�� resize() �޼ҵ�
 - setGeometry() �޼ҵ�

 * QLabel ����
 - text() �޼ҵ�� setText() �޼ҵ�
   > Qstring ���� ������ / ���� �߰��� append() �޼ҵ�
 - ���ڿ� ���� ��ȯ : QString Ŭ���� toInt(), toFloat() �޼ҵ�
 - ����� �Ϲ������� ������ ������ ���

 * ���ڿ� ���ڿ�
 - Qt�� �����ڵ带 ���������ν� ����ȭ�� ����
   > QChar Ŭ���� : 16��Ʈ�� �����ڵ�(UTF)�� ����
   > QString Ŭ���� : 16��Ʈ�� QChar���� �����ڵ� ���ڿ�
 - QString Ŭ����
   > ���ڿ��� ���� �⺻ Ŭ����
   > Qt�� �����鿡 ���ڸ� ǥ���� �� ���������ε� ����Ѵ�.
   > �������̳� �Ǽ������� ��ȯ�ؼ� ��� ����
    (toShort(), toInt(), toLong(), toFloat(), toDouble(),toLongLong(),
     toUShort(), toUInt(), toULong(), toULongLong())
   > ������ ����(Implicit Sharing)�� ���
    - �޸��� ��뷮�� ���̰� ���ʿ��� �������� ���縦 ȸ��
    - ��Ͻ� ����(Copy-on-write)�� 8��Ʈ ���� ��ſ�
      16��Ʈ�� ���ڸ� ����Կ� ���� �߻��ϴ� �����ϸ� ���� !
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
