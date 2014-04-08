#include "conjuntobjectes.h"

ConjuntObjectes::ConjuntObjectes()
{
    nObjectes = 0;
}

void ConjuntObjectes::afegirObjecte(Objecte *o) {
    Objecte *newObj=new Objecte();
    o->copiaObjecte(*newObj); //Para asegurar que cada puntero de objeto apunte a un objeto diferente, asi a la hora de borrar no podra dar error.

    if (nObjectes<MAX_OBJECTES) {
        conjunt[nObjectes]= newObj;
        nObjectes++;
    }
}

void ConjuntObjectes::imprimirConjunt() {
    for (int i=0; i<nObjectes; i++) {
        conjunt[i]->imprimir();
    }
}

ConjuntObjectes::~ConjuntObjectes() {
    cout<<"Esborrant objectes"<<endl;
    for (int i=0; i<nObjectes; i++) {
        // delete conjunt[i];
        if (dynamic_cast<Rectangle*>(conjunt[i])) //instanceof de java.
                delete (Rectangle *)(conjunt[i]);
    }
}
