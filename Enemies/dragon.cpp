#include "dragon.h"
#include "game.h"
#include "player.h"
#include "QGraphicsView"
extern Game *game;
Dragon::Dragon(qreal posx, qreal posy, short direction, qreal amplitud, qreal frequency, qreal phase, qreal velx)
    :Enemy(posx-24, posy-24, 1, 4, direction),
    SimpleHarmonicMotion(amplitud, frequency, phase, velx)
{
    loadSprite(":/new/sprites/sprites/dragon.png",48,48,2,3);
    setPixmap(frames[direction-1][1]);
    setOffset(posx,posy);
    if(direction == 1) v.setX(v.x()*-1);
    spawner = false;
}

Dragon::Dragon(bool spawner, unsigned int stepsToSpawn): Enemy(0,0,9999,0,0,true,true)
{
    this->spawner = spawner;
    setPos(0,0);
    steps = 0;
    this->stepsToSpawn = stepsToSpawn;
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
    if(spawner){
        if(steps == stepsToSpawn){
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
            steps = 0;
        }
        else steps++;
    }
}

void Dragon::attack()
{
    return;
}
