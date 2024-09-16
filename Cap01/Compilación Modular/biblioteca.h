/*********************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:27/08/2024
Materia: Sistemas Operativos
Tema: Gestión de memoria, Puntero y Compilación Modular
Descripción:
*Interfaz de funciones:
     -Colección de funciones que se proporcionan para ser utilizadas por otros módulos o archivos.
     -Define qué funciones están disponibles y cómo deben ser llamadas (sus nombres, parámetros y tipos de retorno).
     -Declaración de las funciones.
     -Archivo de encabezado (.h)

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
        INTERFAZ DE FUNCIONES
****************************************************************************************************************/
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Esta funcion crea un vector dinamico*/
void vectorInicio(vectorDinamico *V);

/*Esta funcion añade un elemento al vector dinamico*/
int totalVector(vectorDinamico *V);

/*Esta funcion redimensiona el tamano del vector dinamico*/
static void resizeVector(vectorDinamico *V, int capacidad);

 /*Esta funcion añade un elemento al vector dinamico*/
void addVector(vectorDinamico *V, void *elemento);

/*Esta funcion libera vector dinamico*/
void freeVector(vectorDinamico *V);

 /*Esta funcion imprime el vector dinamico*/
void *getVector(vectorDinamico *V, int indice);

/*Esta coloca un elemento en una determinada posicion del vector*/
void setVector(vectorDinamico *V, int indice, void *elemento);
/*Esta funcion elimina un elemento del vector dinamico*/
void borrarVector(vectorDinamico *V, int indice);

#endif
