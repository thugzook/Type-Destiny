#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QApplication>
#include <QTime>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ///this is a pointer to the MainWindow and can only be used when in the class that it being used
    ui->setupUi(this);

    ///generate Splash logo (Logo.png) and implement the form to host the image
    ///utilizes "this" and <QPalette> pre-proc. directive
    ///must be put into the MainWindow class to utilize the ui's slot
    QPixmap bkgnd(":/Logo.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}//end construco

/* Function makes use of the QTime class and implements the current time in order to pause certain events
 * uses <QTime> and must be prototyped in the header file
 *
 * Pre   : must be called
 * Param : int msecs
 * Return: none
 * Post  : events would have been delayed msecs milliseconds
*/
void MainWindow::delay(double msecs) ///msecs relates to milliseconds
{
    double MSecs = msecs;
    QTime endTime= QTime::currentTime().addMSecs(MSecs);
    while( QTime::currentTime() < endTime )
    ///QCoreApplication handles event loops without UIs
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}//end delay function

MainWindow::~MainWindow()
{
    delete ui;
}//end MainWindow constructor

/*Takes advantage of the QPixmap and QPalette to cycle through images for the opening of maingame2.ui
 * Pre   : on_btnSplash_clicked() has to have been called in order for this to operate
 * Param : none
 * Return: none
 * Post  : palette becomes altered
*/
void MainWindow::cycleBackground()
{
    ///slowly begin to dim out the logo before proceeding to main game screen
    ///start with a delay
    delay(1000);

    ///reinitialize QPixmap and initialize with 1st picture.
    QPixmap bkgnd(":/LogoDimmer1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay once more
    delay(300);

    ///repeat for the rest of the images.
    bkgnd.load(":/LogoDimmer2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    delay(300);

    ///image 3
    bkgnd.load(":/LogoDimmer3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    delay(300);

    ///image 4
    bkgnd.load(":/LogoDimmer4.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    delay(350);
}//end cycleBackground function

/* hides btnSplash, plays a sound, calls cycleBackground(), hides the form and shows maingame.ui
 * Pre   : ui->btnSplash must have been clicked
 * Param : none
 * Return: none
 * Post  : hides btnSplash, plays a sound, calls cycleBackground(), hides the form and shows maingame.ui
*/
void MainWindow::on_btnSplash_clicked()
{
        ///disable button use from occuring after one press
        ui->btnSplash->hide();

        ///play start.wav immedietely after button press
        QSound::play(":/start.wav");

        ///call cycleBackground()
        cycleBackground();

        ///display maingame.ui and hide mainwindow.ui
        mainGame.show();
        this->hide();
}//end on_btnSplash_clicked function

