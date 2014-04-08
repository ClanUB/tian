#include "cotxe.h"

Cotxe::Cotxe(QString n) : Objecte(NumVerticesF)
{
    nom = n;
    Index = 0;
    tam = 1;

    xorig = 0;
    yorig = 0;
    zorig = 0;

    xRot = 0;
    yRot = 0;
    zRot = 0;

    this->direction[0] = -1;
    this->direction[1] = 0;
    this->direction[2] = 0;
    this->direction[3] = 0;

    readObj(n);
    this->make();
}

Cotxe::Cotxe(QString n, GLfloat mida, GLfloat x0, GLfloat y0, GLfloat z0,
             double girx, double giry, double girz,
             float xdir, float ydir, float zdir):Objecte(NumVerticesF, n, mida, x0, y0, z0, girx, giry, girz)
{  

    //creem les rodes del cotxe
    roda_davantera_esquerra = new Roda(mida,x0, y0, z0,girx,  giry, girz);
    roda_davantera_dreta = new Roda(mida,x0, y0, z0,girx,  giry, girz);
    roda_posterior_esquerra = new Roda(mida,x0, y0, z0,girx,  giry, girz);
    roda_posterior_dreta = new Roda(mida,x0, y0, z0,girx,  giry, girz);
    //creem la carrosseria del cotxe
    carrosseria = new Carrosseria(mida,x0, y0, z0,girx,  giry, girz);

    //afegim els elements creats al vector del cotxe
    this->elements.push_back(roda_davantera_esquerra);
    this->elements.push_back(roda_davantera_dreta);
    this->elements.push_back(roda_posterior_esquerra);
    this->elements.push_back(roda_posterior_dreta);
    this->elements.push_back(carrosseria);

    readObj(n);
    this->make();

    // El seguent codi escala el cotxe entre 0 i 1 i el situa el seu centre 0,0,0. aixo fa que es vegi en la
    //primera visualització
    double escalaX = 1.0 / 4.6;
    mat4 m= Translate(-1.93*escalaX, (+0.26)*escalaX, -2.16*escalaX)*Scale(escalaX, escalaX, escalaX)
            *Translate(+1.93, -0.26, 2.16);

    aplicaTG(m);
}

void Cotxe::draw()
{
    cout<<"entro en draw"<<endl;
    for (int i = 0; i < elements.size(); i++)
        elements.at(i)->draw();
}

void Cotxe::aplicaTGCentrat(mat4 m)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->aplicaTGPoints(m);;
        elements.at(i)->aplicaTG(m);
    }
}

void Cotxe::toGPU(QGLShaderProgram *p)
{
    for (int i = 0; i < elements.size(); i++)
        elements.at(i)->toGPU(p);
}


void Cotxe::aplicaTG(mat4 m)
{
    for (int i = 0; i < elements.size(); i++)
        elements.at(i)->aplicaTG(m);
}

void Cotxe::forward(){
    // Metode a implementar per fer el moviment del cotxe
}

void Cotxe::backward(){
    // Metode a implementar per fer el moviment del cotxe

}

void Cotxe::turnleft(){
    // Metode a implementar per fer el moviment del cotxe

}

void Cotxe::turnright(){
    // Metode a implementar per fer el moviment del cotxe

}

void Cotxe::make(){
    Objecte *o;
    for (itCotxe=elements.begin(); itCotxe!=elements.end(); itCotxe++){
        o=(*itCotxe);
        o->make();
    }
}

