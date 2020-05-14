#include "juegoBase.h"

JuegoBase::JuegoBase(){
}

void JuegoBase::configurarNuevaPartida(){
  tableroDeJuego = new Tablero("nuevaPartida");
  sorteoTurno();
}

void JuegoBase::configurarCargarPartida(){
  tableroDeJuego = new Tablero("cargarPartida");
}

void JuegoBase::Main(string configuracionPartida){
  if(configuracionPartida == "nuevaPartida"){
    configurarNuevaPartida();
  }else{
    configurarCargarPartida();
  }
  int opcion = 1;
  do{
    system("clear");
    tableroDeJuego -> imprimirTablero();
    cout << "\n0.  Exit\n";
    cin >> opcion;
  }while(opcion != 0);
  system("clear");
  //llamar el destructor de tablero
  //delete tableroDeJuego;
}

void JuegoBase::sorteoTurno(){
  cout << "Lanzando moneda para decidir turno\n";
  
  do{
    srand(time(NULL));
    primerTurno = rand()%3;
  }while(primerTurno == 0);

  cout << "Empieza el jugador " << primerTurno << endl;
  int opcion = 0;
  while(opcion != 1){
    cout << "\n1. Continuar\n";
    cin >> opcion;
  }
}