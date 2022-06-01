#include <iostream>
#include<stdio.h>
#include "Lista.h"

using namespace std;

int main() {
  cout << endl;

  Lista *uno = new Lista;

  uno->insertaInicio(1);
  uno->insertaFinal(2);
  uno->insertaFinal(3);
  uno->insertaFinal(4);
  uno->insertaFinal(5);

  cout << "\nLista de numeros = " << endl;

  uno->mostrarTodo();
	cout << endl;
	cout << endl;

	uno->primero();
	uno->anterior(2);
	uno->anterior(3);
	uno->anterior(4);
	uno->anterior(5);
	uno->anterior(6);
	uno->anterior(7);

	cout<<endl;

	uno->siguiente(1);
	uno->siguiente(2);
	uno->siguiente(3);
	uno->siguiente(4);
	uno->siguiente(5);
	uno->siguiente(6);
	uno->siguiente(7);

	cout << endl;

	cout << "\nFin" << endl;
  return 0;
}
