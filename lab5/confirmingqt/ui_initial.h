/********************************************************************************
** Form generated from reading UI file 'initial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIAL_H
#define UI_INITIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initial
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *equalBtn;
    QPushButton *inequalBtn;
    QPushButton *closeBtn;

    void setupUi(QDialog *initial)
    {
        if (initial->objectName().isEmpty())
            initial->setObjectName(QString::fromUtf8("initial"));
        initial->resize(358, 402);
        verticalLayout = new QVBoxLayout(initial);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(initial);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        widget = new QWidget(initial);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        equalBtn = new QPushButton(widget);
        equalBtn->setObjectName(QString::fromUtf8("equalBtn"));

        horizontalLayout->addWidget(equalBtn);

        inequalBtn = new QPushButton(widget);
        inequalBtn->setObjectName(QString::fromUtf8("inequalBtn"));

        horizontalLayout->addWidget(inequalBtn);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget);


        retranslateUi(initial);

        QMetaObject::connectSlotsByName(initial);
    } // setupUi

    void retranslateUi(QDialog *initial)
    {
        initial->setWindowTitle(QCoreApplication::translate("initial", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("initial", "confirm tool", nullptr));
        equalBtn->setText(QCoreApplication::translate("initial", "equal", nullptr));
        inequalBtn->setText(QCoreApplication::translate("initial", "inequal", nullptr));
        closeBtn->setText(QCoreApplication::translate("initial", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initial: public Ui_initial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIAL_H
