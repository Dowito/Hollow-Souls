#ifndef CIRCULARBLOCK_H
#define CIRCULARBLOCK_H

#include <circularmotion.h>
#include <block.h>
class CircularBlock : public Block, public CircularMotion
{
public:
    CircularBlock(qreal posx, qreal posy,
                  unsigned int width,
                  unsigned int height,
                  float radio,
                  unsigned short direction,
                  float angularVel,
                  float angularAcc = 0);
};

#endif // CIRCULARBLOCK_H
