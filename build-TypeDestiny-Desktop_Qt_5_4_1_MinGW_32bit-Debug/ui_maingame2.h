/********************************************************************************
** Form generated from reading UI file 'maingame2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME2_H
#define UI_MAINGAME2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGame2
{
public:
    QListWidget *lstSysMsg;
    QLabel *lblUserName;
    QLineEdit *lnCharInput;

    void setupUi(QWidget *MainGame2)
    {
        if (MainGame2->objectName().isEmpty())
            MainGame2->setObjectName(QStringLiteral("MainGame2"));
        MainGame2->resize(974, 654);
        MainGame2->setMinimumSize(QSize(974, 654));
        MainGame2->setMaximumSize(QSize(974, 654));
        lstSysMsg = new QListWidget(MainGame2);
        lstSysMsg->setObjectName(QStringLiteral("lstSysMsg"));
        lstSysMsg->setEnabled(true);
        lstSysMsg->setGeometry(QRect(12, 521, 951, 121));
        QFont font;
        font.setFamily(QStringLiteral("Fixedsys"));
        font.setPointSize(24);
        lstSysMsg->setFont(font);
        lblUserName = new QLabel(MainGame2);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));
        lblUserName->setGeometry(QRect(0, 500, 47, 13));
        lnCharInput = new QLineEdit(MainGame2);
        lnCharInput->setObjectName(QStringLiteral("lnCharInput"));
        lnCharInput->setGeometry(QRect(480, 460, 40, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Fixedsys"));
        font1.setPointSize(36);
        lnCharInput->setFont(font1);
        lnCharInput->setMaxLength(1);

        retranslateUi(MainGame2);

        QMetaObject::connectSlotsByName(MainGame2);
    } // setupUi

    void retranslateUi(QWidget *MainGame2)
    {
        MainGame2->setWindowTitle(QApplication::translate("MainGame2", "Form", 0));
        lblUserName->setText(QApplication::translate("MainGame2", "lblUserName", 0));
        lnCharInput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainGame2: public Ui_MainGame2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME2_H
