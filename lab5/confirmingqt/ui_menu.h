/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_0;
    QVBoxLayout *verticalLayout;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *file1;
    QLabel *file2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *hint;
    QPushButton *isequal;
    QPushButton *isinequal;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(639, 465);
        gridLayout_2 = new QGridLayout(menu);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_0 = new QWidget(menu);
        widget_0->setObjectName(QString::fromUtf8("widget_0"));
        verticalLayout = new QVBoxLayout(widget_0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_1 = new QWidget(widget_0);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        horizontalLayout_2 = new QHBoxLayout(widget_1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        file1 = new QLabel(widget_1);
        file1->setObjectName(QString::fromUtf8("file1"));

        horizontalLayout_2->addWidget(file1);

        file2 = new QLabel(widget_1);
        file2->setObjectName(QString::fromUtf8("file2"));

        horizontalLayout_2->addWidget(file2);


        verticalLayout->addWidget(widget_1);

        widget_2 = new QWidget(widget_0);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hint = new QLabel(widget_2);
        hint->setObjectName(QString::fromUtf8("hint"));

        gridLayout->addWidget(hint, 0, 1, 1, 1);

        isequal = new QPushButton(widget_2);
        isequal->setObjectName(QString::fromUtf8("isequal"));

        gridLayout->addWidget(isequal, 1, 0, 1, 1);

        isinequal = new QPushButton(widget_2);
        isinequal->setObjectName(QString::fromUtf8("isinequal"));

        gridLayout->addWidget(isinequal, 1, 2, 1, 1);


        verticalLayout->addWidget(widget_2);


        gridLayout_2->addWidget(widget_0, 0, 1, 1, 1);


        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        file1->setText(QString());
        file2->setText(QString());
        hint->setText(QString());
        isequal->setText(QCoreApplication::translate("menu", "\347\255\211\344\273\267", nullptr));
        isinequal->setText(QCoreApplication::translate("menu", "\344\270\215\347\255\211\344\273\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
