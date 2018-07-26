#include "qteditor.h"
#include <QApplication>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolbar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QStatusBar>
#include <QFile>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <string.h>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QFile>
#include <QFileInfo>

#define SDI 1
#define MDI 2
#define MODE 2

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{

#if MODE == 1
    // 기존의 아무입력이 없던 창에서 TextEdit창으로 변경
    // - QTextEdit : 여러 줄의 문자열의 입력을 위한 위젯
    //   > QMainWindow::setCentralWidget() 메소드를 사용해서 중앙 위젯을 등록
    //
    textedit = new QTextEdit(this);
    setCentralWidget(textedit);

#else

    // 위에껀 SDI방식
    /*
     * 다중 문서 인터페이스(MDI)
     - 하나의 응용프로그램 내에서 여러 개의 윈도우를 동시에 열어서 여러 문서의 처리 가능
       > 응용 프로그램의 예 : MS 오피스의 엑셀이나 워드
       > 단일 문서 인터페이스(SDI) : 한번에 하나의 화면에서만 작업이 가능
     - Qt에서 MDI를 사용하려면 QMdiArea 위젯을 사용
       > 메인 윈도우의 중앙 위젯으로 설정해서 사용
       > 폭포(Cascade)와 타일(Tile)과 같은 정렬 형식을 지원
     */

    // QMainWindow의 중앙 위젯을 QMdiArea 위젯의 인스턴스로 변경
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
    newFile();




#endif


    /*
     * 메뉴 바(Menu Bar)
     - 헤더파일 : #include <QMenuBar>
     - 윈도우의 타이틀 바 아래쪽에 위치 (리눅스, 윈도우 등)
       > macOS는 화면의 윗쪽에 위치 : 시스템 와이드 메뉴바
     - 수평 메뉴 바로 풀다운(Full-down) 메뉴 항목으로 구성
     - 자동으로 부모 위젯의 윗쪽에 위치, 부모 위젯의 크기가 바뀌면 자동으로 크기 조절
     - Qt에서는 QMenuBar 클래스를 이용해서 메뉴바를 추가하고, QMenu 클래스로 메뉴를 추가
     - 아래의 두 가지 방법 중 하나를 사용할 수 있다.
       1) QMenubar 클래스의 인스턴스를 생성 후,
          QMainWindow 클래스의 setMenuBar() 메소드를 호출해서 등록하는 방식
          -> QMenuBar *menubar = new QMenuBar(this);
             SetMenuBar(menubar);
       2) QMainWindow 클래스에서 제공하는 메뉴바를 반환받아 사용하는 방식
          : QMainWindow::menuBar() 메소드를 이용
          -> QMenuBar *menubar = this->menuBar();
     */
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);
    //
    // 메뉴를 추가하지 않았으므로 아직 변화 X
    // 아래쪽의 QMenu클래스를 사용해서 메뉴를 추가해야함.


    /*
     * QMenu 클래스
     - 헤더파일 : #include <QMenu>
     - QMenu 클래스는 메뉴바, 콘텍스트 메뉴, 그리고 팝업 메뉴에서 사용하는 메뉴를 제공
       > 키보드의 특수한 키를 누르거나 마우스의 오른쪽 버튼을 클릭하여 보여지는
         콘텍스트 메뉴와 같이 하나씩 사용
       > 메뉴 바의 풀다운 메뉴처럼 여러 개를 묶어서 사용
     - 메뉴 화면
       > MS Windows와 유닉스의 경우 메뉴바가 프로그램 윈도우 안에 위치
       > Mac에서는 화면의 제일 위쪽에 메뉴바(System-wide Menubar)가 위치
     - 메뉴 항목(Item)은 세 가지로 구분
       > 메뉴 항목을 서로 구분해주는 구분자(Separator) : addSeparator()
       > 하위(서브)메뉴(Submenu) : addMenu()
       > 지정된 함수를 실행하는 액션(Action) : addAction()★★
     - 하위(서브) 메뉴의 추가
       > 기존의 메뉴에 addMenu() 메소드를 사용
         ex) QMenu *alignMenu = formatMenu->addMenu("&Exit");

       Quiz. 정렬을 위한 서브메뉴를 구현하려면?
          -> QTextEdit::setAlignment(Qt::Alignment a) 슬롯 사용
    */
    QMenu *fileMenu = menubar->addMenu("&File");
    QMenu *editMenu = menubar->addMenu("&Edit");
    QMenu *formatMenu = menubar->addMenu("F&ormat");
    QMenu *windowMenu = menubar->addMenu("&Window");
    QMenu *helpMenu = menubar->addMenu("&Help");

    /*
     * QAction 클래스
     - 헤더파일 : #include <QAction>
     - 메뉴(QMenu), 툴바(QToolBar) 등의 동작을 하나로 연결해서 사용
       > 하나의 코드로 메뉴와 툴바를 한꺼번에 지원 -> 코드의 통일성 증대
       > 표시되는 텍스트, 아이콘, 단축키, 툴팁, 상태팁 등을 설정
     - QMainWindow의 예제와 아이콘 파일
       > C:\Qt\Qt5.x.x\Examples\Qt-5.x\widgets\mainwindows\mdi\images
       > 유닉스에서 파일 검색 : find 명령어 ( $ find / -name new.png )

     * QStyle에서도 다양한 아이콘을 제공한다. # style()->standardIcon(Qstyle::SP_DialogSaveButton) #

     * ★★★★★★아이콘의 경로★★★★★★
     * 좌측메뉴의 Projects -> Run -> Working Directory 누른후 우클릭 -> show in Explorer
     *

    */

    QAction *newAct = new QAction(QIcon(":/Icon/new.png"), "&New", this);
    // 단축키 지정
    newAct->setShortcut(tr("Ctrl+N"));
    // 설명입력, StatusBar는 아직 만들지않았으므로 표시가 되지 않는다.
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered(bool)),SLOT(newFile()));
    fileMenu->addAction(newAct);

    /*
     * 만들어야하는 메뉴가
     * File - New/Open/Save/Save as../Print/Quit
     * Edit - Undo/Redo/Copy/Cut/Paste/Zoom in/Zoom out
     * Format - Font/Color/Align-(Left/Center/Right/Juisify
     * Window - Cascade/Tile/prev/Next/Excuting
     * Help - About/About Qt
     *
     * 이렇게 엄청 많으므로 액션의 생성 및 설정과 시그널&슬롯을 한번에 처리하는 메소드를 구현하자.
     * (아래에 MakeAction함수로 정의)
     */

    QAction *openAct = makeAction(":/Icon/open.png","&Open","Ctrl+O","open a file",this,SLOT(openFile()));
    fileMenu->addAction(openAct);
    QAction *saveAct = makeAction(":/Icon/save.png","&Save","Ctrl+S","save a file",this,SLOT(saveFile()));
    fileMenu->addAction(saveAct);
    QAction *saveasAct = makeAction(":/Icon/saveas.png","Save &As","Alt+S","save as a file",this,SLOT(saveasFile()));
    fileMenu->addAction(saveasAct);
    QAction *printAct = makeAction(":/Icon/print.png","&Print","Ctrl+P","print a file",this,SLOT(printFile()));
    fileMenu->addAction(printAct);
    // 종료함수는 qApp를 receiver로하고 quit()함수를 호출해주면 된다.
    // qApp를 사용하기위해서 #include <QApplication>
    // -> qApp는 QApplication 클래스의 전역 인스턴스!!!!!!
    QAction *quitAct = makeAction(":/Icon/quit.png","&Quit","Ctrl+Q","quit a file",qApp,SLOT(quit()));
    fileMenu->addAction(quitAct);



    /*
     * 툴바 (Tool Bar)
     - 메인 윈도우의 툴바
       > 툴바의 영역 내에서 드래그해서 자유롭게 이동 및 분리 가능
       > 툴바의 이동이나 분리를 원하지 않는 경우 제한, 통제 가능
     - 툴바를 팔레트처럼 분리 가능
       > 별도의 코드 추가 없이 Qt에서 자동으로 지원
     - 툴바와 독 위젯(Dock Widget)을 새로운 위치로 이동시키기 위해서 드래그할 때, 피드백(Feedback)을 사용
       > QToolBar와 QDockWidget 클래스를 각각 독립적으로 제공

     * QToolBar 클래스
     - 헤더파일 : #include <QToolBar>
     - QToolbar클래스는 버튼으로 구성된 이동 가능한 패널을 제공
       > QMainWindow 클래스나 그 서브클래스에서만 사용 가능
       > 확장(Extension) 버튼
       : 툴바의 크기보다 윈도우의 크기가 작아서 툴 버튼을 모두 표시할 수 없을 때!
     - 툴바에 항목 추가
       > 액션의 추가 : addAction()
       > 위젯의 추가 : addWidget()
         -> 텍스트 에디터에 QFontComboBox위젯으로 폰트를 조정하고,
            QSpinBox위젯을 이용해서 글자의 크기를 설정할 수 있다.
       > 중앙 분리선의 추가 : addSeparator()
     */

    QToolBar *fileToolBar = addToolBar("File &Toolbar");
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();        // 구분선을 추가해준다.
    fileToolBar->addAction(openAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(saveAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(saveasAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);
    fileToolBar->addSeparator();

    /*
    * 툴바(QToolBar)에 위젯을 추가할 수 있다.
    * ->QToolBar 클래스의 addWidget()메소드 사용
    */
#if MODE == 2
    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),this,SLOT(slotFont(QFont)));

    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slotFontSize(qreal)));
