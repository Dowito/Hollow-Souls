#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <QKeyEvent>
#include <QVector>
class Weapon;
class Block;
class Player : public Motion
{
    Q_OBJECT
public:
    Player();

    bool getAir() const;
    void setAir(bool newAir);

    void setWeapon(Weapon *newWeapon);

private slots:
    virtual void move();
    void calculateAcelerationTest();

private:
    void keyPressEvent(QKeyEvent *event);
    bool jump;
    Weapon *weapon;
    QVector<Block*> *blocks;
};

#endif // PLAYER_H
