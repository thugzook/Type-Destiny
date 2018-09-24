#include "maingame2.h"
#include "ui_maingame2.h"
#include <QMessageBox>
#include <QPalette>
#include <QTime>
#include <time.h>
#include <cstdlib>
#include <QSound>

MainGame2::MainGame2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainGame2)
{
    ui->setupUi(this);

    ///variables

    ///hide listbox until displayBackground() is finished
    ui->lstSysMsg->setVisible(false);

    ///hide lnCharInput until called
    ui->lnCharInput->setVisible(false);

    ///hide all the charLocs until called
    ui->charLoc1->setVisible(false);
    ui->charLoc2->setVisible(false);
    ui->charLoc3->setVisible(false);
    ui->charLoc4->setVisible(false);
    ui->charLoc5->setVisible(false);
    ui->charLoc6->setVisible(false);
    ui->charLoc7->setVisible(false);
    ui->charLoc8->setVisible(false);
    ui->charLoc9->setVisible(false);
    ui->charLoc10->setVisible(false);
    ui->charLoc11->setVisible(false);
    ui->charLoc12->setVisible(false);

    ///hide progHealth until called
    ui->progHealth->setVisible(false);
    ui->progHealthEnemy->setVisible(false);

    ///btnCharInput set invisible
    ui->btnCharInput->setVisible(false);

    ///A signal that will look check to see if return was pressed while lnCharInput was in focus.
    QObject::connect(ui->lnCharInput, SIGNAL(returnPressed()), ui->btnCharInput, SIGNAL(clicked()));

    ///hide labels
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
}

/***************************************************************************************************************************************/
/***********************************************************PREGAME********************************************************************/
/**************************************************************************************************************************************/

