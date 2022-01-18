#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename = new QLineEdit(this);
    filename->setGeometry(QRect(50,50,230,25));

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("Browser");
    connect(button, SIGNAL(clicked()), this, SLOT(showFiles()));

    btn = new QPushButton(this);
    btn->setGeometry(QRect(500, 80, 180, 25));
    btn->setText("select Color:");
    connect(btn, SIGNAL(clicked()), this, SLOT(editText()));

    label = new QLabel(this);
    label->setGeometry(QRect(500, 50, 100, 25));
    label->setText("Font Color");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFiles()
{
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "textfile(*.txt)::C file(*.cpp);;All file(*.*)");
    filename->setText(str.toUtf8());
}

void MainWindow::editText()
{
    QColorDialog::setCustomColor(0, QRgb(0x0000FF));
    QColor color = QColorDialog::getColor(QColor(0, 255, 0));
    QPalette p = palette();
    p.setColor(QPalette::WindowText, QColor(color));
    label->setPalette(p);
}


