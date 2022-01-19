#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create Dir
    edit = new QLineEdit(this);
    edit->setGeometry(QRect(50,50,200,26));
    edit->setText("/home/icnexus");

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("Create dir");
    connect(button, SIGNAL(clicked()), this, SLOT(createFolder()));

    // Create new file 
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
    
    
    // Modify file
    mEdit = new QTextEdit(this);
    mEdit->setGeometry(QRect(50,200,240,26));

    browseBt = new QPushButton(this);
    browseBt->setGeometry(QRect(300,200,100,25));
    browseBt->setText("select File");
    connect(browseBt, SIGNAL(clicked()), this, SLOT(browseFile()));

    content = new QTextEdit(this);
    content->setGeometry(QRect(50, 250, 200, 150));

    saveBt = new QPushButton(this);
    saveBt->setGeometry(QRect(300, 250, 100,25));
    saveBt->setText("Save");
    connect(saveBt, SIGNAL(clicked()), this, SLOT(saveFile()));

    // delete file
    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50, 400, 200, 25));

    broBtn = new QPushButton(this);
    broBtn->setText("browser ");
    broBtn->setGeometry(QRect(300, 400, 100, 25));
    connect(broBtn, SIGNAL(clicked()), this, SLOT(browDelFile()));

    delBtn = new QPushButton(this);
    delBtn->setText("delete");
    delBtn->setGeometry(QRect(300, 450, 100, 25));
    connect(delBtn, SIGNAL(clicked()), this, SLOT(deleteFile()));

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

void MainWindow::saveFile()
{
    QFile file(mEdit->toPlainText());
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray str = content->toPlainText().toUtf8();
    file.write(str);
    QMessageBox::warning(this, "modify docs", "finished!");
    file.close();
}

void MainWindow::browseFile()
{
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "text file(*.txt)::C file(*.cpp)::All file(*.*)");
    mEdit->setText(str.toUtf8());
    if(mEdit->toPlainText().isEmpty()) {
        return;
    }
    QFile file(mEdit->toPlainText());
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        QMessageBox::warning(this, "open file", "failed!");
        return;
    }
    QTextStream ts(&file);
    while(!ts.atEnd()) {
        content->setPlainText(ts.readAll());
    }
    file.close();
}

void MainWindow::browDelFile()
{
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "text file(*.txt)::All file(*.*)");
    filePath->setText((str.toUtf8()));
}

void MainWindow::deleteFile()
{
    QFile::remove(filePath->text());
}

