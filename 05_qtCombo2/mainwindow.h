#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *filename;
    QPushButton *button;

    QPushButton *btn;
    QLabel *label;

    QPushButton *btn2;
    QProgressBar *bar;

    QLabel *label2;
    QTimer *timer;


private slots:
    void showFiles();
    void editText();
    void startBar();
    void timerTime();
};
#endif // MAINWINDOW_H
