#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
class Game;
class World : public QGraphicsScene
{
public:
    World(Game *game) { this->game = game;};
    void loadWorld(unsigned short label, qreal posx, qreal posy);

private:
    void clearWorld();
    void initPlayer(qreal posx, qreal posy);
    Game *game;

};

#endif // WORLD_H
