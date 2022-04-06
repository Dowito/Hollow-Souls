#include <QApplication>
#include <game.h>
#include <thebox.h>
#include "ui_thebox.h"
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    //game->show();
    TheBox *thebox = new TheBox();
    thebox->show();
    return a.exec();
}
