#include "arrow.h"
#include <enemy.h>
#include <player.h>
#include <block.h>
#include <QGraphicsScene>
Arrow::Arrow(qreal posx, qreal posy, qreal velx, qreal vely, qreal atk)
    :Motion(posx, posy, velx, vely)
{
    setRect(0,0,48,5);
    setPos(posx, posy);
    this->atk = atk;
    state = true;
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
    collidesWithBlock();
    if(from) { //si es disparada por el jugador, interactua con los enemigos
        collidesWithEnemy();
    }
    else { //si es disparada por el enemigo, interactua con el jugado
        collidesWithPlayer();
    }
    if(!state) die();
}

void Arrow::move()
{
    calculatePos();
    setPos(r);
}

void Arrow::collidesWithPlayer()
{
    if (collidesWithItem(player)) {
        if (!player->getInmu()) {
            player->takeDamage(atk);
            state = false;
        }
    }
}

void Arrow::collidesWithEnemy()
{
    if(state){
        for (int i = 0; i<enemies->size(); i++) {
            if (collidesWithItem(enemies->at(i))) {
                enemies->at(i)->takeDamage(atk);
                state = false;
                break;
            }
        }
    }
}

void Arrow::collidesWithBlock()
{
    if(state) {
        for (int i = 0; i < blocks->size(); i++) {
            if(collidesWithItem(blocks->at(i))){
                state = false;
                break;
            }
        }
    }
}

void Arrow::die()
{
    if(from) player->setCarcaj(player->getCarcaj()+1);
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

