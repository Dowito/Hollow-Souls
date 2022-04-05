#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVector2D>
#include <QGraphicsScene>
#include <QTimer>
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Detener_clicked();

    void on_ZoomPlus_clicked();

    void on_ZoomMinus_clicked();

    void on_Ingresar_clicked();

    void on_Iniciar_clicked();

    void on_Up_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
