#include "block.h"
#include "macros.h"
#include <QGraphicsScene>
Block::Block(QPointF pos, unsigned int width, unsigned int height, QObject *parent)
    : QObject{parent}
{
    setRect(0,0,width,height);
    setPos(pos);
}

Block::Block(qreal posx, qreal posy, unsigned int width, unsigned int height, bool matriz, QObject *parent)
    : QObject{parent}
{
    if(matriz) {
        setRect(0,0,width*SB, height*SB);
        setPos(posx*SB, posy*SB);
    }
    else {
        setRect(0,0,width,height);
        setPos(posx, posy);
    }
}

void Block::update()
{
    for (int i = 0; i<blocks->size(); i++) {
        blocks->at(i)->check();
    }
}

void Block::check()
{
    return;
}

void Block::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
}
