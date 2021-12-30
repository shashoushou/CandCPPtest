#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);

    label->setText("Hello Qt");
    //xyhw
    label->setGeometry(QRect(50,50,200,25));

}

MainWindow::~MainWindow()
{
    delete ui;
}

