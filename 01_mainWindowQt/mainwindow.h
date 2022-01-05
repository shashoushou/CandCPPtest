#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include "mainwindow2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEven(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QPushButton *btClose;
    QPushButton *button;
    MainWindow2 w2;
    QPoint last;

private slots:
    void showMainWindow2();
};
#endif // MAINWINDOW_H
