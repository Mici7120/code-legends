#include "juegoBase.h"

JuegoBase::JuegoBase(){
}

void JuegoBase::configurarNuevaPartida(){
  tableroDeJuego.nuevaPartida();
  sorteoTurno();
}
/*!< Inicia una nueva partida */

void JuegoBase::configurarCargarPartida(){
  tableroDeJuego.cargarPartida();
  Turno = tableroDeJuego.turnoInicial;
}
/*!< Carga una partida guardada */

void JuegoBase::Main(string configuracionPartida){
  if(configuracionPartida == "nuevaPartida"){
    configurarNuevaPartida();
  }else{
    configurarCargarPartida();
  }
  int opcion = 0;

  do{
    system("clear");
    tableroDeJuego.imprimirTablero();
    cout << "Vida de la torreta: " << tableroDeJuego.matrizTablero[tableroDeJuego.TorretaX][tableroDeJuego.TorretaY].getVidaTorreta();
    cout << "\nTurno del Jugador " << Turno << endl;

    tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].informacionEjercito();
    tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito2X][tableroDeJuego.Ejercito2Y].informacionEjercito();
    
    cout << "1. Arriba\n2. Abajo\n3. Derecha\n4. Izquierda\n0. Guardar y Salir\n";
    if(Turno == 1){
      Movimiento(Turno, tableroDeJuego.Ejercito1X, tableroDeJuego.Ejercito1Y, opcion);
      Turno = 2;
    }else{
      Movimiento(Turno, tableroDeJuego.Ejercito2X, tableroDeJuego.Ejercito2Y, opcion);
      Turno = 1;
    }
  }while(tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].ejercito.derrotado() == false && tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito2X][tableroDeJuego.Ejercito2Y].ejercito.derrotado() == false && tableroDeJuego.matrizTablero[tableroDeJuego.TorretaX][tableroDeJuego.TorretaY].getVidaTorreta() != 0 && opcion != 0);

  if(opcion != 0){
    system("clear");
    cout << "La partida ha terminado\n";
    if(tableroDeJuego.matrizTablero[tableroDeJuego.TorretaX][tableroDeJuego.TorretaY].getVidaTorreta() != 0){
      cout << "Gano el ejercito: ";
      if(tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y] .ejercito.derrotado() == false){
        cout << "1\n";
      }else{
        cout << "2\n";
      }
    }else{
        cout << "Torreta destruida, gana el ejercito 1\n";
        }

    tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito1X][tableroDeJuego.Ejercito1Y].informacionEjercito();
    tableroDeJuego.matrizTablero[tableroDeJuego.Ejercito2X][tableroDeJuego.Ejercito2Y].informacionEjercito();

    cout << "\n\n0. Volver al Menu\n";
    cin >> opcion;
    system("clear");
  }else{
    tableroDeJuego.guardarPartida(Turno);
  }
}
/*!< Administra los metodos de los movimientos de los ejercitos y determina cuando se acaba la partida, o por lo contrario se guarda la partida*/

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
/*!< Elige al azar el jugador que hará la primera jugada en la partida*/