//Calcula la capsa minima contenidora del cotxe. la CMC del cotxe es la CMC de les CMCs de les rodes i de la carrosseria.
Capsa3D Cotxe::calculCapsa3D(){
    vec3 pmin,pmax; //Declarar e instanciar la estructura vec 3 para guardar el pmin y el pmax (3D).
    pmin.x=1000;
    pmin.y=1000;
    pmin.z=1000;
    pmax.x=-1000;
    pmax.y=-1000;
    pmax.z=-1000;

    /*Iterar sobre les components del cotxe per calcular la CMC d'ells, cada component va a cridar al metode calculCapsa3D
     *del pare (classe Objecte). Despres, es comparen els punts de les CMCs de les components per obtenir la CMC del cotxe.*/
    for (itCotxe=elements.begin(); itCotxe!=elements.end(); itCotxe++){
        Objecte *o=(*itCotxe);
        Capsa3D capsa=o->calculCapsa3D();

        if (pmin.x>capsa.pmin.x)    pmin.x=capsa.pmin.x;
        if (pmin.y>capsa.pmin.y)    pmin.y=capsa.pmin.y;
        if (pmin.z>capsa.pmin.z)    pmin.z=capsa.pmin.z;
        if (pmax.x<capsa.pmin.x+capsa.a) pmax.x=capsa.pmin.x+capsa.a;
        if (pmax.y<capsa.pmin.y+capsa.h) pmax.y=capsa.pmin.y+capsa.h;
        if (pmax.z<capsa.pmin.z+capsa.p) pmax.z=capsa.pmin.z+capsa.p;
    }
    capsa.pmin=pmin;
    capsa.a=pmax.x-pmin.x;
    capsa.h=pmax.y-pmin.y;
    capsa.p=pmax.z-pmin.z;
    cout<<capsa.pmin.x<<endl;

    return capsa;
}

void Cotxe::readObj(QString filename) {
    Objecte *actual;
    FILE *fp = fopen(filename.toLocal8Bit(),"rb");
    if (!fp)
    {
        cout << "No puc obrir el fitxer " << endl;
    }
    else {

        int vindexAct = 0;
        int vindexUlt = 0;
        int indexObjecte = -1;

        while (true)
        {
            char *comment_ptr = ReadFile::fetch_line (fp);

            if (comment_ptr == (char *) -1)  /* end-of-file */
                break;

            /* did we get a comment? */
            if (comment_ptr) {
                //make_comment (comment_ptr);
                continue;
            }

            /* if we get here, the line was not a comment */
            int nwords = ReadFile::fetch_words();

            /* skip empty lines */
            if (nwords == 0)
                continue;

            char *first_word = ReadFile::words[0];

            if (!strcmp (first_word, "v"))
            {
                if (nwords < 4)
                {
                    fprintf (stderr, "Too few coordinates");//: '%s'", str_orig);
                    exit (-1);
                }
                QString sx(ReadFile::words[1]);
                QString sy(ReadFile::words[2]);
                QString sz(ReadFile::words[3]);
                double x = sx.toDouble();
                double y = sy.toDouble();
                double z = sz.toDouble();

                if (nwords == 5)
                {
                  QString sw(ReadFile::words[4]);
                  double w = sw.toDouble();
                  x/=w;
                  y/=w;
                  z/=w;
                }
                // S'afegeix el vertex a l'objecte
                actual = elements[indexObjecte];
                actual->vertexs.push_back(point4(x, y, z, 1));
                vindexAct++;

            }
            else if (!strcmp (first_word, "vn")) {
            }
            else if (!strcmp (first_word, "vt")) {
            }
            else if (!strcmp (first_word, "f")) {
                // S'afegeix la cara a l'objecte
                actual = elements[indexObjecte];
                construeix_cara (&ReadFile::words[1], nwords-1, this, vindexUlt);
            }
            // added
            else if (!strcmp (first_word, "mtllib")) {
                //read_mtllib (&words[1], nwords-1, matlib, filename);
            }
            else if (!strcmp (first_word, "usemtl")) {
                //int size = strlen(words[1])-1;
                //while (size && (words[1][size]=='\n' || words[1][size]=='\r') ) words[1][size--]=0;
                //currentMaterial = matlib.index(words[1]);
            }
            else if (!strcmp (first_word, "o")) {
                //cada nou objecte s'actualitza aquest Ã­ndex
                indexObjecte++;
                vindexUlt = vindexAct;
            }
            // fadded
            else {
                //fprintf (stderr, "Do not recognize: '%s'\n", str_orig);
            }

            //free(words);
        }
    }
}

