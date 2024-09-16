/**************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:27/08/2024
Materia: Sistemas Operativos
Tema: Gestión de memoria, Puntero y Compilación Modular
Descripción:
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
**************************************************/
#define CAPACIDAD_INICIAL 4

#include <stdio.h>
#include <stdlib.h>

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

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

/*Funcion principal donde se añaden los elementos al vector y se redimensionan los tamaños de ser necesario*/
int main(){
        int i; 
        vectorDinamico editor;
        vectorInicio(&editor);

        addVector(&editor, "Hola");
        addVector(&editor, "Profesional");
        addVector(&editor, "en");
        addVector(&editor, "Formación");
        addVector(&editor, "de");
        addVector(&editor, "Ingeniería");

        for (i = 0; i < totalVector(&editor); i++)
                printf("%s ", (char *) getVector(&editor, i));
     
        printf("\n\n");

        while(i>1){
                borrarVector(&editor, i);
                i--;
        }
         printf("\n\n");
        
        setVector(&editor, 1, "Buenos");
        addVector(&editor, "Días");
              

        for (i = 0; i < totalVector(&editor); i++)
                printf("%s ", (char *) getVector(&editor, i));
        
        freeVector( &editor);
        return 0;
}
