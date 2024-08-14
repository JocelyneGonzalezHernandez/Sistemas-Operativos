/*
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 13/08/2024
Materia:Sistemas Operativos
Tema: Gestión de memoria
Tópico: Reserva de memoria con la función malloc().
La función malloc reserva un espacio de memoria del tamaño especificado y devuelve un puntero al inicio del espacio reservado.
*/
#include  <stdio.h> //Biblioteca para entrada y salida de datos
#include <stdlib.h> //Biblioteca para funciones de memoria

int main(){
  int *bloque00=malloc(4*sizeof(int)); //Asigna un bloque de memoria de 4 enteros
  int *puntero=malloc(15*sizeof(*puntero)); //Asigna un bloque de memoria de 15 enteros

  //BUCLE PARA RELLENAR LOS ESPACIOS

  //Bucle para rellenar los espacios del primer bloque reservado (bloque00)
  for(int i=0; i<4; i++){
    bloque00[i]=i*2; // Asigna a cada posición del bloque00 el doble del índice
    printf("El valor de memoria reservado bloque00[%d] es de %d\n", i, bloque00[i]); // Imprime el valor en cada posición
  }

  if (puntero!=NULL){ // Verifica si la memoria para 'puntero' fue reservada exitosamente
    *(puntero+8)=9889; //Se llena la posición novena con el valor 9889
    // Imprime el valor de la novena posición
    printf("El valor de la novena posici+on de puntero es %d\n", *(puntero+8)); //Forma 1 -Como puntero
     printf("El valor de la novena posici+on de puntero es %d\n", puntero[8]); //Forma 2 - Como vector
  }
  
  //LIBERACIÓN O RETORNO DE MEMORIA
  free(bloque00); // Libera el bloque de memoria reservado para 'bloque00'
  free(puntero);// Libera el bloque de memoria reservado para 'puntero'
  
  return 0;
}
