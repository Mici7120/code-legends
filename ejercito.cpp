#include "ejercito.h"

Ejercito::Ejercito(int numeroLuchadores, int numeroTiradores, int numeroMagos){

    cantidadLuchadores =numeroLuchadores; 
    cantidadTiradores=numeroTiradores;
    cantidadMagos=numeroMagos;
    setCantidadEjercito( cantidadLuchadores,  cantidadTiradores, cantidadMagos);
  //Cual = Cual avatar.

    
} 

int Ejercito::getCantidadLuchadores(){
  return cantidadLuchadores;
}


int Ejercito::getCantidadTiradores(){
  return cantidadTiradores;
}


int Ejercito::getCantidadMagos(){
  return cantidadMagos;
}


//setea el ejercito modifica los valores.

void Ejercito::setCantidadEjercito(int luchadores, int tiradores, int magos){
    ejercitoAvatar.clear();
    for(int cual = 0; cual < luchadores ; cual++){
      ejercitoAvatar.push_back(new Avatar("luchador")); //Añado al vector la cantidad de luchadores que el usuario tiene 
    }
    for(int cual = 0; cual < tiradores ; cual++){
      ejercitoAvatar.push_back(new Avatar("tirador"));
    }
    for(int cual = 0; cual < magos ; cual++){
      ejercitoAvatar.push_back(new Avatar("mago"));
    }

}

// obtengo los valores modificados o actuales
vector<Avatar*> Ejercito::getEjercito(){ //cree un nuevo tipo el cual es: vector<*avatar>
  return ejercitoAvatar;
}
