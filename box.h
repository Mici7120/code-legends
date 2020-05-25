#ifndef BOX_H
#define BOX_H

#include "ejercito.h"
using namespace std;

class Box{
  public:
    Box();
    int ID;
    void setID(int id);
    int getID();

    bool Torreta;
    int vidaTorreta;
    bool Norte, Sur, Este, Oeste;
    void setTorreta();
    void daNoTorreta();
    
    Ejercito ejercito;
    void setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago);
    void movimientoEjercito(Box boxMovido);
    bool Derrotado();
    void informacionEjercito();
};

#endif