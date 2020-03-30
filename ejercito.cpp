#include "ejercito.h"

//Aqui cada cantidad de cada tipo de avatares(cantidadLuchadores,cantidadTiradores, cantidadMagos) guardara los valores que se introduciran en el ejercito ejemplo: 15 luchadores, 12 tiradores, 10 magos.
Ejercito::Ejercito(int numeroLuchadores, int numeroTiradores, int numeroMagos){

  cantidadLuchadores = numeroLuchadores;
  cantidadTiradores = numeroTiradores;
  cantidadMagos = numeroMagos;
  /*
  setCantidadEjercito(numeroLuchadores, numeroTiradores, numeroMagos);
  */
  
} 

//Esta implementacion no dara la cantidad total de los luchadores
int Ejercito::getCantidadLuchadores(){
  return cantidadLuchadores;
}

//Esta implementacion no dara la cantidad total de los tiradores
int Ejercito::getCantidadTiradores(){
  return cantidadTiradores;
}

//Esta implementacion no dara la cantidad total de los magos
int Ejercito::getCantidadMagos(){
  return cantidadMagos;
}


//Setea el ejercito con el fin de modificar sus valores
void Ejercito::setCantidadEjercito(int luchadores, int tiradores, int magos){
    ejercitoAvatar.clear();
    for(int cual = 0; cual < luchadores ; cual++){
      ejercitoAvatar.push_back(new Avatar("luchador")); //Añado al vector la cantidad de luchadores que el usuario tiene 
    }
    for(int cual = 0; cual < tiradores ; cual++){
      ejercitoAvatar.push_back(new Avatar("tirador")); //Añado al vector la cantidad de tiradores que el usuario tiene 
    }
    for(int cual = 0; cual < magos ; cual++){
      ejercitoAvatar.push_back(new Avatar("mago")); //Añado al vector la cantidad de magos que el usuario tiene 
    }

}

// Esta implementacion obtendra los valores modificados o los valores que se actualizaran para dar el ejercito
vector<Avatar*> Ejercito::getEjercito(){ //cree un nuevo tipo el cual es: vector<*avatar>
  return ejercitoAvatar;
}
