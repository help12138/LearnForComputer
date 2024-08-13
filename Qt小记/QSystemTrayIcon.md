## QSystemTrayIcon函数
* 主要作用
<big>给程序创建一个右下角的图标</big>, 可以配合着CloseEvent函数设置不退出功能, 函数使用时要配合QIcon给程序设置一个图标,(如果不用QIcon, 很难直观地看到设置成功了没有)

程序示例
`mainwindow.h`
```C++
#include <QMainWindow>
#include<QSystemTrayIcon>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSystemTrayIcon *SysIcon;
    QAction *max;
    QAction *min;
    QAction *restor;
    QAction *quit;
    QMenu *menu;
private:
    //重载关闭功能
    void closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);


```
`mainwindow.cpp`
```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu = new QMenu(this);
    QIcon icon(":/editor.ico");
    SysIcon = new QSystemTrayIcon(icon,this);
    // SysIcon->setIcon(icon);
    SysIcon->setToolTip("Qt托盘");
    // 设置目录功能
    min = new QAction("托盘最小化", this);
    connect(min, &QAction::triggered, this, &MainWindow::hide);
    max = new QAction("窗口最大化",this);
    connect(max,&QAction::triggered,this,&MainWindow::showMaximized);
    restor = new QAction("恢复原来的样子",this);
    connect(restor,&QAction::triggered,this,&MainWindow::showNormal);
    quit = new QAction("退出",this);
    //    connect(quit,&QAction::triggered,this,&MainWindow::close);
     // 要退出的是整个应用程序, 所以要用Application的槽函数
    connect(quit,&QAction::triggered,qApp,&QApplication::quit); 
    connect(SysIcon, &QSystemTrayIcon::activated, this, &MainWindow::on_activatedSysTrayIcon);
    // 将目录功能显示到菜单栏上
    menu->addAction(min);
    menu->addAction(max);
    menu->addAction(restor);
    menu->addSeparator();
    menu->addAction(quit);
    SysIcon->setContextMenu(menu);
    SysIcon->show();
    close();

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event){
    // 重构closeEvent函数
    if(SysIcon->isVisible()){
        this->hide();
        SysIcon->showMessage("Qt托盘", "this is a little icon");
        event->ignore();
    }else{
        event->accept();
    }
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason){
    switch (reason){
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }

}

```
以上就是QSystemTrayIcon函数的应用主要功能