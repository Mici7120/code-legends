#ifndef BOX_H
#define BOX_H

#include "ejercito.h"
using namespace std;

class Box{
  public:
  Ejercito *ejercito;
  Box();
  int ID;
  void setID(int id);
  int getID();

  bool Torreta;
  bool tieneEjercito;
  void setTieneEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago);
  void setTorreta();

  void informacionEjercito();

};

#endif