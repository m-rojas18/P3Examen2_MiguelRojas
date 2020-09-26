#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include "Equipo.h"
#include "Nodo.h"
using namespace std;

void ordenamiento(Nodo*);

int main(int argc, char *argv[]){

    string nombre_archivo = argv[1];//Conseguir nombre desde linea de comando
    //Leer Archivo de Texto
    ifstream archivo_texto;
    archivo_texto.open(nombre_archivo, ios::in);
    if(archivo_texto.fail()){
        cout << "Ocurrio un error al abrir el archivo\n";
        exit(EXIT_FAILURE);
    }

    vector<string> lineas_datos;
    string texto;
    while(!archivo_texto.eof()){
        getline(archivo_texto, texto,'\n');
        lineas_datos.push_back(texto);
    }

    int contador = 0;
    Nodo* topepila = nullptr;// nodo topepila
    
    //Separar atributos de line y creacion de objetos
    while(contador < lineas_datos.size()){
        string datos_equipo[6], cadena_temporal;
        stringstream separacion_datos(lineas_datos.at(contador));
        int contador_arreglo = 0;
        while(!separacion_datos.eof()){
            getline(separacion_datos, cadena_temporal, ',');
            datos_equipo[contador_arreglo] = cadena_temporal;
            contador_arreglo++;
        }
        //Crear objeto equipo
        Equipo* nuevo_equipo = new Equipo(datos_equipo[0], stoi(datos_equipo[1]), stoi(datos_equipo[2]), stoi(datos_equipo[3]), 
                                        stoi(datos_equipo[4]), stoi(datos_equipo[5]) );
        //Insertar nodo a lista
        Nodo* nuevo_nodo = new Nodo(nuevo_equipo);
        nuevo_nodo->set_next_Node(topepila);
        topepila = nuevo_nodo;
        contador++;
    }
    
    Nodo* nodo_actual = new Nodo();
    nodo_actual = topepila;
    ordenamiento(nodo_actual);

    cout << "\n               PJ  G   E   P   GA  GC  DG  PTS" << endl;
    int contador_tabla = 1;
    //Moverse en lista
    while(nodo_actual != NULL){
        /Impresion Deseada de la tabla
        cout << contador_tabla << " " <<left<< setw(13) << nodo_actual->get_Equipo()->get_nombre_equipo() << setw(3) << nodo_actual->get_Equipo()->get_partidos_jugados() << " " 
             << setw(3) << nodo_actual->get_Equipo()->get_partidos_ganados() << " " << setw(3) << nodo_actual->get_Equipo()->get_partidos_empatados() 
             <<  " " << setw(3) << nodo_actual->get_Equipo()->get_partidos_perdidos() << " " << setw(3) << nodo_actual->get_Equipo()->get_goles_favor() 
             <<  " " << setw(3) << nodo_actual->get_Equipo()->get_goles_contra() << " " << setw(3) << nodo_actual->get_Equipo()->get_diferencia_goles() 
             <<  " " << setw(3) << nodo_actual->get_Equipo()->get_puntos_equipo() << endl;
        nodo_actual = nodo_actual->next_node();
        contador_tabla++;
    }
    cout << endl;
    archivo_texto.close();
    return 0;
}

void ordenamiento(Nodo* topepila){

    Nodo* nodo_temporal = topepila;
    //Recorrer lista
    while(nodo_temporal != NULL){
        Nodo* minimo = nodo_temporal;
        Nodo* sublista_recorrer = nodo_temporal->next_node();
        //Recorrer sublista (recorrer)
        while(sublista_recorrer != NULL){
            if(minimo->get_Equipo()->get_puntos_equipo() < sublista_recorrer->get_Equipo()->get_puntos_equipo()){
                //Encuentra un valor menor al minimo
                minimo = sublista_recorrer;
            } else if(minimo->get_Equipo()->get_puntos_equipo() == sublista_recorrer->get_Equipo()->get_puntos_equipo()){
                if(minimo->get_Equipo()->get_diferencia_goles() < sublista_recorrer->get_Equipo()->get_diferencia_goles()){
                    //Valiacion para cuando puntaje es igual y evaluar por diferencia de goles
                    minimo = sublista_recorrer;
                   
                }
            }
            sublista_recorrer = sublista_recorrer->next_node();
        }
        //Cambio de Datos en la lista enlazada
        Equipo* equipo_temporal = nodo_temporal->get_Equipo();
        nodo_temporal->set_Equipo(minimo->get_Equipo());
        minimo->set_Equipo(equipo_temporal);
        nodo_temporal = nodo_temporal->next_node();
    }
}