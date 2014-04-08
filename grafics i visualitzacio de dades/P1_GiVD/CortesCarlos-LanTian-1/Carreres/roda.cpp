#include "roda.h"

Roda::Roda(GLfloat mida, GLfloat x0, GLfloat y0, GLfloat z0,
           double girx, double giry, double girz):Objecte(NumVerticesF)
{
    //tam=mida;

    xorig=x0;
    yorig=y0;
    zorig=z0;

    xRot=girx;
    yRot=giry;
    zRot=girz;

    Index=0;
}

void Roda::setRadi(GLfloat radi){
    this->radi=radi;
}
