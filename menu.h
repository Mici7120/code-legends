#ifndef MENU_H
#define MENU_H

#include "avatar.h"
#include "ejercito.h"
#include "box.h"
#include "tablero.h"
#include "juegoBase.h"

class Menu{
  public:
  Menu();
  void MenuPrincipal();
  void Instrucciones();
  JuegoBase Partida;
};

#endif