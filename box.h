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
    /*< Posición de la torreta */
    int vidaTorreta;
    /*< Puntos de gole de la torreta (vida) */
    bool Norte, Sur, Este, Oeste;
    /*< Posición de los escudos de la torreta */
    void setTorreta();
    void daNoTorreta();
    
    Ejercito ejercito;
    void setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago);
    void movimientoEjercito(Box boxMovido);
    bool Derrotado();
    void informacionEjercito();
};

#endif