#ifndef RODA_H
#define RODA_H

#include <objecte.h>

class Roda : public Objecte
{
public:
    Roda(GLfloat mida, GLfloat x0, GLfloat y0, GLfloat z0,
         double girx, double giry, double girz);

    void setRadi(GLfloat radi);

private:
    static const int NumVerticesF = 100000;
    static const int NumCares = 300000;

    GLfloat radi;

};

#endif // RODA_H
