#ifndef EJERCITO_H
#define EJERCITO_H //Guardas.

#include "avatar.h"
#include <vector>
using namespace std;

class Ejercito{
  public: 
    Ejercito();
    int getCantidadLuchadores();
    int getCantidadTiradores();
    int getCantidadMagos();
    int soldadosVivos();
    
    bool derrotado();
    void operator / (Ejercito atacado);
    void restarVida(float vidaPerdida);
    float sumaPoder();
    float sumaMana();

    vector<Avatar*> ejercitoAvatar;
    /*!< Es un vector de punteros de clase Avatar */
    void setEjercitoInicial(int luchadores, int tiradores, int magos);
    void setEjercito(int luchadores, int tiradores, int magos, vector<float> vidas);
    void movimientoEjercito(Ejercito ejercitoMovido);

    int Luchadores, Tiradores, Magos;
    float obtenerPeorVida(vector<float> vidas);
    void restaurarVida(float peorVida);
    int cantidadEjercito;
    /*!< Numero de unidades dentro del ejercito */
};

#endif