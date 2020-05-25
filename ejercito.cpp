#include "ejercito.h"

//Aqui cada cantidad de cada tipo de avatares(cantidadLuchadores,cantidadTiradores, cantidadMagos) guardara los valores que se introduciran en el ejercito ejemplo: 15 luchadores, 12 tiradores, 10 magos.
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
/*< Esta implementacion nos dara la cantidad total de los luchadores */

int Ejercito::getCantidadTiradores(){
  int Tiradores = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "tirador" && ejercitoAvatar[i] -> getVida() > 0){
      Tiradores ++;
    }
  }
  return Tiradores;
}
/*< Esta implementacion nos dara la cantidad total de los tiradores */

int Ejercito::getCantidadMagos(){
  int Magos = 0;
  for(int i = 0; i < cantidadEjercito; i++){
    if(ejercitoAvatar[i] -> getTipo() == "mago" && ejercitoAvatar[i] -> getVida() > 0){
      Magos ++;
    }
  }
  return Magos;
}
/*< Esta implementacion nos dara la cantidad total de los magos */

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
/*< Setea el ejercito con el fin de modificar sus valores */

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

//Mueve los avatares del vector de un ejercito a otro
void Ejercito::movimientoEjercito(Ejercito ejercitoMovido){
  ejercitoAvatar.clear();
  setEjercito(ejercitoMovido.getCantidadLuchadores(), ejercitoMovido.getCantidadTiradores(), ejercitoMovido.getCantidadMagos());
  cantidadEjercito = ejercitoMovido.cantidadEjercito;
  for(int i = 0; i < cantidadEjercito; i++){
    ejercitoAvatar[i] -> setVida(ejercitoMovido.ejercitoAvatar[i] -> getVida());
    }
  ejercitoMovido.ejercitoAvatar.clear();
  }

//Ordenara todas las vidas de menor a mayor y obtendra la peor vida.
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
/*< Cuenta el numero de soldados vivos */

void Ejercito:: restaurarVida(float peorVida){

  
  cout << "peor vida: " ; //Imprime la peor vida
  cout << peorVida << endl;
  
  //Imprime las vidas iniciales, es decir las afectadas para verlas antes de ser restauradas
      for(int index = 0; index < ejercitoAvatar.size(); index++){
          cout<< ejercitoAvatar[index]->getTipo()<< endl;
          cout<< ejercitoAvatar[index]->getVida()<< endl;
      }

      //Restaura la vida y luego las imprime otra vez para ver los valores
      cout << "RESTAURAR VIDA" << endl;
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
/*< Restaura al avatar con la vida  más baja */