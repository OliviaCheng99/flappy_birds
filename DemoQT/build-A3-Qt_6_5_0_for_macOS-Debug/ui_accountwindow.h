/********************************************************************************
** Form generated from reading UI file 'accountwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTWINDOW_H
#define UI_ACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountWindow
{
public:
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *dateOfBirthLabel;
    QLabel *usernameLabel;
    QLabel *firstnameVal;
    QLabel *lastnameVal;
    QLabel *bdayVal;
    QLabel *usernameVal;
    QLabel *label;
    QLabel *picVal;

    void setupUi(QWidget *AccountWindow)
    {
        if (AccountWindow->objectName().isEmpty())
            AccountWindow->setObjectName("AccountWindow");
        AccountWindow->resize(674, 437);
        formLayoutWidget_2 = new QWidget(AccountWindow);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(150, 200, 371, 191));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        firstNameLabel = new QLabel(formLayoutWidget_2);
        firstNameLabel->setObjectName("firstNameLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        lastNameLabel = new QLabel(formLayoutWidget_2);
        lastNameLabel->setObjectName("lastNameLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        dateOfBirthLabel = new QLabel(formLayoutWidget_2);
        dateOfBirthLabel->setObjectName("dateOfBirthLabel");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, dateOfBirthLabel);

        usernameLabel = new QLabel(formLayoutWidget_2);
        usernameLabel->setObjectName("usernameLabel");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, usernameLabel);

        firstnameVal = new QLabel(formLayoutWidget_2);
        firstnameVal->setObjectName("firstnameVal");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, firstnameVal);

        lastnameVal = new QLabel(formLayoutWidget_2);
        lastnameVal->setObjectName("lastnameVal");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lastnameVal);

        bdayVal = new QLabel(formLayoutWidget_2);
        bdayVal->setObjectName("bdayVal");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, bdayVal);

        usernameVal = new QLabel(formLayoutWidget_2);
        usernameVal->setObjectName("usernameVal");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, usernameVal);

        label = new QLabel(AccountWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 30, 101, 21));
        picVal = new QLabel(AccountWindow);
        picVal->setObjectName("picVal");
        picVal->setGeometry(QRect(330, 30, 110, 110));

        retranslateUi(AccountWindow);

        QMetaObject::connectSlotsByName(AccountWindow);
    } // setupUi

    void retranslateUi(QWidget *AccountWindow)
    {
        AccountWindow->setWindowTitle(QCoreApplication::translate("AccountWindow", "Form", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("AccountWindow", "First Name:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("AccountWindow", "Last Name:", nullptr));
        dateOfBirthLabel->setText(QCoreApplication::translate("AccountWindow", "Date of Birth:", nullptr));
        usernameLabel->setText(QCoreApplication::translate("AccountWindow", "Username:", nullptr));
        firstnameVal->setText(QCoreApplication::translate("AccountWindow", "TextLabel", nullptr));
        lastnameVal->setText(QCoreApplication::translate("AccountWindow", "TextLabel", nullptr));
        bdayVal->setText(QCoreApplication::translate("AccountWindow", "TextLabel", nullptr));
        usernameVal->setText(QCoreApplication::translate("AccountWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("AccountWindow", "Profile Picture", nullptr));
        picVal->setText(QCoreApplication::translate("AccountWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountWindow: public Ui_AccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTWINDOW_H
