#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

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
    QLineEdit *edit;
    QPushButton *button;

    QPushButton *btn2;
    QLineEdit *newFilename;
    QLineEdit *newFileContent;

    QPushButton *browseBt;
    QPushButton *saveBt;
    QTextEdit *mEdit;
    QTextEdit *content;

    QLineEdit *filePath;
    QPushButton *broBtn;
    QPushButton *delBtn;

private slots:
    void createFolder();
    void createFile();
    void saveFile();
    void browseFile();
    void browDelFile();
    void deleteFile();
};
#endif // MAINWINDOW_H
