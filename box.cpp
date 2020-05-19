#include "box.h"

Box::Box(){
  Torreta = false;
}

void Box::setID(int id){
  ID = id;
}

int Box::getID(){
  return ID;
}

void Box::setTorreta(){
  Torreta = true;
}

void Box::informacionEjercito(){
  cout << "Estado Ejercito" << endl;
  cout<< "Cantidad Luchadores: " << ejercito.getCantidadLuchadores() << endl;
  int contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "luchador" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\tVida Luchador " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida() << endl;
      contador ++;
      }
    }

  cout<< "Cantidad Tiradores: "  << ejercito.getCantidadTiradores() << endl;
  contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "tirador" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\tVida Tirador " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida() << endl;
      contador ++;
      }
    }

  cout<< "Cantidad Magos: " << ejercito.getCantidadMagos() << endl;
  contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "mago" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\tVida Mago " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida() << endl;
      contador ++;
      }
    }
}
  
void Box::setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago){
  ejercito.setEjercito(numeroLuchadores, numeroTiradores, numeroMago);
}

bool Box::Derrotado(){
  ejercito.derrotado();
}
// Aqui debes hacer lo de sumas de habilidades, sin tocar la clase avatar ni la clase ejercito