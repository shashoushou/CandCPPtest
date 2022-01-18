#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);


    gridLayout= new QGridLayout;
    button4 = new QPushButton("btn 4");
    button5 = new QPushButton("btn 5");
    button6 = new QPushButton("btn 6");
    gridLayout->addWidget(button4);
    gridLayout->addWidget(button5);
    gridLayout->addWidget(button6);
    gridLayout->addWidget(button4, 0, 0, 1, 1);
    gridLayout->addWidget(button5, 0, 1, 1, 1);
    gridLayout->addWidget(button6, 1, 0, 1, 1);
    widget2 = new QWidget();
    widget2->setLayout(gridLayout);
    this->setCentralWidget(widget2);

}

MainWindow3::~MainWindow3()
{
    delete ui;
}
