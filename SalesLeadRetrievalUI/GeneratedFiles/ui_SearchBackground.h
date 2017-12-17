/********************************************************************************
** Form generated from reading UI file 'SearchBackground.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBACKGROUND_H
#define UI_SEARCHBACKGROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchBackground
{
public:

    void setupUi(QWidget *SearchBackground)
    {
        if (SearchBackground->objectName().isEmpty())
            SearchBackground->setObjectName(QStringLiteral("SearchBackground"));
        SearchBackground->resize(400, 300);

        retranslateUi(SearchBackground);

        QMetaObject::connectSlotsByName(SearchBackground);
    } // setupUi

    void retranslateUi(QWidget *SearchBackground)
    {
        SearchBackground->setWindowTitle(QApplication::translate("SearchBackground", "SearchBackground", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchBackground: public Ui_SearchBackground {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBACKGROUND_H
