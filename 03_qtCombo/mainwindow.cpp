#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setText("Date: ");

    label->setGeometry(QRect(50,50,100,25));
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry((QRect(110,50,150, 22)));

    connect(lineEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(showTime()));

    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setGeometry(20, 75, 350, 180);
    calendarWidget->setHidden(true);

    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(setDate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    calendarWidget->setHidden(false);
}

void MainWindow::setDate()
{
    QDate date = calendarWidget->selectedDate();
    QString str = date.toString("yyyy-MM-dd");
    lineEdit->setText(str);
    calendarWidget->setHidden(true);
}

