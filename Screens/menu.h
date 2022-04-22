#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
class Menu : public QGraphicsScene
{

public:
    Menu();

private:
    QPushButton *start;
};

#endif // MENU_H