#else
    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),textedit,SLOT(setCurrentFont(QFont)));

    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)), textedit, SLOT(setFontPointSize(qreal)));
#endif
    /*
     * 툴바(QToolBar)의 버튼 스타일
     - 툴바에서 텍스트와 아이콘의 위치와 표시 방법 조정
       > QToolBar 클래스의 void setToolButtonStyle(Qt::ToolButtonStyle toolButtonStyle) 메소드 사용
         ex) fileToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIncon);

        Qt::ToolButtonIconOnly		: 아이콘만 표시 (Default, 값=0)
        Qt::ToolButtonTextOnly		: 텍스트만 표시 (값=1)
        Qt::ToolButtonTextBesideIcon	: 아이콘 옆에 텍스트를 표시 (값=2)
        Qt::ToolButtonTextUnderIcon	: 아이콘 밑에 텍스트를 표시 (값=3)

       > 툴바의 토글을 액션 사용 가능
        : QAction *toggleViesAction() const;
          ex) editMenu->addAction(fileToolBar->toggleViewAction());

     * QToolButton 클래스
     - 헤더파일 : #include <QToolButton>
     - 툴 버튼은 일반적으로 툴바에서 사용하며 명령어나 옵션들에 빨리 접근할 수 있는 방법을 제공
       > QToolBar 클래스에 addWidget() 메소드로 툴버튼을 추가해도
         Qt::ToolButtonStyle는 고려되지 않는다.
       > QToolButton::setDefaultAction() 슬롯 : QAction 설정 가능
     - QIcon 클래스를 이용해서 툴 버튼에 아이콘을 설정
       > QToolButton::setIcon(QIcon("open.png"));
     - 툴 버튼은 다른 버튼들과 마찬가지로 QAbstractButton클래스를 상속
       > 일반적인 사용방법은 QPushButton과 비슷하다
   */

    fileMenu->addSeparator();
    fileMenu->addAction(fileToolBar->toggleViewAction());


    // 이걸 주석처리하면 기존의툴바 오른쪽에 새로만든 위젯이 추가된다.
    // 이걸 주석처리하지 않으면 기존의 툴바 하단에 새로만든 위젯들이 추가된다.
    addToolBarBreak();

    QToolBar *editToolBar = addToolBar("Edit &Toolbar");
    addToolBarBreak();
    QToolBar *windowsToolBar = addToolBar("Windows &Toolbar");
    QToolBar *formatToolBar = addToolBar("Format &Toolbar");
    formatToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    addToolBarBreak();
    QToolBar *fontToolBar = addToolBar("&Font Toolbar");
    QToolBar *sizeToolBar = addToolBar("&Size Toolbar");
    addToolBarBreak();
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addSeparator();
    sizeToolBar->addWidget(sizeSpinBox);
    sizeToolBar->addSeparator();

    formatMenu->addAction(fontToolBar->toggleViewAction());
    formatMenu->addAction(sizeToolBar->toggleViewAction());
    formatMenu->addSeparator();
    /*
     * QStatusBar 클래스
     - 헤더파일 : #include <QstatusBar>
     - 메인 윈도우의 제일 아래에 수평으로 위치
       > 애플리케이션의 진행 상태나 버튼 용도 등의 정보를 사용자에게 제공
       > 오른쪽 아래의 QSizeGrip 클래스를 이용해서 크기를 조정 가능
     - 상태 바에 표시하는 정보는 세 가지로 구분
       > 일시적 : 상태 바에서 잠시 보여주는 정보(툴 ?ㅂ이나 메뉴 엔트리)
       > 보통 : 상태 바의 일부를 차지하지만 일시적인 메시지에 의해서 가려질 수 있는 정보(페이지나 라인 정보)
       > 영구적 : 중요한 정보로 절대 가려지지 않는다 -> 상태바에 새로운 위젯을 추가해서 사용
     */

    statusbar = statusBar();
    statusLabel = new QLabel("Qt Editor",statusbar);
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started",1500);     // 애플리케이션 시작시 "started"메시지가 1.5초간 표시



    /*
     * Edit메뉴 만들기 (Undo/Redo/Copy/Cut/Paste/Zoom in/Zoom out)
     * - QTextEdit 위젯에서 undo(), redo(), copy(), cut(), paste(), zoomIn(), zoomOut() 슬롯을 제공
     * - 시그널 연결시의 인자 설정
     *   >> connect(시그널을 보낼 객체, SIGNAL(시그널()), 슬롯을 가진 객체, SLOT(슬롯()));
     */


    QAction *undoAct = makeAction(":/Icon/undo.png","&Undo","Ctrl+Z","undo",this,SLOT(slotEdit()));
    editMenu->addAction(undoAct);
    QAction *redoAct = makeAction(":/Icon/redo.png","&Redo","Alt+Z","redo",this,SLOT(slotEdit()));
    editMenu->addAction(redoAct);
    QAction *copyAct = makeAction(":/Icon/copy.png","&Copy","Ctrl+C","copy",this,SLOT(slotEdit()));
    editMenu->addAction(copyAct);
    QAction *cutAct = makeAction(":/Icon/cut.png","Cu&t","Ctrl+X","cut",this,SLOT(slotEdit()));
    editMenu->addAction(cutAct);
    QAction *pasteAct = makeAction(":/Icon/paste.png","&Paste","Ctrl+V","paste",this,SLOT(slotEdit()));
    editMenu->addAction(pasteAct);
    QAction *zoominAct = makeAction(":/Icon/zoomin.png","Zoom &In","Ctrl++","zoom in",this,SLOT(slotEdit()));
    editMenu->addAction(zoominAct);
    QAction *zoomoutAct = makeAction(":/Icon/zoomout.png","Zoom &Out","Ctrl+-","zoom out",this,SLOT(slotEdit()));
    editMenu->addAction(zoomoutAct);


    //    QToolBar *editToolBar = addToolBar("Edit &Toolbar"); 는 순서를 위해 위에다선언해둠
    editToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    editToolBar->addAction(undoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(redoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(copyAct);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAct);
    editToolBar->addSeparator();
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoominAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoomoutAct);
    editToolBar->addSeparator();

    editMenu->addSeparator();
    editMenu->addAction(editToolBar->toggleViewAction());



    /*
     * 메뉴에 서브 메뉴를 추가하는 방법
     1. 새로운 메뉴를 만들고 기존의 메뉴에 서브 메뉴로 추가하는 방법
        Ex) QMenu *alignMenu = new QMenu("&Align",this);
            formatMenu->addMenu(alignMenu);

     2. 기존의 메뉴에 바로 추가하는 방법
        Ex) QMenu *alignMenu = formatMenu->addMenu("&Align");
    */

    // - Format메뉴에 alignMenu 추가
    //   > addMenu를 사용했다!!! (addAction이랑 구분 !!)
    QMenu *alignMenu = formatMenu->addMenu("&Align");
    formatMenu->addSeparator();

    // - 정렬 시그널과 슬롯 연결
    //
    //QAction *alignCenter = makeAction("aligncenter.png","&Center","Ctrl+Shift+C","align center",textedit, SLOT(setAlignment(Qt::AlignCenter)));
    //QAction *alignCenter = makeAction("aligncenter.png","&Center","Ctrl+Shift+C","align center",textedit, setAlignment(Qt::AlignCenter)));
    //QAction *alignCenter = makeAction("aligncenter.png","&Center","Ctrl+Shift+C","align center",this, SLOT(alignCenter()));
    QAction *alignCenter = makeAction(":/Icon/aligncenter.png","&Center","Ctrl+Shift+C","align center",this, SLOT(alignText()));
    QAction *alignLeft = makeAction(":/Icon/alignleft.png","&Left","Ctrl+Shift+L","align left",this,SLOT(alignText()));
    QAction *alignRight = makeAction(":/Icon/alignright.png","&Right","Ctrl+Shift+R","align right",this,SLOT(alignText()));
    QAction *alignJusify = makeAction(":/Icon/alignjustify.png","&Justify","Ctrl+Shift+J","align justify",this,SLOT(alignText()));

    //
    // 가장 아래 방법을 사용하기 위해서 qteditor.h에서 textedit을 클래스의 멤버 변수로 !!!
    // 그리고 qteditor.cpp파일에서 로컬변수가 아닌 멤버 변수(textedit)에 할당!!

    // 위의 주석처리한 두개의 방식은 틀렸다!!
    // Why?
    // [시그널/슬롯을 쓸때 주의사항★]
    // 시그널과 슬롯의 매개변수 타입이 동일해야한다 !!!!
    // -> trigger()이 시그널이므로 슬롯또한 값을 매개변수로 쓸 수 없으니 사용자정의슬롯을 사용해야한다!!

    /*
     * 슬롯과 시그널
     - 슬롯은 시그널과 연결될 수 있고, 시그널과 연결된 스롯은 해당 시그널이 발생될 때마다 자동으로 호출
       > 시그널/슬롯 메커니즘은 QObject에 구현되어 있으며,
         QObject를 상속받는 클래스라면 어디에서든 사용이 가능하다.

     - connect(sender, SIGNAL(signal), receiver, SLOT(slot));
       > sender와 receiver는 QObject에 대한 포인터이며
         signal과 slot은 매개변수의 이름이 생략된 함수 시그니처이다.
       > SIGNAL()과 SLOT() 매크로는 자신의 인자를 문자열로 변환하는 역할을 담당한다.

     - 기본적으로 시그널과 슬롯은 아래와 같이 연결될 수 있다.

       1. 하나의 시그널이 여러개의 슬롯에 연결될 수 있다.
        ex) connect(sender, SIGNAL(signal), receiver, SLOT(slot1));
        connect(sender, SIGNAL(signal), receiver, SLOT(slot2));

       2. 여러개의 시그널이 하나의 슬롯에 연결될 수 있다.
        ex) connect(sender, SIGNAL(signal1), receiver, SLOT(slot));
        connect(sender, SIGNAL(signal2), receiver, SLOT(slot));

       3. 시그널은 또 다른 시그널에 연결될 수 있다.
        ex) connect(sender, SIGNAL(signal), receiver, SIGNAL(signal));

       4. 기존에 설정된 연결은 해제될 수있다.
          (Qt는 객체가 삭제될 때 그 객체가 갖고 있던 모든 연결을 해제한다.)
        ex) disconnect(sender, SIGNAL(signal), receiver, SLOT(slot));

     - 또한, 시그널과 슬롯이 정상적으로 연결되려면 매개변수 타입과 순서가 동일해야 한다.
       ex) connect(sender, SIGNAL(signal_test(int, const QString &)), receiver, SLOT(slot_test(int, const QString &));

       하지만 시그널이 슬롯보다 더 많은 매개변수를 갖는 경우에는 예외적으로 연결이 가능하며,
       시그널이 갖는 추가적인 매개변수는 무시된다.
       ex) connect(sender, SIGNAL(signal_test(int, const QString &)), receiver, SLOT(slot_test(int));

     */



    // - Format메뉴 -> align메뉴에 alignCenter추가
    alignMenu->addAction(alignCenter);
    alignMenu->addAction(alignLeft);
    alignMenu->addAction(alignRight);
    alignMenu->addAction(alignJusify);


    /*
     * QDockWidget 위젯
     - 다른 위젯들을 담을 수 있는 독 위젯

     */

    QLabel *label = new QLabel("Dock Widget",this);
    QDockWidget *dock = new QDockWidget("Dock Widget", this);
    // 독의 위치는 좌, 우만 가능!!
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    dock->setWidget(label);

    windowMenu->addAction(dock->toggleViewAction());

