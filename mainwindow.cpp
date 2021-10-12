#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=8000;
    w=8000;
    dt=0.5;
    setWindowTitle("Práctica 6");
    setWindowIcon(QIcon(":/imagen/orbitas.jpg"));
    setup_scene();
}

MainWindow::~MainWindow()
{
    delete scene;
    delete tiempo;
    delete ui;
}

void MainWindow::setup_scene()
{
    scene = new QGraphicsScene(this);
    tiempo = new QTimer(this);
    scene->setSceneRect(-h/2,-w/2,h,w);
    ui->graphicsView->setScene(scene);
    ui->centralWidget->adjustSize();
    tiempo->stop();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(simulacion()));
}

void MainWindow::simulacion()
{
    for (int i=0;i<sist.size() ;i++ ) {
        sist.at(i)->getPla()->ax=0;
        sist.at(i)->getPla()->ay=0;
        for (int j=0;j<sist.size() ;j++ ) {
            if(i!=j){
                sist.at(i)->getPla()->acelerar(sist.at(j)->getPla()->get_px(),sist.at(j)->getPla()->get_py(),sist.at(j)->getPla()->get_masa());
            }
        }
        sist.at(i)->actualizar(dt);
    }
}

void MainWindow::on_agregar_clicked()
{
    if(ejec==true){
        ejec=false;
        for (int i=0;i<sist.size() ;i++ ) {
            scene->removeItem(sist.at(i));
        }
    }
    pxo = ui->pxo->value();
    pyo = ui->pyo->value();
    vxo = ui->vxo->value();
    vyo = ui->vyo->value();
    m = ui->masa->value();
    r = ui->radio->value();
    fstream ofs("../practica6/Planetas.txt",ios::app);
    ofs<<pxo<<" "<<pyo<<" "<<m<<" "<<r<<" "<<vxo<<" "<<vyo<<"\n";
    ofs.close();
    sist.clear();
}

void MainWindow::on_actionIniciar_triggered()
{
    if(ejec==false){
        int cont;
        string linea,pxs,pys,ms,rs,vxs,vys;
        fstream ifs("../practica6/Planetas.txt",ifstream::in);
        while(getline(ifs,linea)){
            if(linea.size()>0){
                cont=0;
                pxs.clear();
                pys.clear();
                ms.clear();
                rs.clear();
                vxs.clear();
                vys.clear();
                for(int i=0;i<linea.size();i++){
                    if(linea[i]==' ') cont++;
                    else{
                        if(cont==0) pxs+=linea[i];
                        if(cont==1) pys+=linea[i];
                        if(cont==2) ms+=linea[i];
                        if(cont==3) rs+=linea[i];
                        if(cont==4) vxs+=linea[i];
                        if(cont==5) vys+=linea[i];
                    }
                }
                pxo=stof(pxs);
                pyo=stof(pys);
                m=stof(ms);
                r=stof(rs);
                vxo=stof(vxs);
                vyo=stof(vys);
                sist.append(new planetagraf(pxo,pyo,m,r,vxo,vyo));
            }
        }
        ifs.close();
        for(int j=0;j<sist.size();j++){
            sist.at(j)->actualizar(dt);
            scene->addItem(sist.at(j));
        }
        ejec=true;
    }
    tiempo->start(dt);
}

void MainWindow::on_actionDetener_triggered()
{
    tiempo->stop();
}

void MainWindow::on_actionCerrar_triggered()
{
    close();
}

