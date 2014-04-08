#ifndef HIJA1_H
#define HIJA1_H
#include <primera.h>

namespace miespacio{
    //Herencia privada, el hijo no va a poder acceder nada. Hacer más restrictivo a las cosas
    class Hija1 : public Primera //Herencia publico, tengo todos los contenidos publicos y protegidos del padre
    {
    public:
        Hija1();
        int getNum(); //implementar el metodo abstracto del padre para dejar de ser abstracto hija1, ahora se puede instaciar
    };
}
#endif // HIJA1_H
