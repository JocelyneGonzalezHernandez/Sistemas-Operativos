/*********************************************************************************************************************************
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
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h" //Fichero donde se encuentran las funciones

/*Funcion principal donde se añaden los elementos al vector y se redimensionan los tamaños de ser necesario*/
int main(){
        int i; 
        vectorDinamico editor;
        vectorInicio(&editor);

        //Se añaden los elementos al vector dinámico
        addVector(&editor, "Hola");
        addVector(&editor, "Profesional");
        addVector(&editor, "en");
        addVector(&editor, "Formación");
        addVector(&editor, "de");
        addVector(&editor, "Ingeniería");

        //Imprime todos los elementos del vector
        for (i = 0; i < totalVector(&editor); i++)
                printf("%s ", (char *) getVector(&editor, i));
     
        printf("\n\n");

        while(i>1){ //Comenzando desde el valor final del bucle anterior.
                borrarVector(&editor, i);  //Elimina elementos del vector dinámico en la posición i
                i--; //Decrementa el valor de i en 1 para ir eliminando en orden descendente
        }
         printf("\n\n");
        
        setVector(&editor, 1, "Buenos"); //Modifica el segundo elemento del vector (posición 1) reemplazando su valor
        addVector(&editor, "Días"); //Añade el string "Días" al final del vector dinámico
              
//Recorre nuevamente todos los elementos del vector para imprimir los valores actualizados después de las modificaciones.
        for (i = 0; i < totalVector(&editor); i++)
                printf("%s ", (char *) getVector(&editor, i));

        freeVector( &editor); //Libera la memoria del vector
        return 0;
}