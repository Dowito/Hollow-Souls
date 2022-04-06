#ifndef THEBOX_H
#define THEBOX_H

#include <QMainWindow>
#include <QGraphicsScene>
namespace Ui {
class TheBox;
}
class Player;
class TheBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheBox(QWidget *parent = nullptr);
    ~TheBox();

    Ui::TheBox *getUi() const;

private slots:
    void on_ZoomPlus_clicked();

    void on_ZoomMinus_clicked();

    void on_Iniciar_clicked();

    void on_Detener_clicked();

    void on_Ingresar_clicked();

    void on_Left_clicked();

    void on_Right_clicked();

    void on_Up_clicked();

    void on_pushButton_2_clicked();

private:
    Player *prueba;
    unsigned int *clockMs;
    QGraphicsScene *scene;
    Ui::TheBox *ui;
};

#endif // THEBOX_H
