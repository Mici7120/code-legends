#include "juegoBase.h"

JuegoBase::JuegoBase(){
}

void JuegoBase::configurarNuevaPartida(){
  tableroDeJuego.nuevaPartida();
  sorteoTurno();
}

void JuegoBase::configurarCargarPartida(){
  tableroDeJuego.cargarPartida();
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
    tableroDeJuego.imprimirTablero();
    cout << "Turno del Jugador " << Turno << endl;
    
    if(Turno == 1){
      Movimiento(Turno, tableroDeJuego.Ejercito1X, tableroDeJuego.Ejercito1Y);
      Turno = 2;
      }else{
        Movimiento(Turno, tableroDeJuego.Ejercito2X, tableroDeJuego.Ejercito2Y);
        Turno = 1;
      }
  }while(tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].ejercito.derrotado() == false || tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito2X][tableroDeJuego.Ejercito2Y].ejercito.derrotado() == false);

  cout << "\nLa partida ha terminado\nGano el ejercito: ";
  if(tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].ejercito.derrotado() == false){
    cout << "1\n";
  }else{
    cout << "2\n";
  }

  tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].informacionEjercito();
  tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito2X][tableroDeJuego.Ejercito2Y].informacionEjercito();

  cin >> opcion;
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
  vector<float> vidas; //Vector de todas las vidas
  float peorVidaLocal = 0.0; //Se inicializa la peor vida en 0.0
  tableroDeJuego.matrizTablero[coordeX][coordeY].informacionEjercito();
  cout << "1. Arriba\n2. Abajo\n3. Derecha\n4. Izquierda\n";

  int opcionMovimiento;
  bool movimientoCorrecto = false;

  while(movimientoCorrecto == false){
    
    cin >> opcionMovimiento;
    switch (opcionMovimiento){

      case 1: //Arriba
      if(coordeX != 0){
        switch(tableroDeJuego.matrizTablero[coordeX][coordeY - 1].getID()){
          case 0:
          tableroDeJuego.matrizTablero[coordeX][coordeY - 1].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX][coordeY - 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeY --;
          movimientoCorrecto = true;
          break;

          //Caso 5 es para el Bonus Vida
          //Bonus vida: Se extrajo las vidas del ejercito, y se miro la peor vida y se restaruro a la vida original.
      case 5:
            cout << "BONUS VIDA" << endl;

          //Ejemplo de cuando se le quita la vida
            //tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[4]->restarVida(2.9);

            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);

             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);
             ////////////////////////////////////////////

            //Sirve para hacer los movimientos del ejercito y se pueda comer el Bonus.
             tableroDeJuego.matrizTablero[coordeX][coordeY - 1].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX][coordeY - 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeY --;
          movimientoCorrecto = true;
          break;


          case 9:
            break;

          default:
          tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX][coordeY - 1].ejercito;
          movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 2: //Abajo
      if(coordeX != 9){
        switch(tableroDeJuego.matrizTablero[coordeX][coordeY + 1].getID()){
          case 0:
          tableroDeJuego.matrizTablero[coordeX][coordeY + 1].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeY ++;
          movimientoCorrecto = true;
          break;

         //Caso para el Bonus Vida
          case 5:
            cout << "BONUS VIDA" << endl;

            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);

             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);

//////////////////////////////////////////////
//Sirve para hacer los movimientos del ejercito y se pueda comer el Bonus.
          tableroDeJuego.matrizTablero[coordeX][coordeY + 1].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeY ++;
          movimientoCorrecto = true;    
            //cout << tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito << endl;

         
            break;
          
          case 9:
          break;

          default:
          tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito;
          movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 3: //Derecha
      if(coordeY != 9){
        switch(tableroDeJuego.matrizTablero[coordeX + 1][coordeY].getID()){
          case 0:
          tableroDeJuego.matrizTablero[coordeX + 1][coordeY].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX + 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeX ++;
          movimientoCorrecto = true;
          break;

      case 5:
            cout << "BONUS VIDA" << endl;

            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);

             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);

//////////////////////////////////////////////
  
  //Sirve para hacer los movimientos del ejercito y se pueda comer el Bonus.
          tableroDeJuego.matrizTablero[coordeX + 1][coordeY].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          tableroDeJuego.matrizTablero[coordeX + 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar);
          coordeX ++;
          movimientoCorrecto = true;
            break;

          case 9:
          break;

          default:
          tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX + 1][coordeY].ejercito;
          movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 4: //Izquierda
      if(coordeY != 0){
        switch(tableroDeJuego.matrizTablero[coordeX - 1][coordeY].getID()){
          case 0:
          tableroDeJuego.matrizTablero[coordeX - 1][coordeY].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX - 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.getEjercito());
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          coordeX --;
          movimientoCorrecto = true;
          break;

      //Caso para el Bonus Vida
      case 5:
            cout << "BONUS VIDA" << endl;

            //tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[4]->restarVida(2.9);

            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);

             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);

             //////////////////////////////

             //Sirve para hacer los movimientos del ejercito y se pueda comer el Bonus.

             tableroDeJuego.matrizTablero[coordeX - 1][coordeY].setID(_Ejercito);
          tableroDeJuego.matrizTablero[coordeX - 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.getEjercito());
          tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
          coordeX --;
          movimientoCorrecto = true;

             break;


          case 9:
          break;

          default:
          tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX - 1][coordeY].ejercito;
          movimientoCorrecto = true;
          break;
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