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
  void guardarPartida(int _Turno);
  void imprimirTablero();
  Box **matrizTablero;

  int turnoInicial;
  /*!< Turno del Jugador al iniciar la partida */

  int Ejercito1X, Ejercito1Y, Ejercito2X, Ejercito2Y;
  void setCoordenadasEjercito(int _Ejercito, int X, int Y);

  int TorretaX, TorretaY;
  /*!< Posición de la torreta en la matriz */

};

#endif