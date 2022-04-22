#include "fairy.h"
#include <QFont>
#include <QDebug>
Fairy::Fairy(unsigned short world, qreal posx, qreal posy, QGraphicsItem *parent)
      :QGraphicsPixmapItem(parent)
{
    loadSprite(":/new/sprites/sprites/fairy.png",48,48);
    setPixmap(frames[0][1]);
    this->world = world;
    setPos(posx+50,posy+100);
    text = new QGraphicsTextItem;
    showSaveText();
    stepsAnimation = 200;
}

void Fairy::initText()
{
    scene()->addItem(text);
}

void Fairy::check()
{
    if(saving) animation();
}

void Fairy::animation()
{
    steps++;
    if(steps == stepsAnimation) {
        showSaveText();
    }
}

void Fairy::showSaveText()
{
    steps = 0;
    saving = false;
    text->setPlainText("Press Up '^' to save the game ^-^");
    text->setPos(x() - text->boundingRect().width()/2 + 22 , y()-25);
}

void Fairy::showFeedBack()
{
    saving = true;
    text->setPlainText("save successful ^-^");
    text->setPos(x() - text->boundingRect().width()/2 + 22 , y()-25);
}

void Fairy::saveGame(Player *player)
{
    showFeedBack();
    //guardar partida
}

bool Fairy::getSaving() const
{
    return saving;
}