/*Takes advantage of the QPixmap and QPalette to cycle through images for the opening of maingame2.ui
 * Pre   : onReturnPressed(QString) has to have been called in order for this to operate
 * Param : none
 * Return: none
 * Post  : palette becomes altered and startGame() is called
*/
void MainGame2::displayBackground()
{
    ///create a background that cycles through images
    QPixmap bkgnd(":/black.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay
    delay(500);

    ///create a background that cycles through images
    bkgnd.load(":/black 2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay
    delay(500);

    ///create a background that cycles through images
    bkgnd.load(":/black 3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay
    delay(500);

    ///create a background that cycles through images
    bkgnd.load(":/black 4.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay
    delay(500);

    ///create a background that cycles through images
    bkgnd.load(":/black 5.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///delay
    delay(600);

    ///create a background that cycles through images
    bkgnd.load(":/border - Copy.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ///enable listbox when done
    ui->lstSysMsg->setHidden(false);
    ///startGame() called
    startGame();
}//end function displayBackground()

/* Function makes use of the QTime class and implements the current time in order to pause certain events taken from mainwindow.cpp
 * Pre   : must be called
 * Param : int msecs
 * Return: none
 * Post  : the function will have delayed msecs milliseconds
*/
void MainGame2::delay(int msecs)
{
    QTime endTime= QTime::currentTime().addMSecs(msecs);
    while( QTime::currentTime() < endTime )
    ///QCoreApplication handles event loops without UIs
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}//end function delay

MainGame2::~MainGame2()
{
    delete ui;

}//end MainGame2 destructor

/*Slot function that receives QString userName from maingame.cpp
 * Pre   : maingame.cpp must have emitted QString userName to allow this to happen
 * Param : const QString &userName
 * Return: none
 * Post  : maingame2.ui will show, lblUserName will be set to visible and have userName inserted as text, and displayBackground is called
*/
void MainGame2::onReturnPressed(const QString &userName)
{
    ///open maingame2.ui
    this->show();

    ///store userName into text property of label and grab it later
    ui->lblUserName->setVisible(false);
    ui->lblUserName->setText(userName);

    ///call display background
    displayBackground();

}//end function onReturnPressed

/***************************************************************************************************************************************/
/***********************************************************GAME***********************************************************************/
/**************************************************************************************************************************************/

/* handles game functions and maintains the flow of the game
 * Pre	 : must be called
 * Param : none
 * Return: none
 * Post  : game ends
*/
void MainGame2::startGame()
{
    ///variables
    const int TOT_CHARS = 7; //determines how many letters will be on the screen at a time
    char chars[TOT_CHARS]; //stores chars to be used in battle
    int userHealth = 100; //user's health starts at 100
    int userDamage = 1; //user's total damage
    static int progress = 0; //tracks where in the game the user is
    QString finalName = ui->lblUserName->text(); //the user's final ingame name
    static QString *pntFinalName = &finalName;

    ///introduce user
    ui->lstSysMsg->addItem("Welcome to Type Destiny, " + *pntFinalName + "!");
    ui->lstSysMsg->addItem("This game was created by Noah Chong. \nEnjoy!");
    delay(4000);

    ///fill chars
    fillChars(chars, TOT_CHARS);

    ///handling of battles starts here
    ///pass value of progress to storyHandler to be handled appropriately
    while (progress != -1)
    {
         createBattle(userHealth, userDamage, chars, progress, TOT_CHARS, finalName);
         progress++;
    }//end while


}//end function startGame()

/* Handles similar to story handler; however, calls fightEnemy(...) to actually do the combat. This is used for organizational purposes only
 * Pre   : gets called on by storyHandler(...)
 * Param : int &userHealth, int &userDamage, char chars[], int progress
 * Return: none
 * Post  : calls fightEnemy(...) and handles necessary story elements
*/
void MainGame2::createBattle(int &userHealth, int &userDamage, char chars[], int &progress, int TOT_CHARS, QString finalName)
{
    ///variables
    int enemyCode = 0; //used to determine which enemy the user is battling

    ///check where in the game the user is at the time
    switch (progress)
    {
        case 0:
        {
            ///main prompt
            ui->lstSysMsg->clear();
            ui->lstSysMsg->addItem("Welcome to the land of Norden");
            delay(1600);
            ui->lstSysMsg->addItem("A world consumed by dark creatures.");
            delay(1600);
            ui->lstSysMsg->addItem("Their only weakness...");
            delay(2300);
            ui->lstSysMsg->addItem("Typing.");
            delay(2000);

            ///instructions
            ui->lstSysMsg->clear();
            ui->lstSysMsg->addItem("INSTRUCTIONS:");
            delay(600);
            ui->lstSysMsg->addItem("When faced with an enemy, type the corresponding number or letter");
            delay(1000);
            ui->lstSysMsg->addItem("Then Press Enter");
            delay(1000);
            ui->lstSysMsg->addItem("You have a certain time limit to do so");
            ui->lstSysMsg->scrollToBottom();
            delay(4000);
            break;
        }//end case
        case 1:
        {
            ///display labels
            ui->label->setVisible(true);
            ui->label_2->setVisible(true);
            enemyCode = 0;
            fightEnemy(userHealth, userDamage, enemyCode, chars, TOT_CHARS, progress);
            break;
        }//end case 0
    }//ends switch
}//end function createBattle

/* Controls which enemy the user faces
 * Pre   : gets called on by createBattle(...)
 * Param : int &userHealth, int &userDamage, int enemyCode, char chars[]
 * Return: none
 * Post  : enemy is either defeated or user is killed
*/
void MainGame2::fightEnemy (int &userHealth, int &userDamage,int enemyCode, char chars[], int TOT_CHARS, int &progress)
{
    ///variables
    int enemyHealth;
    int enemyDamage;
    bool userDead = false; //checks to see if user is dead
    bool enemyDead = false; // "    "   "  "  enemy "   "
    bool charLocs[12]; //will house bool status of whether or not there is a value present in the location.
    char charAtLoc[12]; //will house the appropriate char from char chars[] to be used in tandem with bool charLocs[]; % is a default value
    int totCharCorrectInput; //tracks how many correct inputs the character has inputted
    QString enemyName;
    switch (enemyCode)
    {
        case 0:
        {
            enemyName = "Innocent Mushroom";
            QPixmap enemyPic(":/Innocent_Mushroom.png");
            enemyPic = enemyPic.scaled(ui->lblPics->size(), Qt::KeepAspectRatio);
            ui->lblPics->setPixmap(enemyPic);
            ///announce to user
            ui->lstSysMsg->clear();
            ui->lstSysMsg->addItem("You encountered an " + enemyName + "!");
            ///initialize enemy damage and enemy health
            enemyHealth = 20;
            ///change max of progress bar to the enemy health and display
            ui->progHealthEnemy->setMaximum(enemyHealth);
            ui->progHealthEnemy->setVisible(true);
            ui->progHealthEnemy->setValue(enemyHealth);
            ui->progHealth->setMaximum(userHealth);
            ui->progHealth->setVisible(true);
            ui->progHealth->setValue(userHealth);
            enemyDamage = 1;
            ///display damage to user
            ui->lblUserDamage->setText(QString::number(userDamage));
            ui->lblEnemyDamage->setText(QString::number(enemyDamage));
            while (userDead != true && enemyDead !=true)
            {
                ///fill screen with chars
                fillScreen(chars, TOT_CHARS, charLocs, charAtLoc);
                ///delay the arrival
                gameDelay(7000);
                ///call chkScreen
                totCharCorrectInput = chkScreen();
                ///fill chars
                fillChars(chars, TOT_CHARS);
                ///handle damage dealt, taken, etc.
                damageTracker(enemyName, userDead, enemyDead, enemyHealth, userHealth, userDamage, enemyDamage, totCharCorrectInput, TOT_CHARS, progress);
            }//end while
            break;
        }//end case
    }//ends switch
}//end function void fightEnemy(...)

/* Handles the actual battles and attacking of the enemy
 * Pre   : gets called on by fightEnemy(...)
 * Param : QString enemyName, bool &userDead, bool &enemyDead, int &enemyHealth, int &userHealth, int &userDamage, int &enemyDamage, int totCharCorrectInput
 * Return: none
 * Post  : enemy is either defeated or user is killed
*/
void MainGame2::damageTracker(QString enemyName, bool &userDead, bool &enemyDead, int &enemyHealth, int &userHealth, int &userDamage, int &enemyDamage, int totCharCorrectInput, int TOT_CHARS, int &progress)
{
    ///user damage to enemy
    ///if value is less than 0
    if((enemyHealth - (userDamage * totCharCorrectInput)) <= 0)
    {
        ui->progHealthEnemy->setValue(0);
        enemyHealth = 0;
    }//end if
    else
    {
        enemyHealth = enemyHealth - (userDamage * totCharCorrectInput);
        if ((userDamage * totCharCorrectInput) == 0) //enemy blocked the attack
            QSound::play(":/Block.wav");
        else //enemy did not block the attack
            QSound::play(":/punch.wav");
        ui->progHealthEnemy->setValue(enemyHealth);
    }//end else
    ui->lstSysMsg->addItem("You attacked " + enemyName + " for " + QString::number(userDamage * totCharCorrectInput) + " damage!");

    ui->lstSysMsg->scrollToBottom();
    chkHealth(userHealth, enemyHealth, userDead, enemyDead);

    ///check to see if enemy is dead
    if (enemyDead == true)
    {
        ui->lstSysMsg->clear();
        ui->lstSysMsg->addItem("You attacked " + enemyName + " for " + QString::number(userDamage * totCharCorrectInput) + " damage!");
        QSound::play(":/punch.wav");
        delay(1000);
        ui->lstSysMsg->addItem("You defeated the " + enemyName + "!");
        QSound::play(":/EnemyDead.wav");
        delay (3000);
        ui->lblEnemyDamage->setVisible(false);
        return;
    }//end if
    delay (1600);

    ///enemy damage to user
    if((userHealth - (enemyDamage * (TOT_CHARS - totCharCorrectInput))) <= 0) //user has died
    {
         ui->progHealth->setValue(0);
         userHealth = 0;
         progress = -1;
    }//end if
    else
    {
         userHealth = userHealth - (enemyDamage * (TOT_CHARS - totCharCorrectInput));
         if ((enemyDamage * (TOT_CHARS - totCharCorrectInput)) == 0) //user blocked the attack
             QSound::play(":/Block.wav");
         else //user did not block the attack
             QSound::play(":/punch.wav");
         ui->progHealth->setValue(userHealth);
    }//end else
    ui->lstSysMsg->addItem(enemyName + " attacked you for " + (QString::number(enemyDamage * (TOT_CHARS - totCharCorrectInput))) + " damage!");
    ui->lstSysMsg->scrollToBottom();
    delay(2000);

    ///if value is less than 0
    chkHealth(userHealth, enemyHealth, userDead, enemyDead);
    if (userDead == true)
    {
        QSound::play(":/UserDead.wav");
        delay(2000);
        this->close();
        GameOver.show();
    }//end if
}
/* checks the screen for how many uninputted characters there are
 * Pre   : called on by void fightEnemy(...)
 * Param : none
 * Return: none
 * Post  : number of uninputted characters returned
*/
int MainGame2::chkScreen()
{
    ///variable
    int totCharCorrectInput = 0;

    ///check to see if the user has entered a correct
    for (int i = 0; i < 7; i++)
    {
            if(ui->charLoc1->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc1->setVisible(false);
                ui->charLoc1->setText("");
            }//end if
            else if(ui->charLoc2->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc2->setVisible(false);
                ui->charLoc2->setText("");
            }//end else if
            else if(ui->charLoc3->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc3->setVisible(false);
                ui->charLoc3->setText("");
            }//end else if
            else if(ui->charLoc4->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc4->setVisible(false);
                ui->charLoc4->setText("");
            }//end else if
            else if(ui->charLoc5->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc5->setVisible(false);
                ui->charLoc5->setText("");
            }
            else if(ui->charLoc6->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc6->setVisible(false);
                ui->charLoc6->setText("");
            }//end else if
            else if(ui->charLoc7->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc7->setVisible(false);
                ui->charLoc7->setText("");
            }//end else if
            else if(ui->charLoc8->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc8->setVisible(false);
                ui->charLoc8->setText("");
            }//end else if
            else if(ui->charLoc9->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc9->setVisible(false);
                ui->charLoc9->setText("");
            }//end else if
            else if(ui->charLoc10->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc10->setVisible(false);
                ui->charLoc10->setText("");
            }//end else if
            else if(ui->charLoc11->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc11->setVisible(false);
                ui->charLoc11->setText("");
            }//end else if
            else if(ui->charLoc12->text() == "*")
            {
                totCharCorrectInput++;
                ui->charLoc12->setVisible(false);
                ui->charLoc12->setText("");
            }//end else if
    }//end for

    ///set everything to invisible
    ui->charLoc1->setVisible(false);
    ui->charLoc2->setVisible(false);
    ui->charLoc3->setVisible(false);
    ui->charLoc4->setVisible(false);
    ui->charLoc5->setVisible(false);
    ui->charLoc6->setVisible(false);
    ui->charLoc7->setVisible(false);
    ui->charLoc8->setVisible(false);
    ui->charLoc9->setVisible(false);
    ui->charLoc10->setVisible(false);
    ui->charLoc11->setVisible(false);
    ui->charLoc12->setVisible(false);

    ///return
    return totCharCorrectInput;
}

/* fill screen with chars for game operations
 * Pre   : called on by void fightEnemy(...)
 * Param : char chars[]
 * Return: none
 * Post  : letters outputted to the game
*/
void MainGame2::fillScreen(char chars[], int TOT_CHARS, bool charLocs[], char charAtLoc[])
{
    ///variables
    int randNum; //will house a random number 0 - 11 to simulate which label the char will reside in
    int currentNum = 0; //will track on which position of chars[] we are on
    ///set seed
    srand(time(NULL));

    ///fill both arrays with default values
    for (int i = 0; i < 12; i ++)
        charLocs[i] = false;
    for (int i = 0; i < 12; i ++)
        charAtLoc[i] = '%';

    ///default text lbls (% sign means unoccupied)
    /// "*" means lbl at location has been solved
    /// "^" means incorrect input
    ui->charLoc1->setText("%");
    ui->charLoc2->setText("%");
    ui->charLoc3->setText("%");
    ui->charLoc4->setText("%");
    ui->charLoc5->setText("%");
    ui->charLoc6->setText("%");
    ui->charLoc7->setText("%");
    ui->charLoc8->setText("%");
    ui->charLoc9->setText("%");
    ui->charLoc10->setText("%");
    ui->charLoc11->setText("%");
    ui->charLoc12->setText("%");

    ///will decide the input of the chars at which location
    while (currentNum < TOT_CHARS)
    {
        ///value from 0 - 11 decided
        randNum = rand () % 12;
        ///check to see if there is a value present at the location
        if (charLocs[randNum] == false)
        {
            ///make the location true
            charLocs[randNum] = true;
            ///insert the value in the appropriate spot in charAtLoc
            charAtLoc[randNum] = chars[currentNum];
            currentNum++;
        }//end if

        ///value is present already
        else //if (charLocs[randNum] == true)
        {
            ///loop through until game finds a location
            while (charLocs[randNum] == true)
            {
                ///value from 0 - 11 re-decided
                randNum = rand () % 12;

                ///check location , if true
                if (charLocs[randNum] == false)
                {
                    charAtLoc[randNum] = chars[currentNum];
                    currentNum++;
                }//end if
            }//end while
            charLocs[randNum] = true;
        }//end if
    }//end while

    ///cycle through both arrays to make visible the appropriate labels
    for (int i = 0; i < 12; i++)
    {
        if(charLocs[i] != false)
        {
            switch (i)
            {
                ///if the case is true, then reset both arrays back to their default value.
                case 0:
                {
                    ui->charLoc1->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc1->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 0
                case 1:
                {
                    ui->charLoc2->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc2->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 1
                case 2:
                {
                    ui->charLoc3->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc3->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 2
                case 3:
                {
                    ui->charLoc4->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc4->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 3
                case 4:
                {
                    ui->charLoc5->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc5->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 4
                case 5:
                {
                    ui->charLoc6->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc6->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 5
                case 6:
                {
                   ui->charLoc7->setText(static_cast<QString>(charAtLoc[i]));
                   ui->charLoc7->setVisible(true);
                   charAtLoc[i] = '%';
                   charLocs[i] = true;
                   break;
                }//end case 6
                case 7:
                {
                    ui->charLoc8->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc8->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 7
                case 8:
                {
                    ui->charLoc9->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc9->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 8
                case 9:
                {
                    ui->charLoc10->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc10->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 9
                case 10:
                {
                    ui->charLoc11->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc11->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 10
                case 11:
                {
                    ui->charLoc12->setText(static_cast<QString>(charAtLoc[i]));
                    ui->charLoc12->setVisible(true);
                    charAtLoc[i] = '%';
                    charLocs[i] = true;
                    break;
                }//end case 11
            }//end switch
        }//end if
    }//end for

    ///show lnCharInput
    ui->lnCharInput->setVisible(true);
    ui->lnCharInput->setFocus();
}//end function

/* checks the health of user and enemy health; if 0, then return
 * Pre   : called on by void fightEnemy(...)
 * Param : int userhealth, int enemyHealth, bool userDead, bool enemyDead
 * Return: none
 * Post  : appropriate bool value is changed to true, depending on conditions
*/
void MainGame2::chkHealth (int userHealth, int enemyHealth, bool& userDead, bool& enemyDead)
{
    if (userHealth <= 0 && enemyHealth <= 0) ///only happens if both users take damage at the same time (will be implemented to certain enemies)
    {
        userDead = true; ///both enemy and user died. User counted as dead.
    }

    if (userHealth <= 0 || enemyHealth <= 0) ///checks to see if either user or enemy is dead
    {
        ///nested if statement to determine who died
        if (userHealth <= 0)
        {
            userDead = true; ///user is dead
        }//end if
        else ///if (enemyHealth <= 0)
        {
            enemyDead = true; ///enemy is dead
        }//ends else
    }//ends if

}//end function chkHealth

/* fills char chars[] in order to be used in battle sequences
 * Pre   : fillChars(char*, const int) is called
 * Param : char chars[]
 * Return: none
 * Post  : char chars[] gets inserted with TOT_CHARS chars
 */
void MainGame2::fillChars (char chars[], const int TOT_CHARS)
{
    ///declare int array to be inputted with letter and number values to be converted into chars
    int valChars[TOT_CHARS];

    ///call randNum(int *, const int) to fill the int array
    randNum(valChars);

    ///call transNums(int *, const int) to translate the ASCII values to characters
    transNums(valChars, chars);
}//end function fillChars(...)

/* translates values in int valChars[] into characters to be inputted into char chars[]
 * Pre   : called on by function fillChars(char *, const int)
 * Param : int valChars[], char chars[], const int TOT_CHARS -> default value
 * Return: none
 * Post  : chars are stored into char chars[]
*/
void MainGame2::transNums (int valChars[], char chars[], const int TOT_CHARS)
{
    for (int i = 0; i < TOT_CHARS; i++)
    {
        chars[i] = static_cast<char>(valChars[i]);
    }//ends for
}//end function transNums

/* Uses a random number generator in order to input values into an array valChars[], which in turn will be used for battle sequences
 * Pre   : called on by MainGame2:fillChars(char, const int)
 * Param : int valChars[] and int TOT_CHARS ***TOT_CHARS HAS A DEFAULT VALUE DECLARED IN THE FUNCTION HEADER***
 * Return: none
 * Post  : int valChars[] is filled with ASCII values
*/
void MainGame2::randNum (int valChars[], int TOT_CHARS)
{
    ///variables
    int chooser; //determines which value will be randomly generated; elaborated on below
    int ASCII; //holds a randomly generated ASCII
    struct timeval time; //used to set seed

    ///set random seed to time microseconds
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));


    ///select chooser and assign either a number's, lowerLetters, or upperLetters ASCII value
    for (int i = 0; i < TOT_CHARS; i++)
    {
        ///value from 0 - 2 decided
        chooser = rand () % 3;

        ///determine values
        switch (chooser)
        {
            ///to be used for number ASCII 48 - 57
            case 0:
                ASCII = rand() % 10 + 48;
                break;

            ///to be used for upperLetter ASCII 65 - 90
            case 1:
                ASCII = rand() % 26 + 65;
                break;

            ///to be used for lowerLetter ASCII 97 - 122
            case 2:
                ASCII = rand() % 26 + 97;
                break;
        }//ends switch
        ///insert value into valChars[i]
        valChars[i] = ASCII;
    }//ends for

}//end function randNum

/* Sends whatever is in ui->lnCharInput to be checked with functions and check to see if the correct letter was inputted
 * Pre   : called by a return detected slot; checks to see if return is pressed when lnCharInput is in focus
 * Param : none
 * Return: none
 * Post  : the char in lnCharInput is passed to the appropriate function
*/
void MainGame2::on_btnCharInput_clicked()
{
    ///check to see if a char is in lnCharInput
    if (ui->lnCharInput->text() != "*" && ui->lnCharInput->text() != "*")
    {
        ///then see if that character is present in one of the labels
        if (ui->charLoc1->text() == ui->lnCharInput->text())
        {
            ui->charLoc1->setVisible(false);
            ui->charLoc1->setText("*");
        }//end if
        else if (ui->charLoc2->text() == ui->lnCharInput->text())
        {
            ui->charLoc2->setVisible(false);
            ui->charLoc2->setText("*");
        }//end else if
        else if (ui->charLoc3->text() == ui->lnCharInput->text())
        {
            ui->charLoc3->setVisible(false);
            ui->charLoc3->setText("*");
        }//end else if
        else if (ui->charLoc4->text() == ui->lnCharInput->text())
        {
            ui->charLoc4->setVisible(false);
            ui->charLoc4->setText("*");
        }//end else if
        else if (ui->charLoc5->text() == ui->lnCharInput->text())
        {
            ui->charLoc5->setVisible(false);
            ui->charLoc5->setText("*");
        }//end else if
        else if (ui->charLoc6->text() == ui->lnCharInput->text())
        {
            ui->charLoc6->setVisible(false);
            ui->charLoc6->setText("*");
        }//end else if
        else if (ui->charLoc7->text() == ui->lnCharInput->text())
        {
            ui->charLoc7->setVisible(false);
            ui->charLoc7->setText("*");
        }//end else if
        else if (ui->charLoc8->text() == ui->lnCharInput->text())
        {
            ui->charLoc8->setVisible(false);
            ui->charLoc8->setText("*");
        }//end else if
        else if (ui->charLoc9->text() == ui->lnCharInput->text())
        {
            ui->charLoc9->setVisible(false);
            ui->charLoc9->setText("*");
        }//end else if
        else if (ui->charLoc10->text() == ui->lnCharInput->text())
        {
            ui->charLoc10->setVisible(false);
            ui->charLoc10->setText("*");
        }//end else if
        else if (ui->charLoc11->text() == ui->lnCharInput->text())
        {
            ui->charLoc11->setVisible(false);
            ui->charLoc11->setText("*");
        }//end else if
        else if (ui->charLoc12->text() == ui->lnCharInput->text())
        {
            ui->charLoc12->setVisible(false);
            ui->charLoc12->setText("*");
        }//end else if

        ///clear the ln
        ui->lnCharInput->setText("");
    }//end if
}

/* Function makes use of the QTime class and implements the current time in order to pause certain events taken from mainwindow.cpp
 * similar to main delay function, but this one implements the progress bar in the ui
 * Pre   : must be called
 * Param : int msecs
 * Return: none
 * Post  : the function will have delayed msecs milliseconds and the progress bar will have responded accordingly
*/
void MainGame2::gameDelay(int msecs)
{
    ///variables
    int timeLeft = msecs; //used in tandem with progress bar
    QTime endTime= QTime::currentTime().addMSecs(msecs);
    while( QTime::currentTime() < endTime )
    {
    ///QCoreApplication handles event loops without UIs
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }//end while
}//end function delay
