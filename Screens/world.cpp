#include "world.h"
#include "game.h"
#include "block.h"
#include "enemy.h"
#include "arrow.h"
#include "player.h"
extern Game *game;
World::World(int w, int h)
{
    setSceneRect(0,0,w,h);
}

void World::loadWorld(unsigned short label)
{
    switch (label) {
        case 0: {
            //stop timer por fuera o en pantalla de carga
            //quitarle focus al player por fuera
            clearWorld();
            //poner fondo
            setSceneRect(0,0,38*SB,9*SB);
            Block *arrBlock[17] = {new Block(0*SB,0*SB,38,3), new Block(6*SB,5*SB,16,1)};
            for (int i = 0; i<2; i++) {
                game->blocks->push_back(arrBlock[i]);
                addItem(arrBlock[i]);
            }
            addItem(game->player);
            game->player->setPos(14*SB, 3*SB);
            //setSceneRect(game->player->x(), game->player->y(), width(), height());
            //cargar enemigos
            //cargar NextLebel
            //cargar muros invisibles
            //setPos al player
            //poner en pantalla
            //iniciar timer por fuera
            break;
        }
        case 1: {
            //carga mapa 1
            break;
        }
        case 2: {
            //carga mapa 1
            break;
        }
        default: {
            break;
        }
    }
}

void World::clearWorld()
{
    clear();
    for (int i = 0; i<game->enemies->size(); i++) {
        delete game->enemies->at(i);
    }game->enemies->clear();
    for (int i = 0; i<game->blocks->size(); i++) {
        delete game->blocks->at(i);
    }game->blocks->clear();
    for (int i = 0; i<game->arrows->size(); i++) {
        delete game->arrows->at(i);
    }game->arrows->clear();
}
