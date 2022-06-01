#include "Nodo.h"

Nodo::Nodo() {
  dato = 0;
  sig = nullptr;
}

Nodo::~Nodo() { }

void Nodo::eliminar_todo()
{
    if (sig)
        sig->eliminar_todo();
    delete this;
}
