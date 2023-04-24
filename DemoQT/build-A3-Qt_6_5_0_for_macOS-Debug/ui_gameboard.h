/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *logoutButton;
    QPushButton *startGame;
    QPushButton *checkAccountButton;

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(884, 651);
        label = new QLabel(GameBoard);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 100, 111, 20));
        label_2 = new QLabel(GameBoard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 180, 58, 16));
        label_3 = new QLabel(GameBoard);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(440, 100, 58, 16));
        label_4 = new QLabel(GameBoard);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 180, 58, 16));
        logoutButton = new QPushButton(GameBoard);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(270, 290, 100, 32));
        startGame = new QPushButton(GameBoard);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(420, 290, 100, 32));
        checkAccountButton = new QPushButton(GameBoard);
        checkAccountButton->setObjectName("checkAccountButton");
        checkAccountButton->setGeometry(QRect(660, 50, 100, 32));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        checkAccountButton->setFont(font);
        logoutButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        startGame->raise();
        checkAccountButton->raise();

        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "GameBoard", nullptr));
        label->setText(QCoreApplication::translate("GameBoard", "Last Score", nullptr));
        label_2->setText(QCoreApplication::translate("GameBoard", "Ranking", nullptr));
        label_3->setText(QCoreApplication::translate("GameBoard", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("GameBoard", "TextLabel", nullptr));
        logoutButton->setText(QCoreApplication::translate("GameBoard", "logout", nullptr));
        startGame->setText(QCoreApplication::translate("GameBoard", "start game", nullptr));
        checkAccountButton->setText(QCoreApplication::translate("GameBoard", "my account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