#if MODE == 2
    windowMenu->addSeparator();

    QMenu *windowsAlignMenu = windowMenu->addMenu("Windows &Align");
    windowMenu->addSeparator();
    QAction *cascadeAlign = makeAction(":/Icon/cascadealign.png","&Cascade","Ctrl+A+C","windows align - cascade",this,SLOT(slotWindow()));
    QAction *tileAlign = makeAction(":/Icon/tilealign.png","&Tile","Ctrl+A+T","windows align - tile",this,SLOT(slotWindow()));
    windowsAlignMenu->addAction(cascadeAlign);
    windowsAlignMenu->addAction(tileAlign);

    QAction *nextWindows = makeAction(":/Icon/nextwindow.png","&Next","Ctrl+Shift+N","next window",this,SLOT(slotWindow()));
    QAction *prevWindows = makeAction(":/Icon/prevwindow.png","&Prev","Ctrl+Shift+P","previous window",this,SLOT(slotWindow()));
    windowMenu->addAction(nextWindows);
    windowMenu->addAction(prevWindows);

    QAction *closeOne = makeAction(":/Icon/closeone.png","&Close","Ctrl+Alt+C","close activated window",this,SLOT(slotWindow()));
    QAction *closeAll = makeAction(":/Icon/closeall.png","Close &All","Ctrl+Alt+Q","close all windows",this,SLOT(slotWindow()));
    windowMenu->addAction(closeOne);
    windowMenu->addAction(closeAll);


    windowsToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    windowsToolBar->addAction(cascadeAlign);
    windowsToolBar->addAction(tileAlign);
    windowsToolBar->addSeparator();
    windowsToolBar->addAction(prevWindows);
    windowsToolBar->addAction(nextWindows);
    windowsToolBar->addSeparator();
    windowsToolBar->addAction(closeOne);
    windowsToolBar->addAction(closeAll);
    windowsToolBar->addSeparator();

    windowMenu->addSeparator();
    windowMenu->addAction(windowsToolBar->toggleViewAction());
