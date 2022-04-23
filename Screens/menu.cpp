#include "menu.h"
#include "button.h"
#include "game.h"
#include "userwindow.h"
#include <QGraphicsTextItem>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <Utilities/fairy.h>
Menu::Menu()
{
    int alto = 340;
    setSceneRect(0,0,1280,720);
    //Fondo
    setBackgroundBrush(QBrush(QImage(":/new/sprites/sprites/Night.png")));

    //Titulo
    tittle = new QGraphicsTextItem("Hollow Souls");
    QFont tittleFont("comic sans",60,1);
    tittle->setFont(tittleFont);
    tittle->setDefaultTextColor(QColor(Qt::white));
    qreal posx = width()/2 - tittle->boundingRect().width()/2;
    tittle->setPos(posx, 130);
    addItem(tittle);

    //crear New Game Button
    newGameButton = new Button(QString("New Game"));
    posx = width()/2 - newGameButton->boundingRect().width()/2;
    newGameButton->setPos(posx, alto);
    connect(newGameButton, &Button::clicked, this, &Menu::createUser);
    //connect(newGameButton, &Button::clicked, game, &Game::newGame);
    addItem(newGameButton);

    //crear Load Game Button
    loadGameButton = new Button(QString("Load Game"));
    loadGameButton->setPos(posx, alto+30+loadGameButton->boundingRect().height());
    connect(loadGameButton, &Button::clicked, this, &Menu::loadUser);
    //connect(loadGameButton, &Button::clicked, game, &Game::loadGame);
    addItem(loadGameButton);

    //crear Exit Button
    exitButton = new Button(QString("Exit"));
    exitButton->setPos(posx, alto+60+exitButton->boundingRect().height()*2);
    connect(exitButton, &Button::clicked, game, &Game::close);
    addItem(exitButton);

    //UserWindow
    userWindow = new UserWindow();

    //conections

}

void Menu::createUser()
{
    userWindow->createNewUser();
    userWindow->setGeometry(sceneRect().center().x(), sceneRect().center().y(), 500, 200);
    userWindow->show();
}

void Menu::loadUser()
{
    userWindow->loadUser();
    userWindow->setGeometry(sceneRect().center().x(), sceneRect().center().y(), 500, 200);
    userWindow->show();
}

void Menu::setGame(Game *newGame)
{
    game = newGame;
}
