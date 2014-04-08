#include "hija2.h"
using namespace miespacio;

Hija2::Hija2():Primera()
{
    //this->x=0; //no hereta del privado y da error de compilacion
    this->setValues(1,2);
}

int Hija2::getNum(){
    return 2;
}
