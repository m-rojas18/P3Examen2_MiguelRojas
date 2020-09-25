#ifndef NODO_H
#define NODO_H

#include "Equipo.h"
class Nodo {
    private:
        Nodo* node;
        Equipo* equipo;
    public:
        Nodo();
        Nodo(Equipo*);
        Nodo* next_node();
        void set_next_Node(Nodo*);
        Equipo* get_Equipo();
        ~Nodo();
};
#endif