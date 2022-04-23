#include "userwindow.h"
#include "game.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QtDebug>
#include <QDialog>
#include "Utilities/fairy.h"
UserWindow::UserWindow(QWidget *parent)
    : QWidget{parent}
{
    //setup
    setGeometry(400,400,500,200);
    setWindowFlag(Qt::WindowTitleHint, false);
    setWindowFlag(Qt::WindowSystemMenuHint, false);
    setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    //construyendo interfaz
    layout = new QVBoxLayout(this);
    layoutUser = new QHBoxLayout;
    layoutButton = new QHBoxLayout;
    start = new QPushButton("Start");
    cancel = new QPushButton("Cancel");
    label = new QLabel("User: ");
    inUser = new QLineEdit("ingrese usuario...");
    layoutUser->addWidget(label);
    layoutUser->addWidget(inUser);
    layoutButton->addWidget(start);
    layoutButton->addWidget(cancel);
    layout->addLayout(layoutUser);
    layout->addLayout(layoutButton);
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
}

void UserWindow::createNewUser()
{
    setWindowTitle("Create New User");
    inUser->setText("ingrese nuevo usuario...");
    connect(start, SIGNAL(clicked()), this, SLOT(onStartNewGameButton()));
}

void UserWindow::loadUser()
{
    setWindowTitle("Load User");
    inUser->setText("ingrese usuario...");
    connect(start, SIGNAL(clicked()), this, SLOT(onStartSaveGameButton()));
}

void UserWindow::onStartNewGameButton()
{
    QString reUser;
    string fileString = readArchivo("../HollowSouls/save_games/saves.txt");
    fileString.pop_back();
    reUser = inUser->text();
    int validate = validateNewUser(reUser, fileString);
    if (validate == 0) {
        inUser->setText("¡Usuario debe contener mas de 4 letras!");
    }
    else if (validate == 1) {
        inUser->setText("¡Usuario solo puede contener letras!");
    }
    else if (validate == 2) {
        inUser->setText("Usuario ya registrado, ingrese un nuevo usuario...");
    }
    else {
        game->user = reUser;
        game->newGame();
        close();
    }
}

void UserWindow::onStartSaveGameButton()
{
    QString reUser;
    string fileString = readArchivo("../HollowSouls/save_games/saves.txt");
    fileString.pop_back();
    reUser = inUser->text();
    int validate = validateNewUser(reUser, fileString);
    if (validate != 2) {
        inUser->setText("¡Usuario no registrado, ingrese un usuario registrado!");
    }
    else {
        game->user = reUser;
        game->loadGame();
        close();
    }
}

int UserWindow::validateNewUser(QString &reUser, string &fileString)
{
    int index = fileString.find(reUser.toStdString());
    //0
    if(reUser.size() < 5) { //mayor de 4
        return 0;
    }
    //1
    else if (!ifLet(reUser)) { //que sean solo
        return 1;
    }
    //2
    else if (index != -1) { // que no este regist
        return 2;
    }
    else { //es valido
        return 3;
    }
}

bool UserWindow::ifLet(QString &reUser)
{
    bool condition;
    for (auto ch : reUser) {
        condition = (65<=ch && ch<=90) || (97<=ch && ch<=122);
        if(!condition) {
            return false;
        }
    }
    return true;
}

void UserWindow::setGame(Game *newGame)
{
    game = newGame;
}
