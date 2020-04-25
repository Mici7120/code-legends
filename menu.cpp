#include "menu.h"

Menu::Menu(){
  
}

void Menu::MenuPrincipal(){
  int opcion;

  do{
    //Imprimir titulo Code Legends
    string imprimirTitulo;
    ifstream Titulo;
    Titulo.open("Titulo.txt");
    while(getline(Titulo, imprimirTitulo)){
      cout << imprimirTitulo << endl;
    }
    Titulo.close();
    
    cout << "\n1. Nueva Partida\n2. Cargar Partida\n3. Instrucciones\n4. Exit\n";
    cin >> opcion;
    switch(opcion){

    //configura el tablero para una nueva partida
     case 1:
     system("clear");
     Partida = new JuegoBase("nuevaPartida");
     Partida -> Main();
     delete Partida;
     break;

    //configura el tablero para que carge una partida
     case 2:
     system("clear");
     Partida = new JuegoBase("cargarPartida");
     Partida -> Main();
     delete Partida;
     break;

    //imprima las instrucciones
     case 3:
     system("clear");
     Instrucciones();
     break;

     case 4:
     exit(1);
    }
  }
  while(opcion != 4);
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

  int opcion = 0;
  while(opcion != 1){
    cout << "\n1. Salir al Menu\n";
    cin >> opcion;
  }
  system("clear");
}
