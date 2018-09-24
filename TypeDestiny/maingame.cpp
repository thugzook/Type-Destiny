#include "maingame.h"
#include "ui_maingame.h"
#include <QLineEdit>
#include <QString>
#include <QObject>
#include <QPalette>
#include <QMessageBox>

MainGame::MainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);

    ///allow user to automatically input values
    ui->lnName->setFocus();

    ///variables
    //QString userName (currently located in MainGame.h::Public:)

    ///makes the button appear as a label.
    ui->btnConfirm->setFlat(true);

    ///A signal that will look check to see if return was pressed while lnName was in focus.
    QObject::connect(ui->lnName, SIGNAL(returnPressed()), ui->btnConfirm, SIGNAL(clicked()));

    ///generate Splash logo (Logo.png) and implement the form to host the image
    ///utilizes "this" and <QPalette> pre-proc. directive
    ///must be put into the MainWindow class to utilize the ui's slot
    QPixmap bkgnd(":/NamePrompt.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainGame::~MainGame()
{
    delete ui;
}//end main game constructor

/* gathers the user's input from lnName.
 * Pre   :   ui->on_btnConfirm_clicked
 * Param :   QString &userName
 * Return:   None
 * Post  :   userName will either remain or change to "Adventurer"
*/
void MainGame::getText(QString &userName)
{
    ///check to see if user has entered a name into the field
    ///if not, give default name

    userName = ui->lnName->text();
    if (userName == "")
    {
        QMessageBox::information(this, "Type Destiny", "You did not type anything into the field. \nYou have been given the name 'Adventurer'");
        userName = "Adventurer";
    }//end if
    else
        userName = userName;
}//end getText function

/* signal function that will activate when btnConfirm is clicked
 * Pre   : ui->on_btnConfirm_clicked() must be true
 * Param : none
 * Return: none
 * Post  : QString userName will be emitted to maingame2.cpp, form will hide
*/
void MainGame::on_btnConfirm_clicked()
{
    ///call getText in order to gather the user's input
    getText(userName);

    ///hide this form
    this->hide();

    ///IMPORTANT!!!!!
    ///connect (part of <QObject>) will look for a signal (returnPressed(QString)) found in the class above
    ///Then, it will communicate wil onReturnPressed(QString) found in maingame2.h/cpp
    ///finally, emit will pass the argument userName to its intended location -> onReturnPressed(QString) in maingame2.cpp
    connect(this, SIGNAL(returnPressed(QString)), &mainGame2, SLOT(onReturnPressed(QString)));
    emit this->returnPressed(userName);
}//end void on_btnConfirm_clicked() function
