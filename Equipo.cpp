
#include"Equipo.h"

Equipo::Equipo(){
}

Equipo::Equipo(string _nombre_equipo, int _partidos_ganados, int _partidos_empatados, int _partidos_perdidos, int _goles_favor, int _goles_contra){
  nombre_equipo =  _nombre_equipo;
  partidos_ganados =  _partidos_ganados;
  partidos_empatados =  _partidos_empatados;
  partidos_perdidos =  _partidos_perdidos;
  goles_favor =  _goles_favor;
  goles_contra =  _goles_contra;
  puntos = (partidos_ganados * 3) + partidos_empatados;
}

//Calculo de Partidos Jugados
int Equipo::get_partidos_jugados(){
     return partidos_ganados + partidos_empatados + partidos_perdidos;
}
//Calculo de puntos 
int Equipo::get_puntos_equipo(){
     return puntos;
}
//Calculo de Diferencia de Goles
int Equipo::get_diferencia_goles(){
     int resultado = goles_favor - goles_contra;
     return resultado;
}

void Equipo:: set_puntos(int puntos){
     this->puntos = puntos;
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

int Equipo::get_partidos_perdidos(){
     return partidos_perdidos;
}

int Equipo::get_goles_favor(){
     return goles_favor;
}

int Equipo::get_goles_contra(){
     return goles_contra;
}

Equipo::~Equipo(){
}
