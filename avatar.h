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
  public:
    Avatar(string _tipoAvatar);
    void setVida(float _Vida);
    void restarVida(float _DaNo);
    string getTipo();
    float getPoder();
    float getVida();
    float getMana();

  protected:
    string tipoAvatar;
    /*!< Tipo de Avatar (luchador, tirador o mago) */
    float Poder;
    /*!< Poder del Avatar (Ataque) */
    float Mana;
    /*!< Mana del Avatar (Defensa) */
    float Vida;
    /*!< Vida */
};

#endif