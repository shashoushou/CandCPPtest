#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

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
    QLabel *explainL;
    QPushButton *createBtn;

private slots:
    void createFile();

};

#endif // MAINWINDOW3_H
