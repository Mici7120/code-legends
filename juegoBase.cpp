#include "juegoBase.h"

JuegoBase::JuegoBase(){
}

void JuegoBase::configurarNuevaPartida(){
  tableroDeJuego = new Tablero("nuevaPartida");
  sorteoTurno();
}

void JuegoBase::configurarCargarPartida(){
  tableroDeJuego = new Tablero("cargarPartida");
  Turno = 1;
}

void JuegoBase::Main(string configuracionPartida){
  if(configuracionPartida == "nuevaPartida"){
    configurarNuevaPartida();
  }else{
    configurarCargarPartida();
  }
  int opcion = 1;

  do{
    system("clear");
    tableroDeJuego -> imprimirTablero();

    cout << "Turno del Jugador" << Turno << endl;
    if (Turno == 1){
      Movimiento(Turno, tableroDeJuego -> Ejercito1X, tableroDeJuego -> Ejercito1Y);
      Turno = 2;
    }else{
      Movimiento(Turno, tableroDeJuego -> Ejercito2X, tableroDeJuego -> Ejercito2Y);
      Turno = 1;
    }
  }while(opcion != 0);
  system("clear");

}

void JuegoBase::sorteoTurno(){
  cout << "Lanzando moneda para decidir turno\n";

  srand(time(NULL));
  Turno = 1 + rand()%2;

  cout << "Empieza el jugador " << Turno << endl;
  int opcion = 0;
  while(opcion != 1){
    cout << "\n1. Continuar\n";
    cin >> opcion;
  }
}

void JuegoBase::Movimiento(int _Ejercito, int &coordeX, int &coordeY){
  cout << "1. Arriba\n2. Abajo\n3. Derecha\n4. Izquierda\n";

  int opcionMovimiento;
  bool movimientoCorrecto = false;

  while(movimientoCorrecto == false){
    cin >> opcionMovimiento;
    switch (opcionMovimiento){
      case 1: //Arriba
      if(coordeX != 0){
        if(tableroDeJuego -> matrizTablero[coordeX - 1][coordeY].Torreta == false){
          tableroDeJuego -> matrizTablero[coordeX - 1][coordeY].setID(_Ejercito);
          tableroDeJuego -> matrizTablero[coordeX][coordeY].setID(0);
          coordeX --;
          movimientoCorrecto = true;
        }
      }
      break;

      case 2: //Abajo
      if(coordeX != 9){
        if(tableroDeJuego -> matrizTablero[coordeX + 1][coordeY].Torreta == false){
          tableroDeJuego -> matrizTablero[coordeX + 1][coordeY].setID(_Ejercito);
          tableroDeJuego -> matrizTablero[coordeX][coordeY].setID(0);
          coordeX ++;
          movimientoCorrecto = true;
        }
      }
      break;

      case 3: //Derecha
      if(coordeY != 9){
        //Verifica si la posicion a moverse esta la torreta
        if(tableroDeJuego -> matrizTablero[coordeX][coordeY + 1].Torreta == false){
          tableroDeJuego -> matrizTablero[coordeX][coordeY + 1].setID(_Ejercito);
          tableroDeJuego -> matrizTablero[coordeX][coordeY].setID(0);
          coordeY ++;
          movimientoCorrecto = true;
        }
      }
      break;

      case 4: //Izquierda
      if(coordeY != 0){
        if(tableroDeJuego -> matrizTablero[coordeX][coordeY - 1].Torreta == false){
          tableroDeJuego -> matrizTablero[coordeX][coordeY - 1].setID(_Ejercito);
          tableroDeJuego -> matrizTablero[coordeX][coordeY].setID(0);
          coordeY -- ;
          movimientoCorrecto = true;
        }
      }
      break;

      default:
      break;
    }
  if(movimientoCorrecto == false){
    cout << "Movimiento Invalido\n";
  }

  }
}