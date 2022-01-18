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
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
