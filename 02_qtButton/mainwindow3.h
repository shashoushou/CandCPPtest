#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private:
    Ui::MainWindow3 *ui;

    QGridLayout *gridLayout;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QWidget *widget2;
};

#endif // MAINWINDOW3_H
