#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
class QGraphicsTextItem;
class Button;
class Game;
class QMainWindow;
class Menu : public QGraphicsScene
{

public:
    Menu();

    static void setGame(Game *newGame);

private:
    QGraphicsTextItem *tittle;
    Button *newGameButton;
    Button *loadGameButton;
    Button *exitButton;
    QMainWindow *inUsers;
    static Game *game;
};

#endif // MENU_H
