#include "ejercito.h"


Ejercito::Ejercito(){
  cantidadLuchadores  = 0;
  cantidadTiradores = 0;
  cantidadMagos = 0;
  ejercito = new vector<Avatar&>;
}
  
  //Cual = Cual avatar.
void Ejercito::llenarFilas(){
  for(int cual = 0; cual < cantidadLuchadores ; cual++){
      ejercito.push_back(new Avatar("luchador"));
  }
  for(int cual = 0; cual < cantidadTiradores ; cual++){
      ejercito.push_back(new Avatar("tirador"));
  }
  for(int cual = 0; cual < cantidadMagos ; cual++){
      ejercito.push_back(new Avatar("mago"));
  }
    
} 

int Ejercito::getCantidadLuchadores(){
  return cantidadLuchadores;
}

void Ejercito::setCantidadLuchadores(int numero){
  cantidadLuchadores = numero;
}

int Ejercito::getCantidadTiradores(){
  return cantidadTiradores;
}

void Ejercito::setCantidadTiradores(int numero){
  cantidadLuchadores = numero;
}

int Ejercito::getCantidadMagos(){
  return cantidadMagos;
}

void Ejercito::setCantidadMagos(int numero){
  cantidadLuchadores = numero;
}


void Ejercito::setCantidadEjercito(int luchadores, int tiradores, int magos){
  cantidadLuchadores = luchadores;
  cantidadTiradores = tiradores;
  cantidadMagos = magos;

}
/*
//Calcula la suma del poder
void calcularPoder(){
  for()
}
//Calcula la suma del mana
void calcularMana(){
  
}
*/

vector<Avatar*> Ejercito::getEjercito(){ //cree un nuevo tipo el cual es: vector<*avatar>
  return ejercito;
}
