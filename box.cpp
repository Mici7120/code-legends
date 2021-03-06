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

int Box::getVidaTorreta(){
  return vidaTorreta;
}
/*!< Retorna la vida actual de la torreta */

void Box::setVidaTorreta(int _vidaTorreta){
  vidaTorreta = _vidaTorreta;
}
/*!< Modifica la vida de la torreta */

void Box::setTorretaInicial(){
  Torreta = true;
  Norte = true;
  Sur = true;
  Este = true;
  Oeste = true;
  setVidaTorreta(4);
}
/*!< Inicializa los valores predetermindados a la torreta */

void Box::setTorreta(int _valoresTorreta[5]){
  Torreta = true;
  vidaTorreta = _valoresTorreta[0];
  Norte = _valoresTorreta[1];
  Sur = _valoresTorreta[2];
  Este = _valoresTorreta[3];
  Oeste = _valoresTorreta[4];
}
/*!< Configura el box como una torreta, con los valores cargados */

void Box::daNoTorreta(){
  vidaTorreta --;
}
/*!< Daño a la torreta */

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
/*!< Imprime las estadisticas del ejercito */
  
void Box::setEjercitoInicial(int numeroLuchadores, int numeroTiradores, int numeroMago){
  ejercito.setEjercitoInicial(numeroLuchadores, numeroTiradores, numeroMago);
}
/*!< Introduce el numero de unidades de cada tipo de ejercito */

void Box::setEjercito(int numeroLuchadores, int numeroTiradores, int numeroMago, vector<float> vidas){
  ejercito.setEjercito(numeroLuchadores, numeroTiradores, numeroMago, vidas);
}
/*!< Crea el ejercito con los respectivos valores de vida de cada avatar */

void Box::movimientoEjercito(Box boxMovido){
  ejercito.movimientoEjercito(boxMovido.ejercito);
}
/*!< Mueve el ejercito a otro box */

bool Box::Derrotado(){
  return ejercito.derrotado();
}
/*!< Especifica si el ejercito ha sido derrotado */