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

  int coordenadasX = 0;
  int coordenadasY = 0;
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
      
      matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));
      //Se configura la cantidad de avatares de cada tipo en el Box
      matrizTablero[coordenadasX][coordenadasY].setEjercito(luchadores, tiradores, magos);

      //Guarda las coordenadas de los ejercitos
      setCoordenadasEjercito(stoi(aux), coordenadasX, coordenadasY);
    }else{
      matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));
      if(stoi(aux) == 9){
        matrizTablero[coordenadasX][coordenadasY].setTorreta();
        }
    }
    if(coordenadasX == 9){
      coordenadasX = 0;
      coordenadasY ++;
    }else{
      coordenadasX ++;
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
  int coordenadasX = 0;
  int coordenadasY = 0;

  while(getline(configuracion, aux, '|')){
    if(stoi(aux) == 1 || stoi(aux) == 2){
      matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));

      //Se configura la cantidad de avatares de cada tipo en el Box
      matrizTablero[coordenadasX][coordenadasY].setEjercito(1, 1, 1);

      //Guarda las coordenadas de los ejercitos
      setCoordenadasEjercito(stoi(aux), coordenadasX, coordenadasY);
      }else{
        matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));
        if(stoi(aux) == 9){
          matrizTablero[coordenadasX][coordenadasY].setTorreta();
        }
    }
    //cout << recorridoRenglon << endl;
    if(coordenadasX == 9){
      coordenadasX = 0;
      coordenadasY ++;
    }else{
      coordenadasX ++;
    }
  }
  //Se cierra el archivo plano
  configuracion.close();
}

//Recorre la matriz del tablero e imprime sus valores, "1" para ejercito 1, "2" para ejercito 2 y "9" para la torreta.
void Tablero::imprimirTablero(){
  for(int y = 0; y <= 9; y ++){
    for(int x = 0; x <= 9; x ++){
      cout << matrizTablero[x][y].getID() << "\t";
    }
    cout << endl << endl;
  }
}

//Guarda las coordenadas del ejercito 
void Tablero::setCoordenadasEjercito(int _Ejercito, int coordenadasX, int coordenadasY){
  if(_Ejercito == 1){
    Ejercito1X = coordenadasX;
    Ejercito1Y = coordenadasY;
  }else{
    Ejercito2X = coordenadasX;
    Ejercito2Y = coordenadasY;
  }
}
