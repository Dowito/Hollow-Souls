#include "world.h"
#include <game.h>
#include "block.h"
#include "enemy.h"
#include "arrow.h"
#include "player.h"
#include "furry.h"
#include "Enemies/audhulma.h"
#include "Enemies/dragon.h"
#include "bow.h"
#include "demon.h"
#include "spike.h"
#include "Utilities/fairy.h"
#include "Enemies/saw.h"
#include "healthbar.h"
#include "Utilities/lever.h"
#include "motionblock.h"
#include "Utilities/portal.h"
#include "QGraphicsTextItem"

#define forest ":/new/sprites/sprites/Forest.png"
#define lava ":/new/sprites/sprites/Lava.png"
#define clouds ":/new/sprites/sprites/Clouds.png"
#define dark_clouds ":/new/sprites/sprites/DarkClouds.png"
#define texture_rock ":/new/sprites/sprites/texture_rock.png"
#define texture_forest ":/new/sprites/sprites/texture_forest.png"
#define texture_lava ":/new/sprites/sprites/texture_lava.png"
void World::loadWorld(unsigned short label, QPointF posPlayer)
{
    clearWorld();//limpia todos los contenedores
    QVector<Block*> vecBlocks;
    QVector<Enemy*> vecEnemies;
    QVector<Portal*> vecPortals;
    QBrush texture;
    switch (label) {
        case 0: {   
            //dimenciones de la escena
            setSceneRect(0,0,38*SB,9*SB);
            //poner fondo
            setBackgroundBrush(QBrush(QImage(clouds)));
            //Bloques
            texture.setTextureImage(QImage(texture_rock));
            vecBlocks = {new Block(0,0,38,3,true), new Block(0,3,3,2,true), new Block(0,5,4,4,true), new Block(3,3,1,1,true), new Block(4,7,2,2,true), //parteizquierda
                         new Block(6,5,16,4,true), new Block(15,3,4,1), new Block(22,6,4,3), new Block(26,5,12,4), new Block(34,3,4,1), new Block(35,4,3,1)}; //parte derecha
            //Enemigos
            vecEnemies = {new Furry(23*SB,5*SB), new Furry(29*SB,4*SB, 26*SB, 32*SB, true),
                         new Spike(4*SB, 100+6*SB, 6*SB, 4*SB), new Spike(5*SB, 100+6*SB, 6*SB, 4*SB),
                         new Lever(3*SB+100,4*SB+78)};
            //Portals
            vecPortals = {new Portal(34*SB+100, 4*SB+100, 6*SB+100, 11*SB+100, 1), new Portal(3*SB,4*SB+100,15*SB,4*SB+100,4)};
            //Fairy
            game->player->getFairy()->setFairy(0,11*SB+50, 4*SB+100);
            game->player->getFairy()->getText()->setDefaultTextColor(Qt::black);
            tutorial();
            break;
        }
        case 1: {
            //dimenciones de la escena
            setSceneRect(0,0,25*SB,16*SB);
            //poner fondo
            setBackgroundBrush(QBrush(QImage(forest)));
            //Bloques
            texture.setTextureImage(QImage(texture_forest));
            vecBlocks = {new Block(0,0,25,3), new Block(0,3,5,2), new Block(0,5,4,1), new Block(0,6,7,5), new Block (0,11,6,2), new Block(0,13,25,3),
                         new Block(6,12,2,1), new Block(13,12,8,1), new Block(16,3,4,8), new Block(21,3,4,10), new Block(11,11,1,1), new Block(12*SB,9*SB,2*SB,50,false),
                         new Block(11,6,1,1), new Block(9*SB,5*SB,1*SB,50,false), new Block(7,6,1,1),
                         new MotionBlock(+50+8*SB,11*SB,-100+3*SB,50,false,true,0,0,8*SB,11*SB+50,0,-7),
                         new MotionBlock(13*SB,8*SB,2*SB,50,false,true,0,0,5*SB,8*SB,0,-7)};
            //Enemies
            vecEnemies = {new Furry(9*SB,10*SB,+50+8*SB,50+10*SB,true), new Furry(14*SB,7*SB,13*SB,-48+15*SB,true), new Furry(10*SB,12*SB),
                          new Demon(13*SB+54, 8*SB+54,1), new Demon(6*SB,5*SB+54,2)};
            //Portals
            vecPortals = {new Portal(6*SB,11*SB+100,34*SB,4*SB+100,0), new Portal(4*SB,5*SB+100,16*SB,17*SB+100,2)};
            //Fairy
            game->player->getFairy()->popFairy();
            break;
        }
        case 2: {
            //dimeciones escena
            setSceneRect(0,0,22*SB,22*SB);
            //poner fondo
            setBackgroundBrush(QBrush(QImage(forest)));
            //bloques
            texture.setTextureImage(QImage(texture_forest));
            vecBlocks = {new Block(14,18,8,1), new Block(17,17,5,1), new Block(16,7,6,10), new Block(8,19,14,3), new Block(7,18,1,4), new Block(6,17,1,5),
                        new Block(0,11,6,11), new Block(0,9,7,2), new Block(0,8,5,1), new Block(0,3,6,5), new Block(0,0,22,5), new Block(16,3,6,3),
                        new Block(17,6,5,1), new Block(12,7,4,1),
                        new Block(11,14,2,3), new Block(14,13,1,1), new Block(15*SB,12*SB,SB,50,false), new Block(12,11,2,1), new Block(13*SB,10*SB,50,50,false), new Block(12*SB-100,9*SB,200,50,false),
                        new MotionBlock(8*SB,14*SB,2*SB,50,false,true,0,0,13*SB,17*SB,0,-7),
                        new MotionBlock(8*SB,6*SB,3*SB,SB,false,true,0,0,6*SB,11*SB+50,0,10)};
            //enemies
            vecEnemies = {new Furry(9*SB,18*SB), new Furry(9*SB,14*SB,8*SB,10*SB-48,true), new Furry(13*SB,10*SB+50,12*SB,14*SB-48,true),
                          new Furry(9*SB,5*SB+50,8*SB,11*SB-48,true), new Furry(10*SB,5*SB+50,8*SB,11*SB-48,true),
                          new Demon(12*SB,13*SB+50,1),
                          new Demon(14*SB,6*SB+50,1),
                          new Demon(6*SB,16*SB+50,2),
                          new Dragon(true)};
            //portal
            vecPortals = {new Portal(16*SB+100,17*SB+100,4*SB+100,5*SB+100,1), new Portal(16*SB+100,6*SB+100,5*SB+100,7*SB+100,3)};
            //Fairy
            game->player->getFairy()->setFairy(2,5*SB+100,8*SB+100);
            game->player->getFairy()->getText()->setDefaultTextColor(Qt::white);
            //tutorial

            break;
        }
    case 3: {
        //dimensiones escena
        setSceneRect(0,0,29*SB,12*SB);
        //poner fondo
        setBackgroundBrush(QBrush(QImage(dark_clouds)));
        //bloques - pintar, texturas
        texture.setTextureImage(QImage(texture_rock));
        vecBlocks = {new Block(0,0,29,3), new Block(0,3,6,4), new Block(0,7,5,5), new Block(5,8,17,4), new Block(17,12,5,8), new Block(22,17,6,3),
                     new Block(23,8,6,9), new Block(24,3,5,5),
                     new Block(9*SB,7*SB,SB+50,50,false), new Block(11*SB,6*SB,SB,50,false), new Block(13*SB,5*SB,SB,50,false), new Block(15*SB,6*SB,SB,50,false),
                     new Block(17*SB-50,7*SB,SB+50,50,false)};
        //enemies
        if(!game->player->getBow()->getIfEquip()) vecEnemies = {new Audhulma()};
        //portal
        vecPortals = {new Portal(22*SB+50,16*SB+100,20*SB+52,3*SB+2,1)};
        //Fairy
        game->player->getFairy()->popFairy();
        break;
    }
    case 4: {
        //dimeciones escena
        setSceneRect(0,0,21*SB,30*SB);
        //poner fondo
        setBackgroundBrush(QBrush(QImage(lava)));
        //bloques - pintar, texturas
        texture.setTextureImage(QImage(texture_lava));
        vecBlocks = {new Block(0,0,21,3), new Block(0,22,5,4), new Block(0,26,21,4), new Block(0,3,6,19), new Block(15,3,6,1), new Block(16,4,5,1), new Block(15,5,6,21),
                    new Block(8*SB,5*SB,7*SB,50,false), new Block(6,6,1,1), new Block(6*SB,7*SB,7*SB,50,false), new Block(14,8,1,1), new Block(8*SB,9*SB,7*SB,50,false),
                    new Block(6,10,1,1), new Block(6,11,2,2), new Block(6,13,8,1), new Block(9,11,2,1), new Block(12,11,1,1), new Block(14*SB,12*SB,1*SB,50,false),
                    new Block(14*SB+50,14*SB,100,50,false), new Block(14,15,1,1), new Block(12*SB,15*SB,1*SB,50,false), new Block(10*SB,16*SB,1*SB,50,false), new Block(8,17,7,1),
                    new Block(6,18,1,1), new Block(6,19,2,1), new Block(6,20,4,2), new Block(11,20,2,1), new Block(11,21,1,1), new Block(10*SB,21*SB+100,1*SB,50,false),
                    new Block(5,23,2,1), new Block(5,24,1,1), new Block(8*SB,23*SB,1*SB,50,false), new Block(8*SB,25*SB,1*SB,50,false), new Block(10*SB,24*SB,1*SB,50,false), new Block(12*SB,23*SB,1*SB,50,false), new Block(12*SB,25*SB,SB,50,false),
                    new MotionBlock(14*SB,21*SB,1*SB,50,false,true,0,0,20*SB,24*SB,0,-7)};
        //enemies
        qreal rad4 = 75+50;
        vecEnemies = {new Saw(10*SB+75,6*SB+25,4,350,0,0.4), new Furry(10*SB,4*SB+100,8*SB,14*SB,true), new Furry(9*SB,6*SB+100,6*SB,13*SB-48,true), new Furry(11*SB,6*SB+100,6*SB,13*SB-48,true),
                     new Saw(10*SB,11*SB+75,2,225,0,0.5), new Furry(10*SB,10*SB,9*SB,11*SB-48,true),
                     new Saw(12*SB+75,15*SB+25,2,150,0,-0.5), new Saw(10*SB+75,16*SB+25,2,150,0,0.5),
                     new Saw(10*SB+75,20*SB+10,1,65,0,0.5), new Saw(10*SB+75,20*SB+10,1,65,PI/2,0.5), new Saw(10*SB+75,20*SB+10,1,65,PI,0.5), new Saw(10*SB+75,20*SB+10,1,65,(3*PI)/2,0.5),
                     new Saw(10*SB+75,20*SB+10-300,1,65,0,0.5), new Saw(10*SB+75,20*SB+10-300,1,65,PI/2,0.5), new Saw(10*SB+75,20*SB+10-300,1,65,PI,0.5), new Saw(10*SB+75,20*SB+10-300,1,65,(3*PI)/2,0.5),
                     new Saw(12*SB+75,23*SB+25,1,rad4,1.57,0.5), new Saw(12*SB+75,25*SB+25,1,rad4,-1.57,0.5), new Saw(10*SB+75,24*SB+25,1,rad4,1.57,0.5), new Saw(8*SB+75,23*SB+25,1,rad4,0,0.5) ,new Saw(8*SB+75,25*SB+25,1,rad4,-2.40,0.5),
                     new Spike(10*SB,21*SB+50,8*SB+50,19*SB+50), new Dragon(true)};
        //Spikes
        fillSpikes(vecEnemies,5,8,12,7*SB+50,10*SB+50);
        fillSpikes(vecEnemies,6,9,16,14*SB+50,14*SB+52);
        fillSpikes(vecEnemies,8,7,25,12*SB+50,19*SB+50);
        //portal
        vecPortals = {new Portal(15*SB+100,4*SB+100,3*SB+100,4*SB+100,0), new Portal(5*SB,25*SB+100,21*SB,7*SB+100,5)};
        //Fairy
        game->player->getFairy()->setFairy(4,5*SB+150,22*SB+100);
        game->player->getFairy()->getText()->setDefaultTextColor(Qt::white);
        break;
    }
    case 5: {
        //dimensiones escena
        setSceneRect(0,0,29*SB,12*SB);
        //poner fondo
        setBackgroundBrush(QBrush(QImage(lava)));
        //bloques - pintar, texturas
        texture.setTextureImage(QImage(texture_lava));
        vecBlocks = {new Block(0,0,29,3), new Block(0,3,6,4), new Block(0,7,5,5), new Block(5,8,24,4), new Block(24,3,5,5),
                     new Block(9*SB,7*SB,SB+50,50,false), new Block(11*SB,6*SB,SB,50,false), new Block(13*SB,5*SB,SB,50,false),
                     new Block(15*SB,6*SB,SB,50,false), new Block(17*SB-50,7*SB,SB+50,50,false), new Block(22,7,2,1),
                     new Block(21,3,3,4)};
        //enemies
        vecEnemies = {new Audhulma(), new Dragon(true,1)};
        //portal
        vecPortals = {};
        game->player->getFairy()->popFairy();
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
    //hacienod pincel
    QPen pen;
    pen.setColor(Qt::transparent);
    for (auto block : qAsConst(vecBlocks)) {
        block->setBrush(texture);
        block->setPen(pen);
        addItem(block);
    }
    //para que la barra siempre este encima de los bloques
    removeItem(game->player->getHealthBar());
    removeItem(game->player->getHealthBar()->getUpdateHealth());
    addItem(game->player->getHealthBar());
    addItem(game->player->getHealthBar()->getUpdateHealth());
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
    for (int i = 0; i<game->portals->size(); i++) {
        removeItem(game->portals->at(i));
        delete game->portals->at(i);
    }
    game->portals->clear();
}

void World::updatePosPlayer(QPointF pos)
{
    game->player->setPos(pos);
    game->player->setRPos(game->player->pos());
}

void World::tutorial()
{
    qreal he = 30;
    qreal wi = 50;
    int i = 0;
    QGraphicsTextItem *tuMove = new QGraphicsTextItem("Press Left '<' or Right '>' to move");
    tuMove->setPos(10*SB+wi,4*SB+he*i);
    i += 1;
    QGraphicsTextItem *tuAttack = new QGraphicsTextItem("Press 'X' to attack");
    tuAttack->setPos(23*SB+wi,4*SB+he*i);
    i += 1;
    QGraphicsTextItem *tuDash = new QGraphicsTextItem("Press 'Z' to use the dash");
    tuDash->setPos(23*SB+wi,4*SB+he*i);
    i += 1;
    QGraphicsTextItem *tuJump = new QGraphicsTextItem("Press 'C' to jump");
    tuJump->setPos(23*SB+wi,4*SB+he*i);
    i += 1;
    QGraphicsTextItem *tuAction = new QGraphicsTextItem("You can use the dash while jumping");
    tuAction->setPos(23*SB+wi,4*SB+he*i);
    addItem(tuAction);
    addItem(tuDash);
    addItem(tuJump);
    addItem(tuAttack);
    addItem(tuMove);

}

void World::fillSpikes(QVector<Enemy*> &vecEnemies, unsigned int num, qreal posx, qreal posy, qreal posPlayerX, qreal posPlayerY)
{
    for (unsigned int i = 0; i<num; i++) {
        vecEnemies.push_back(new Spike(SB*(posx+i),SB*posy+100,posPlayerX,posPlayerY));
    }
}

void World::initPlayer()
{
    addItem(game->player);
    addItem(game->player->getHealthBar());
    addItem(game->player->getHealthBar()->getUpdateHealth()); //que se actualize constantemente segun la posicion del GV
    addItem(game->player->getBow());
}

void World::addToWorld(Block *block)
{
    addItem(block);
}
