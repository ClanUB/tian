#include "terra.h"

Terra::Terra(GLfloat amp, GLfloat alt, GLfloat prof):Objecte(NumVertices)
{
    std::cout<<"Constructor no parametrizat de terra\n";
    this->amp=amp;
    this->alt=alt;
    this->prof=prof;

    Index = 0;
    //tam = 1;

    xorig = 0;
    yorig = alt;
    zorig = 0;

    xRot = 0;
    yRot = 0;
    zRot = 0;

    // Vertices of a unit cube centered at origin, sides aligned with axes
    vertices[0] = point4( -1, yorig, -1, 1.0 );
    vertices[1] = point4( 1, yorig,  -1, 1.0 );
    vertices[2] = point4(  -1, yorig, 1, 1.0 );
    vertices[3] = point4(  1, yorig,  1, 1.0 );

    vertex_colors[0] = color4( 0.0, 0.0, 0.0, 1.0 );  // black
    vertex_colors[1] = color4( 1.0, 0.0, 0.0, 1.0 );  // red
    vertex_colors[2] = color4( 1.0, 1.0, 0.0, 1.0 );  // yellow
    vertex_colors[3] = color4( 0.0, 1.0, 0.0, 1.0 );  // green

    make();
}

Terra::~Terra(){
    std::cout<<"estic en el destructor de la terra"<<endl;
}

void Terra::quad( int a, int b, int c, int d ){
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
    colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
    colors[Index] = vertex_colors[d]; points[Index] = vertices[d]; Index++;
}

void Terra::make(){
    Index=0;
    quad(0,2,3,1);

}
