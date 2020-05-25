#ifndef BOX_H
#define BOX_H

#include "ejercito.h"
using namespace std;

class Box{
  public:
    Box();
    int ID;
    /*!< Identificacion de la casilla que indica si es ejercito (1 o 2) o torreta (9) */
    void setID(int id);
    int getID();

    bool Torreta;
    /*!< Posición de la torreta */
    bool Norte, Sur, Este, Oeste;
    /*!< Posición de los escudos de la torreta */
    int getVidaTorreta();
    void setVidaTorreta(int _vidaTorreta);
    void setTorreta(int _valoresTorreta[5]);
    void setTorretaInicial();
    void daNoTorreta();
    
    Ejercito ejercito;
    void setEjercitoInicial(int numeroLuchadores, int numeroTiradores, int numeroMago);
    void setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago, vector<float> vidas);
    void movimientoEjercito(Box boxMovido);
    bool Derrotado();
    void informacionEjercito();

    protected:
    int vidaTorreta;
    /*!< Puntos de golpe de la torreta (vida) */
};

#endif