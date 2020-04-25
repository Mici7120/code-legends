#include "tablero.h"

Tablero::Tablero(){
}

void Tablero::Interfaz(){
  int opcion;

  do{

    cout << "1. ImprimirTablero\n2. Estado Ejercitos\n3. Salir al menu\n";
    cin >> opcion;
    switch(opcion){

      //imprime el tablero
      case 1:
      system("clear");
      imprimirTablero();
      break;

      //Recorre la matriz e imprime la informacion de los ejercitos que contiene
      case 2:
      system("clear");
        for(int x = 0; x<=9; x++){
          for(int y = 0; y<=9; y++){
            if(tablero[x][y].tieneEjercito){
              tablero[x][y].informacionEjercito();
            }
          }
        }
      break;

    }
  }while(opcion != 3);
  system("clear");

}

void Tablero::configurarPartida(int tipoConfiguracion){
  ifstream configuracion;
  int recorridoColumna = 0;
  string aux;

  //Al puntero le agregamos un array de 10 punteros tipo Box
  tablero = new Box*[10];

  //A cada uno de los punteros del array, agregamos un array de 9 objetos Box, para completar la matriz
  for(int i = 0; i <= 9 ; i++){
    *(tablero + i) = new Box[9];
  }

  switch (tipoConfiguracion){
    case 0:
      //Se cargara la matriz desde el archivo "nuevaPartida.txt"
      configuracion.open("nuevaPartida.txt");
      if(configuracion.fail()){
       cout << "No se creo una nueva partida";
      }else{
        cout << "Se creo una nueva partida\n\n";
      }
      while(!configuracion.eof()){
        string aux;
        int recorridoRenglon = 0;
        while(getline(configuracion, aux, '|')){
          if(stoi(aux) == 1 || stoi(aux) == 2){
            //Se ingresan los valores iniciales del ejercito
            int luchadores, tiradores, magos;
            cout << "Configuracion Ejercito " << aux << endl;
            cout << "Ingrese cantidad Luchadores: ";
            cin >> luchadores;
            cout << "Ingrese cantidad Tiradores: ";
            cin >> tiradores;
            cout << "Ingrese cantidad Magos: ";
            cin >> magos;
            cout << endl;
            tablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
            //Se configura el Box con la cantidad de avatares de cada tipo
            tablero[recorridoColumna][recorridoRenglon].setTieneEjercito(luchadores, tiradores, magos);
            recorridoRenglon++;
          }else{
            tablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
            recorridoRenglon++;
          }
      }
      recorridoColumna ++;
      }
      configuracion.close();
    break;

  case 1:
    //Se cargara la matriz desde el archivo "cargarPartida.txt"
    configuracion.open("cargarPartida.txt");
    if(configuracion.fail()){
     cout << "No se encontro partida guardada";
    }else{
      cout << "Se cargo una partida\n\n";
    }

    while(!configuracion.eof()){
    string aux;
    int recorridoRenglon = 0;
    while(getline(configuracion, aux, '|')){
      if(stoi(aux) == 1 || stoi(aux) == 2){
        tablero[recorridoColumna][recorridoRenglon].setTieneEjercito(stoi(aux), stoi(aux), stoi(aux));
        tablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        recorridoRenglon++;
      }else{
        tablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        recorridoRenglon++;
      }
    }
    recorridoColumna ++;
    }
    //Se cierra el archivo plano
    configuracion.close();
    break; 

  }
}

//Recorre la matriz del tablero e imprime sus valores, "1" para ejercito 1, "2" para ejercito 2 y "9" para la torreta.
void Tablero::imprimirTablero(){
  for(int x = 0; x <= 9; x++){
    for(int y = 0; y <= 9; y++){
      cout << tablero[x][y].getID() << " ";
    }
    cout << endl;
  }
}