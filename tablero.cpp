#include "tablero.h"

Tablero::Tablero(string configurarTablero){
  //Al puntero le agregamos un array de 10 punteros tipo Box
  matrizTablero = new Box*[10];

  //A cada uno de los punteros del array, agregamos un array de 9 objetos Box, para completar la matriz
  for(int i = 0; i <= 9 ; i++){
    *(matrizTablero + i) = new Box[9];
  }

  if(configurarTablero == "nuevaPartida"){
    nuevaPartida();
  }else{
    cargarPartida();
  }
}

void Tablero::nuevaPartida(){
  ifstream configuracion;
  int recorridoColumna = 0;
  string aux;

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
        matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        //Se configura el Box con la cantidad de avatares de cada tipo
        matrizTablero[recorridoColumna][recorridoRenglon].setTieneEjercito(luchadores, tiradores, magos);
        recorridoRenglon++;

        //Guarda la direccion de los ejercitos
        if(stoi(aux) == 1){
        Ejercito1 = &matrizTablero[recorridoColumna][recorridoRenglon];
        }else{
          Ejercito2 = &matrizTablero[recorridoColumna][recorridoRenglon];
        }

      }else{
        matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        recorridoRenglon++;
      }
  }
  recorridoColumna ++;
  }
  configuracion.close();
}

void Tablero::cargarPartida(){
  ifstream configuracion;
  int recorridoColumna = 0;
  string aux;

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
      matrizTablero[recorridoColumna][recorridoRenglon].setTieneEjercito(stoi(aux), stoi(aux), stoi(aux));
      matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
      recorridoRenglon++;
    }else{
      matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
      recorridoRenglon++;
    }
  }
  recorridoColumna ++;
  }
  //Se cierra el archivo plano
  configuracion.close();
}


//Recorre la matriz del tablero e imprime sus valores, "1" para ejercito 1, "2" para ejercito 2 y "9" para la torreta.
void Tablero::imprimirTablero(){
  for(int x = 0; x <= 9; x++){
    for(int y = 0; y <= 9; y++){
      cout << matrizTablero[x][y].getID() << " ";
    }
    cout << endl;
  }
}