#include "sprite.h"
void Sprite::loadFrames(QPixmap sprite, unsigned short fil, unsigned short col)
{
    QPixmap image;
    QVector<QPixmap> frameBuffer;
    //frames.resize(fil);
    for (unsigned short i=0; i<fil; i++) {
        frameBuffer.clear();
        for (unsigned short j=0; j<col; j++) {
            image = sprite.copy(j*w, i*h, w, h).scaled(w*GAME_SCALE, h*GAME_SCALE);
            //frames[i].push_back(image);
            frameBuffer.push_back(image);
        }
        frames.push_back(frameBuffer);
    }
    for (auto vector : qAsConst(frames)) {
        vector.shrink_to_fit();
    }
}

unsigned int Sprite::getW() const
{
    return w;
}

void Sprite::loadSprite(QString name, unsigned int w, unsigned int h, unsigned short fil, unsigned short col)
{
    QPixmap sprite(name);
    setSize(w,h);
    loadFrames(sprite, fil ,col);
}

void Sprite::setSize(unsigned int w, unsigned int h)
{
    this->w = w; //*GAME_SCALE
    this->h = h; //*GAME_SCALE
}
