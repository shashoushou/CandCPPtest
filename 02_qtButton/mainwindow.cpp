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
    tableView->setGeometry(QRect(300,50,310,200));
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

    hlBtn = new QPushButton(this);
    hlBtn->setText("open w2");
    hlBtn->setGeometry(QRect(300,300,200,50));
    connect(hlBtn, SIGNAL(clicked()), this, SLOT(openW()));

    glBtn = new QPushButton(this);
    glBtn->setText("open w3");
    glBtn->setGeometry(QRect(300,350,200,50));
    connect(glBtn, SIGNAL(clicked()), this, SLOT(openW()));

    gbBtn = new QPushButton(this);
    gbBtn->setText("open w4");
    gbBtn->setGeometry(QRect(300,400,200,50));
    connect(gbBtn, SIGNAL(clicked()), this, SLOT(openW()));

    twBtn = new QPushButton(this);
    twBtn->setText("open w5");
    twBtn->setGeometry(QRect(300,450,200,50));
    connect(twBtn, SIGNAL(clicked()), this, SLOT(openW()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openW()
{
   if(sender() == hlBtn)
       w2.show();
   else if(sender() == glBtn)
       w3.show();
   else if(sender() == gbBtn)
       w4.show();
   else if(sender() == twBtn)
       w5.show();
}


