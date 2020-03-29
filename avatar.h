#ifndef AVATAR_H
#define AVATAR_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include<stdlib.h>
using namespace std;

class Avatar{

 protected:
    string tipoAvatar;
    float poder;
    float mana;
    float vida; 

  public:
    
    Avatar(string tipo);
    void setVida(float nuevaVida); //Para modificar la vida
    string getTipoAvatar();
    float getPoder();
    float getVida();
    float getMana(); 

};

#endif