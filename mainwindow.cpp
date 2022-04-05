#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,1280,720);
    ui->graphicsView->setGeometry(0,0,width(),height());
    ui->graphicsView->scale(0.05,0.05);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Detener_clicked()
{
    ui->Ingresar->setEnabled(true);
    ui->rX->setEnabled(true);
    ui->rY->setEnabled(true);
    ui->rVx->setEnabled(true);
    ui->rVy->setEnabled(true);
    ui->rMasa->setEnabled(true);
    ui->rRadio->setEnabled(true);
    ui->numPlanets->setText(ui->numPlanets->text().setNum(0));
}


void MainWindow::on_ZoomPlus_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}


void MainWindow::on_ZoomMinus_clicked()
{
    ui->graphicsView->scale(0.8,0.8);
}


void MainWindow::on_Ingresar_clicked()
{

}


void MainWindow::on_Iniciar_clicked()
{
    ui->Ingresar->setEnabled(false);
    ui->rX->setEnabled(false);
    ui->rY->setEnabled(false);
    ui->rVx->setEnabled(false);
    ui->rVy->setEnabled(false);
    ui->rMasa->setEnabled(false);
    ui->rRadio->setEnabled(false);
}

void MainWindow::on_Up_clicked()
{

}

