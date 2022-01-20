#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QSettings>

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
    QGridLayout *gLayout;
    QWidget *widget;
    QLabel *filePathL;
    QLineEdit *filePath;
    QLabel *nodeL;
    QLineEdit *nodeEdit;
    QLabel *keyL;
    QLineEdit *keyEdit;
    QLabel *valL;
    QLineEdit *valEdit;
    QPushButton *writeBtn;
    QSettings *writeIni;

private slots:
    void writeFile();

};
#endif // MAINWINDOW_H
