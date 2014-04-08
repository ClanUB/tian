#include "carrosseria.h"

Carrosseria::Carrosseria(GLfloat mida, GLfloat x0, GLfloat y0, GLfloat z0,
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
