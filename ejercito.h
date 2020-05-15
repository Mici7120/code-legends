#ifndef EJERCITO_H
#define EJERCITO_H //Guardas.

#include "avatar.h"
#include <vector>
using namespace std;

//Se creo la clase ejercito la cual tendra atributos protegidos, los cuales nos serviran para guardar los valores que se introduzcan en el constructor, de igual forma el constructor tendra tres parametros que seran los grupos de cada tipo de avatares.
class Ejercito{
  public: 
  //Seran los metodos que nos servira para dar la cantidad total de cada tipo de avatar y de igual forma nos dara la suma total de cada ejercito de avatares.
    Ejercito(int numeroLuchadores, int numeroTiradores, int numeroMagos);
    int getCantidadLuchadores();
    int getCantidadTiradores();
    int getCantidadMagos();
    int soldadosVivos();
    bool derrotado();
    void operator / (Ejercito atacado);
    void sumaPoder();
    void sumaMana();
    void setCantidadEjercito(int luchadores, int tiradores, int magos);
    vector<Avatar*> getEjercito();// Obtener el ejercito, obitiene el vector de objetos de avatar.
  protected:
    int cantidadLuchadores, cantidadTiradores, cantidadMagos, cantidadEjercito; 
    vector<Avatar*> ejercitoAvatar; //avatar* es un vector de punteros a la clase avatar.
  
    double poderTotal;
    double manaTotal;
};

#endif