void JuegoBase::Movimiento(int _Ejercito, int &coordeX, int &coordeY, int &opcion){
  vector<float> vidas; //Vector de todas las vidas
  float peorVidaLocal = 0; //Se inicializa la peor vida en 0

  bool movimientoCorrecto = false;

  while(movimientoCorrecto == false){
    cin >> opcion;
    switch (opcion){
      case 1: //Arriba
      if(coordeY != 0){
        switch(tableroDeJuego.matrizTablero[coordeX][coordeY - 1].getID()){
          case 0:
            tableroDeJuego.matrizTablero[coordeX][coordeY - 1].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX][coordeY - 1].movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY]);
            coordeY --;
            movimientoCorrecto = true;
          break;

          //Caso 5 es para el Bonus Vida
          //Bonus vida: Se extrajo las vidas del ejercito, y se miro la peor vida y se restaruro a la vida original
          case 5:
            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);
             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);
            //Hace los movimientos del ejercito y pueda comerse el Bonus.
             tableroDeJuego.matrizTablero[coordeX][coordeY - 1].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX][coordeY - 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito);
            coordeY --;
            movimientoCorrecto = true;
            break;

          //Ataque torreta si es el ejercito 1(Atacante)
          case 9:
            if(_Ejercito == 1){
              if(tableroDeJuego.matrizTablero[coordeX][coordeY - 1].Sur){
                tableroDeJuego.matrizTablero[coordeX][coordeY - 1].daNoTorreta();
                tableroDeJuego.matrizTablero[coordeX][coordeY - 1].Sur = false;
                cout << "Ataque a la torreta por el Sur\n";
                movimientoCorrecto = true;
              }else{
                cout << "Ya se ha hecho un ataque por este costado\n";
                }
              }
          break;

          default:
          tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX][coordeY - 1].ejercito;
          movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 2: //Abajo
      if(coordeY != 9){
        switch(tableroDeJuego.matrizTablero[coordeX][coordeY + 1].getID()){
          case 0:
            tableroDeJuego.matrizTablero[coordeX][coordeY + 1].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX][coordeY + 1].movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY]);
            coordeY ++;
            movimientoCorrecto = true;
          break;

          //Caso para el Bonus Vida
          //Bonus vida: Se extrajo las vidas del ejercito, y se miro la peor vida y se restaruro a la vida original
          case 5:
            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);

             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);

            //Hace los movimientos del ejercito y pueda comerse el Bonus.
            tableroDeJuego.matrizTablero[coordeX][coordeY + 1].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito);
            coordeY ++;
            movimientoCorrecto = true;
          break;

          //Ataque torreta si es el ejercito 1(Atacante)
          case 9:
            if(_Ejercito == 1){
              if(tableroDeJuego.matrizTablero[coordeX][coordeY + 1].Norte){
                tableroDeJuego.matrizTablero[coordeX][coordeY + 1].daNoTorreta();
                tableroDeJuego.matrizTablero[coordeX][coordeY + 1].Norte = false;
                cout << "Ataque a la torreta por el Norte\n";
                movimientoCorrecto = true;
              }else{
                cout << "Ya se ha hecho un ataque por este costado\n";
              }
            }
          break;

          default:
            tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX][coordeY + 1].ejercito;
            movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 3: //Derecha
      if(coordeX != 9){
        switch(tableroDeJuego.matrizTablero[coordeX + 1][coordeY].getID()){
          case 0:
            tableroDeJuego.matrizTablero[coordeX + 1][coordeY].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX + 1][coordeY].movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY]);
            coordeX ++;
            movimientoCorrecto = true;
          break;

          //Caso para el Bonus Vida
          //Bonus vida: Se extrajo las vidas del ejercito, y se miro la peor vida y se restaruro a la vida original
          case 5:
            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);
            tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);
  
            //Hace los movimientos del ejercito y pueda comerse el Bonus.
            tableroDeJuego.matrizTablero[coordeX + 1][coordeY].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            tableroDeJuego.matrizTablero[coordeX + 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito);
            coordeX ++;
            movimientoCorrecto = true;
          break;

          //Ataque torreta si es el ejercito 1(Atacante)
          case 9:
            if(_Ejercito == 1){
              if(tableroDeJuego.matrizTablero[coordeX + 1][coordeY].Oeste){
                tableroDeJuego.matrizTablero[coordeX + 1][coordeY].daNoTorreta();
                tableroDeJuego.matrizTablero[coordeX + 1][coordeY].Oeste = false;
                movimientoCorrecto = true;
              }else{
                cout << "Ya se ha hecho un ataque por este costado\n";
              }
            }
          break;

          default:
            tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX + 1][coordeY].ejercito;
            movimientoCorrecto = true;
          break;
        }
      }
      break;

      case 4: //Izquierda
      if(coordeX != 0){
        switch(tableroDeJuego.matrizTablero[coordeX - 1][coordeY].getID()){
          case 0:
            tableroDeJuego.matrizTablero[coordeX - 1][coordeY].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX - 1][coordeY].movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY]);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            coordeX --;
            movimientoCorrecto = true;
          break;

          //Caso para el Bonus Vida
          //Bonus vida: Se extrajo las vidas del ejercito, y se miro la peor vida y se restaruro a la vida original
            case 5:
            for(int index = 0; index < tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar.size() ; index++){
              vidas.push_back(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.ejercitoAvatar[index]->getVida());
            }
            
            peorVidaLocal =  tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.obtenerPeorVida(vidas);
             tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito.restaurarVida(peorVidaLocal);

             //Hacer los movimientos del ejercito y se pueda comer el Bonus.
             tableroDeJuego.matrizTablero[coordeX - 1][coordeY].setID(_Ejercito);
            tableroDeJuego.matrizTablero[coordeX - 1][coordeY].ejercito.movimientoEjercito(tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito);
            tableroDeJuego.matrizTablero[coordeX][coordeY].setID(0);
            coordeX --;
            movimientoCorrecto = true;
          break;

          case 9:
            if(_Ejercito == 1){
              if(tableroDeJuego.matrizTablero[coordeX - 1][coordeY].Este){
                tableroDeJuego.matrizTablero[coordeX - 1][coordeY].daNoTorreta();
                tableroDeJuego.matrizTablero[coordeX - 1][coordeY].Este = false;
                movimientoCorrecto = true;
              }else{
                cout << "Ya se ha hecho un ataque por este costado\n";
              }
            }
          break;

          default:
            tableroDeJuego.matrizTablero[coordeX][coordeY].ejercito / tableroDeJuego.matrizTablero[coordeX - 1][coordeY].ejercito;
            movimientoCorrecto = true;
          break;
        }
      }
      break;

      default:
        movimientoCorrecto = true;
      break;
    }
    if(movimientoCorrecto == false){
      cout << "Movimiento Invalido\n";
    }else if(Turno == 1){
      Turno = 2;
    }else{
      Turno = 1;
    }
  }
}
/*!< Compara la dirección hacia donde se va a mover cada ejercito y ejecuta su acción correspondiente de acuerdo a lo que encuentre, ya sea ataque movimiento normal o bloqueo */