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
    string tipoAvatar;
    float poder;
    float mana;
    float vida; 

    
    Avatar(string tipo);
    void setVida(float nuevaVida); //Para modificar la vida
    string getTipoAvatar(); //Clasificara el tipo de avatar para ingresar a la caracteristica del poder
    float getPoder(); //Metodo que nos servira para dar el poder
    float getVida(); //Metodo que nos servira para dar la vida
    float getMana(); //Metodo que nos servira para dar el mana

};

#endif