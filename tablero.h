#ifndef TABLERO_H
#define TABLERO_H

#include "avatar.h"
#include "ejercito.h"
#include "box.h"
using namespace std;

class Tablero{
  public:
  Tablero();
  void Interfaz();
  void configurarPartida(int tipoConfiguracion);
  void imprimirTablero();
  Box **Puntero;
};

#endif