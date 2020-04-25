#ifndef MENU_H
#define MENU_H

#include "avatar.h"
#include "ejercito.h"
#include "box.h"
#include "tablero.h"
using namespace std;

class Menu{
  public:
  Menu();
  void MenuPrincipal();
  void configurarPartida(int tipoConfiguracion);
  void Instrucciones();
  Tablero tableroDeJuego;
};

#endif