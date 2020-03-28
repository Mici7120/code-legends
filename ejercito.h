#ifndef EJERCITO_H
#define EJERCITO_H

#include "avatar.h"
#include <vector>
using namespace std;

class Ejercito{
  protected:
    int cantidadLuchadores, cantidadTiradores, cantidadMagos, cantidadEjercito; 
    vector<Avatar*> ejercitoAvatar; //avatar* es un vector de punteros a la clase avatar
  public: 
  
    Ejercito(int numeroLuchadores, int numeroTiradores, int numeroMago);
    void calcularEjercito(); 
    int getCantidadLuchadores();
    int getCantidadTiradores();
    int getCantidadMagos();
    void setCantidadEjercito(int luchadores, int tiradores, int magos);
    vector<Avatar*> getEjercito();// Obtener el ejercito, obitiene el vector de objetos de avatar
};

#endif