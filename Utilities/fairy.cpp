#include "fairy.h"
#include "player.h"
#include <QDebug>
#include <bow.h>
unsigned long long tamArchivo(string name)
{
    fstream Archivo;
    Archivo.open(name, fstream::in | fstream::ate);
    if(Archivo.is_open()){
        unsigned long long tamArchivo = Archivo.tellg();
        Archivo.close();
        return tamArchivo;
    }
    else{
        cout << "El archivo no existe." << endl;
        return 0;
    }
}

QString readArchivo(string name)
{
    unsigned long long tam = tamArchivo(name);
    fstream Archivo;
    Archivo.open(name, fstream::in);
    if(Archivo.is_open()){
        QString info;
        for (unsigned long long i=0; i<tam; i++) {
            info.push_back(Archivo.get());
        }
        Archivo.close();
        return info;
    }
    else{
        cout << "El archivo no existe.";
        return 0;
    }
}

void writeArchivo(string name, string str)
{
    unsigned long long tam = str.size();//str.size();
    fstream Archivo;
    Archivo.open(name, fstream::out);
    if (Archivo.is_open()) {
        for (unsigned long long i=0; i<tam; i++) {
            Archivo.put(str[i]);
        }
        Archivo.close();
    }
    else cout << "Archivo no existe";
}

Fairy::Fairy(unsigned short world, qreal posx, qreal posy, QGraphicsItem *parent)
      :QGraphicsPixmapItem(parent)
{
    loadSprite(":/new/sprites/sprites/fairy.png",48,48);
    setPixmap(frames[0][1]);
    this->world = world;
    setPos(posx+50,posy+100);
    text = new QGraphicsTextItem;
    showSaveText();
    stepsAnimation = 200;
}

void Fairy::initText()
{
    scene()->addItem(text);
}

void Fairy::check()
{
    if(saving) animation();
}

void Fairy::animation()
{
    steps++;
    if(steps == stepsAnimation) {
        showSaveText();
    }
}

void Fairy::showSaveText()
{
    steps = 0;
    saving = false;
    text->setPlainText("Press Up '^' to save the game ^-^");
    text->setPos(x() - text->boundingRect().width()/2 + 22 , y()-25);
}

void Fairy::showFeedBack()
{
    saving = true;
    text->setPlainText("save successful ^-^");
    text->setPos(x() - text->boundingRect().width()/2 + 22 , y()-25);
}

void Fairy::saveGame(Player *player)
{
    showFeedBack();
    //guardar partida
    stringFile = readArchivo("../HollowSouls/save_games/saves.txt");
    /*
    for(int i = 0; i<stringFile.size();i++){
        cout << stringFile[i].toLatin1();
        cout.flush();
    }
    */
    int index = stringFile.indexOf(player->getUser());
    QString world = QString::number(this->world);
    QString posx = QString::number(x());
    QString posy = QString::number(y());
    QString bow = QString::number(player->getBow()->getIfEquip());
    QString user = player->getUser();
    qDebug() << index;
    if(index != -1){ //sobreescribir
        qDebug() << "guardando partida";
        QString buffer;
        for (int i = 0; i<index; i++) {
            buffer.push_back(stringFile[i]);
        }
        buffer.push_back(player->getUser());
        buffer.push_back(' ');
        buffer.push_back(world);
        buffer.push_back(' ');
        buffer.push_back(posx);
        buffer.push_back(' ');
        buffer.push_back(posy);
        buffer.push_back(' ');
        buffer.push_back(bow);
        buffer.push_back('\n');
        index = stringFile.indexOf('\n', index);
        index += 1;
        for (int i = index; i<stringFile.size(); i++) {
            buffer.push_back(stringFile[i]);
        }
        for(int i = 0; i<buffer.size();i++){
            cout << buffer[i].toLatin1();
            cout.flush();
        }
        stringFile = buffer;
    }
    else { //crear nueva partida

    }
    writeArchivo("../HollowSouls/save_games/saves.txt", stringFile.toStdString());
}

bool Fairy::getSaving() const
{
    return saving;
}