#endif


   /*
    * 리소스 시스템(Resource System)
    - 실시간으로 애플리케이션에 의하여 다른 자원들에 접근할 수 있도록 데이터 파일이 실행 파일 내에 저장
    - 장점
      > 애플리케이션의 배포와 설치 문제를 간소화
      > 리소스 파일이 제대로 배포되지 않아서 생기는 애플리케이션의 문제를 해소
      > 메모리 공간을 절약
    - 프로젝트 파일(.pro)에 .qrc 파일 지정
      > Files and Classes > Qt > Qt Resource File
      > RESOURCES = application.qrc

    * Qt의 리소스 시스템
    - XML 형식의 .qrc(Qt Resource Collection) 파일 내에 나열
         <RCC>
          <qresource prefix="/">
           <file>icon/new.png</file>
       <file>icon/open.png</file>
              ...
       </qresource>
          </RCC>
    - 리소스 경로로 해당 파일들이 표시
    - Qt Creator 를 이용하면 쉽게 관리 -> Resource Editor에서 Prefix를 추가하고 파일을 추가
    - rcc 유틸리티에 의해 바이너리 데이터로 변환
    - 소스코드 내에서는 파일 시스템과의 구분을 위해 ':'을 사용
      ex) QAction* saveAct = new QAction(QIcon(":/icon/save.png"),"&Save",this);


    * ★이미지 파일들을 내 소스코드와 함께 보관해보자!!★
      - 원하는위치에 아이콘이미지 폴더 생성
      -> 프로젝트 이름 클릭 -> Add New
      -> Qt선택 -> Qt Resource File 선택 ->
      -> 이름설정 (ex.application.qrc)
      -> 프로젝트에 Resources와 application.qrc 생성됨
      -> application.qrc 선택후 add->prefix
      -> prefix 설정 후 다시 application.qrc 우클릭
      -> add Existing files 후 아이콘선택호 확인
      -> 소스코드에서는 ":/icon/image.png" 로 사용한다!!

     (Build 디렉토리의 debug폴더에서 qrc_application.cpp 파일을 보면
       이미지 아이콘들이 헥사코드로 잘 변경된것을 확인할 수 있다.)
    */

    QAction *about = makeAction(":/Icon/about.png","&About","","about this app", this, SLOT(slotAbout()));
    QAction *aboutQt = makeAction(":/Icon/aboutqt.png","About&Qt","","about qt", qApp,SLOT(aboutQt()));
    helpMenu->addAction(about);
    helpMenu->addAction(aboutQt);


    /*
     * QColorDialog 클래스

     - 사용자가 색상을 선택할 수 있도록 관련 다이얼로그를 제공
     > 다이얼로그의 왼쪽에는 기본 색상 팔레트가 위치
     > 오른쪽에는 색상 선택을 보다 정밀하게 하기 위핸 색상 선택 창이 위치

     - 생상 다이얼로그를 사용하기 위해서는 getColor()메소드를 이용(Static Method)
       Ex) QColor color = QColorDialog::getColor(Qt::green,this);
    */



    QAction *colorDialog = makeAction(":/Icon/color.png","&Color","","color dialog",this,SLOT(slotSetColor()));
    formatMenu->addAction(colorDialog);
    formatToolBar->addAction(colorDialog);
    formatToolBar->addSeparator();
    /*
     * QFontDialog 클래스

     - 폰트를 선택할 수 있도록 관련 다이얼로그를 제공
     > 폰트의 이름과 스타일 그리고 크기를 선택하여 설정
     > 선택한 폰트에 대한 모양은 다이얼로그의 샘플(Sample)창을 통해서 미리 확인 가능

     - 폰트 다이얼로그를 사용하기 위해서는 getFont()메소드를 이용(Static Method)
     > QFontDialog의 getFont()메소드는 아래의 Cancel 버튼을 누르는 것을 확인하기 위해
       bool타입의 변수를 하나 더 사용한다.
     */

    QAction *fontDialog = makeAction(":/Icon/font.png","&Font","","font dialog",this,SLOT(slotSetFont()));
    formatMenu->addAction(fontDialog);
    formatToolBar->addAction(fontDialog);
    formatToolBar->addSeparator();
    formatMenu->addSeparator();
    formatMenu->addAction(formatToolBar->toggleViewAction());
}

