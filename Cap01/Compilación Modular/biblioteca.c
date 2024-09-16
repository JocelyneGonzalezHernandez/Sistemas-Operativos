/*********************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:27/08/2024
Materia: Sistemas Operativos
Tema: Gestión de memoria, Puntero y Compilación Modular
Descripción:
*Implementación de funciones: 
        -Archivo que proporciona el código que define el comportamiento específico de las funciones.
        -Permite separar la interfaz (declaraciones de funciones) de su implementación. 
        -Esto ayuda a mantener el código organizado y facilita la reutilización y el mantenimiento. 
        -Los archivos de encabezado (.h) contienen las declaraciones, 
        mientras que los archivos de implementación (.c) contienen la lógica.
        
*Gestion de Memoria (Dinamica, Estatica): 
Manipulación de espacio de memoria según necesite la aplicación.
-Memoria Estática
        -La memoria estática solo se dispone en tiempo de compilación. 
        -Incluye variables globales, *vectores fijos, etc. 
        -No es necesario liberar la memoria
        -Siempre es de tamaño fijo.
-Memoria Dinámica:
        -El usuario en función del problema puede cambiar y modificar el espación de memoria que necesite.
        -Se asigna durante la ejecución del programa.
        -Se debe liberar la memoria al final.

*Punteros:
        -Los punteros son variabies auxiliares como herramientas a disposición del usuario para de forma ligera. 
        -Señalan espacios de memoria o contenedores (estructuras de datos, etc)
        -Proporcionan de forma precisa la dirección de memoria.
        -Son útiles cuando se quiere que el programa sea ligero al administrar el uso de memoria.

*Compilacion Modular: 
        -Representa crear biblioteca de funciones con su interfaz correspondiente. 
        -De forma que permita que la biblioteca quede a disposición de otros programas o usuarios. 
        -Adicional, se crea un fichero que se llama Makefile cuyo propósito es el de automatizar la compilación.
*********************************************************************************************************************************/

/****************************************************************************************************************
        IMPLEMENTACIÓN DE FUNCIONES
****************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h" //Fichero donde se encuentran las funciones

#define CAPACIDAD_INICIAL 4

/*Esta funcion crea un vector dinamico*/
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL; //Capacidad de 4
        V->totalElementos = 0; //Tiene 0 elementos
        V->elementos = malloc(sizeof(void *) * V->capacidad); //Asigna memoria para 4 elementos
}

/*Esta funcion añade un elemento al vector dinamico*/
int totalVector(vectorDinamico *V){
        return V->totalElementos; //Devuelve el total de elementos
}

/*Esta funcion redimensiona el tamano del vector dinamico*/
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}
 /*Esta funcion añade un elemento al vector dinamico*/
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos) //Si la capacidad de V es igual al total de elementos
                resizeVector(V, V->capacidad*2); //Se redimensiona el vector V al doble de su capacidad
        V->elementos[V->totalElementos++] = elemento;
}
/*Esta funcion libera vector dinamico*/
void freeVector(vectorDinamico *V){
        free(V->elementos);
}
 /*Esta funcion imprime el vector dinamico*/
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}
/*Esta coloca un elemento en una determinada posicion del vector*/
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}
/*Esta funcion elimina un elemento del vector dinamico*/
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}
