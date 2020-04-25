#ifndef TABLERO_H
#define TABLERO_H

#include "box.h"
using namespace std;

class Tablero{
  public:
  Tablero(string configurarTablero);
  void nuevaPartida();
  void cargarPartida();
  void imprimirTablero();
  Box **matrizTablero;
  Box *Ejercito1;
  Box *Ejercito2;
};

#endif