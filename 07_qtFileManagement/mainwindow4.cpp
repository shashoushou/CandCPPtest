#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include <QFile>
#include <QXmlStreamReader>

MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);
    resultL = new QLabel(this);
    resultL->setGeometry(QRect(50,50,300,100));

    readBtn = new QPushButton(this);
    readBtn->setText("Read title node");
    readBtn->setGeometry(QRect(50,180,150,25));
    connect(readBtn, SIGNAL(clicked()), this, SLOT(readNode()));

}

MainWindow4::~MainWindow4()
{
    delete ui;
}

void MainWindow4::readNode()
{
    QString xmlPath = "/home/icnexus/001.xml";
    QFile file(xmlPath);
    QString str;
    if(file.exists()) {
        if(file.open(QIODevice::ReadOnly|QIODevice::Text)) {
            QXmlStreamReader xmlRead(&file);
            while(!xmlRead.atEnd()) {
                xmlRead.readNext();
                if(xmlRead.isStartElement()){
                    if(xmlRead.name() == "title") {
                        str = xmlRead.readElementText();
                    } else {
                        str = "node not found!";
                    }
                }
            }
            resultL->setText(str);
        } else {
            resultL->setText("open file error!");
        }
        file.close();
    } else {
        resultL->setText("file not found!");
    }

}
