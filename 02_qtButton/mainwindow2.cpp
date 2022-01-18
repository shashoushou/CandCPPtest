#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    hboxLayout = new QHBoxLayout();
    button1 = new QPushButton("btn 1");
    button2 = new QPushButton("btn 2");
    button3 = new QPushButton("btn 3");
    hboxLayout->addWidget(button1);
    hboxLayout->addWidget(button2);
    hboxLayout->addWidget(button3);
    hboxLayout->setSpacing(60);
    widget = new QWidget();
    widget->setLayout(hboxLayout);
    this->setCentralWidget(widget);

    createMenu();
    if(!QSystemTrayIcon::isSystemTrayAvailable())
    {
        return;
    }
    myTrayIcon = new QSystemTrayIcon(this);
    myTrayIcon->setIcon(QIcon(":/new/prefix/ico"));
    myTrayIcon->setToolTip("Qt Tray Icon");
    myTrayIcon->showMessage("Tray", "Tray managent", QSystemTrayIcon::Information, 10000);
    myTrayIcon->setContextMenu(myMenu);
    myTrayIcon->show();
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::createMenu()
{
    restoreWinAction = new QAction("Restore(&R)", this);
    quitAction = new QAction("Exit(&Q)", this);

    connect(restoreWinAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction,SIGNAL(triggered()), qApp, SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();
    myMenu->addAction(quitAction);

}

void MainWindow2::showNormal()
{
    this->show();
}

void QWidget::changeEvent(QEvent *e)
{
    if((e->type() == QEvent::WindowStateChange) && this->isMinimized())
    {
        this->hide();
    }
}
