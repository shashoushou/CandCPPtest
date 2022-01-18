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
#include "tabwidget.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>

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

    QMenu *fileMenu, *editMenu, *helpMenu;
    QToolBar *fileToolBar, *editToolBar;
    QAction *newAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pastAct;
    QAction *aboutQtAct;

    QPushButton *hlBtn;
    MainWindow2 w2;

    QPushButton *glBtn;
    MainWindow3 w3;

    QPushButton *gbBtn;
    MainWindow4 w4;

    QPushButton *twBtn;
    tabWidget w5;

private slots:
    void openW();
    void newFile();

};
#endif // MAINWINH
