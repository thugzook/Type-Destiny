#ifndef MAINGAME2_H
#define MAINGAME2_H

#include <QWidget>
#include <QString>
#include "gameover.h"
namespace Ui {
class MainGame2;
}

class MainGame2 : public QWidget
{
    Q_OBJECT

public:
    explicit MainGame2(QWidget *parent = 0);
    ~MainGame2();
    bool charDestroyed; //will track whether user has typed a char within the alotted time limit


public slots:
    void onReturnPressed(const QString &userName);


private slots:
    void delay(int msecs);
    void displayBackground();
    void startGame();
    void fillChars(char chars[], const int TOT);
    void randNum (int valChars[] , int TOT_CHARS = 7); //default value assigned to TOT_CHARS
    void transNums (int valChars[], char chars[], int TOT_CHARS = 7); //default value assigned to TOT_CHARS
    void chkHealth (int userHealth, int enemyHealth, bool& userDead, bool& enemyDead);
    void createBattle(int &userHealth, int &userDamage, char chars[], int &progress, int TOT_CHARS, QString finalName);
    void fightEnemy(int &userHealth, int &userDamage, int enemyCode, char chars[], int TOT_CHARS, int &progress);
    void on_btnCharInput_clicked();
    void fillScreen(char chars[], int TOT_CHARS, bool charLocs[], char charAtLoc[]);
    void gameDelay(int msecs);
    int chkScreen();
    void damageTracker(QString enemyName, bool &userDead, bool &enemyDead, int &enemyHealth, int &userHealth, int &userDamage, int &enemyDamage, int totCharCorrectInput, int TOT_CHARS, int &progress);
private:
    Ui::MainGame2 *ui;
    gameOver GameOver;

};

#endif // MAINGAME2_H
