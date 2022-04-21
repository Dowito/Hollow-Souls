#ifndef AUDHULMA_H
#define AUDHULMA_H

#include "enemy.h"
class Audhulma : public Enemy
{
public:
    Audhulma(qreal posx = 13*SB+15, qreal posy = 7*SB+30);
    virtual ~Audhulma() {};

private:
    unsigned short delay;
    void inmulateFloor();
    void fireBall();
    void calculateDirectionPlayer();
    void limitPlayer();
    bool limit;
    QPointF directionPlayer;


    // Enemy interface
public:
    void check();
    QPointF getDirectionPlayer() const;

protected:
    void attack();
};

#endif // AUDHULMA_H
