#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>

#include <QTreeView>
#include <QStandardItemModel>

#include <QTableView>

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


};
#endif // MAINWINDOW_H
