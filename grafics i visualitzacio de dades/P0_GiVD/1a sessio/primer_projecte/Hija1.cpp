#include "hija1.h"
using namespace miespacio;

Hija1::Hija1():Primera() //Usa el constructor del padre
{
    //this->x=0; //no hereta del privado y da error de compilacion
    this->setValues(1,2);
}

int Hija1::getNum(){
    return 1;
}
