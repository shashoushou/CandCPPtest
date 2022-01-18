#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = new QLineEdit(this);
    filename->setGeometry(QRect(50,50,230,25));

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("Browser");
    connect(button, SIGNAL(clicked()), this, SLOT(showFiles()));



    btn = new QPushButton(this);
    btn->setGeometry(QRect(200, 100, 180, 25));
    btn->setText("select Color:");
    connect(btn, SIGNAL(clicked()), this, SLOT(editText()));

    label = new QLabel(this);
    label->setGeometry(QRect(50, 100, 100, 25));
    label->setText("Font Color");



    bar = new QProgressBar(this);
    bar ->setGeometry(QRect(50, 150, 200, 20));
    bar->setRange(0, 100000-1);
    bar->setValue(0);
    btn2 = new QPushButton(this);
    btn2->setGeometry(QRect(50, 200, 80, 25));
    btn2->setText("Start");
    connect(btn2, SIGNAL(clicked()), this, SLOT(startBar()));


    label2 = new QLabel(this);
    label2->setGeometry(QRect(400, 50, 200, 25));

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTime()));

    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFiles()
{
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "textfile(*.txt)::C file(*.cpp);;All file(*.*)");
    filename->setText(str.toUtf8());
}

void MainWindow::editText()
{
    QColorDialog::setCustomColor(0, QRgb(0x0000FF));
    QColor color = QColorDialog::getColor(QColor(0, 255, 0));
    QPalette p = palette();
    p.setColor(QPalette::WindowText, QColor(color));
    label->setPalette(p);
}

void MainWindow::startBar()
{
    for(int i = 0 ; i <100000; i++){
        bar->setValue(i);
    }
    btn2->setText("stop");
}

void MainWindow::timerTime()
{
    QDateTime sysTime = QDateTime::currentDateTime();
    label2->setText(sysTime.toString());
}


