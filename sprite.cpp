#include "sprite.h"
#include <macros.h>
Sprite::Sprite(QObject *parent)
    : QObject{parent}
{

}

void Sprite::setSprite(QString spriteName)
{
    sprite.load(spriteName);
}

void Sprite::setFrame(unsigned int typeX, unsigned int typeY)
{
    frame = sprite.copy(typeX*w, typeY*h, w, h).scaled(GAME_SCALE, GAME_SCALE);
}

void Sprite::setSize(unsigned int w, unsigned int h)
{
    this->w = w;
    this->h = h;
}
