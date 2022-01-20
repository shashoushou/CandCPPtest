#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Write INI
    filePathL = new QLabel;
    filePathL->setText("ini file path");
    filePath = new QLineEdit;
    filePath->setText("/home/icnexus/001.ini");

    nodeL = new QLabel;
    nodeL->setText("node");
    nodeEdit = new QLineEdit;
    nodeEdit->setText("Node name");

    keyL = new QLabel;
    keyL->setText("Key");
    keyEdit = new QLineEdit;
    keyEdit->setText("ip");

    valL = new QLabel;
    valL->setText("Value");
    valEdit = new QLineEdit;
    valEdit->setText("192.168.1.1");

    writeBtn = new QPushButton;
    writeBtn->setText("write setting");
    connect(writeBtn, SIGNAL(clicked()), this, SLOT(writeFile()));

    gLayout = new QGridLayout;
    gLayout->addWidget(filePathL, 0, 0, 1, 1);
    gLayout->addWidget(filePath, 0, 1, 1, 4);
    gLayout->addWidget(nodeL, 1, 0, 1, 1);
    gLayout->addWidget(nodeEdit, 1, 1, 1, 1);
    gLayout->addWidget(keyL, 2, 0, 1, 1);
    gLayout->addWidget(keyEdit, 2, 1, 1, 1);
    gLayout->addWidget(valL, 2, 3, 1, 1);
    gLayout->addWidget(valEdit, 2, 4, 1, 1);
    gLayout->addWidget(writeBtn, 3, 4, 1, 1);

    widget = new QWidget();
    widget->setLayout(gLayout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeFile()
{
    writeIni = new QSettings(filePath->text(), QSettings::IniFormat);
    writeIni->setValue(nodeEdit->text()+"/"+keyEdit->text(),valEdit->text());
    delete writeIni;
}

