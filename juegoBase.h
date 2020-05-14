#ifndef JUEGOBASE_H
#define JUEGOBASE_H

#include "avatar.h"
#include "ejercito.h"
#include "box.h"
#include "tablero.h"
using namespace std;

class JuegoBase{
  public:
  JuegoBase();
  void Main(string configuracionPartida);
  void configurarNuevaPartida();
  void configurarCargarPartida();
  void sorteoTurno();

  int primerTurno;
  Tablero *tableroDeJuego;
};

#endif