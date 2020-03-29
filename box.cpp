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
//Puntos de impacto de la torreta
int torreta = 4;
//Si los puntos de impacto de la torreta llegan a cero
void Box::torretaDestruida(){
  if (torreta == 0){
    cout<<"La torreta ha sido destruida "<<endl;
  }
}

void Box::setEjercito(int NLuchadores, int NTiradores, int NMagos){
  //ejercito = new Ejercito(NLuchadores, NTiradores, NMagos);
  
  
}

//Meotodo el cual dara la informacion del ejercito
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
