#ifndef ENEMY_H
#define ENEMY_H

#include <motion.h>
class Player;
class HealthBar;
class Enemy : public Motion
{
    Q_OBJECT
public:
    Enemy(QObject *parent = nullptr);
    Enemy(QString name, float px, float py, QObject *parent = nullptr);

private:
    void move();
    void collisionsPlayer();
    void collisionsWeapon();
    void changeDirectionX();
    void damage(int damage);
    virtual void attack();
    bool state;
    bool inmu;
    int atk;
    int health;
    Player *player;
};

#endif // ENEMY_H
