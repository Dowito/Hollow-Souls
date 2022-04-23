#ifndef ARROW_H
#define ARROW_H

#include <motion.h>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
class Player;
class Block;
class Enemy;
class Arrow : public QGraphicsRectItem, public Motion
{
public:
    Arrow(qreal posx, qreal posy, qreal velx, qreal vely, qreal atk, bool from = true);
    virtual ~Arrow() {};

    static void update();
    void check();    

    static void setPlayer(Player *newPlayer);
    static void setBlocks(QVector<Block *> *newBlocks);
    static void setEnemies(QList<Enemy *> *newEnemies);
    static void setArrows(QList<Arrow *> *newArrows);

private:
    void move();
    void collidesWithPlayer();
    void collidesWithEnemy();
    void collidesWithBlock();
    void die();
    short direction;
    int atk;
    bool state; //Necesario para que se elimina al final de hacer el checkeo para no generar problemas con la memoria.
    bool from; //true=disparada por el player, false=disparada por el enemigo
    static Player *player;
    static QList<Enemy*> *enemies;
    static QVector<Block*> *blocks;
    static QList<Arrow*> *arrows;
};

#endif // ARROW_H
