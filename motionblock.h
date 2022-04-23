#ifndef MOTIONBLOCK_H
#define MOTIONBLOCK_H

#include <block.h>
#include <motion.h>
class Player;
class Enemy;
class MotionBlock : public Motion, public Block
{
public:
    MotionBlock(qreal posx, qreal posy ,
                unsigned int width, unsigned int height,
                bool limitX = false, bool limitY = false,
                qreal xmin = 0, qreal xmax = 0,
                qreal ymin = 0, qreal ymax = 0,
                qreal velx = 0, qreal vely = 0,
                qreal accx = 0, qreal accy = 0);
    virtual ~MotionBlock() {};

    static void setPlayer(Player *newPlayer) {player = newPlayer;};
    static void setEnemies(QList<Enemy *> *newEnemies);

private:
    virtual void check() override;
    void collidesWithPlayer();
    void collidesWithEnemies();
    void checkLimits();
    void changeDirectionX();
    void changeDirectionY();
    bool limitX;
    bool limitY;
    qreal xmin;
    qreal xmax;
    qreal ymin;
    qreal ymax;
    QPointF dezplazamiento;
    static Player *player;
    static QList<Enemy*> *enemies;
};

#endif // MOTIONBLOCK_H
