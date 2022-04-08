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
    void setHealth(HealthBar *newHealth);
    HealthBar *getHealth() const;

public:
    void takeDamage(int damage);

private slots:
    virtual void move();

private:
    void keyPressEvent(QKeyEvent *event);
    bool jump;
    bool inmu;
    int playerHealth;
    int maxPlayerHealth;
    HealthBar *health;
    Weapon *weapon;
};

#endif // PLAYER_H
