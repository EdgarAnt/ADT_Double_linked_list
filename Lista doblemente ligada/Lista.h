#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista {
  public:
    Lista();
    ~Lista();
    void inicializa(void);
    void insertaInicio(int);
    void insertaFinal(int);
    void insertaPos(int,int);
    void mostrarTodo();
    bool vacia();
    int tamanio();
    void eliminar(int);
    void buscar(int);
    void vaciar();
    void primero();

		Nodo* anterior(int);
		Nodo* siguiente(int);

    /*Pendientes:
        --ultimo
    */

  private:
    Nodo *h; //ancla o head
};

#endif //LISTA_H
