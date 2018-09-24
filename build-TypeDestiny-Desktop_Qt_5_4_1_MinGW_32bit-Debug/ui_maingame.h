/********************************************************************************
** Form generated from reading UI file 'maingame.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGame
{
public:
    QLabel *lblPrompt;
    QPushButton *btnConfirm;
    QLabel *lblPrompt_2;
    QLineEdit *lnName;

    void setupUi(QWidget *MainGame)
    {
        if (MainGame->objectName().isEmpty())
            MainGame->setObjectName(QStringLiteral("MainGame"));
        MainGame->resize(974, 654);
        MainGame->setMinimumSize(QSize(974, 654));
        MainGame->setMaximumSize(QSize(974, 654));
        lblPrompt = new QLabel(MainGame);
        lblPrompt->setObjectName(QStringLiteral("lblPrompt"));
        lblPrompt->setGeometry(QRect(220, 170, 541, 61));
        QFont font;
        font.setFamily(QStringLiteral("Fixedsys"));
        font.setPointSize(26);
        lblPrompt->setFont(font);
        btnConfirm = new QPushButton(MainGame);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));
        btnConfirm->setGeometry(QRect(390, 420, 151, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Fixedsys"));
        font1.setPointSize(22);
        btnConfirm->setFont(font1);
        btnConfirm->setCursor(QCursor(Qt::PointingHandCursor));
        btnConfirm->setMouseTracking(false);
        btnConfirm->setCheckable(false);
        lblPrompt_2 = new QLabel(MainGame);
        lblPrompt_2->setObjectName(QStringLiteral("lblPrompt_2"));
        lblPrompt_2->setGeometry(QRect(150, 240, 631, 51));
        lblPrompt_2->setFont(font);
        lnName = new QLineEdit(MainGame);
        lnName->setObjectName(QStringLiteral("lnName"));
        lnName->setGeometry(QRect(190, 350, 561, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Fixedsys"));
        font2.setPointSize(24);
        lnName->setFont(font2);
        lnName->setMaxLength(20);
        lnName->setAlignment(Qt::AlignCenter);

        retranslateUi(MainGame);

        QMetaObject::connectSlotsByName(MainGame);
    } // setupUi

    void retranslateUi(QWidget *MainGame)
    {
        MainGame->setWindowTitle(QApplication::translate("MainGame", "Form", 0));
        lblPrompt->setText(QApplication::translate("MainGame", "Welcome, Adventurer...", 0));
        btnConfirm->setText(QApplication::translate("MainGame", "CONFIRM", 0));
        lblPrompt_2->setText(QApplication::translate("MainGame", "What do you call yourself?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainGame: public Ui_MainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
