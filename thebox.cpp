#include "thebox.h"
#include "ui_thebox.h"
#include <game.h>
#include <QTimer>
extern Game *game;
TheBox::TheBox(QGraphicsScene *scene, QWidget *parent) :
    QMainWindow(parent),
    clockMs(new unsigned int),
    ui(new Ui::TheBox)
{
    ui->setupUi(this);
    setGeometry(0,0,1280,720);
    ui->graphicsView->setGeometry(0,0,width(),height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    game->timer->stop();
}

TheBox::~TheBox()
{
    delete ui;
}

Ui::TheBox *TheBox::getUi() const
{
    return ui;
}

void TheBox::on_ZoomPlus_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}

void TheBox::on_ZoomMinus_clicked()
{
    ui->graphicsView->scale(0.8,0.8);
}


void TheBox::on_Iniciar_clicked()
{
    ui->Ingresar->setEnabled(false);
    ui->rX->setEnabled(false);
    ui->rY->setEnabled(false);
    ui->rVx->setEnabled(false);
    ui->rVy->setEnabled(false);
    ui->rax->setEnabled(false);
    ui->ray->setEnabled(false);
    ui->rClockMs->setEnabled(false);
    game->prueba->setR({static_cast<float>(ui->rX->value()),static_cast<float>(ui->rY->value())});
    game->prueba->setV({static_cast<float>(ui->rVx->value()),static_cast<float>(ui->rVy->value())});
    game->prueba->setA({static_cast<float>(ui->rax->value()),static_cast<float>(ui->ray->value())});
    game->prueba->setPeriodo(ui->rPeriodo->value());
    *clockMs = ui->rClockMs->value();
    game->timer->start(*clockMs);
}


void TheBox::on_Detener_clicked()
{
    game->timer->stop();
    ui->Ingresar->setEnabled(true);
    ui->rX->setEnabled(true);
    ui->rY->setEnabled(true);
    ui->rVx->setEnabled(true);
    ui->rVy->setEnabled(true);
    ui->rax->setEnabled(true);
    ui->ray->setEnabled(true);
    ui->rClockMs->setEnabled(true);
}


void TheBox::on_Ingresar_clicked()
{
    game->prueba->setR({static_cast<float>(ui->rX->value()),static_cast<float>(ui->rY->value())});
    game->prueba->setV({static_cast<float>(ui->rVx->value()),static_cast<float>(ui->rVy->value())});
    game->prueba->setA({static_cast<float>(ui->rax->value()),static_cast<float>(ui->ray->value())});
    game->prueba->setPeriodo(ui->rPeriodo->value());
    game->prueba->setPos(game->prueba->getR().toPointF());
    *clockMs = ui->rClockMs->value();
}


void TheBox::on_Left_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x()-10,
                                            ui->graphicsView->scene()->sceneRect().y(),
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_Right_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x()+10,
                                            ui->graphicsView->scene()->sceneRect().y(),
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_Up_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x(),
                                            ui->graphicsView->scene()->sceneRect().y()-10,
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_pushButton_2_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x(),
                                            ui->graphicsView->scene()->sceneRect().y()+10,
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}

