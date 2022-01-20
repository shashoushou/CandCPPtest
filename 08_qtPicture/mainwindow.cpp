#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene;
    scene->setBackgroundBrush(QColor(0, 255, 255, 127));
    QFont font("black", 60);
    scene->addSimpleText("picture", font);
    QGraphicsView *view = new QGraphicsView(scene);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

