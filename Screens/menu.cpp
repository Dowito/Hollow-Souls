#include "menu.h"
#include "button.h"
#include "game.h"
#include "QFontDatabase"
#include <QGraphicsTextItem>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
Menu::Menu()
{
    int alto = 340;
    //Fondo
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/new/sprites/sprites/Night.png")));

    //inUsers prototipo
    inUsers = new QMainWindow;
    inUsers->setWindowTitle("Ingreso de Usuario");
    setParent(inUsers);
    inUsers->setGeometry(400,400,500,200);
    QLabel *label = new QLabel("user: ",inUsers);
    label->setGeometry(20,0,50,50);
    QLineEdit *inText = new QLineEdit("ingrese usuario..",inUsers);
    inText->setGeometry(60,0,200,50);
    QPushButton *inButton = new QPushButton("Ingresar",inUsers);
    inButton->setGeometry(50,120,100,50);
    QPushButton *quitButton = new QPushButton("Volver",inUsers);
    quitButton->setGeometry(160,120,100,50);
    inUsers->show();

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
    connect(newGameButton, &Button::clicked, game, &Game::newGame);
    addItem(newGameButton);

    //crear Load Game Button
    loadGameButton = new Button(QString("Load Game"));
    loadGameButton->setPos(posx, alto+30+loadGameButton->boundingRect().height());
    connect(loadGameButton, &Button::clicked, game, &Game::loadGame);
    addItem(loadGameButton);

    //crear Exit Button
    exitButton = new Button(QString("Exit"));
    exitButton->setPos(posx, alto+60+exitButton->boundingRect().height()*2);
    connect(exitButton, &Button::clicked, game, &Game::close);
    addItem(exitButton);
}

void Menu::setGame(Game *newGame)
{
    game = newGame;
}
