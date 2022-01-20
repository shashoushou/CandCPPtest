#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = nullptr);
    ~MainWindow4();

private:
    Ui::MainWindow4 *ui;
    QLabel *resultL;
    QPushButton *readBtn;

private slots:
    void readNode();
};

#endif // MAINWINDOW4_H