QtEditor::~QtEditor()
{

}



// ★★
// qteditor.h를 보면
// QAction *makeAction(...) 로 선언하고,
// qteditor.cpp에서는
// QAction *QtEditor::makeAction(...) 로 정의하는 차이점에 주의하자!!!!
//
QAction *QtEditor::makeAction(QString icon, QString name, \
                              QString shortCut, QString toolTip,\
                              QObject *recv, const char *slot)
{
    QAction *act = new QAction(name, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act,SIGNAL(triggered(bool)),recv,slot);
    return act;
}
void QtEditor::newFile()
{
    // 슬롯 호출시 QTextEdit 위젯의 인스턴스를 QMdiArea 위젯에 추가하고 화면에 표시
    //
    qDebug("Make New File");

#if MODE == 2
    QTextEdit *newtextedit = new QTextEdit;

    /*
     * 커서 이동시 관련 위젯의 폰트를 관리하기위해 커서 이동과 관련된 슬롯을 추가해준다.
     */

    connect(newtextedit,SIGNAL(cursorPositionChanged()),SLOT(slotFontWidget()));

    char temp1[20] = "Note";
    char temp2[10];
    itoa(++count,temp2,10);
    strcat(temp1,temp2);

    QLabel *editname = new QLabel(temp1, this);
    fileName = tr(temp1);
    newtextedit->setWindowTitle(temp1);
    mdiArea->addSubWindow(newtextedit);
    newtextedit->show();
#endif

}
    /*
     * 다이얼로그 입력 모드

     - 위젯(Widget) vs 다이얼로그(Dialog)
     > 다이얼로그는 사용자와의 인터렉션(Interaction)을 위해 사용
     > 다이얼로그는 하나의 윈도우로 사용되는데 입력 모드가 있다.

     - 모달(Modal)
     : 같은 응용 프로그램의 다른 윈도우의 입력을 블록(Block)시키는 다이얼로그 (QDialog::open() 메소드)
     > 다른 윈도우를 사용하기 위해서는 다이얼로그를 당아야 한다.
     - 모들리스(Modeless / Non-Modal)
     : 다른 윈도우와 '독립적'으로 동작하는 다이얼로그 (QWidget::show() 메소드)
     > 다른 다이얼로그가 떠 있는 상태에서도 다른 다이얼로그의 조작 가능

     - 세미 모달(Semi-modal)
     : 호출한 윈도우에 제어권을 즉시 돌려주는 다이얼로그 (QDialog::exec() 메소드)
     > 사용자의 입장에서는 모달(modal) 다이얼로그처럼 동작 -> 블록
     > 응용 프로그램 입장에서는 현재 다이얼로그에서 계속 처리 가능 -> 독립적


     * QDialog 클래스

     - 다이얼로그를 위한 추상 클래스
     > 모달(Modal), 모들리스(Modeless), 세미 모달(Semi-modal)
       ex) void QDialog::setModal(bool modal)메소드
     > 결과 값 획득 : 실행 완료 후 다이얼로그마다 해당 값을 얻을 수 있다.

     - 모달(Modal) / 세미모달(Semi-modal)
     > 다른 다이얼로그(윈도우)로 가는 이벤트(event)를 블록(block)
     > QDialog::open() / QDialog::exec() 메소드를 사용하여, 이벤트 루프를 처리
     > 반환값(Return) : OK(accept) 또는 CANCEL(reject) 결과값

     - 모들리스(Modeless/ NonModal)
     > 다른 다이얼로그(윈도우)와 동시에 사용
     > QDialog(QWidget)의 show()메소드를 사용하여 이벤트 루프 처리 시작
     > 반환값 : 모들리스(Modeless)인 경우는 종료시점을 모르기 때문에 시그널/슬롯을 연결해서 처리


     * 사용자 정의 다이얼로그

     - QDialog 클래스를 상속받아서 사용
     > 생성자에서는 먼저 위젯의 속성(크기 등)을 설정하고 다이얼로그에 보여줄 위젯들을 선택해서 적절히 배치
     > 사용자 정의 위젯과 만드는 방법은 비슷

     - Qt Creator를 사용하면 편리
     > 프로젝트를 만들 때 기본 위젯(Base Widget)으로 QDialog클래스를 선택
     > 폼 디자이너/ Qt 디자이너를 이용하면 쉽게 사용자 정의 다이얼로그 생성


     * 표준 다이얼로그

     - 응용 프로그램에서 사용자와의 대화를 위해서 사용

     - 표준 다이얼로그는 QDialog 클래스를 상속
     > QFileDialog : 파일 선택 다이얼로그
     > QColorDialog : 색상 선택 다이얼로그
     > QFontDialog : 폰트 선택 다이얼로그
     > QMessageBox : 간단한 정보를 출력하여 보여줄 때 사용
        - "Yes", "No"와 같은 질의를 위한 인터렉션을 위해서도 사용
     > QPrintDialog : 프린터의 설정과 관련된 다이얼로그
     > QPageSetupDialog : 프린터의 페이지 설정 다이얼로그
     > QInputDialog : 사용자로부터 간단한 입력을 받을 때 사용
     > QProgressDialog : 진행 상태 표시 다이얼로그
     > QErrorMessage : 에러 메시지 출력 다이얼로그


     * QFileDialog 클래스
     - 헤더파일 : #include <QFileDialog>
                #include <QDebug>  <- qDebug로 메시지 출력을 위하여
     - 파일을 선택할 수 있도록 관련 다이얼로그를 제공
     > 하나 또는 복수의 파일을 선택 가능
     > 디렉터리 간에 이동, 디렉터리의 생성이나 파일명의 수정이 가능
     > 열기(Open)과 저장(Save)의 다이얼로그 제공

     * QFile 클래스

     - 파일의 입출력 용도로 QFile 클래스를 제공
     > 파일에 텍스트나 바이너리 형식의 데이터를 입출력할 때 사용

     - 파일의 데이터를 처리할 때는 스트림을 이용하면 보다 편리
     > QTextStream나 QDataStream 클래스의 직렬화 이용

     - 사용되는 파일명에 대한 디렉토리 경로(Path)
     > 파일명 : 디렉토리 경로가 포함되지 않는다.
     > 상대 경로 : 현재 파일이 있는 디렉토리를 기준으로 한 상대적인 디렉토리 경로
     > 절대 경로 : 루트 디렉토리(/)로부터 현재 디렉토리까지의 절대적인 디렉토리 경로

     * 파일 처리 에러
     - QFile::error() 메소드 : 현재 발생한 에러를 검사한다.

         0 -> QFile::NoError		- 아무런 오류도 발생하지 않았다.
         1 -> QFile::ReadError		- 읽는 도중 오류 발생
         2 -> QFile::WriteError		- 쓰는 도중 오류 발생
         3 -> QFile::FatalError		- 치명적인 오류 발생
         4 -> QFile::ResourceError	- 자원 오류 발생
         5 -> QFile::OpenError		- 파일을 열 수 없음
         6 -> QFile::AbortError		- 동작 중단
         7 -> QFile::TimeOutError	- 시간 오류 발생
         8 -> QFile::UnspecifiedError	- 정의되지 않은 오류 발생
         9 -> QFile::RemoveError	- 파일 삭제시에 오류 발생
        10 -> QFile::RenameError	- 파일 이름 변경시에 오류 발생
        11 -> QFile::PositionError	- 파일 내에서 위치 변경 불가능
        12 -> QFile::ResizeError	- 파일 크기 변경 오류
        13 -> QFile::PermissionsError	- 파일의 접근 오류 발생
        14 -> QFile::CopyError		- 파일 복사시 오류 발생

    */
