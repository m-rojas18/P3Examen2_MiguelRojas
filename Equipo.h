
#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

using namespace std;

class Equipo{
    private:
       string nombre_equipo;
       int partidos_ganados;
       int partidos_empatados;
       int goles_favor;
       int partidos_contra;
public:
       Equipo();
       Equipo(string,int,int,int,int);
       void set_nombre_equipo(string);
       void set_partidos_ganados(int);
       void set_partidos_empatados(int);
       void set_goles_favor(int);
       void set_partidos_contra(int);
       string get_nombre_equipo();
       int get_partidos_ganados();
       int get_partidos_empatados();
       int get_goles_favor();
       int get_partidos_contra();
       ~Equipo();
};

#endif