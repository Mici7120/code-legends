#include "box.h"

Box::Box(){
  ID = 0;
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
  cout << "Estado Ejercito " << ID << endl;
  cout<< "Cantidad Luchadores: " << endl;
  cout<< "Cantidad Tiradores: "  << endl;
  cout<< "Cantidad Magos: " << endl;
}
  
void Box::setTieneEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago){
  ejercito.setCantidadEjercito(numeroLuchadores, numeroTiradores, numeroMago);
}

// Aqui debes hacer lo de sumas de habilidades, sin tocar la clase avatar ni la clase ejercito