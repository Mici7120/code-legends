#ifndef TABLERO_H
#define TABLERO_H

#include "box.h"
using namespace std;

class Tablero{
  public:
  Tablero(string configurarTablero);
  ~Tablero();
  void nuevaPartida();
  void cargarPartida();
  void imprimirTablero();
  Box **matrizTablero;

  int Ejercito1X, Ejercito1Y, Ejercito2X, Ejercito2Y;
};

#endif