#ifndef FAIRY_H
#define FAIRY_H

#include <QGraphicsView>
#include "sprite.h"
#include <QGraphicsTextItem>
class Player;
class Fairy
{
public:
    Fairy();

private:
    void showFeedBack();
    void showSaveText();
    void saveGame(Player *player);
    unsigned short world;
    QString file; //nombre del archivo a guardar
    QGraphicsTextItem *text;
};

#endif // FAIRY_H
