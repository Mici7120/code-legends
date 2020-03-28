#include "box.h"

Box::Box(){
  Torreta = false;
  tieneEjercito = false;
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

void Box::setEjercito(int NLuchadores, int NTiradores, int NMagos){
  //ejercito = new Ejercito(NLuchadores, NTiradores, NMagos);
  
  
}

void Box::informacionEjercito(){
  cout << "Estado Ejercito " << ID << endl;
  cout<< "Cantidad Luchadores: " << ejercito->getCantidadLuchadores() << endl;
  cout<< "Cantidad Tiradores: " << ejercito->getCantidadTiradores() << endl;
  cout<< "Cantidad Magos: " << ejercito->getCantidadMagos() << endl << endl;
}
  
void Box::setTieneEjercito(int NLuchadores, int NTiradores, int NMagos){
  tieneEjercito = true;
  ejercito = new Ejercito(NLuchadores, NTiradores, NMagos);
}

// Aqui debes hacer lo de sumas de habilidades, sin tocar la clase avatar ni la clase ejercito