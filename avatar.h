#ifndef AVATAR_H
#define AVATAR_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Avatar{

//Atributos principales de los avatares
  public:
    Avatar(string _tipoAvatar);

    void setVida(float _Vida); //Para modificar la vida
    void restarVida(float _DaNo);
    string getTipo(); //Clasificara el tipo de avatar para ingresar a la caracteristica del poder
    float getPoder(); //Metodo que nos servira para dar el poder
    float getVida(); //Metodo que nos servira para dar la vida
    float getMana(); //Metodo que nos servira para dar el mana

  protected:
    string tipoAvatar;
    float Poder;
    float Mana;
    float Vida; 
};

#endif