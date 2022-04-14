#include "arrow.h"
#include <enemy.h>
#include <player.h>
#include <block.h>
#include <QGraphicsScene>
Arrow::Arrow(qreal posx, qreal posy, qreal velx, qreal vely, qreal atk)
    :Motion(posx, posy, velx, vely)
{
    setRect(40,40,40,40);
    setPos(posx, posy);
    this->atk = atk;
    arrows->push_back(this);
}

void Arrow::update()
{
    for (int i = 0; i<arrows->size(); i++) {
        arrows->at(i)->check();
    }
}

void Arrow::check()
{
    move();
}

void Arrow::move()
{
    calculatePos();
    setPos(r);
}

void Arrow::collidesWithPlayer()
{
    if (collidesWithItem(player)) {
        if (!player->getInmu()) player->takeDamage(atk);
    }
}

void Arrow::collidesWithEnemy()
{
    for (int i = 0; i<enemies->size(); i++) {
        if (collidesWithItem(enemies->at(i))) {
            if (!player->getInmu()) enemies->at(i)->takeDamage(atk);
        }
    }
}

void Arrow::collidesWithBlock()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            die();
            break;
        }
    }
}

void Arrow::die()
{
    arrows->removeOne(this);
    scene()->removeItem(this);
    delete this;
}

void Arrow::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Arrow::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
}

void Arrow::setEnemies(QList<Enemy *> *newEnemies)
{
    enemies = newEnemies;
}

void Arrow::setArrows(QList<Arrow *> *newArrows)
{
    arrows = newArrows;
}
