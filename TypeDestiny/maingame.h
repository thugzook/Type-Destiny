#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include "maingame2.h"
namespace Ui {
class MainGame;
}

class MainGame : public QWidget
{
    Q_OBJECT

public:
    explicit MainGame(QWidget *parent = 0);
    ~MainGame();
    ///public variable to be sent to maingame2
    QString userName;
    ///detects key press; namely return button
    QKeyEvent *key;


private slots:
    void getText( QString &userName);
    void on_btnConfirm_clicked();

private:
    Ui::MainGame *ui;
    MainGame2 mainGame2;

signals:
    void returnPressed(const QString &userName);
};

#endif // MAINGAME_H
