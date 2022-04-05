#include "game.h"

Game::Game(QWidget *parent)
{
    setParent(parent);
    setScene(new QGraphicsScene);
}
