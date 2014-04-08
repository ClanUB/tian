#include <escena.h>

using namespace std;

escena::escena()

{
    // Capsa minima contenidora provisional: S'ha de fer un recorregut dels objectes de l'escenes
    capsaMinima.pmin[0] = -25;
    capsaMinima.pmin[1] = -25;
    capsaMinima.pmin[2] = -25;
    capsaMinima.a = 25;
    capsaMinima.h = 25;
    capsaMinima.p = 25;

    terra = NULL;
    cotxe_1 = NULL;
    cotxe_2 = NULL;
    cameraPanoramica = NULL;
    cameraThirdPerson = NULL;
}


escena::~escena()
{
    printf("DESTRUCTOR!");

}

void escena::addObjecte(Objecte *obj) {
    if (dynamic_cast<Cotxe*>(obj)){
        //inserim el cotxe a la llista de cotxes
        if (cotxe_1 == NULL) cotxe_1 = (Cotxe*) obj;
        else if(cotxe_2 == NULL) cotxe_2 = (Cotxe*) obj;

        cotxes.add((Cotxe*) obj);
    }

    if (dynamic_cast<Obstacle*>(obj)){
        //inserim el cotxe a la llista de cotxes
        obstacles.add((Obstacle*) obj);
    }

    if (dynamic_cast<Terra*>(obj))
        this->terra = (Terra*)obj;
}


void escena::CapsaMinCont3DEscena()
{
    // Metode a implementar
    //TODO
    vec3 pmin, pmax;

    CotxeContainer[0]->calculCapsa3D();
    Capsa3D capsa_init = CotxeContainer[0]->capsa;

    pmin.x = capsa_init.pmin.x;
    pmin.y = capsa_init.pmin.y;
    pmin.z = capsa_init.pmin.z;

    pmax.x = capsa_init.pmin.x + capsa_init.a;
    pmax.y = capsa_init.pmin.y + capsa_init.h;
    pmax.z = capsa_init.pmin.z + capsa_init.p;

    for ( int i = 1; i < CotxeContainer.size(); i++ ){
        CotxeContainer[i]->calculCapsa3D();
        Capsa3D capsa = CotxeContainer[i]->capsa;
        if(capsa.pmin.x < pmin.x) pmin.x = capsa.pmin.x;
        if(capsa.pmin.y < pmin.y) pmin.y = capsa.pmin.y;
        if(capsa.pmin.z < pmin.z) pmin.z = capsa.pmin.z;

        if(capsa.pmin.x + capsa.a > pmax.x) pmax.x = capsa.pmin.x + capsa.a;
        if(capsa.pmin.y + capsa.h > pmax.y) pmax.y = capsa.pmin.y + capsa.h;
        if(capsa.pmin.z + capsa.p > pmax.z) pmax.z = capsa.pmin.z + capsa.p;
    }

    for (int i =0; i<ObstacleContainer.size(); i++){
        ObstacleContainer[i]->calculCapsa3D();
        Capsa3D capsa = ObstacleContainer[i]->capsa;

        if(capsa.pmin.x < pmin.x) pmin.x = capsa.pmin.x;
        if(capsa.pmin.y < pmin.y) pmin.y = capsa.pmin.y;
        if(capsa.pmin.z < pmin.z) pmin.z = capsa.pmin.z;

        if(capsa.pmin.x + capsa.a > pmax.x) pmax.x = capsa.pmin.x + capsa.a;
        if(capsa.pmin.y + capsa.h > pmax.y) pmax.y = capsa.pmin.y + capsa.h;
        if(capsa.pmin.z + capsa.p > pmax.z) pmax.z = capsa.pmin.z + capsa.p;
    }

    this->capsa.pmin = pmin;
    this->capsa.a = pmax.x - pmin.x;
    this->capsa.h = pmax.y - pmin.y;
    this->capsa.p = pmax.z - pmin.z;

    return this->capsa;
}

void escena::aplicaTG(mat4 m) {

    // Metode a modificar
    //apliquem a la llista de cotxes
    cotxes.aplicaTG(m);
    obstacles.aplicaTG(m);
    if(terra!=NULL)
        terra->aplicaTG(m);

}

void escena::aplicaTGCentrat(mat4 m) {

    // Metode a modificar
    //apliquem a la llista de cotxes
    cotxes.aplicaTGCentrat(m);
    obstacles.aplicaTGCentrat(m);
    if(terra!=NULL)
        terra->aplicaTGCentrat(m);

}

void escena::draw() {

    // Metode a modificar

    cotxes.draw();
    obstacles.draw();
    if (terra!=NULL)
        terra->draw();
}

void escena::reset() {

    // posem tots els element al origin
    float yorig = terra!=NULL ? terra->getYOrig() : 0;
    // Metode a modificar
    cotxes.reset(yorig);
    obstacles.reset(yorig);
    if (terra!=NULL)
        terra->make();

}

void escena::accelera_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->forward();
    }
}
void escena::desaccelera_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->backward();
    }
}

void escena::gira_dreta_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->turnright();
    }
}

void escena::gira_esquerra_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->turnleft();
    }
}
void escena::llibera_gir_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->llibera_gir();
    }
}

void escena::llibera_acceleracio_cotxe1(){
    if(cotxe_1!=NULL){
        cotxe_1->llibera_acceleracio();
    }
}
/**
 * Retorna el punt y origen de l'escena
 * @brief escena::getYOrig
 * @return
 */
float escena::getYOrig(){
    if (terra!=NULL)
        return terra->getYOrig();
    else
        return 0;

}


void escena::temps(){
    cotxes.temps();
}

vector<Cotxe *> escena::getCotxes(){
    return cotxes.getListado();
}

vector<Obstacle *> escena::getObstacles(){
    return obstacles.getListado();
}

void escena::actualitzaCameraPanoramica(bool clip){}
void escena::resetCameraPanoramica(){}
void escena::actualitzaCameraThirdPerson(){}
void escena::iniLookAtCotxe(){}
