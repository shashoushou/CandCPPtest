#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QFontComboBox>
#include <QSpinBox>
#include <QTimeEdit>

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
    QPushButton *button;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;

    QFontComboBox *fontComboBox;
    QPushButton *fontButton;
    QLabel *fontLabel;

    QSpinBox *spinBox;
    QTimeEdit *timeEdit;


private slots:
    void txtButton();
    void txtFontButton();
};
#endif // MAINWINDOW_H
