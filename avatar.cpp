#include "avatar.h"

/*
Avatar::Avatar(){

}

void Avatar::setTipo(string tipo){
  Tipo = tipo;
  if(tipo=="luchador"){
    Poder = .7;
    Mana = .6;
    Vida = 4;
  }else if(tipo=="tirador"){
    Poder = 1;
    Mana = .3;
    Vida = 3;
  }else if(tipo=="mago"){
    Poder = .2;
    Mana = 1;
    Vida = 5;
  }

} */

// Para modificar la vida 


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

void Avatar::setVida(float nuevaVida){
  vida=vida-nuevaVida;
}

//Para saber de que tipo es el avatar
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