void QtEditor::openFile()
{
    qDebug("Open File");
    QString filename = QFileDialog::getOpenFileName(this, "Select file to open",
                                                    ".","Text File(*.txt *text *.html * htm *.c *.cpp *.h)");
    qDebug() << filename;

    QFileInfo *fileinfo = new QFileInfo(filename);
    if(fileinfo->isReadable())
    {
        QByteArray msg;
        QFile *file = new QFile(filename);
        file->open(QIODevice::ReadOnly);
        msg = file->readAll();
        file->close();
        delete file;

        QTextEdit* textedit = new QTextEdit(this);
        textedit->setWindowTitle(filename);
        textedit->setHtml(msg);
        mdiArea->addSubWindow(textedit);
        textedit->show();
    }
    else
    {
        QMessageBox::warning(this, "Error","Can't Read this File",QMessageBox::Ok,NULL);
    }
}
void QtEditor::saveFile()
{
    qDebug("Save File");
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QString filename = textedit->windowTitle();

    if(!filename.length())
    {
        filename = QFileDialog::getSaveFileName(this,
                                                "Select a file to Save",".",
                                                "Text File(*.txt *text *.html * htm *.c *.cpp *.h");
        textedit->setWindowTitle(filename);
    }
    else
    {
        filename = QFileDialog::getSaveFileName(this,
                                                "Select a file to Save",fileName,
                                                "Text File(*.txt *text *.html * htm *.c *.cpp *.h");

    }
    QFile *file = new QFile(filename);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QFileInfo* fileInfo = new QFileInfo(filename);
    if(fileInfo->isWritable())  // if(file->error() != QFile::OpenError)
    {
        QByteArray msg;
        msg.append(textedit->toHtml()); // QString을 QByteArray로 변환
        file->write(msg);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok,NULL);
    }
    file->close();

    delete file;

}
void QtEditor::saveasFile()
{
    qDebug("Save File");
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QString filename = textedit->windowTitle();

    filename = QFileDialog::getSaveFileName(this,
                                            "Select a file to Save",".",
                                            "Text File(*.txt *text *.html * htm *.c *.cpp *.h");

    QFile *file = new QFile(filename);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QFileInfo* fileInfo = new QFileInfo(filename);
    if(fileInfo->isWritable())  // if(file->error() != QFile::OpenError)
    {
        QByteArray msg;
        msg.append(textedit->toHtml()); // QString을 QByteArray로 변환
        file->write(msg);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok,NULL);
    }
    file->close();
    delete file;
}
    /*
     * QPrinter 클래스

     - 프린터로 출력하기 위한 페인트 디바이스
     > MS Windows나 Mac OS X : 운영체제에서 기본으로 제공하는 프린터 장치를 사용
     > UNIX의 X11 : 포스트스크립트(Postscript)를 생성하여 lpr이나 lp명령어를 사용

     - Qpainter에서 QWidget 클래스나 QPixmap 클래스를 사용하는 것과 같은 방법으로 사용
     > 차이점 : QPrinter 클래스는 페이지 단위로 처리
     > 프린터 다이얼로그로 설정할 수 있는 파라미터(Parameter)들을 제공

     - QPrinter클래스에 QPainter를 사용하면 모니터에 출력하는것과 같이 바로 출력한다.
     > 다이얼로그를 이용해 사용자에게 프린트 할 것인지 물어봐야 한다.

     - Qt5에서는 QtCore에서 분리 : printsupport모듈
       ( 좌측탭의 qtEditor.pro 선택 후, 9번째 줄을
         greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport 로 바꾼다.)


     * QPrintDialog 클래스

     - Qt에서 프린터를 사용하기 위해서는 QPrinter클래스를 사용
     > 프린트 설정을 위해 QPrintDialog나 QPageSetupDialog클래스를 사용

     - 프린터 설정에 사용하는 다이얼로그를 제공
     > 인쇄 설정과 프린터 설정을 모두 지원

     - 프린트 다이얼로그의 사용
       Ex) QPrintDialog printDialog(printer, this);
           if(printDialog.exec() == QDialog::Accepted)
            QPrinter *printer = new QPrinter();


     * QPageSetupDialog 클래스

     - 프린터의 페이지 설정과 관련된 다이얼로그를 제공
     > 종이의 크기와 여백 등을 설정
     > MS Windows와 Mac OS X에서는 운영체제에서 기본적으로 제공하는 다이얼로그르 창을 이용
       Ex) QPrinter *printer = new QPrinter();
           QPageSetupDialog *pageSetupDIG = new QPageSetupDialog(printer,this);
           pageSetupDIG->exec();
     */
