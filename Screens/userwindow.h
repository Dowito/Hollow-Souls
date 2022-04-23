#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
class QPushButton;
class QLabel;
class QLineEdit;
class QHBoxLayout;
class QVBoxLayout;
class Game;
class QCheckBox;
class UserWindow : public QWidget
{
    Q_OBJECT
public:
    explicit UserWindow(QWidget *parent = nullptr);
    virtual ~UserWindow();
    void createNewUser();
    void loadUser();

    static void setGame(Game *newGame);

signals:

private:
    int validateNewUser(QString &reUser, std::string &fileString);
    int readDifficulty();
    bool ifLet(QString &reUser); //retorna true si el string solo tiene letras
    QPushButton *start;
    QPushButton *cancel;
    QLabel *label;
    QLineEdit *inUser;
    QHBoxLayout *layoutUser;
    QHBoxLayout *layoutButton;
    QHBoxLayout *layoutCheckBox;
    QVBoxLayout *layout;
    QCheckBox *easy;
    QCheckBox *medium;
    QCheckBox *hard;
    static Game *game;

private slots:
    void onStartNewGameButton();
    void onStartSaveGameButton();
    void selectEasy();
    void selectMedium();
    void selectHard();
};
#endif // USERWINDOW_H
