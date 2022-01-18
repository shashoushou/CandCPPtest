/********************************************************************************
** Form generated from reading UI file 'tabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABWIDGET_H
#define UI_TABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabWidget
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tabWidget)
    {
        if (tabWidget->objectName().isEmpty())
            tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->resize(800, 600);
        menubar = new QMenuBar(tabWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        tabWidget->setMenuBar(menubar);
        centralwidget = new QWidget(tabWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(tabWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tabWidget->setStatusBar(statusbar);

        retranslateUi(tabWidget);

        QMetaObject::connectSlotsByName(tabWidget);
    } // setupUi

    void retranslateUi(QMainWindow *tabWidget)
    {
        tabWidget->setWindowTitle(QApplication::translate("tabWidget", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tabWidget: public Ui_tabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGET_H
