#include "Nodo.h"

Nodo::Nodo(){}

Nodo::Nodo(Equipo* equipo){
    this->equipo = equipo;
}

void Nodo::set_next_Node(Nodo* next_node){
    this->node = next_node;
}

void Nodo::set_Equipo(Equipo* _equipo){
    this->equipo = _equipo;
}

Nodo* Nodo::next_node(){
    return node;
}

Equipo* Nodo::get_Equipo(){
    return equipo;
}

Nodo::~Nodo(){}