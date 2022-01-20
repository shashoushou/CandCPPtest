#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    filePathL = new QLabel;
    filePathL->setText("ini file path");
    filePath = new QLineEdit;
    filePath->setText("/home/icnexus/001.ini");

    nodeL = new QLabel;
    nodeL->setText("node");
    nodeEdit = new QLineEdit;
    nodeEdit->setText("NodeName");

    keyL = new QLabel;
    keyL->setText("Key");
    keyEdit = new QLineEdit;
    keyEdit->setText("ip");

    valL = new QLabel;
    valL->setText("Value");
    valEdit = new QLineEdit;
//    valEdit->setText("192.168.1.1");

    readBtn = new QPushButton;
    readBtn->setText("Read setting");
    connect(readBtn, SIGNAL(clicked()), this, SLOT(readFile()));

    gLayout = new QGridLayout;
    gLayout->addWidget(filePathL, 0, 0, 1, 1);
    gLayout->addWidget(filePath, 0, 1, 1, 4);
    gLayout->addWidget(nodeL, 1, 0, 1, 1);
    gLayout->addWidget(nodeEdit, 1, 1, 1, 1);
    gLayout->addWidget(keyL, 2, 0, 1, 1);
    gLayout->addWidget(keyEdit, 2, 1, 1, 1);
    gLayout->addWidget(valL, 2, 3, 1, 1);
    gLayout->addWidget(valEdit, 2, 4, 1, 1);
    gLayout->addWidget(readBtn, 3, 4, 1, 1);

    widget = new QWidget();
    widget->setLayout(gLayout);
    this->setCentralWidget(widget);
}

MainWindow2::~MainWindow2()
{
    delete ui;

}

void MainWindow2::readFile()
{
    readIni = new QSettings(filePath->text(), QSettings::IniFormat);
    QString ipResult = readIni->value(nodeEdit->text()+"/"+keyEdit->text()).toString();
    valEdit->setText(ipResult);
    delete readIni;
}
