#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

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
    QGroupBox *box;
    QPushButton *button;
    QVBoxLayout *vbox;
};

#endif // MAINWINDOW4_H
