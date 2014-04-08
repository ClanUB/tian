#ifndef PRIMERA_H
#define PRIMERA_H

namespace miespacio{
    class Primera
    {
    //private, protected, public
    private:
        int *x, *y; //Por defecto son privados
    public:
        Primera(); //Constructor
        Primera(int x, int y);
        ~Primera();//Especificamos el destructor de clase
        void setValues(int x, int y);
        virtual int getNum() = 0; //metodo abstracto,teniendo un metodo abstracto, la clase es abstracta
    };
}

#endif // PRIMERA_H
