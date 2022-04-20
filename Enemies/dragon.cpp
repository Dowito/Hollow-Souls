#include "dragon.h"
#include "game.h"
#include "QGraphicsView"
extern Game *game;
Dragon::Dragon(qreal posx, qreal posy, short direction, qreal amplitud, qreal frequency, qreal phase, qreal velx)
    :Enemy(posx-24, posy-24, 10, 10, direction),
    SimpleHarmonicMotion(amplitud, frequency, phase, velx)
{
    loadSprite(":/new/sprites/sprites/dragon.png",48,48,2,3);
    setPixmap(frames[direction-1][1]);
    setOffset(posx,posy);
    if(direction == 1) v.setX(v.x()*-1);
    spawner = false;
}

Dragon::Dragon(bool spawner): Enemy(0,0,9999,0,0,true,true)
{
    this->spawner = spawner;
}

void Dragon::check()
{
    if(spawner) spawn();
    else if(state){
        move();
        limitScene();
        collidesWithWeapon();
        collidesWithPlayer();
    }
    else die();
}

void Dragon::move()
{
    calculatePos();
    setPos(r);
}

void Dragon::limitScene()
{
    QPointF posScene = offset() + pos();
    if(posScene.x()+50 < 0 || posScene.x() > scene()->width()) {
        state = false;
    }
}

void Dragon::spawn()
{
    static unsigned int delay = 0;
    if(spawner){
            if(delay == 200){
            //65+rand()%(91-65);//genera numeros aleatorios en el rango de 65-90
            short direction;
            qreal posx = 0+rand()%(2-0);
            qreal posy = 50+rand()%((721-50)-50);
            (posx == 0) ? direction = 2 : direction = 1;
            (posx == 0) ? posx = 0-50 : posx = game->width()+50;
            QPointF pos = {posx,posy};
            pos = game->mapToScene(pos.toPoint());
            qreal amplitud = 100+rand()%(331-150);
            qreal frequency = 6+rand()%(11-6);
            frequency /= 1000;
            qreal phase = 0+rand()%(180-0);
            phase = qDegreesToRadians(phase);
            scene()->addItem(new Dragon(pos.x(),pos.y(),direction,amplitud,frequency,phase));
            delay = 0;
        }
        else delay++;
    }
}

void Dragon::attack()
{
    return;
}
