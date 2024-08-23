/*****************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 13/08/2024 Modificado el 23/08/2024
Materia:Sistemas Operativos
Tema: Gestión de memoria
Tópico: Reserva de memoria con la función malloc().

*Asignación dinámica de memoria
*La función malloc() reserva un bloque de memoria del tamaño especificado y devuelve un puntero al inicio del bloque reservado. 
*La memoria reservada no está inicializada y puede contener valores indeterminados.
*****************************************************************/
#include  <stdio.h> //Biblioteca para entrada y salida de datos
#include <stdlib.h> //Biblioteca para funciones de memoria

int main(){
  int *bloque00=malloc(4*sizeof(int)); // Reserva memoria para 4 enteros y devuelve un puntero al bloque reservado
  int *puntero=malloc(15*sizeof(*puntero)); // Reserva memoria para 4 enteros y devuelve un puntero al bloque reservado

  /**BUCLE PARA RELLENAR LOS ESPACIOS**/
  //Bucle para rellenar los espacios del primer bloque reservado (bloque00)
  
  for(int i=0; i<4; i++){
    bloque00[i]=i*2; // Asigna a cada posición del bloque00 el doble del índice
    printf("El valor de memoria reservado bloque00[%d] es de %d\n", i, bloque00[i]); // Imprime el valor en cada posición
  }

  // Verifica si la memoria para 'puntero' fue reservada exitosamente
  if (puntero!=NULL){
    *(puntero+8)=9889; // Asigna el valor 9889 a la novena posición (índice 8) en 'puntero'
    // Imprime el valor de la novena posición de dos formas
    printf("El valor de la novena posici+on de puntero es %d\n", *(puntero+8)); //Forma 1 -Como puntero
    printf("El valor de la novena posici+on de puntero es %d\n", puntero[8]); //Forma 2 - Como vector
  }
  
  /**LIBERACIÓN DE MEMORIA**/
  //Libera la memoria reservada para 'bloque00' y 'puntero' para evitar fugas de memoria
  free(bloque00); // Libera el bloque de memoria reservado para 'bloque00'
  free(puntero);// Libera el bloque de memoria reservado para 'puntero'
  
  return 0;
}
