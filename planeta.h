#ifndef PLANETA_H
#define PLANETA_H

#include <math.h>
#include <cmath>

class planeta
{
public:
    planeta(float posx, float posy, float masa, float radio, float velx, float vely);
    void acelerar(float posx_,float posy_, float masa_);
    void actualizar(float dt);
    float get_radio();
    float get_masa();
    float get_px();
    float get_py();
    float get_vx();
    float get_vy();
    float ax,ay;
private:
    float x,y,m,r,vx,vy,dist,G;

};

#endif // PLANETA_H
