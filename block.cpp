#include "block.h"
#include <QGraphicsScene>
Block::Block(QPointF pos, unsigned int width, unsigned int height, QObject *parent)
    : QObject{parent}
{
    setRect(0,0,width,height);
    setPos(pos);
}

Block::Block(qreal posx, qreal posy, unsigned int width, unsigned int height, QObject *parent)
    : QObject{parent}
{
    setRect(0,0,width,height);
    setPos(posx, posy);
}
