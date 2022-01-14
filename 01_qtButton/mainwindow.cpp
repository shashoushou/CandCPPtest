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
    label->setGeometry(QRect(100,150,200,30));
    label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic");

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(100,200,200,25));
    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color: bluered;");
    lineEdit->setMaxLength(12);
    lineEdit->setEchoMode(QLineEdit::Password);

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(QRect(100,250,200,150));
    textEdit->setText("Line one<br/>Line two");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtButton()
{
    button->setText("Button B");
}

