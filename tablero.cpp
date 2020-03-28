#include "tablero.h"

Tablero::Tablero(){
}

void Tablero::Interfaz(){
  int opcion;

  do{

    cout << "\n1. ImprimirTablero\n2. Estado Ejercitos\n3. Salir al menu\n";
    cin >> opcion;
    switch(opcion){
      case 1:
      imprimirTablero();
      break;

      case 2:
       //cout << "[1]" << endl;
      for(int x = 0; x<=9; x++){
        for(int y = 0; y<=9; y++){
          //cout << "[2]" << endl;
          if(Puntero[x][y].tieneEjercito){
            //cout << "[3]" << endl;
            Puntero[x][y].informacionEjercito();
            //cout << "[4]" << endl;
          }
        }
      }
      break;

    }
  }while(opcion != 3);
  delete[]Puntero;
}

void Tablero::configurarPartida(int tipoConfiguracion){
  ifstream configuracion;
  int recorridoColumna = 0;
  string aux;
  string texto;
  Puntero = new Box*[10];
  *Puntero = new Box[9];
  *(Puntero+1) = new Box[9];
  *(Puntero+2) = new Box[9];
  *(Puntero+3) = new Box[9];
  *(Puntero+4) = new Box[9];
  *(Puntero+5) = new Box[9];
  *(Puntero+6) = new Box[9];
  *(Puntero+7) = new Box[9];
  *(Puntero+8) = new Box[9];
  *(Puntero+9) = new Box[9];
  *(Puntero+10) = new Box[9];

  switch (tipoConfiguracion){
    case 0:
      configuracion.open("nuevaPartida.txt");

      if(configuracion.fail()){
       cout << "No se creo una nueva partida";
      }else{
      cout << "Se creo una nueva partida\n";
      }

      while(!configuracion.eof()){
      string aux;
      int recorridoRenglon = 0;
      while(getline(configuracion, aux, '|')){
        if(stoi(aux) == 1 || stoi(aux) == 2){
          
          Puntero[recorridoColumna][recorridoRenglon].setID(stoi(aux));

          int luchadores, tiradores, magos;
          cout << "Ingrese cantidad Luchadores: ";
          cin >> luchadores;
          cout << "Ingrese cantidad Tiradores: ";
          cin >> tiradores;
          cout << "Ingrese cantidad Magos: ";
          cin >> magos;
          Puntero[recorridoColumna][recorridoRenglon].setTieneEjercito(luchadores, tiradores, magos);
           recorridoRenglon++;
          Puntero[recorridoColumna][recorridoRenglon].setEjercito(luchadores, tiradores, magos);
        }else{
          Puntero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
          recorridoRenglon++;}
      }
        recorridoColumna ++;
      }
    
      configuracion.close();
    break;

    case 1:
      configuracion.open("cargarPartida.txt");
      if(configuracion.fail()){
       cout << "No se encontro partida guardada";
      }else{
      cout << "Se cargo una partida\n";
      }

      while(!configuracion.eof()){
      string aux;
      int recorridoRenglon = 0;
      while(getline(configuracion, aux, '|')){
        if(stoi(aux) == 10 || stoi(aux) == 20){
          Puntero[recorridoColumna][recorridoRenglon].setTieneEjercito(0,0,0);
          Puntero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
          recorridoRenglon++;
        }else{
        Puntero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        recorridoRenglon++;}
      }
      recorridoColumna ++;
      }
    
      configuracion.close();
    break;   
  }
}

void Tablero::estadoEjercitos(){

}

void Tablero::imprimirTablero(){

  for(int x = 0; x != 10; x++){
    for(int y = 0; y != 10; y++){
      cout << Puntero[x][y].getID() << " ";
    }
    cout << endl;
  }
}