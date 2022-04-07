#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <QKeyEvent>
#include <QVector>
class Weapon;
class Block;
class HealthBar;
class Player : public Motion
{
    Q_OBJECT
public:
    Player();

    bool getAir() const;
    void setAir(bool newAir);

    void setWeapon(Weapon *newWeapon);

    void setHealth(HealthBar *newHealth);

    HealthBar *getHealth() const;

private slots:
    virtual void move();
    void calculateAcelerationTest();

private:
    void keyPressEvent(QKeyEvent *event);
    bool jump;
    bool inmu;
    HealthBar *health;
    Weapon *weapon;
    QVector<Block*> *blocks;
};

#endif // PLAYER_H
