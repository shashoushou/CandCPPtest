#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include <QFile>
#include <QXmlStreamWriter>

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    explainL = new QLabel(this);
    explainL->setText("test");
    explainL->setGeometry(QRect(50,50,300,100));

    createBtn  = new QPushButton(this);
    createBtn->setText("create xml");
    createBtn->setGeometry(QRect(50,180, 100,25));
    connect(createBtn, SIGNAL(clicked()), this, SLOT(createFile()));

}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::createFile()
{
   QString xmlPath= "/home/icnexus/002.xml";
   QFile file(xmlPath);
   if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
       QXmlStreamWriter stream(&file);
       stream.setAutoFormatting(true);
       stream.writeStartDocument();
       stream.writeStartElement("Root");
       stream.writeAttribute("href", "http://www.google.com");
       stream.writeTextElement("title", "google");
       stream.writeEndElement();
       stream.writeEndDocument();
       file.close();
   }
}
