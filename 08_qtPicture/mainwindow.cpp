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
    QGraphicsView *view = new QGraphicsView(scene);
    this->setCentralWidget(view);

    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(5);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    scene->addLine(20,130,200,30,pen);
    QGraphicsView *view2 = new QGraphicsView(scene);
    this->setCentralWidget(view2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

