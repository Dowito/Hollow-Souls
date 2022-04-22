#include "menu.h"

Menu::Menu()
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/new/sprites/sprites/Night.png")));
    start = new QPushButton;
    start->setText("New Game");
    start->setGeometry(0,0,200,30);
    start->show();
}
