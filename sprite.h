#ifndef SPRITE_H
#define SPRITE_H
#include <macros.h>
#include <QPixmap>
class Sprite
{
public:
    explicit Sprite() {};
    virtual ~Sprite() {};
    //short getDirection() const {return direction;};
    //void setDirection(short direction) {this->direction = direction;};

    unsigned int getW() const;

protected:
    virtual void loadSprite(QString name, unsigned int w = SIZE_BLOCK, unsigned int h = SIZE_BLOCK, unsigned short fil = 4, unsigned short col = 3);
    /*!
     * \brief setSize establece el tamaño de los frames en pixeles
     * \param w pixeles de ancho
     * \param h pixeles de largo
     */
    void setSize(unsigned int w, unsigned int h);
    /*!
     * \brief loadFrames recorta y guarda los distintos frames del sprite ingresado segun el ancho y alto que tendra cada frame en pixeles
     * \param sprite sprite a recortar
     * \param fil
     * \param col
     */
    virtual void loadFrames(QPixmap sprite, unsigned short fil, unsigned short col);
    QPixmap sprite;
    QPixmap frame;
    QVector<QVector<QPixmap>> frames;
    unsigned int w;
    unsigned int h;
    //short direction;
};

#endif // SPRITE_H
