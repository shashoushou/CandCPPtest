#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("main windows");
    this->setMaximumSize(300,300);
    this->setMinimumSize(300,300);
    this->move(200,200);
    this->setStyleSheet("background:gray");
    this->setWindowFlag(Qt::WindowCloseButtonHint);

    btClose = new QPushButton(this);
    btClose->setText("close");

    button = new QPushButton(this);
    button->setGeometry(QRect(50,50,100,25));
    button->setText("open w2");
    connect(button, SIGNAL(clicked()), this, SLOT(showMainWindow2()));
    connect(btClose, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::mouseReleaseEven(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::showMainWindow2()
{
    w2.show();
}

