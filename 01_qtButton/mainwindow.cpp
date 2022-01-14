#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button = new QPushButton(this);
    button->setGeometry(QRect(100,100,100,25));
    connect(button, SIGNAL(released()), this, SLOT(txtButton()));

    label = new QLabel("This is Qt label", this);
    label->setGeometry(QRect(100,150,200,30));
    label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic");

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(100,200,200,25));
    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color: bluered;");
    lineEdit->setMaxLength(12);
    lineEdit->setEchoMode(QLineEdit::Password);

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(QRect(100,250,200,150));
    textEdit->setText("Line one<br/>Line two");

    plainTextEdit = new QPlainTextEdit(this);
    plainTextEdit->setGeometry(QRect(100,300,200,100));
    plainTextEdit->setPlainText("Line one");

    comboBox = new QComboBox(this);
    comboBox->setGeometry(QRect(100,450,120,25));
    QStringList str;
    str <<"math"<<"eng"<<"geo";
    comboBox->addItems(str);

    fontComboBox = new QFontComboBox(this);
    fontButton = new QPushButton(this);
    fontLabel = new QLabel(this);
    fontLabel->setGeometry(QRect(400,100,300,25));
    fontButton->setText("Button");
    fontButton->move(650,50);
    connect(fontButton, SIGNAL(released()), this, SLOT(txtFontButton()));
    fontComboBox->setGeometry(QRect(400, 50,200,25));

    spinBox = new QSpinBox(this);
    spinBox->setGeometry(QRect(400, 100, 100, 25));
    spinBox->setRange(0,200);
    spinBox->setValue(10);
    spinBox->setSuffix("  Yu");
    spinBox->setPrefix("$ ");

    QDateTime sysTime = QDateTime::currentDateTime();
    QStringList list = sysTime.toString("hh:mm:ss").split(':');
    timeEdit = new QTimeEdit(this);
    timeEdit->setGeometry(QRect(400, 150,200, 25));
    timeEdit->setTime(QTime(list[0].toUInt(), list[1].toInt(), list[2].toInt()));
    //timeEdit->setDisplayFormat(timeEdit->locale().dateFormat()+"HH:mm:ss");

    dateEdit = new QDateEdit(this);
    dateEdit->setGeometry(QRect(400,200, 200, 25));
    QStringList list2 = sysTime.toString("yyyy-MM-dd").split('-');
    dateEdit->setDate(QDate(list2[0].toInt(),list2[1].toUInt(), list2[2].toUInt()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::txtButton()
{
    button->setText("Button B");
}

void MainWindow::txtFontButton()
{
    fontLabel->setText("Select font: "+fontComboBox->currentText());
}

