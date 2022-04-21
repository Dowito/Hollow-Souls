#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"
#include "simpleharmonicmotion.h"
class Dragon : public Enemy, public SimpleHarmonicMotion
{
public:
    Dragon(qreal posx, qreal posy, short direction,
           qreal amplitud = 330, qreal frequency = 0.01, qreal phase = 0, qreal velx = 15);
    /*
     * amplitud: 330 es lo maximo para que se no salga de la pantalla mientras oscila
     * frequency: 0.01 para que pueda oscilar bien
     * phase: cualquier valor, determina la posicion inicial en y respecto a su origen, es un angulo en rad
     * vel: 10 esta bien o 20
     */
    Dragon(bool spawner, unsigned int stepsToSpawn = 200);
    virtual ~Dragon() {};

    void move();
    void limitScene();
    void spawn();

private:
    bool spawner;
    unsigned int stepsToSpawn;
    unsigned int steps;

    // Motion interface
public:
    virtual void check() override;

    // Enemy interface
protected:
    virtual void attack() override;
};

#endif // DRAGON_H
