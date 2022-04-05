#include <QApplication>
#include <game.h>
#include <mainwindow.h>
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game;
    game->show();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
    return a.exec();
}
