#include <iostream>
#include "Lista.h"

using namespace std;

int Lista::tamanio() {
  int cont = 0;
  Nodo *aux = h;
  while(aux){
    cont++;
    aux = aux->sig;
  }
  return cont;
}

Lista::Lista() {
  inicializa();
}

Lista::~Lista() { }

void Lista::inicializa(void) {
  h = nullptr;
}

bool Lista::vacia() {
  if (h == nullptr) {
    return true;
  } else {
    return false;
  }
}

void Lista::insertaInicio(int d) {
  Nodo *tmp = new Nodo();
  tmp->dato = d;
  if (vacia()){ //h==nullptr
    h = tmp;
  } else {
    tmp->sig = h;
    h = tmp;
  }
}

void Lista::insertaFinal(int d) {
  Nodo *tmp = new Nodo();
  tmp->dato = d;
  Nodo *aux = h;

  if(aux == nullptr){
    h = tmp;
  } else {
    while(aux->sig) {
      aux = aux->sig;
    }
    aux->sig = tmp;
  }
}

void Lista::insertaPos(int d, int pos) {
  Nodo *tmp = new Nodo();
  tmp->dato = d;
  Nodo *aux = h, *auxRet;

  int i = 0;

  if(pos>= 1 && pos-1<tamanio()) {
    while(i<pos-1 && aux) {
      auxRet = aux;
      aux = aux->sig;
      i++;
    }

    if (aux == h) {
      tmp->sig = h;
      h = tmp;
    } else {
      auxRet->sig = tmp;
      tmp->sig = aux;
    }
  } else {
    cout << "Posicion invalida" << endl;
  }
}

void Lista::mostrarTodo() {
  Nodo *aux = h;
  if(aux) { //true
    while(aux) {
      cout << aux->dato << "= " << &aux->dato << endl;
      aux = aux->sig;
    }
  } else { //false
    cout << "Lista vacia" << endl;
  }
}

void Lista::eliminar(int d) {
  Nodo *aux = h, *auxRet = nullptr;
  bool band = true;

  //Busqueda del elemento
  if(aux) {
    while(aux && band) {
      if(aux->dato != d) {
        auxRet = aux;
        aux = aux->sig;
      } else {
        band = false;
      }
    }

    //Eliminacion del elemento despues de encontrarlo
    if (aux == nullptr) {
      cout << "Dato no encontrado" << endl;
    } else if(aux == h) {
      aux->sig = h;
      delete aux;
    } else {
      auxRet->sig = aux->sig;
      delete aux;
    }
  } else {
    cout << "Lista vacia" << endl;
  }
}

void Lista::buscar(int d) {
  Nodo *aux = h;
  int cont = 1;
    int cont2 = 0;

    while (aux) {
        if (aux->dato == d) {
            cout << "El dato " << d << " se encuentra en la posicion: " << cont-1 << endl;
            cont2++;
        }
        aux = aux->sig;
        cont++;
    }
    if (cont2 == 0) {
        cout << "No existe el dato (buscar)" << endl;
    }
    cout << endl << endl;
}

void Lista::vaciar() {
    h->eliminar_todo();
    h = 0;
}

void Lista::primero() {
		if (vacia()) {
			cout << "Lista vacia (primero)" << endl;
		} else {
			cout << "Primer elemento = " << h <<endl;
		}
}

Nodo* Lista::anterior(int d) {
	Nodo *aux = h;
	Nodo *auxR = nullptr;
	bool band = true;

	if(aux) {
		while(aux and band) {
			if(aux->dato != d) {
				auxR = aux;
				aux = aux->sig;
			} else {
				band = false;
			}
		}

		if(auxR == nullptr) {
			cout << "Primera posicion " << endl;
			return auxR;
		} else if(aux == nullptr) {
			cout << "El dato no existe " << endl;
			return nullptr;
		} else {
				cout << "Elemento anterior a " << d << ": "<< auxR << endl;
				return auxR;
		}
	}
	return nullptr;
}

Nodo* Lista::siguiente(int d) {
	Nodo *aux = nullptr;
	Nodo *auxS = h;
	bool band = true;

	if(auxS) {
		while(auxS and band) {
			if(auxS->dato != d) {
				aux = auxS;
				auxS = auxS->sig;
			} else {
				band = false;
			}
		}

		if(auxS == nullptr) {
			cout << "El dato no existe " << endl;
			return nullptr;
		} else if(auxS->sig == nullptr) {
			cout << "Ultima posicion " << endl;
			return auxS;
		} else {
				cout << "Elemento siguiente a " << d << " es: "<< auxS->sig << endl;
				return auxS->sig;
		}
	}
	return nullptr;
}



