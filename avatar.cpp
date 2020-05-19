#include "avatar.h"

//Dara las caracteristicas de cada tipo de avatar
Avatar::Avatar(string _tipoAvatar){
  tipoAvatar = _tipoAvatar;
  if(tipoAvatar == "luchador"){
    Poder = .7;
    Mana = .6;
    Vida = 4;
  }else if(tipoAvatar == "tirador"){
    Poder = 1;
    Mana = .3;
    Vida = 3;
  }else if(tipoAvatar == "mago"){
    Poder = .2;
    Mana = 1;
    Vida = 5;
  }
}

//Esta implementacion nos dara una nueva vida despues de que el avatar haya perdido sus puntos predeterminados
void Avatar::setVida(float _Vida){
  Vida = _Vida;
}

void Avatar::restarVida(float _Daño){
  Vida -= _Daño;
}

//Esta implementacion nos dara el tipo de avatar
string Avatar::getTipo(){
  return tipoAvatar;
}

//Para obtener el poder del avatar dependiendo del tipo
float Avatar::getPoder(){
  return Poder;
}

//Para obtener el mana del avatar dependiendo del tipo
float Avatar::getMana(){
  return Mana;
}

//Para obtener el mana del avatar dependiendo del tipo
float Avatar::getVida(){
  return Vida;
}