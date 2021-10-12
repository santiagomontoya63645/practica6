#ifndef PLANETAGRAF_H
#define PLANETAGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "planeta.h"

class planetagraf: public QGraphicsItem
{
public:
    planetagraf(float posx, float posy, float masa, float radio, float velx, float vely);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float dt);
    planeta* getPla();
private:
    planeta *pla;
    float escala=0.05;
};

#endif // PLANETAGRAF_H
