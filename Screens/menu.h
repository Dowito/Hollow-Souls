#ifndef MENU_H
#define MENU_H

#include <QGraphicsScene>
#include <QPushButton>
class QGraphicsTextItem;
class Button;
class Game;
class UserWindow;
class Menu : public QGraphicsScene
{

public:
    Menu();
    virtual ~Menu();
    static void setGame(Game *newGame);

private:
    QGraphicsTextItem *tittle;
    Button *newGameButton;
    Button *loadGameButton;
    Button *exitButton;
    UserWindow *userWindow;
    static Game *game;

private slots:
    void createUser();
    void loadUser();
    void onStartNewGameButton();
    void onStartSaveGame();
};

#endif // MENU_H
