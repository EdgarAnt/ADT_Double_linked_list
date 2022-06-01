#ifndef NODO_H
#define NODO_H

class Nodo {
  public:
    Nodo();
    ~Nodo();
    int dato;
    Nodo *sig;
    void eliminar_todo();
};

#endif //NODO_H
