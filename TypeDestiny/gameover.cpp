#include "gameover.h"
#include "ui_gameover.h"
#include <QPalette>
gameOver::gameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOver)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Ded.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

gameOver::~gameOver()
{
    delete ui;
}
