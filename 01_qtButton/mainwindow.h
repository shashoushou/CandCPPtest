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
#include <QDateEdit>
#include <QScrollBar>
#include <QRadioButton>
#include <QCheckBox>

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
    QDateEdit *dateEdit;

    QScrollBar *scrollBar;
    QSpinBox *spinBox2;
    QRadioButton *radioM;
    QRadioButton *radioW;
    QLabel *radioLabel;

    QCheckBox *checkBox01;
    QCheckBox *checkBox02;
    QCheckBox *checkBox03;
    QLabel *checkLabel;

private slots:
    void txtButton();
    void txtFontButton();
    void radioChange();
    void checkChange();
};
#endif // MAINWINDOW_H
