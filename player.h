#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
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
    void takeDamage(int damage);

    void setJump(bool newJump);
    bool getInmu() const;    

    void setHealthBar(HealthBar *newHealthBar);
    HealthBar *getHealthBar() const;

    int *getHealth() const;
    void setHealth(int newHealth);
    int *getMaxHealth() const;
    void setMaxHealth(int newMaxHealth);

private slots:
    virtual void move();
    void framesInmu();

private:
    void keyPressEvent(QKeyEvent *event);
    bool jump;
    bool inmu;
    int *health;
    int *maxHealth;
    HealthBar *healthBar;
    Weapon *weapon;
};

#endif // PLAYER_H
