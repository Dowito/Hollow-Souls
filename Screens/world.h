#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
class World : public QGraphicsScene
{
public:
    World(int w, int h);
    void loadWorld(unsigned short label);

private:
    void clearWorld();

};

#endif // WORLD_H
