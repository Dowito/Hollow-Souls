#ifndef WEAPON_H
#define WEAPON_H

#include <sprite.h>
class Game;
class Player;
class Weapon : public Sprite
{
    Q_OBJECT
public:
    Weapon(Player *owner, QObject *parent = nullptr);
    void attack();

    bool getUsable() const;

    unsigned short getAtk() const;

private slots:
    void animation();

private:
    //QString type;
    bool usable;
    unsigned int steps;
    int atk;
    Player *owner;
    QTimer *timer;
};

#endif // WEAPON_H
