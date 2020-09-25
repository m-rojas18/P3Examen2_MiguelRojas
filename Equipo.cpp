
#include"Equipo.h"

Equipo::Equipo(){
}

Equipo::Equipo(string _nombre_equipo, int _partidos_ganados, int _partidos_empatados, int _goles_favor, int _partidos_contra){
  nombre_equipo =  _nombre_equipo;
  partidos_ganados =  _partidos_ganados;
  partidos_empatados =  _partidos_empatados;
  goles_favor =  _goles_favor;
  partidos_contra =  _partidos_contra;
}

void Equipo::set_nombre_equipo(string _nombre_equipo){
     nombre_equipo = _nombre_equipo;
}

void Equipo::set_partidos_ganados(int _partidos_ganados){
     partidos_ganados = _partidos_ganados;
}

void Equipo::set_partidos_empatados(int _partidos_empatados){
     partidos_empatados = _partidos_empatados;
}

void Equipo::set_goles_favor(int _goles_favor){
     goles_favor = _goles_favor;
}

void Equipo::set_partidos_contra(int _partidos_contra){
     partidos_contra = _partidos_contra;
}

string Equipo::get_nombre_equipo(){
     return nombre_equipo;
}

int Equipo::get_partidos_ganados(){
     return partidos_ganados;
}

int Equipo::get_partidos_empatados(){
     return partidos_empatados;
}

int Equipo::get_goles_favor(){
     return goles_favor;
}

int Equipo::get_partidos_contra(){
     return partidos_contra;
}

Equipo::~Equipo(){
}
