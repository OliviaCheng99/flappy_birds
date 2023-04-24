/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *dateOfBirthLabel;
    QDateEdit *dateOfBirthDateEdit;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QPushButton *picButton;
    QLabel *label_6;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(824, 504);
        buttonBox = new QDialogButtonBox(SignUp);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(350, 350, 152, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(SignUp);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 90, 711, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        firstNameLabel = new QLabel(formLayoutWidget);
        firstNameLabel->setObjectName("firstNameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineEdit = new QLineEdit(formLayoutWidget);
        firstNameLineEdit->setObjectName("firstNameLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(firstNameLineEdit->sizePolicy().hasHeightForWidth());
        firstNameLineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameLineEdit);

        lastNameLabel = new QLabel(formLayoutWidget);
        lastNameLabel->setObjectName("lastNameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(formLayoutWidget);
        lastNameLineEdit->setObjectName("lastNameLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameLineEdit);

        dateOfBirthLabel = new QLabel(formLayoutWidget);
        dateOfBirthLabel->setObjectName("dateOfBirthLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, dateOfBirthLabel);

        dateOfBirthDateEdit = new QDateEdit(formLayoutWidget);
        dateOfBirthDateEdit->setObjectName("dateOfBirthDateEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, dateOfBirthDateEdit);

        usernameLabel = new QLabel(formLayoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(formLayoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(formLayoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, passwordLineEdit);

        picButton = new QPushButton(formLayoutWidget);
        picButton->setObjectName("picButton");

        formLayout->setWidget(5, QFormLayout::FieldRole, picButton);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);


        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Sign Up", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("SignUp", "First Name", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("SignUp", "Last Name", nullptr));
        dateOfBirthLabel->setText(QCoreApplication::translate("SignUp", "Date of Birth", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignUp", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        picButton->setText(QCoreApplication::translate("SignUp", "upload profile picture", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "Profile Picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
