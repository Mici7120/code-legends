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
    /*!< Posición de la torreta */
    int vidaTorreta;
    /*!< Puntos de gole de la torreta (vida) */
    bool Norte, Sur, Este, Oeste;
    /*!< Posición de los escudos de la torreta */
    void setTorreta(int _valoresTorreta[5]);
    void setTorretaInicial();
    void daNoTorreta();
    
    Ejercito ejercito;
    void setEjercitoInicial(int numeroLuchadores, int numeroTiradores, int numeroMago);
    void setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago, vector<float> vidas);
    void movimientoEjercito(Box boxMovido);
    bool Derrotado();
    void informacionEjercito();
};

#endif