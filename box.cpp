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

//Configura el box como una torreta, con sus valores iniciales
void Box::setTorreta(){
  Torreta = true;
  Norte = true;
  Sur = true;
  Este = true;
  Oeste = true;
  vidaTorreta = 4;
  }

//
void Box::daNoTorreta(){
  vidaTorreta --;
}

//Imprime las estadisticas del ejercito
void Box::informacionEjercito(){
  cout << "\nEstado Ejercito " << getID() << endl;
  cout << "\nTotal Luchadores: " << ejercito.getCantidadLuchadores();
  int contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "luchador" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\n\tVida Luchador " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida();
      contador ++;
      }
    }

  cout << "\nTotal Tiradores: "  << ejercito.getCantidadTiradores();
  contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "tirador" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\n\tVida Tirador " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida();
      contador ++;
      }
    }

  cout << "\nTotal Magos: " << ejercito.getCantidadMagos();
  contador = 1;
  for(int i = 0; i < ejercito.cantidadEjercito; i++){
    if(ejercito.ejercitoAvatar[i] -> getTipo() == "mago" && ejercito.ejercitoAvatar[i] -> getVida() > 0){
      cout << "\n\tVida Mago " << contador << ": " << ejercito.ejercitoAvatar[i] -> getVida();
      contador ++;
      }
    }
  cout << endl;
}
  
void Box::setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago){
  ejercito.setEjercito(numeroLuchadores, numeroTiradores, numeroMago);
}

void Box::movimientoEjercito(Box boxMovido){
  ejercito.movimientoEjercito(boxMovido.ejercito);

  /*
  setEjercito(boxMovido.ejercito.getCantidadLuchadores(),boxMovido.ejercito.getCantidadTiradores(),boxMovido.ejercito.getCantidadMagos());
  ejercito.ejercitoAvatar.clear();
  for(int i = 0; i < 2; i++){
    ejercito.ejercitoAvatar.push_back(new Avatar("mago"));
  }
  boxMovido.ejercito.ejercitoAvatar.clear();
  */
}

bool Box::Derrotado(){
  return ejercito.derrotado();
}
// Aqui debes hacer lo de sumas de habilidades, sin tocar la clase avatar ni la clase ejercito