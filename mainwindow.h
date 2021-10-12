#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <QTimer>
#include "planeta.h"
#include "planetagraf.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setup_scene();

private:
    Ui::MainWindow *ui;
    QTimer *tiempo;
    QGraphicsScene *scene;
    QList <planetagraf*> sist;
    int h,w;
    float dt,pxo=0,pyo=0,m=0,r=0,vxo=0,vyo=0;
    bool ejec=false;

private slots:
    void simulacion();
    void on_agregar_clicked();
    void on_actionIniciar_triggered();
    void on_actionDetener_triggered();
    void on_actionCerrar_triggered();
};

#endif // MAINWINDOW_H
