#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
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

