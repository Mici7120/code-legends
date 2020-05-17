#include "tablero.h"

Tablero::Tablero(){

}

Tablero::~Tablero(){

}

void Tablero::setMatrizTablero(){
  //Al puntero le agregamos un array de 10 punteros tipo Box
  matrizTablero = new Box*[9];

  //A cada uno de los punteros del array, agregamos un array de 9 objetos Box, para completar la matriz
  for(int i = 0; i <= 9 ; i++){
    *(matrizTablero + i) = new Box[9];
  }
}

void Tablero::nuevaPartida(){
  setMatrizTablero();

  //Se cargara la matriz desde el archivo "nuevaPartida.txt"
  ifstream configuracion;
  configuracion.open("nuevaPartida.txt");

  int recorridoRenglon = 0;
  int recorridoColumna = 0;
  string aux;

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
      //Se configura la cantidad de avatares de cada tipo en el Box
      //matrizTablero[recorridoColumna][recorridoRenglon].setTieneEjercito(luchadores, tiradores, magos);

      //Guarda las coordenadas de los ejercitos
      setCoordenadasEjercito(stoi(aux), recorridoRenglon, recorridoColumna);
    }else{
      matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
      if(stoi(aux) == 9){
        matrizTablero[recorridoColumna][recorridoRenglon].setTorreta();
        }
    }
    if(recorridoRenglon == 9){
      recorridoRenglon = 0;
      recorridoColumna++;
    }else{
      recorridoRenglon++;
    }
  }
  configuracion.close();
}

void Tablero::cargarPartida(){
  setMatrizTablero();

  //Se cargara la matriz desde el archivo "cargarPartida.txt"
  ifstream configuracion;
  configuracion.open("cargarPartida.txt");

  string aux;
  int recorridoRenglon = 0;
  int recorridoColumna = 0;

  while(getline(configuracion, aux, '|')){
    if(stoi(aux) == 1 || stoi(aux) == 2){
      matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));

      //Se configura la cantidad de avatares de cada tipo en el Box
      //matrizTablero[recorridoColumna][recorridoRenglon].setTieneEjercito(1, 3, 5);

      //Guarda las coordenadas de los ejercitos
      setCoordenadasEjercito(stoi(aux), recorridoColumna, recorridoRenglon);
      }else{
        matrizTablero[recorridoColumna][recorridoRenglon].setID(stoi(aux));
        if(stoi(aux) == 9){
          matrizTablero[recorridoColumna][recorridoRenglon].setTorreta();
        }
    }
    //cout << recorridoRenglon << endl;
    if(recorridoRenglon == 9){
      recorridoRenglon = 0;
      recorridoColumna++;
    }else{
      recorridoRenglon++;
    }
  }
  //Se cierra el archivo plano
  configuracion.close();
}

//Recorre la matriz del tablero e imprime sus valores, "1" para ejercito 1, "2" para ejercito 2 y "9" para la torreta.
void Tablero::imprimirTablero(){
  for(int y = 0; y <= 9; y++){
    for(int x = 0; x <= 9; x++){
      cout << matrizTablero[y][x].getID() << "\t";
    }
    cout << endl << endl;
  }
}

void Tablero::setCoordenadasEjercito(int _Ejercito, int X, int Y){
  if(_Ejercito == 1){
    Ejercito1X = X;
    Ejercito1Y = Y;
  }else{
    Ejercito2X = X;
    Ejercito2Y = Y;
  }
}
