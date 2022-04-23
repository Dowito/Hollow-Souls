#include "userwindow.h"
#include "game.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QtDebug>
#include <QCheckBox>
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
    layoutCheckBox = new QHBoxLayout;
    layoutButton = new QHBoxLayout;
    //Button
    start = new QPushButton("Start");
    cancel = new QPushButton("Cancel");
    //In User
    label = new QLabel("User: ");
    inUser = new QLineEdit("ingrese usuario...");
    //Dificulties
    easy = new QCheckBox("Easy");
    connect(easy, SIGNAL(clicked()), this, SLOT(selectEasy()));
    medium= new QCheckBox("Medium");
    connect(medium, SIGNAL(clicked()), this, SLOT(selectMedium()));
    hard = new QCheckBox("Hard");
    connect(hard, SIGNAL(clicked()), this, SLOT(selectHard()));
    //Layout
    layoutUser->addWidget(label);
    layoutUser->addWidget(inUser);
    layoutCheckBox->addWidget(easy);
    layoutCheckBox->addWidget(medium);
    layoutCheckBox->addWidget(hard);
    layoutButton->addWidget(start);
    layoutButton->addWidget(cancel);
    //order
    layout->addLayout(layoutUser);
    layout->addLayout(layoutCheckBox);
    layout->addLayout(layoutButton);
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
}

void UserWindow::createNewUser()
{
    disconnect(start, SIGNAL(clicked()), this, SLOT(onStartSaveGameButton()));
    setWindowTitle("Create New User");
    inUser->setText("ingrese nuevo usuario...");
    easy->setChecked(false);
    medium->setChecked(true);
    hard->setChecked(false);
    connect(start, SIGNAL(clicked()), this, SLOT(onStartNewGameButton()));
}

void UserWindow::loadUser()
{
    disconnect(start, SIGNAL(clicked()), this, SLOT(onStartNewGameButton()));
    setWindowTitle("Load User");
    inUser->setText("ingrese usuario...");
    easy->setChecked(false);
    medium->setChecked(true);
    hard->setChecked(false);
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
        game->difficulty = readDifficulty();
        qDebug() << "Dificultad: " << game->difficulty;
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
        game->difficulty = readDifficulty();
        game->user = reUser;
        game->loadGame();
        close();
    }
}

void UserWindow::selectEasy()
{
    easy->setChecked(true);
    medium->setChecked(false);
    hard->setChecked(false);
}

void UserWindow::selectMedium()
{
    easy->setChecked(false);
    medium->setChecked(true);
    hard->setChecked(false);
}

void UserWindow::selectHard()
{
    easy->setChecked(false);
    medium->setChecked(false);
    hard->setChecked(true);
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

int UserWindow::readDifficulty()
{
    if (easy->isChecked()) {
        return 1;
    }
    else if (medium->isChecked()) {
        return 2;
    }
    else {
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

UserWindow::~UserWindow()
{
    delete start;
    delete cancel;
    delete label;
    delete inUser;
    delete layoutUser;
    delete layoutButton;
    delete easy;
    delete medium;
    delete hard;
    delete layout;
}

void UserWindow::setGame(Game *newGame)
{
    game = newGame;
}
