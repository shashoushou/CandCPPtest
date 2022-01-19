#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit = new QLineEdit(this);
    edit->setGeometry(QRect(50,50,200,26));
    edit->setText("/home/icnexus");

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("Create");
    connect(button, SIGNAL(clicked()), this, SLOT(createFolder()));

    newFilename = new QLineEdit(this);
    newFilename->setGeometry(QRect(50,100, 200,25));
    newFilename->setText("/home/icnexus/test.txt");

    newFileContent = new QLineEdit(this);
    newFileContent->setGeometry(QRect(50,150,200,25));
    newFileContent->setText("write content to file");

    btn2 = new QPushButton(this);
    btn2->setGeometry(QRect(270,100,180,25));
    btn2->setText("create file");
    connect(btn2, SIGNAL(clicked()), this, SLOT(createFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFolder()
{
    QDir *folder = new QDir;
    bool exist = folder->exists(edit->text());
    if(exist) {
        QMessageBox::warning(this, tr("create folder"), tr("folder exist!"));
    } else {
        bool ok = folder->mkdir(edit->text());
        if(ok) {
            QMessageBox::warning(this, tr("create folder"), tr("Finished!"));
        } else {
            QMessageBox::warning(this, tr("create folder"), tr("Failed!"));
        }
    }

}

void MainWindow::createFile()
{
    QFile file(newFilename->text());
    if(file.exists()){
        QMessageBox::warning(this, "create file", "file exist!");
    } else {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QByteArray str = newFileContent->text().toUtf8();
        file.write(str);
        QMessageBox::warning(this, "create file", "finished!");
    }
    file.close();
}

