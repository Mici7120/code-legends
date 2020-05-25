#include "avatar.h"

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
/*!< Dara las caracteristicas iniciales dependiendo al tipo de avatar */
	
void Avatar::setVida(float _Vida){
  Vida = _Vida;
}
/*!< Modifca la vida del avatar */

void Avatar::restarVida(float _DaNo){
  Vida -= _DaNo;
}
/*!< Resta el daño recibido a la vida del avatar */

string Avatar::getTipo(){
  return tipoAvatar;
}
/*!< Para obtener el tipo de avatar */

float Avatar::getPoder(){
  return Poder;
}
/*!< Para obtener el poder del avatar */

float Avatar::getMana(){
  return Mana;
}
/*!< Para obtener el mana del avatar */

float Avatar::getVida(){
  return Vida;
}
/*!< Para obtener la vida actual del avatar */