#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listView = new QListView(this);
    listView->setGeometry(QRect(50,50,100,100));
    QStringList string;
    string  <<"math"<<"eng"<<"geo";
    model = new QStringListModel(string);
    listView->setModel(model);

    treeView = new QTreeView(this);
    treeView->setGeometry(QRect(50,200,150,200));
    model2 = new QStandardItemModel(3,2);
    model2->setHeaderData(0,Qt::Horizontal, "Line 1");
    model2->setHeaderData(1,Qt::Horizontal, "Line 2");
    QStandardItem *item1 = new QStandardItem("math");
    item1->setIcon((QIcon(":/new/prefix1/folder")));
    QStandardItem *item2 = new QStandardItem("eng");
    item2->setIcon((QIcon(":/new/prefix1/folder")));
    QStandardItem *item3 = new QStandardItem("geo");
    item3->setIcon((QIcon(":/new/prefix1/folder")));
    QStandardItem *item4 = new QStandardItem("eng A");
    item4->setIcon((QIcon(":/new/prefix1/folder")));
    item2->appendRow(item4);
    model2->setItem(0, 0, item1);
    model2->setItem(1, 0, item2);
    model2->setItem(2, 0, item3);
    treeView->setModel(model2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

