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

private slots:    
    void animation();

private:
    //QString type;
    bool usable;
    unsigned int steps;
    unsigned short atk;
    Player *owner;
    QTimer *timer;
};

#endif // WEAPON_H
