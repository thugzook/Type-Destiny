#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maingame.h"
#include <QLineEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnSplash_clicked();
    void delay(double msecs);
    void cycleBackground();

private:
    Ui::MainWindow *ui;
    MainGame mainGame;
};

#endif // MAINWINDOW_H
