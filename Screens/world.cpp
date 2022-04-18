#include "world.h"
#include <game.h>
#include "block.h"
#include "enemy.h"
#include "arrow.h"
#include "player.h"
#include "furry.h"
#include "bow.h"
#include "spike.h"
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
            //dimenciones de la escena
            setSceneRect(0,0,38*SB,9*SB);
            //Bloques
            Block *arrBlock[11] = {new Block(0,0,38,3,true), new Block(0,3,3,2,true), new Block(0,5,4,4,true), new Block(3,3,1,1,true), new Block(4,7,2,2,true), //parteizquierda
                                   new Block(6,5,16,4,true), new Block(15,3,4,1), new Block(22,6,4,3), new Block(26,5,12,4), new Block(34,3,4,1), new Block(35,4,3,1)}; //parte derecha
            for (int i = 0; i<11; i++) {
                //game->blocks->push_back(arrBlock[i]);
                addItem(arrBlock[i]);
            }
            //Enemigos
            Enemy *arrEnemy[4] = {new Furry(23*SB,5*SB), new Furry(29*SB,4*SB, 26*SB, 32*SB, true),
                                  new Spike(4*SB, 6*SB, 6*SB, 4*SB), new Spike(5*SB, 6*SB, 6*SB, 4*SB)};
            for (int i = 0; i<4; i++) {
                //game->enemies->push_back(arrEnemy[i]);
                addItem(arrEnemy[i]);
            }
            //cargar muros invisibles

            //poniendo jugador en la nueva scena
            addItem(game->player);
            game->player->setPos(12*SB, 4*SB);
            game->player->setRPos(game->player->pos()); //actualiza su posicion
            addItem(game->player->getHealthBar()); //poner la health en la nueva escena
            addItem(game->player->getHealthBar()->getUpdateHealth()); //que se actualize constantemente segun la posicion del GV
            addItem(game->player->getBow()); //Siempre se debe de actualizar cuando se cambia de escena
            //cargar Door
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
