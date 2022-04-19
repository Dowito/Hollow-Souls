#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
class Game;
class World : public QGraphicsScene
{
public:
    World(Game *game) { this->game = game;};
    void loadWorld(unsigned short label, QPointF posPlayer);
    void initPlayer();

private:
    void clearWorld();
    void updatePosPlayer(QPointF pos);
    Game *game;

};

#endif // WORLD_H
