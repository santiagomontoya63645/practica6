#include "planetagraf.h"

planetagraf::planetagraf(float posx, float posy, float masa, float radio, float velx, float vely)
{
    pla = new planeta(posx,posy,masa,radio,velx,vely);
}

QRectF planetagraf::boundingRect() const
{
    return QRectF(-1*escala*pla->get_radio(),-1*escala*pla->get_radio(),2*escala*pla->get_radio(),2*escala*pla->get_radio());
}

void planetagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::lightGray);
    painter->drawEllipse(boundingRect());
}

void planetagraf::actualizar(float dt)
{
    pla->actualizar(dt);
    setPos(pla->get_px()*escala,pla->get_py()*escala);
}

planeta *planetagraf::getPla()
{
    return pla;
}
