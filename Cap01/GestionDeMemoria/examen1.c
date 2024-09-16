/************************************************************************************
Fecha:20/08/2024
Materia: Sistemas Operativos
Tema: Vector dinámico
************************************************************************************/


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