void QtEditor::printFile()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec() == QDialog::Accepted)
    {
        QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->print(&printer);

    }
}


void QtEditor::alignText()
{
#if MODE == 2
    textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
#endif
    QAction *action = (QAction*)sender();
    if(action->text() == "&Center") textedit->setAlignment(Qt::AlignCenter);
    if(action->text() == "&Left") textedit->setAlignment(Qt::AlignLeft);
    if(action->text() == "&Right") textedit->setAlignment(Qt::AlignRight);
    if(action->text() == "&Justify") textedit->setAlignment(Qt::AlignJustify);
}

void QtEditor::slotEdit()
{
#if MODE == 2
    textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
#endif
    QAction *action = (QAction*)sender();
    if(action->text() == "&Undo") textedit->undo();
    if(action->text() == "&Redo") textedit->redo();
    if(action->text() == "&Copy") textedit->copy();
    if(action->text() == "Cu&t") textedit->cut();
    if(action->text() == "&Paste") textedit->paste();
    if(action->text() == "Zoom &In") textedit->zoomIn();
    if(action->text() == "Zoom &Out") textedit->zoomOut();

}

void QtEditor::slotWindow()
{
#if MODE == 2

    QAction *action = (QAction*)sender();

    if(action->text() == "&Cascade") mdiArea->cascadeSubWindows();
    if(action->text() == "&Tile") mdiArea->tileSubWindows();
    if(action->text() == "&Next") mdiArea->activateNextSubWindow();
    if(action->text() == "&Prev") mdiArea->activatePreviousSubWindow();
    if(action->text() == "&Close") mdiArea->closeActiveSubWindow();
    if(action->text() == "Close &All") mdiArea->closeAllSubWindows();

#endif

}

    /*
     * QMessageBox 클래스

     - 가장 많이 사용되는 다이얼로그
     > 사용자에게 시스템 오류나 정보 등의 정보를 보여줄 때 사용

     - 네 종류의 메시지 박스를 제공 : 아이콘으로 구분
     > 4 종류의 스태틱 메소드 : question, information, warning, critical
        질문(Question,값:4)    : 사용자에게 Ok나 No의 정보를 입력받기 위한 다이얼로그
        정보(Information,값:1) : 사용자에게 정보를 제공하기 위한 다이얼로그
        경고(Warning,값:2)     : 사용자에게 경고의 메시지를 전달하기 위한 다이얼로그
        위기(Critical,값:3)    : 사용자에게 치명적인 수준의 경고 메시지를 전달하기 위한 다이얼로그

     - 사용법 : QMessageBox::question(this, "Windows Title", "Message",
                    QMessageBox::Yes | QMessageBox::No | QMessageBox);
         (주의) 윈도우 매니저에 따라 순서가 바뀔 수 있다.

        QMessageBox::Ok     - Ok버튼, 값:1
        QMessageBox::Cancel - Cancel버튼, 값:2
        QMessageBox::Yes    - Yes버튼, 값:3
        QMessageBox::No     - No버튼, 값:4
        QMessageBox::Abort  - Abort버튼, 값:5
        QMessageBox::Retry  - Retry버튼, 값:6
        QMessageBox::Ignore - Ignore버튼, 값:7
        QMessageBox::YesAll - Yes to all버튼, 값:8
        QMessageBox::NoAll  - No to all버튼, 값:9

     - aboutQt() : QApplication과 QMessageBox클래스에서 슬롯으로 제공
       > QApplication 클래스 이용하여 qApp과 aboutQt()를 인자로 넣는게 편하다
     */
