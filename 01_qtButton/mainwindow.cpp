#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button = new QPushButton(this);
    button->setGeometry(QRect(100,100,100,25));
    connect(button, SIGNAL(released()), this, SLOT(txtButton()));

    label = new QLabel("This is Qt label", this);
    label->setGeometry(QRect(150,150,200,30));
    label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtButton()
{
    button->setText("Button B");
}

