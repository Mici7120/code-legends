#include "menu.h"

Menu::Menu(){
  
}

void Menu::Interfaz(){
  int opcion;

  do{
    cout << "\n1. Nueva Partida\n2. Cargar Partida\n3. Instrucciones\n4. Exit\n";
    cin >> opcion;
    switch(opcion){
     case 1:
     configurarPartida(opcion);
     break;

     case 2:
     configurarPartida(opcion);
     break;

     case 3:
     Instrucciones();
     break;

     case 4:
     exit(1);
    }
  }
  while(opcion != 4);
}

void Menu::configurarPartida(int tipoConfiguracion){
  tableroDeJuego -> configurarPartida(tipoConfiguracion);
  tableroDeJuego -> Interfaz();
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
