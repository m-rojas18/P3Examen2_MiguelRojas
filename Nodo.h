#ifndef NODO_H
#define NODO_H

#include "Equipo.h"
class Nodo {
    private:
        Nodo* apuntador_nodo;
        Equipo* equipo;
    public:
    Nodo();
    Nodo(Equipo);
    ~Nodo();
};
#endif