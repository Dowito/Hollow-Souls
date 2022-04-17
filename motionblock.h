#ifndef MOTIONBLOCK_H
#define MOTIONBLOCK_H

#include <block.h>
#include <motion.h>
class MotionBlock : public Motion, public Block
{
public:
    MotionBlock(qreal posx, qreal posy ,
                unsigned int width, unsigned int height,
                qreal velx = 0, qreal vely = 0,
                qreal accx = 0, qreal accy = 0,
                QObject *parent = nullptr);

private:
    virtual void check() override;
};

#endif // MOTIONBLOCK_H
