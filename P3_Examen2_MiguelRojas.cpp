#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Equipo.h"
#include "Nodo.h"
using namespace std;

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
        Equipo* nuevo_equipo = new Equipo(datos_equipo[0], stoi(datos_equipo[1]), stoi(datos_equipo[2]), stoi(datos_equipo[3]), stoi(datos_equipo[4]), stoi(datos_equipo[5]) );
        //Insertar nodo a lista
        Nodo* nuevo_nodo = new Nodo(nuevo_equipo);
        nuevo_nodo->set_next_Node(topepila);
        topepila = nuevo_nodo;
        contador++;
    }
    //Moverse en lista
    Nodo* nodo_actual = new Nodo();
    nodo_actual = topepila;
    while(nodo_actual != NULL){
        cout << nodo_actual->get_Equipo()->get_nombre_equipo() << endl;
        nodo_actual = nodo_actual->next_node();
    }
    archivo_texto.close();
    return 0;
}