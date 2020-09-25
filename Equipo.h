
#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

using namespace std;

class Equipo{
    private:
       string nombre_equipo;
       int partidos_ganados;
       int partidos_empatados;
       int partidos_perdidos;
       int goles_favor;
       int goles_contra;
       int puntos;
public:
       Equipo();
       Equipo(string,int,int,int,int,int);
       int get_partidos_jugados();
       int get_puntos_equipo();
       void set_puntos(int);
       int get_diferencia_goles();
       string get_nombre_equipo();
       int get_partidos_ganados();
       int get_partidos_empatados();
       int get_partidos_perdidos();
       int get_goles_favor();
       int get_goles_contra();
       string toString();
       ~Equipo();
};

#endif