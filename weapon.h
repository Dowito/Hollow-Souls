#ifndef WEAPON_H
#define WEAPON_H

#include <sprite.h>
#include <QGraphicsPixmapItem>
class Game;
class Player;
class Weapon : public Sprite
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
    unsigned int steps;
    int atk;
    short direction;
    Player *owner;
    QTimer *timer;
};

#endif // WEAPON_H
