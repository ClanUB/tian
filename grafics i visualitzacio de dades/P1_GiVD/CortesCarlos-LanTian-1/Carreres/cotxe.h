#ifndef COTXE_H
#define COTXE_H

#include <Common.h>
#include <objecte.h>
#include <roda.h>
#include <carrosseria.h>
#include <readfile.h>

#include <iostream>

using namespace std;

class Cotxe: public Objecte
{
public:
    Cotxe(QString n);
    Cotxe(QString n, GLfloat tamanio, GLfloat x0, GLfloat y0, GLfloat z0,
          double girx, double giry, double girz,
          float xdir, float ydir, float zdir);

    void forward();
    void backward();
    void turnleft();
    void turnright();
    point4 direction;

    //sobrecarreguem els metodes necessaris de la classe objecte
    void readObj(QString filename);
    void make();
    void draw();
    void aplicaTGCentrat(mat4 m);
    void toGPU(QGLShaderProgram *p);
    void aplicaTG(mat4 m);

private:
    static const int NumVerticesF = 100000;
    static const int NumCares = 300000;

    //declarem i inicialitzem el vector que contindra els elements del cotxe
    vector<Objecte*> elements;

    //rodes del cotxe
    Roda *roda_davantera_esquerra;
    Roda *roda_davantera_dreta;
    Roda *roda_posterior_esquerra;
    Roda *roda_posterior_dreta;

    //carrosseria del cotxe
    Carrosseria *carrosseria;
    vector<Objecte*>::iterator itCotxe;

    Capsa3D calculCapsa3D();
};

#endif // COTXE_H
