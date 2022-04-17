#include "world.h"
#include <game.h>
#include "block.h"
#include "enemy.h"
#include "arrow.h"
#include "player.h"
#include "furry.h"
#include "bow.h"
#include "healthbar.h"
//extern Game *game; por alguna razon el extern no me funcionaba
void World::loadWorld(unsigned short label)
{
    clearWorld();
    switch (label) {
        case 0: {
            //stop timer por fuera o en pantalla de carga
            //quitarle focus al player por fuera            
            //poner fondo
            setSceneRect(0,0,38*SB,9*SB);
            addItem(new Block(50,50,250,50));
            Block *arrBlock[11] = {new Block(0,0,38,3,true), new Block(0,3,3,2,true), new Block(0,5,4,4,true), new Block(3,3,1,1,true), new Block(4,7,2,2,true), //parteizquierda
                                   new Block(6,5,16,4,true), new Block(15,3,4,1), new Block(22,6,4,3), new Block(26,5,12,4), new Block(34,3,4,1), new Block(35,4,3,1)}; //parte derecha
            for (int i = 0; i<11; i++) {
                game->blocks->push_back(arrBlock[i]);
                addItem(arrBlock[i]);
            }
            //poniendo jugador en la nueva scena
            addItem(game->player);
            game->player->setPos(12*SB, 4*SB);
            game->player->setRPos(game->player->pos());
            addItem(game->player->getHealthBar());
            addItem(game->player->getHealthBar()->getUpdateHealth()); //que se actualize constantemente segun la posicion del GV
            //game->player->getHealthBar()->startHealthBar();
            addItem(game->player->getBow());
            //Weapon al tacar se actualiza con la escena del player.
            //addItem(game->player->getBow()); //necesita estar dentro de la misma scenea, al dispara alterna entre estar visible y no estarlo y actualia la pos segun quien la disparo en ese momento
            //game->player->getHealthBar()->startHealthBar();
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
