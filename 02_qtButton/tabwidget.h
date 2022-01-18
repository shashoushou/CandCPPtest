#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class tabWidget;
}

class tabWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit tabWidget(QWidget *parent = nullptr);
    ~tabWidget();

private:
    Ui::tabWidget *ui;
    QTabWidget *tabwidget;
};

class tabA:public QWidget
{
    Q_OBJECT
public:
    tabA(QWidget *parent =0);
};

class tabB:public QWidget
{
    Q_OBJECT
public:
    tabB(QWidget *parent =0);
};

#endif // TABWIDGET_H
