#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QLabel;   // ������ �޽��� ǥ�ø� ���ؼ� QLabel ��ü�� �߰�
class QTextEdit;
class QMdiArea;
class QFontComboBox;
class QDoubleSpinBox;
class QString;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = 0);
    ~QtEditor();

private:
    // �׼��� ���� �� ������ �ñ׳�/������ �Ѳ����� ó���ϴ� �޼ҵ�
    //
    QAction *makeAction(QString icon, QString name, QString shortCut,\
                        QString toolTip, QObject* recv, const char* slot);
    QStatusBar *statusbar;
    QLabel* statusLabel;
    QTextEdit* textedit;
    QFontComboBox* fontComboBox;
    QDoubleSpinBox* sizeSpinBox;
    QMdiArea* mdiArea;
    QString fileName;
    int count=0;
public slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveasFile();
    void printFile();
    void alignText();
    void slotEdit();
    void slotWindow();
    void slotAbout();
    void slotFont(QFont font);
    void slotFontSize(qreal size);
    void slotFontWidget();
    void slotSetColor();
    void slotSetFont();

};

#endif // QTEDITOR_H
