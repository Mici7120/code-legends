#include "tablero.h"

Tablero::Tablero(){
}

Tablero::~Tablero(){
}

void Tablero::setMatrizTablero(){
  //Al puntero le agregamos un array de 10 punteros tipo Box
  matrizTablero = new Box*[10];

  //A cada uno de los punteros del array, agregamos un array de 9 objetos Box, para completar la matriz
  for(int i = 0; i <= 9 ; i++){
    *(matrizTablero + i) = new Box[10];
  }
}
/*!< Crea los box del tablero */

void Tablero::nuevaPartida(){
  setMatrizTablero();

  //Se cargara la matriz desde el archivo "nuevaPartida.txt"
  ifstream configuracion;
  configuracion.open("nuevaPartida.txt");

  int coordenadasX = 0;
  int coordenadasY = 0;
  string aux;

  //Carga la matriz
  for(int coordenadasY = 0; coordenadasY < 10; coordenadasY ++){
    for(int coordenadasX = 0; coordenadasX < 10; coordenadasX ++){
      getline(configuracion, aux, '|');
      matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));
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
      
      //Se configura la cantidad de avatares de cada tipo en el Box
      matrizTablero[coordenadasX][coordenadasY].setEjercitoInicial(luchadores, tiradores, magos);

      //Se guarda las coordenadas del ejercito
      setCoordenadasEjercito(stoi(aux), coordenadasX, coordenadasY);
      }else if(stoi(aux) == 9){
        matrizTablero[coordenadasX][coordenadasY].setTorretaInicial();
        TorretaX = coordenadasX;
        TorretaY = coordenadasY;
      }
    }
  }
  configuracion.close();
}
/*!< Carga los valores iniciales para una nueva partida */

void Tablero::cargarPartida(){
  setMatrizTablero();

  //Se cargara la matriz desde el archivo "cargarPartida.txt"
  ifstream configuracion;
  configuracion.open("partidaGuardada.txt");

  string aux;
  int coordenadasX = 0;
  int coordenadasY = 0;

  //La primera linea del archivo es el turno ha empezar
  getline(configuracion, aux, '|');
  turnoInicial = stoi(aux);

  //Carga la matriz
  for(int coordenadasY = 0; coordenadasY < 10; coordenadasY ++){
    for(int coordenadasX = 0; coordenadasX < 10; coordenadasX ++){
      getline(configuracion, aux, '|');

      //Se guarda las coordenadas del ejercito
      matrizTablero[coordenadasX][coordenadasY].setID(stoi(aux));
      if(stoi(aux) == 1 || stoi(aux) == 2){
        setCoordenadasEjercito(stoi(aux), coordenadasX, coordenadasY);
      }else if(stoi(aux) == 9){
        TorretaX = coordenadasX;
        TorretaY = coordenadasY;
      }
    }
  }

  //Carga las estadisticas de los ejercitos
  vector<float> vector;
  //Ejercito1
  getline(configuracion, aux, '|');
  int cantidadLuchadores1 = stoi(aux);
  for(int i = 0; i < cantidadLuchadores1; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }

  getline(configuracion, aux, '|');
  int cantidadTiradores1 = stoi(aux);
  for(int i = 0; i < cantidadTiradores1; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }

  getline(configuracion, aux, '|');
  int cantidadMagos1 = stoi(aux);
  for(int i = 0; i < cantidadMagos1; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }
  matrizTablero[Ejercito1X][Ejercito1Y].ejercito.setEjercito(cantidadLuchadores1, cantidadTiradores1, cantidadMagos1, vector);

  vector.clear();
  //Ejercito2
  getline(configuracion, aux, '|');
  int cantidadLuchadores2 = stoi(aux);
  for(int i = 0; i < cantidadLuchadores2; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }

  getline(configuracion, aux, '|');
  int cantidadTiradores2 = stoi(aux);
  for(int i = 0; i < cantidadTiradores2; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }

  getline(configuracion, aux, '|');
  int cantidadMagos2 = stoi(aux);
  for(int i = 0; i < cantidadMagos2; i++){
    getline(configuracion, aux, '|');
    vector.push_back(stof(aux));
  }
  matrizTablero[Ejercito2X][Ejercito2Y].ejercito.setEjercito(cantidadLuchadores1, cantidadTiradores1, cantidadMagos1, vector);

  //Valores de Torreta
  int valoresTorreta [5];
  for(int i = 0; i < 5; i++){
    getline(configuracion, aux, '|');
    valoresTorreta[i] = stoi(aux);
  }
  matrizTablero[TorretaX][TorretaY].setTorreta(valoresTorreta);

  //Se cierra el archivo plano
  configuracion.close();
}
/*!< Lee el archivo y guarda su determinada información en cada uno de los boxes */

