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
  void setTorreta();
  
  Ejercito ejercito;
  void setTieneEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago);

  void informacionEjercito();

};

#endif