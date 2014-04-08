#ifndef TERRA_H
#define TERRA_H

#include <objecte.h>
#include <iostream>

class Terra : public Objecte
{
public:
    Terra(GLfloat amp, GLfloat alt, GLfloat prof);
    ~Terra();
    void make(); //Sobrecarregar el make de la Objecte

private:
    static const int NumVertices = 6; //(2 faces)(2 triangles/face)(3 vertices/triangle)
    void quad(int a, int b, int c, int d);
    GLfloat amp, alt, prof;
    point4 vertices[4]; // 8 vertexs del cub
    color4 vertex_colors[4]; // 8 colors RGBA associats a cada vertex
};

#endif // TERRA_H
