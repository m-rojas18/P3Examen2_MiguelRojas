#include "Nodo.h"

Nodo::Nodo(){}

Nodo::Nodo(Equipo* equipo){
    this->equipo = equipo;
}

void Nodo::set_next_Node(Nodo* next_node){
    this->node = next_node;
}
Nodo* Nodo::next_node(){
    return node;
}
//Set Equipo
void Nodo::set_Equipo(Equipo* _equipo){
    this->equipo = _equipo;
}
//Get Equipo
Equipo* Nodo::get_Equipo(){
    return equipo;
}

Nodo::~Nodo(){}