#include "ejercito.h"

Ejercito::Ejercito(){
} 

int Ejercito::getCantidadLuchadores(){
  int Luchadores = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "luchador" && ejercitoAvatar[i] -> getVida() > 0){
      Luchadores ++;
    }
  }
  return Luchadores;
}
/*!< Esta implementacion nos dara la cantidad total de luchadores vivos */

int Ejercito::getCantidadTiradores(){
  int Tiradores = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "tirador" && ejercitoAvatar[i] -> getVida() > 0){
      Tiradores ++;
    }
  }
  return Tiradores;
}
/*!< Esta implementacion nos dara la cantidad total de tiradores vivos */

int Ejercito::getCantidadMagos(){
  int Magos = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "mago" && ejercitoAvatar[i] -> getVida() > 0){
      Magos ++;
    }
  }
  return Magos;
}
/*!< Esta implementacion nos dara la cantidad total de magos vivos */

void Ejercito::setEjercitoInicial(int luchadores, int tiradores, int magos){
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
  Luchadores = luchadores;
  Tiradores = tiradores;
  Magos = magos;
  cantidadEjercito = luchadores + tiradores + magos;
}
/*!< Inicializa el ejercito con la cantidad correspondiente de avatares */

void Ejercito::setEjercito(int luchadores, int tiradores, int magos, vector<float> vidas){
  ejercitoAvatar.clear();
  int vector = 0;
  //Añado al vector la cantidad de luchadores que el usuario tiene. 
  for(int i = 0; i < luchadores; i ++){
    ejercitoAvatar.push_back(new Avatar("luchador"));
    ejercitoAvatar[vector] -> setVida(vidas[vector]);
    vector ++;
  }
  //Añado al vector la cantidad de tiradores que el usuario tiene.
  for(int i = 0; i < tiradores; i ++){
    ejercitoAvatar.push_back(new Avatar("tirador"));
    ejercitoAvatar[vector] -> setVida(vidas[vector]);
    vector ++;
  }
  //Añado al vector la cantidad de magos que el usuario tiene.
  for(int i = 0; i < magos; i ++){
    ejercitoAvatar.push_back(new Avatar("mago"));
    ejercitoAvatar[vector] -> setVida(vidas[vector]);
    vector ++;
  }
  Luchadores = luchadores;
  Tiradores = tiradores;
  Magos = magos;
  cantidadEjercito = luchadores + tiradores + magos;
}
/*!< Inicializa el ejercito con la cantidad correspondiente de avatares y su respectiva vida */

int Ejercito::soldadosVivos(){
  int numeroDeSoldados = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
      numeroDeSoldados ++;
    }
  }
  return numeroDeSoldados;
}
/*!< Indica el numero de soldados vivos*/

bool Ejercito::derrotado(){
    if(soldadosVivos() <= 0){
      return true;
      }else{
        return false;
      }
  }
/*!< Indica si el ejercito ha sido destruido */

float Ejercito::sumaPoder(){
  int poderTotal = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
      poderTotal += ejercitoAvatar[i] -> getPoder();
      }
    }
  return poderTotal;
  }
/*!< Suma los puntos de poder del ejercito */

float Ejercito::sumaMana(){
  int manaTotal = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getVida() > 0){
    manaTotal += ejercitoAvatar[i] -> getMana();
    }
  }
  return manaTotal;
}
/*!< Suma los puntos de mana del ejercito */

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
/*!< Resta vida al avatar de menor poder */

void Ejercito::operator / (Ejercito ejercitoAtacado){
  if(sumaPoder() > ejercitoAtacado.sumaMana()){
    ejercitoAtacado.restarVida(.5);
  }else if(sumaPoder() < ejercitoAtacado.sumaMana()){
    restarVida(.5);
  }else{
    ejercitoAtacado.restarVida(.2);
    restarVida(.2);
  }
}
/*!< Recibe como parametro al otro ejercito y hace el combate */

void Ejercito::movimientoEjercito(Ejercito ejercitoMovido){
  ejercitoAvatar.clear();
  setEjercitoInicial(ejercitoMovido.Luchadores, ejercitoMovido.Tiradores, ejercitoMovido.Magos);
  cantidadEjercito = ejercitoMovido.cantidadEjercito;
  for(int i = 0; i < cantidadEjercito; i++){
    ejercitoAvatar[i] -> setVida(ejercitoMovido.ejercitoAvatar[i] -> getVida());
  }
  ejercitoMovido.ejercitoAvatar.clear();
}
/*!< Mueve los avatares del vector de un ejercito a otro */

float Ejercito:: obtenerPeorVida(vector<float> vidas){
  vector<float> ejercitoCopia = vidas; //Ejercito copia, Guarda todas las vidas

  //Ordeno de menor a mayor las vidas
  float temporal = 0;
  for(int i = 1; i< ejercitoCopia.size(); i++){
    for(int j = 0; j< ejercitoCopia.size()-1; j++){
      if(ejercitoCopia[j] > ejercitoCopia[j+1]){
        temporal = ejercitoCopia[j];
        ejercitoCopia[j] = ejercitoCopia[j+1];
        ejercitoCopia[j+1] = temporal;
      }
    }
  }
  //Retorna la peor vida
  return ejercitoCopia[0];
}
/*!< Ordenara todas las vidas de menor a mayor y obtendra la peor vida */

void Ejercito:: restaurarVida(float peorVida){
    //Imprime las vidas iniciales, es decir las afectadas para verlas antes de ser restauradas
    for(int index = 0; index < ejercitoAvatar.size(); index++){
      cout<< ejercitoAvatar[index]->getTipo()<< endl;
      cout<< ejercitoAvatar[index]->getVida()<< endl;
    }

    //Restaura la vida y luego las imprime otra vez para ver los valores
    for(int index = 0; index < ejercitoAvatar.size(); index++){
      
    //Es la comparacion de todas las vidas de cada tipo de avatar, para saber en que momento esta la peor vida.

    if(ejercitoAvatar[index]->getVida() == peorVida){
      if(ejercitoAvatar[index]->getTipo()=="luchador"){
        float vidaFaltante = 4-ejercitoAvatar[index]->getVida();
        ejercitoAvatar[index]->setVida(vidaFaltante+peorVida);
        break;
      }
      //ejercitoAvatar[index], es cada avatar
      if(ejercitoAvatar[index]->getTipo()=="tirador"){
        float vidaFaltante =3-ejercitoAvatar[index]->getVida();
        ejercitoAvatar[index]->setVida(vidaFaltante+peorVida);
        break;
      }
      if(ejercitoAvatar[index]->getTipo()=="mago"){
        float vidaFaltante = 5-ejercitoAvatar[index]->getVida();
        ejercitoAvatar[index]->setVida(vidaFaltante+peorVida);
        break;
      }
    }
  }
  //Imprime los nuevos valores
  for(int index = 0; index < ejercitoAvatar.size(); index++){
    cout<< ejercitoAvatar[index]->getTipo()<< endl;
    cout<< ejercitoAvatar[index]->getVida()<< endl;
  }
}
/*!< Restaura al avatar con la vida  más baja */