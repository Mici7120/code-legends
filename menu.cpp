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
     cout << "\nNueva Partida:\n";
     configurarPartida(0);
     break;

     case 2:
     cout << "\nCargar Partida:\n";
     configurarPartida(1);
     break;

     case 3:
     cout << "\nInstrucciones:\n";
     Instrucciones();
     break;
     case 4:
     exit(1);
    }
  }
  while(opcion != 4);
}

void Menu::configurarPartida(int tipoConfiguracion){
  tableroGuardado.configurarPartida(tipoConfiguracion);
  tableroGuardado.Interfaz();
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
