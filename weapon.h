#ifndef WEAPON_H
#define WEAPON_H

#include <sprite.h>
#include <QObject>
#include <QGraphicsPixmapItem>
class Game;
class Player;
class Weapon : public QObject, public Sprite, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Weapon(Player *owner, QObject *parent = nullptr);
    void attack();
    void animation();

    bool getAttacking() const;
    unsigned short getAtk() const;
    short getDirection() const;

private:
    bool attacking;
    unsigned int steps; //contador hasta terminar la animacion
    int atk;
    short direction;
    Player *owner;
};

#endif // WEAPON_H
