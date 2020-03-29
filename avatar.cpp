#include "avatar.h"



//Dara las caracteristicas de cada tipo de avatar


Avatar::Avatar(string tipo){
  tipoAvatar = tipo;
  if(tipoAvatar=="luchador"){
    poder = 0.7;
    mana = .6;
    vida = 4;
  }else if(tipoAvatar=="tirador"){
    poder = 1.0;
    mana = .3;
    vida = 3;
  }else if(tipoAvatar=="mago"){
    poder = 0.2;
    mana = 1;
    vida = 5;
  }
}


//Esta implementacion nos dara una nueva vida despues de que el avatar haya perdido sus puntos predeterminados
void Avatar::setVida(float nuevaVida){
  vida=vida-nuevaVida;
}

//Esta implementacion nos dara el tipo de avatar
string Avatar::getTipoAvatar(){
  return tipoAvatar;
}

//Para obtener el poder del avatar dependiendo del tipo
float Avatar::getPoder(){
  return poder;
}

//Para obtener el mana del avatar dependiendo del tipo

float Avatar::getMana(){
  return mana;
}

//Para obtener el mana del avatar dependiendo del tipo
float Avatar::getVida(){
  return vida;
}