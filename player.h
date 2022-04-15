#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <sprite.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Weapon;
class HealthBar;
class Block;
class Bow;
class Player : public QObject, public QGraphicsPixmapItem, public Sprite, public Motion
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);

    bool getAir() const;
    void setAir(bool newAir);
    void setWeapon(Weapon *newWeapon);
    Weapon *getWeapon() const;


public:
    void move(); //corregir el movimiento del Pj.
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
    void setBlocks(QVector<Block*> *newBlocks);  
    void setBow(Bow *newBow);

    Bow *getBow() const;

private:
    void keyPressEvent(QKeyEvent *event) override;
    void collisionsY();
    void collisionsX();
    bool state;
    bool jump;
    bool inmu;
    short direction;
    int *health;
    int *maxHealth;
    HealthBar *healthBar;
    Bow *bow;
    Weapon *weapon;
    QVector<Block*> *blocks;
};

#endif // PLAYER_H
