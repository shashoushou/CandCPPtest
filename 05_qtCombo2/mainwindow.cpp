#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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


