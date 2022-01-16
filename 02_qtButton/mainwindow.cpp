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

    tableView = new QTableView(this);
    tableView->setGeometry(QRect(200,50,310,200));
    model3 = new QStandardItemModel();
    model3->setHorizontalHeaderItem(0, new QStandardItem("math"));
    model3->setHorizontalHeaderItem(1, new QStandardItem("eng"));
    model3->setHorizontalHeaderItem(2, new QStandardItem("geo"));
    model3->setItem(0,0,new QStandardItem("math A"));
    model3->setItem(0,1,new QStandardItem("eng A"));
    model3->setItem(0,2,new QStandardItem("geo A"));
    model3->setItem(1,0,new QStandardItem("math B"));
    model3->setItem(1,1,new QStandardItem("eng B"));
    model3->setItem(1,2,new QStandardItem("geo B"));
    tableView->setModel(model3);

    hboxLayout = new QHBoxLayout();
    button1 = new QPushButton("btn 1");
    button2 = new QPushButton("btn 2");
    button3 = new QPushButton("btn 3");
    hboxLayout->addWidget(button1);
    hboxLayout->addWidget(button2);
    hboxLayout->addWidget(button3);
    hboxLayout->setSpacing(60);
    widget = new QWidget();
    widget->setLayout(hboxLayout);
    this->setCentralWidget(widget);

    gridLayout= new QGridLayout;
    button4 = new QPushButton("btn 4");
    button5 = new QPushButton("btn 5");
    button6 = new QPushButton("btn 6");
    hboxLayout->addWidget(button4);
    hboxLayout->addWidget(button5);
    hboxLayout->addWidget(button6);
    gridLayout->addWidget(button4, 0, 0, 1, 1);
    gridLayout->addWidget(button5, 0, 1, 1, 1);
    gridLayout->addWidget(button6, 1, 0, 1, 1);
    widget2 = new QWidget();
    widget2->setLayout(gridLayout);
    this->setCentralWidget(widget2);


}

MainWindow::~MainWindow()
{
    delete ui;
}