void Tablero::guardarPartida(int _Turno){
  ofstream guardarPartida;
  guardarPartida.open("partidaGuardada.txt");

  //Guarda el turno en la primera linea del archivo
  guardarPartida << _Turno << " |\n";

  //Guarda la matriz
  for(int coordenadasY = 0; coordenadasY < 10; coordenadasY ++){
    guardarPartida << endl;
    for(int coordenadasX = 0; coordenadasX < 10; coordenadasX ++){
      guardarPartida << matrizTablero[coordenadasX][coordenadasY].getID() << " |";
    }
  }
  guardarPartida << endl << endl;

  //Guarda la informacion de los ejercitos y sus vidas en un vector
  int vectorEjercito1 = 0;
  int vectorEjercito2 = 0;
  guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Luchadores << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Luchadores; i++){
    guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.ejercitoAvatar[vectorEjercito1] -> getVida() << " |";
    vectorEjercito1 ++;
  }
  guardarPartida << endl;

  guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Tiradores << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Tiradores; i++){
    guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.ejercitoAvatar[vectorEjercito1] -> getVida() << " |";
    vectorEjercito1 ++;
  }
  guardarPartida << endl;

  guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Magos << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito1X][Ejercito1Y].ejercito.Magos; i++){
    guardarPartida << matrizTablero[Ejercito1X][Ejercito1Y].ejercito.ejercitoAvatar[vectorEjercito1] -> getVida() << " |";
    vectorEjercito1 ++;
  }
  guardarPartida << endl << endl;

  guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Luchadores << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Luchadores; i++){
    guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.ejercitoAvatar[vectorEjercito2] -> getVida() << " |";
    vectorEjercito2 ++;
  }
  guardarPartida << endl;

  guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Tiradores << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Tiradores; i++){
    guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.ejercitoAvatar[vectorEjercito2] -> getVida() << " |";
    vectorEjercito2 ++;
  }
  guardarPartida << endl;

  guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Magos << " |\n";
  for(int i = 0; i < matrizTablero[Ejercito2X][Ejercito2Y].ejercito.Magos; i++){
    guardarPartida << matrizTablero[Ejercito2X][Ejercito2Y].ejercito.ejercitoAvatar[vectorEjercito2] -> getVida() << " |";
    vectorEjercito2 ++;
  }

  //Guarda la informacion de la torreta
  guardarPartida << endl << endl << matrizTablero[TorretaX][TorretaY].getVidaTorreta() << " |\n";
  if(matrizTablero[TorretaX][TorretaY].Norte){
    guardarPartida << "1 |\n";
  }else{
    guardarPartida << "0 |\n";
  }

  if(matrizTablero[TorretaX][TorretaY].Sur){
    guardarPartida << "1 |\n";
  }else{
    guardarPartida << "0 |\n";
  }

  if(matrizTablero[TorretaX][TorretaY].Este){
    guardarPartida << "1 |\n";
  }else{
    guardarPartida << "0 |\n";
  }

  if(matrizTablero[TorretaX][TorretaY].Oeste){
    guardarPartida << "1 |";
  }else{
    guardarPartida << "0 |";
  }

  guardarPartida.close();
}
/*!< Guarda el estado de la partida actual en el archivo "partidaGuardada" */

void Tablero::imprimirTablero(){
  for(int y = 0; y <= 9; y ++){
    for(int x = 0; x <= 9; x ++){
      cout << matrizTablero[x][y].getID() << "\t";
    }
    cout << endl << endl;
  }
}
/*!< Recorre la matriz del tablero e imprime sus valores, "1" para ejercito 1, "2" para ejercito 2 y "9" para la torreta */

void Tablero::setCoordenadasEjercito(int _Ejercito, int coordenadasX, int coordenadasY){
  if(_Ejercito == 1){
    Ejercito1X = coordenadasX;
    Ejercito1Y = coordenadasY;
  }else{
    Ejercito2X = coordenadasX;
    Ejercito2Y = coordenadasY;
  }
}
/*!< Guarda las coordenadas del ejercito */
