#include "ejercito.h"

//Aqui cada cantidad de cada tipo de avatares(cantidadLuchadores,cantidadTiradores, cantidadMagos) guardara los valores que se introduciran en el ejercito ejemplo: 15 luchadores, 12 tiradores, 10 magos.
Ejercito::Ejercito(){

} 

//Esta implementacion nos dara la cantidad total de los luchadores.
int Ejercito::getCantidadLuchadores(){
  int Luchadores = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "luchador" && ejercitoAvatar[i] -> getVida() > 0){
      Luchadores ++;
    }
  }
  return Luchadores;
}

//Esta implementacion nos dara la cantidad total de los tiradores.
int Ejercito::getCantidadTiradores(){
  int Tiradores = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "tirador" && ejercitoAvatar[i] -> getVida() > 0){
      Tiradores ++;
    }
  }
  return Tiradores;
}

//Esta implementacion nos dara la cantidad total de los magos.
int Ejercito::getCantidadMagos(){
  int Magos = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "mago" && ejercitoAvatar[i] -> getVida() > 0){
      Magos ++;
    }
  }
  return Magos;
}

//Setea el ejercito con el fin de modificar sus valores.
void Ejercito::setEjercito(int luchadores, int tiradores, int magos){
  ejercitoAvatar.clear();
  //Añado al vector la cantidad de luchadores que el usuario tiene. 
  for(int i = 0; i < luchadores; i ++){
    ejercitoAvatar.push_back(new Avatar("luchador"));
    }
  //Añado al vector la cantidad de tiradores que el usuario tiene.
  for(int i = 0; i < tiradores; i ++){
    ejercitoAvatar.push_back(new Avatar("tirador"));
    }
  //Añado al vector la cantidad de magos que el usuario tiene.
  for(int i = 0; i < magos; i ++){
    ejercitoAvatar.push_back(new Avatar("mago"));
    }
  cantidadEjercito = luchadores + tiradores + magos;
} 

//Esta implementacion obtendra los valores modificados o los valores que se actualizaran para dar el ejercito.
vector<Avatar*> Ejercito::getEjercito(){ //cree un nuevo tipo el cual es: vector<*avatar>
  return ejercitoAvatar;
  }

//Cuenta el numero de soldados vivos.
int Ejercito::soldadosVivos(){
  int numeroDeSoldados = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
      numeroDeSoldados ++;
      }
    }
  return numeroDeSoldados;
  }

//Indica si el ejercito ha sido destruido.
bool Ejercito::derrotado(){
    if(soldadosVivos() <= 0){
      return true;
      }else{
        return false;
      }
  }

//Suma los puntos de poder del ejercito.
float Ejercito::sumaPoder(){
  int poderTotal = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
      poderTotal += ejercitoAvatar[i] -> getPoder();
      }
    }
  return poderTotal;
  }

//Suma los puntos de mana del ejercito.
float Ejercito::sumaMana(){
  int manaTotal = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
      manaTotal += ejercitoAvatar[i] -> getMana();
      }
    }
  return manaTotal;
  }

void Ejercito::restarVida(float vidaPerdida){
  int i = 0;
  bool Ataque = false;

  while(i < cantidadEjercito && Ataque == false){
    if(ejercitoAvatar[i] -> getTipo() == "mago" && ejercitoAvatar[i] -> getVida() > 0){
      ejercitoAvatar[i] -> restarVida(vidaPerdida);
      Ataque = true;
      }else{
        i++;
      }
    }
  if(Ataque == false){
    i = 0;
    while(i < cantidadEjercito && Ataque == false){
      if(ejercitoAvatar[i] -> getTipo() == "luchador" && ejercitoAvatar[i] -> getVida() > 0){
        ejercitoAvatar[i] -> restarVida(vidaPerdida);
        Ataque = true;
        }else{
          i++;
          }
      }
    }
  if(Ataque == false){
    i = 0;
    while(i < cantidadEjercito && Ataque == false){
      if(ejercitoAvatar[i] -> getTipo() == "tirador" && ejercitoAvatar[i] -> getVida() > 0){
        ejercitoAvatar[i] -> restarVida(vidaPerdida);
        Ataque = true;
        }else{
          i++;
          }
      }
    }
  }

//Recibe al otro Ejercito y hace el combate
void Ejercito::operator / (Ejercito ejercitoAtacado){
  if(sumaPoder() > ejercitoAtacado.sumaMana()){
    ejercitoAtacado.restarVida(2);
    }else if(sumaPoder() < ejercitoAtacado.sumaMana()){
      restarVida(2);
      }else{
        ejercitoAtacado.restarVida(2);
        restarVida(2);
        }
  }

//Mueve los avatares del vector ejercito del Box a otro vector ejercito de otro Box
void Ejercito::movimientoEjercito(Ejercito ejercitoMovido){
  ejercitoAvatar.clear();
  setEjercito(ejercitoMovido.getCantidadLuchadores(), ejercitoMovido.getCantidadTiradores(), ejercitoMovido.getCantidadMagos());
  cantidadEjercito = ejercitoMovido.cantidadEjercito;
  for(int i = 0; i < cantidadEjercito; i++){
    ejercitoAvatar[i] -> setVida(ejercitoMovido.ejercitoAvatar[i] -> getVida());
  }

  ejercitoMovido.ejercitoAvatar.clear();
  }