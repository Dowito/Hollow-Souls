#include "lever.h"
#include "block.h"
#include "player.h"
Lever::Lever(qreal posx, qreal posy)
    :Enemy(posx,posy,1,0)
{
    loadSprite(":/new/sprites/sprites/lever.png",48,48,4,1);
    setPixmap(frames[0][0]);
    if(player->leverOn) state = false;
}

void Lever::ON()
{
    setPixmap(frames[3][0]);
    state = true;
    player->leverOn = true;
    Block *block = new Block(4,5,2,1);
    block->setBrush(QBrush(QImage(":/new/sprites/sprites/texture_rock.png")));
    scene()->addItem(block);
}

void Lever::check()
{
    if(!state){
        ON();
    }
}

void Lever::attack()
{
    return;
}
