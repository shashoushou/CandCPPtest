#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // paint text
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setBackgroundBrush(QColor(0, 255, 255, 127));
    QFont font("black", 60);
    scene->addSimpleText("picture", font);
//    QGraphicsView *view = new QGraphicsView(scene);
//    this->setCentralWidget(view);

    // Paint Line
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(5);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    scene->addLine(20,130,200,30,pen);

    // circle
    scene->addEllipse(150,50,100,120);

    QGraphicsView *view = new QGraphicsView(scene);
    this->setCentralWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

