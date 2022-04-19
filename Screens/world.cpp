#include "world.h"
#include <game.h>
#include "block.h"
#include "enemy.h"
#include "arrow.h"
#include "player.h"
#include "furry.h"
#include "bow.h"
#include "demon.h"
#include "spike.h"
#include "healthbar.h"
#include "motionblock.h"
#include "Utilities/portal.h"
void World::loadWorld(unsigned short label, QPointF posPlayer)
{
    clearWorld();//limpia todos los contenedores
    QVector<Block*> vecBlocks;
    QVector<Enemy*> vecEnemies;
    QVector<Portal*> vecPortals;
    switch (label) {
        case 0: {   
            //poner fondo

            //dimenciones de la escena
            setSceneRect(0,0,38*SB,9*SB);
            //Bloques
            vecBlocks = {new Block(0,0,38,3,true), new Block(0,3,3,2,true), new Block(0,5,4,4,true), new Block(3,3,1,1,true), new Block(4,7,2,2,true), //parteizquierda
                         new Block(6,5,16,4,true), new Block(15,3,4,1), new Block(22,6,4,3), new Block(26,5,12,4), new Block(34,3,4,1), new Block(35,4,3,1)}; //parte derecha
            //Enemigos
            vecEnemies = {new Furry(23*SB,5*SB), new Furry(29*SB,4*SB, 26*SB, 32*SB, true),
                          new Spike(4*SB, 100+6*SB, 6*SB, 4*SB), new Spike(5*SB, 100+6*SB, 6*SB, 4*SB)};
            //Portals
            vecPortals = {new Portal(34*SB+100, 4*SB+100, 6*SB+100, 11*SB+100, 1)};
            break;
        }
        case 1: {
            //poner fondo

            //dimenciones de la escena
            setSceneRect(0,0,25*SB,16*SB);
            //Bloques
            vecBlocks = {new Block(0,0,25,3), new Block(0,3,5,2), new Block(0,5,4,1), new Block(0,6,7,5), new Block (0,11,6,2), new Block(0,13,25,3),
                         new Block(6,12,2,1), new Block(13,12,8,1), new Block(16,3,4,8), new Block(21,3,4,10), new Block(11,11,1,1), new Block(12*SB,9*SB,2*SB,50,false),
                         new Block(11,6,1,1), new Block(9*SB,5*SB,1*SB,50,false), new Block(7,6,1,1),
                         new MotionBlock(+50+8*SB,11*SB,-100+3*SB,50,false,true,0,0,8*SB,11*SB+50,0,-7),
                         new MotionBlock(13*SB,8*SB,2*SB,50,false,true,0,0,5*SB,8*SB,0,-7)};
            //Enemies
            vecEnemies = {new Furry(9*SB,10*SB,+50+8*SB,50+10*SB,true), new Furry(14*SB,7*SB,13*SB,-48+15*SB,true), new Furry(10*SB,12*SB),
                          new Demon(13*SB+54, 8*SB+54,1), new Demon(6*SB,5*SB+54,2)};
            //Portals
            vecPortals = {new Portal(6*SB, 11*SB+100, 34*SB, 4*SB+100, 0), new Portal(4*SB,5*SB+100,16*SB,17*SB+100,2)};
            break;
        }
        case 2: {
            //poner fondo

            //dimeciones escena
            setSceneRect(0,0,22*SB,22*SB);
            //bloques - pintar, texturas
            vecBlocks = {new Block(14,18,8,1), new Block(17,17,5,1), new Block(16,7,6,10), new Block(8,19,14,3), new Block(7,18,1,4), new Block(6,17,1,5),
                        new Block(0,11,6,11), new Block(0,9,7,2), new Block(0,8,5,1), new Block(0,3,6,5), new Block(0,0,22,3), new Block(16,3,6,3),
                        new Block(17,6,5,1), new Block(12,7,4,1),
                        new Block(11,14,2,3), new Block(14,13,1,1), new Block(15*SB,12*SB,SB,50,false), new Block(12,11,2,1),
                        new MotionBlock(8*SB,14*SB,2*SB,50,false,true,0,0,13*SB,17*SB,0,-7),
                        new MotionBlock(8*SB,5*SB,3*SB,SB,false,true,0,0,5*SB,11*SB,0,10)};
            //enemies
            vecEnemies = {new Furry(9*SB,18*SB)};
            //portal
            vecPortals = {};
            break;
        }
        default: {
            //poner fondo

            //dimeciones escena
            setSceneRect(0,0,SB,SB);
            //bloques - pintar, texturas
            vecBlocks = {};
            //enemies
            vecEnemies = {};
            //portal
            vecPortals = {};
            break;
        }        
    }
    for (auto block : qAsConst(vecBlocks)) {
        addItem(block);
    }
    for (auto enemy: qAsConst(vecEnemies)) {
        addItem(enemy);
    }
    for (auto portal : qAsConst(vecPortals)) {
        addItem(portal);
    }
    updatePosPlayer(posPlayer);
}

void World::clearWorld()
{
    for (int i = 0; i<game->enemies->size(); i++) {
        removeItem(game->enemies->at(i));
        delete game->enemies->at(i);
    }
    game->enemies->clear();
    for (int i = 0; i<game->blocks->size(); i++) {
        removeItem(game->blocks->at(i));
        delete game->blocks->at(i);
    }
    game->blocks->clear();
    for (int i = 0; i<game->arrows->size(); i++) {
        removeItem(game->blocks->at(i));
        delete game->arrows->at(i);
    }
    game->arrows->clear();
}

void World::updatePosPlayer(QPointF pos)
{
    game->player->setPos(pos);
    game->player->setRPos(game->player->pos());
}

void World::initPlayer()
{
    addItem(game->player);
    addItem(game->player->getHealthBar());
    addItem(game->player->getHealthBar()->getUpdateHealth()); //que se actualize constantemente segun la posicion del GV
    addItem(game->player->getBow());
}
