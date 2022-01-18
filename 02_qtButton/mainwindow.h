#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QPushButton>
#include <QTreeView>
#include <QStandardItemModel>
#include <QTableView>

#include "mainwindow2.h"
#include "mainwindow3.h"
#include "mainwindow4.h"

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
    QListView *listView;
    QStringListModel *model;

    QTreeView *treeView;
    QStandardItemModel *model2;

    QTableView *tableView;
    QStandardItemModel *model3;

    QPushButton *hlBtn;
    MainWindow2 w2;

    QPushButton *glBtn;
    MainWindow3 w3;

    QPushButton *gbBtn;
    MainWindow4 w4;

private slots:
    void openW();

};
#endif // MAINWINDOW_H
