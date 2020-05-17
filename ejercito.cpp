#include "ejercito.h"

//Aqui cada cantidad de cada tipo de avatares(cantidadLuchadores,cantidadTiradores, cantidadMagos) guardara los valores que se introduciran en el ejercito ejemplo: 15 luchadores, 12 tiradores, 10 magos.
Ejercito::Ejercito(){

} 

//Esta implementacion nos dara la cantidad total de los luchadores.
void Ejercito::getCantidadLuchadores(){
}

//Esta implementacion nos dara la cantidad total de los tiradores.
void Ejercito::getCantidadTiradores(){
}

//Esta implementacion nos dara la cantidad total de los magos.
void Ejercito::getCantidadMagos(){
}


//Setea el ejercito con el fin de modificar sus valores.
void Ejercito::setCantidadEjercito(int luchadores, int tiradores, int magos){
    ejercitoAvatar.clear();
    for(int cual = 0; cual < luchadores ; cual++){
      ejercitoAvatar.push_back(new Avatar("luchador")); //Añado al vector la cantidad de luchadores que el usuario tiene. 
    }
    for(int cual = 0; cual < tiradores ; cual++){
      ejercitoAvatar.push_back(new Avatar("tirador")); //Añado al vector la cantidad de tiradores que el usuario tiene.
    }
    for(int cual = 0; cual < magos ; cual++){
      ejercitoAvatar.push_back(new Avatar("mago")); //Añado al vector la cantidad de magos que el usuario tiene.
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
    for(int i = 0; i <= (6); i++){
      if(ejercitoAvatar[i] -> vida >= 0){
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
double Ejercito::sumaPoder(){
  int poderTotal = 0;
  for(int i = 0; i <= (cantidadEjercito); i++){
    if(ejercitoAvatar[i] -> poder >= 0){
      poderTotal += ejercitoAvatar[i] -> poder;
    }
  }
  return poderTotal;
}

//Suma los puntos de mana del ejercito.
double Ejercito::sumaMana(){
  int manaTotal = 0;
  for(int i = 0; i <= (cantidadEjercito); i++){
    if(ejercitoAvatar[i] -> mana >= 0){
      manaTotal += ejercitoAvatar[i] -> mana;
    }
  }
  return manaTotal;
}

void Ejercito::restarVida(float vidaPerdida){
  int i = 0;
  vector<Avatar*>::iterator iterator;
  iterator = ejercitoAvatar.begin();
  while(ejercitoAvatar[i] -> getTipoAvatar() != "mago" || iterator != ejercitoAvatar.end()){
    i ++;
    iterator ++;
  }
  if(ejercitoAvatar[i] -> getTipoAvatar() != "mago"){
    ejercitoAvatar[i] -> setVida(vidaPerdida);
  }else{
    i = 0;
    iterator = ejercitoAvatar.begin();
    while(ejercitoAvatar[i] -> getTipoAvatar() != "luchador" || iterator != ejercitoAvatar.end()){
    i ++;
    iterator ++;
    }
    if(ejercitoAvatar[i] -> getTipoAvatar() != "luchador"){
      ejercitoAvatar[i] -> setVida(vidaPerdida);
    }else{
      i = 0;
      iterator = ejercitoAvatar.begin();
      while(ejercitoAvatar[i] -> getTipoAvatar() != "tirador" || iterator != ejercitoAvatar.end()){
        i ++;
        iterator ++;
      }
      if(ejercitoAvatar[i] -> getTipoAvatar() != "tirador"){
        ejercitoAvatar[i] -> setVida(vidaPerdida);
      }
    }
  }
}

//Recibe al otro Ejercito y hace el combate
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
