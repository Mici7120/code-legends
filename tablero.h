#ifndef TABLERO_H
#define TABLERO_H

#include "box.h"
using namespace std;

class Tablero{
  public:
  Tablero();
  ~Tablero();
  void setMatrizTablero();
  void nuevaPartida();
  void cargarPartida();
  void imprimirTablero();
  Box **matrizTablero;

  int turnoInicial;

  int Ejercito1X, Ejercito1Y, Ejercito2X, Ejercito2Y;
  void setCoordenadasEjercito(int _Ejercito, int X, int Y);

  int TorretaX, TorretaY;
};

#endif