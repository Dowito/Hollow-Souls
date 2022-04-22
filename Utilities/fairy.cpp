#include "fairy.h"
#include "player.h"
#include <QDebug>
#include <bow.h>

string readArchivo(string name)
{
    fstream Archivo;
    Archivo.open(name, fstream::in);
    if(Archivo.is_open()){
        string info;
        while(!Archivo.eof()){
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

void Fairy::setFairy(unsigned short world, qreal posx, qreal posy)
{
    setVisible(true);
    this->world = world;
    setPos(posx,posy);
    text->setVisible(true);
    showSaveText();
}

void Fairy::popFairy()
{
    setPos(0,0);
    setVisible(false);
    text->setVisible(false);
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
    player->cure(9999);
    showFeedBack();
    stringFile = readArchivo("../HollowSouls/save_games/saves.txt");
    stringFile.pop_back();
    int index = stringFile.find(player->getUser().toStdString());
    string world = to_string(this->world);
    string posx = to_string(int(x()));
    string posy = to_string(int(y()));
    string bow = to_string(player->getBow()->getIfEquip());
    string user = player->getUser().toStdString();
    if(index != -1){
        string buffer;
        for (int i = 0; i<index; i++) {
            buffer.push_back(stringFile[i]);
        }
        buffer.append(player->getUser().toStdString());
        buffer.push_back(' ');
        buffer.append(world);
        buffer.push_back(' ');
        buffer.append(posx);
        buffer.push_back(' ');
        buffer.append(posy);
        buffer.push_back(' ');
        buffer.append(bow);
        buffer.push_back('\n');
        index = stringFile.find('\n', index);
        index += 1;
        for (unsigned int i = index; i < stringFile.size(); i++) {
            buffer.push_back(stringFile[i]);
        }
        stringFile = buffer;
    }
    else {
        stringFile.append(player->getUser().toStdString());
        stringFile.push_back(' ');
        stringFile.append(world);
        stringFile.push_back(' ');
        stringFile.append(posx);
        stringFile.push_back(' ');
        stringFile.append(posy);
        stringFile.push_back(' ');
        stringFile.append(bow);
        stringFile.push_back('\n');
    }
    writeArchivo("../HollowSouls/save_games/saves.txt", stringFile);
}

bool Fairy::getSaving() const
{
    return saving;
}
