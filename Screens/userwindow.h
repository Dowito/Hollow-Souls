#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
class QPushButton;
class QLabel;
class QLineEdit;
class QHBoxLayout;
class QVBoxLayout;
class Game;
class UserWindow : public QWidget
{
    Q_OBJECT
public:
    explicit UserWindow(QWidget *parent = nullptr);
    void createNewUser();
    void loadUser();

    static void setGame(Game *newGame);

signals:

private:
    int validateNewUser(QString &reUser, std::string &fileString);
    bool ifLet(QString &reUser); //retorna true si el string solo tiene letras
    QPushButton *start;
    QPushButton *cancel;
    QLabel *label;
    QLineEdit *inUser;
    QHBoxLayout *layoutUser;
    QHBoxLayout *layoutButton;
    QVBoxLayout *layout;
    static Game *game;

private slots:
    void onStartNewGameButton();
    void onStartSaveGameButton();
};
#endif // USERWINDOW_H
