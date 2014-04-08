#include "objecte.h"

Objecte::Objecte()
{
    cout<<"Crida al constructor d'Objecte"<<endl;
}


Objecte::Objecte(float base, float altura) {
    cout<<"Constructor de l'Objecte amb parametres"<<endl;
    this->base = base;
    this->altura = altura;
}

float Objecte::calculArea() {
    cout<<"Calcul Area de l'Objecte"<<endl;
    return base*altura;

}

void Objecte::copiaObjecte(Objecte &o) {
    o.altura = altura;
    o.base = base;
    cout<<"r: alcada "<<o.altura<<" amplada "<<o.base<<endl;
    cout<<"this: alcada "<<altura<<" amplada "<<base<<endl;

}

Objecte::~Objecte() {
    cout<<"Destructor de objecte"<<endl;

}
