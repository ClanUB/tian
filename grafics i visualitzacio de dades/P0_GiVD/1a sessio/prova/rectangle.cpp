#include "rectangle.h"

Rectangle::Rectangle()
{
    cout<<"Constructor de Rectangle buit"<<endl;
    base = 1.0;
    altura = 1.0;
}

//Llama al constructor del padre Objeto, las asignaciones no hacen falta
Rectangle::Rectangle(float base, float altura):Objecte(base, altura) {
    cout<<"Constructor de Rectangle amb parametres"<<endl;
    //this->base = base;
    //this->altura = altura;
}

float Rectangle::calculArea() {
    return Objecte::calculArea();
}
Rectangle::~Rectangle() {
    cout<<"Destructor de rectangle"<<endl;

}
