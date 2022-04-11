#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QVector>

class Weapon;
class HealthBar;
class Player : public Motion
{
    Q_OBJECT
public:
    Player();

    bool getAir() const;
    void setAir(bool newAir);
    void setWeapon(Weapon *newWeapon);
    Weapon *getWeapon() const;


public:
    virtual void move();
    void takeDamage(int damage);
    void framesInmu();

    void setJump(bool newJump);
    bool getInmu() const;    

    void setHealthBar(HealthBar *newHealthBar);
    HealthBar *getHealthBar() const;

    int *getHealth() const;
    void setHealth(int newHealth);
    int *getMaxHealth() const;
    void setMaxHealth(int newMaxHealth);

private slots:


private:
    void keyPressEvent(QKeyEvent *event);
    bool state;
    bool jump;
    bool inmu;
    int *health;
    int *maxHealth;
    HealthBar *healthBar;
    Weapon *weapon;
};

#endif // PLAYER_H
