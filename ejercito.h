#ifndef EJERCITO_H
#define EJERCITO_H //Guardas.

#include "avatar.h"
#include <vector>
using namespace std;

//Se creo la clase ejercito la cual tendra atributos protegidos, los cuales nos serviran para guardar los valores que se introduzcan en el constructor, de igual forma el constructor tendra tres parametros que seran los grupos de cada tipo de avatares.
class Ejercito{
  public: 
    Ejercito();
    //Seran los metodos que nos servira para dar la cantidad total de cada tipo de avatar y de igual forma nos dara la suma total de cada ejercito de avatares.
    int getCantidadLuchadores();
    int getCantidadTiradores();
    int getCantidadMagos();
    int soldadosVivos();
    
    bool derrotado();
    void operator / (Ejercito atacado);
    void restarVida(float vidaPerdida);
    float sumaPoder();
    float sumaMana();
    void setEjercito(int luchadores, int tiradores, int magos);
    vector<Avatar*> ejercitoAvatar; //avatar* es un vector de punteros a la clase avatar.
    void movimientoEjercito(Ejercito ejercitoMovido);

  //Para obtener peor vida, y restaurar vida
    float obtenerPeorVida(vector<float> vidas);
    void restaurarVida(float peorVida);
    int cantidadEjercito;
};

#endif