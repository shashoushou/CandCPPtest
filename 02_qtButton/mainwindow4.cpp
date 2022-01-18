#include "mainwindow4.h"
#include "ui_mainwindow4.h"

MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);
    box = new QGroupBox(this);
    box->setGeometry(QRect(30,30,340,100));
    box->setTitle("audio");
    button = new QPushButton(this);
    button->setText("button");
    vbox = new QVBoxLayout;
    vbox->addWidget(button);
    box->setLayout(vbox);
}

MainWindow4::~MainWindow4()
{
    delete ui;
}
