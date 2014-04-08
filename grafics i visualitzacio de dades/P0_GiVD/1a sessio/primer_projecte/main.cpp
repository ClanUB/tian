#include <iostream>
#include <vector>
#include <primera.h>
#include <hija1.h>
#include <hija2.h>

using namespace std; //Sirve para agrupar clases
using namespace miespacio;
//En otros ficheros tambien puede haber namespace operaciones con otras funciones, pero todos son el mismo namespace

namespace operaciones {
    int suma(int x,int y){
        return x+y;
    }
}

int main()
{
    int x,y;
    cin >> x;
    cin >> y;
    int sumaEntero = operaciones::suma(x,y);
    string hola = "Hello!";

    vector<int> miVector;
    miVector.push_back(x);
    miVector.push_back(y);


    cout << "La suma es: " <<sumaEntero << endl;
    //std::cout
    cout << hola << endl;

    //miespacio::Primera miClase;
    Hija1 miClase;//Llama al constructor por defecto
    miClase.setValues(8, 9);

    //Primera miClase(6, 7);//Llamo al segundo constructor
    Hija2 *miOtraClase;//De momento no hace nada
    miOtraClase = new Hija2(); //Reservar memoria para el puntero, equivalente al malloc en 'c'

    miOtraClase->setValues(6,9);

    Primera *miPuntero; //No puedo instanciar una clase abstracta pero sí un puntero

    miPuntero = &miClase; //Apuntar al hija1
    miPuntero->getNum();

    miPuntero = miOtraClase;
    miPuntero->getNum();

    vector<Primera*> miVector2;
    miVector2.push_back(&miClase);
    miVector2.push_back(miOtraClase);

    miVector2[0]->getNum();
    delete miOtraClase; //Llama al destructor de la clase

    return 0;
}

