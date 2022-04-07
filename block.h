#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
class Block : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Block();
};

#endif // BLOCK_H
