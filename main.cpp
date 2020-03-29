#include "avatar.h"
#include "ejercito.h"
#include "box.h"
#include "tablero.h"
#include "coordenadas.h"
#include "menu.h"

int main() {
  //Imprimir titulo Code Legends
  string imprimirTitulo;
  ifstream Titulo;
  Titulo.open("Titulo.txt");
  while(getline(Titulo, imprimirTitulo)){
    cout << imprimirTitulo << endl;
  }
  Titulo.close();
  
  Menu Menu;
  Menu.Interfaz();

}