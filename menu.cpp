#include "menu.h"

Menu::Menu(){
  
}

void Menu::Interfaz(){
  int opcion;

  do{
    cout << "\n1. Nueva Partida\n2. Cargar Partida\n3. Instrucciones\n4. Exit\n";
    cin >> opcion;
    switch(opcion){

    //configura el tablero para una nueva partida
     case 1:
     configurarPartida(0);
     break;

    //configura el tablero para que carge una partida
     case 2:
     configurarPartida(1);
     break;

    //imprima las instrucciones
     case 3:
     Instrucciones();
     break;

     case 4:
     exit(1);
    }
  }
  while(opcion != 4);
}

//Se configura el tablero al estado deseado y luego muestra la interfaz para imprimir tablero o mostrar estado ejercito
void Menu::configurarPartida(int tipoConfiguracion){
  tableroDeJuego.configurarPartida(tipoConfiguracion);
  tableroDeJuego.Interfaz();
}

//Carga las instrucciones del archivo "Instrucciones.txt"
void Menu::Instrucciones(){
  string imprimirInstrucciones;
  ifstream archivoInstrucciones;
  archivoInstrucciones.open("Instrucciones.txt");
  while(getline(archivoInstrucciones, imprimirInstrucciones)){
    cout << imprimirInstrucciones << endl;
  }
  archivoInstrucciones.close();
}
