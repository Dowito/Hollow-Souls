#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
class Game;
class World : public QGraphicsScene
{
public:
    World(Game *game) { this->game = game;};
    void loadWorld(unsigned short label);

private:
    void clearWorld();
    Game *game;

};

#endif // WORLD_H
