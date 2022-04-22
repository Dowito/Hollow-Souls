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
class Dash;
class Fairy;
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
    void check() override;
    void move();
    void moveX();
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
    void setCarcaj(unsigned short newCarcaj);
    int getCarcaj() const;
    short getDirection() const;
    void setDash(Dash *newDash);
    Dash *getDash() const;
    void setInmu(bool newInmu);

    bool leverOn;

    void setFairy(Fairy *newFairy);

    const QString &getUser() const;
    void setUser(const QString &newUser);

private:
    void keyPressEvent(QKeyEvent *event) override;
    unsigned short calculatedFrame();
    void collisionsY();
    void collisionsX();
    void updateHealthBarPos();
    bool state;
    bool jump;
    bool inmu;
    short direction;
    int *health;
    int *maxHealth;
    unsigned short carcaj;
    QString user = "David";
    HealthBar *healthBar;
    Dash *dash;
    Bow *bow;
    Weapon *weapon;
    QVector<Block*> *blocks;
    Fairy *fairy;
};

#endif // PLAYER_H
