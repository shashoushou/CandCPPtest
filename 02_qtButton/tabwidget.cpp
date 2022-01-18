#include "tabwidget.h"
#include "ui_tabwidget.h"
#include <QWidget>
#include <QPushButton>

tabWidget::tabWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabWidget)
{
    ui->setupUi(this);
    tabwidget = new QTabWidget(this);
    tabwidget->setGeometry(QRect(30,30,340,140));
    tabwidget->addTab(new tabA, "A tab");
    tabwidget->addTab(new tabB, "B tab");
}

tabWidget::~tabWidget()
{
    delete ui;
}

tabA::tabA(QWidget *parent):QWidget(parent)
{
   QPushButton *buttonA = new QPushButton(this);
   buttonA->setText("Tab A");
}

tabB::tabB(QWidget *parent):QWidget(parent)
{
   QPushButton *buttonB = new QPushButton(this);
   buttonB->setText("Tab B");

}