void QtEditor::slotAbout()
{

    QMessageBox *myBox = new QMessageBox;
    QPushButton *agreebutton = myBox->addButton(tr("Agree"),QMessageBox::YesRole);
    QPushButton *disagreebutton = myBox->addButton(tr("Disagree"),QMessageBox::NoRole);


    myBox->resize(1000,300);
    myBox->setIcon(QMessageBox::Information);
    myBox->setWindowTitle("About This Program...");
    myBox->setText("My name is Joohongkeem !!");
    myBox->setInformativeText("This program is made by me !!\n"
                              "I want to get a job in Samsung !\n"
                              "Please, pray for me. HAHAHA \n");
    myBox->exec();


    if(myBox->clickedButton() == agreebutton)
    {
        QMessageBox *agreeBox = new QMessageBox;
        agreeBox->setText("Thank you!!");
        agreeBox->setIconPixmap(QPixmap(":/Icon/smile.png"));
        agreeBox->setWindowTitle("My Response");
        agreeBox->exec();

    }
    else if(myBox->clickedButton() == disagreebutton)
    {
        QMessageBox *disagreeBox = new QMessageBox;
        disagreeBox->setIconPixmap(QPixmap(":/Icon/angry.png"));
        disagreeBox->setWindowTitle("My Response");
        disagreeBox->setText("Fuck You!!");
        disagreeBox->exec();
    }

}
void QtEditor::slotFont(QFont font)
{
#if MODE == 2

    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    textedit->setCurrentFont(font);

#endif
}
void QtEditor::slotFontSize(qreal size)
{
#if MODE == 2

    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = textedit->currentFont();
    font.setPointSizeF(size);
    textedit->setCurrentFont(font);

#endif
}

void QtEditor::slotFontWidget()
{
#if MODE == 2

    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = textedit->currentFont();

    fontComboBox->setCurrentFont(font);
    sizeSpinBox->setValue(font.pointSize());


#endif
}

void QtEditor::slotSetColor()
{
#if MODE == 2
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QColor color = QColorDialog::getColor(textedit->textColor(),this);
    textedit->setTextColor(color);
#endif
}

void QtEditor::slotSetFont()
{
#if MODE == 2
    bool ok;
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = QFontDialog::getFont(&ok,textedit->currentFont(),this);
    if(ok) textedit->setCurrentFont(font);
#endif
}
