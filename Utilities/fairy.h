#ifndef FAIRY_H
#define FAIRY_H

#include <QGraphicsView>
#include "sprite.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "iostream"
#include <fstream>
using namespace std;

unsigned long long tamArchivo(string name);
QString readArchivo(string name);
void writeArchivo(string name, string str);

class Player;
class Fairy : public Sprite, public QGraphicsPixmapItem
{
public:
    Fairy(unsigned short world, qreal posx, qreal posy, QGraphicsItem *parent = nullptr);
    virtual ~Fairy() {};
    void initText();
    void check();
    void saveGame(Player *player);

    bool getSaving() const;

private:
    void showFeedBack();
    void showSaveText();
    void animation();
    bool saving;
    unsigned short world;
    unsigned short steps;
    unsigned short stepsAnimation;
    QString stringFile;
    QGraphicsTextItem *text;
};

#endif // FAIRY_H
