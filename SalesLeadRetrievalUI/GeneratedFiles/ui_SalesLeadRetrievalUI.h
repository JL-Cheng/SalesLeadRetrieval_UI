/********************************************************************************
** Form generated from reading UI file 'SalesLeadRetrievalUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESLEADRETRIEVALUI_H
#define UI_SALESLEADRETRIEVALUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SalesLeadRetrievalUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SalesLeadRetrievalUIClass)
    {
        if (SalesLeadRetrievalUIClass->objectName().isEmpty())
            SalesLeadRetrievalUIClass->setObjectName(QStringLiteral("SalesLeadRetrievalUIClass"));
        SalesLeadRetrievalUIClass->resize(600, 400);
        menuBar = new QMenuBar(SalesLeadRetrievalUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SalesLeadRetrievalUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SalesLeadRetrievalUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SalesLeadRetrievalUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SalesLeadRetrievalUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SalesLeadRetrievalUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SalesLeadRetrievalUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SalesLeadRetrievalUIClass->setStatusBar(statusBar);

        retranslateUi(SalesLeadRetrievalUIClass);

        QMetaObject::connectSlotsByName(SalesLeadRetrievalUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SalesLeadRetrievalUIClass)
    {
        SalesLeadRetrievalUIClass->setWindowTitle(QApplication::translate("SalesLeadRetrievalUIClass", "SalesLeadRetrievalUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SalesLeadRetrievalUIClass: public Ui_SalesLeadRetrievalUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESLEADRETRIEVALUI_H
