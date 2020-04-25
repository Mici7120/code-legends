#include "juegoBase.h"

JuegoBase::JuegoBase(){

}
void JuegoBase::Main(){
  sorteoTurno();
  int opcion = 0;
  while(opcion != 5){

  }
}

void JuegoBase::sorteoTurno(){
  cout << "Lanzando moneda para decidir turno"
  srand(time(NULL));
  
  cout << "Empieza el jugador " << rand()%2 << endl;
  int opcion = 0;
  while(opcion != 1){
  cout << "\n1. Continuar\n";
    cin >> opcion;
  }
}