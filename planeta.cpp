#include "planeta.h"

planeta::planeta(float posx, float posy, float masa, float radio, float velx, float vely)
{
    x=posx;
    y=posy;
    m=masa;
    r=radio;
    vx=velx;
    vy=vely;
    ax=0;
    ay=0;
    G=1;
}

void planeta::acelerar(float posx_, float posy_, float masa_)
{
    dist = sqrt((pow((posx_-x),2)+pow((posy_-y),2)));
    ax+=G*(masa_*(posx_-x)/pow(dist,3));
    ay+=G*(masa_*(posy_-y)/pow(dist,3));
}

void planeta::actualizar(float dt)
{
    vx=vx+(ax*dt);
    vy=vy+(ay*dt);
    x=x+(vx*dt);
    y=y+(vy*dt);
}

float planeta::get_radio()
{
    return r;
}

float planeta::get_masa()
{
    return m;
}

float planeta::get_px()
{
    return x;
}

float planeta::get_py()
{
    return y;
}

float planeta::get_vx()
{
    return vx;
}

float planeta::get_vy()
{
    return vy;
}
