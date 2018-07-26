#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QLabel;   // 영구적 메시지 표시를 위해서 QLabel 객체를 추가
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
    // 액션의 생성 및 설정과 시그널/슬롯을 한꺼번에 처리하는 메소드
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
