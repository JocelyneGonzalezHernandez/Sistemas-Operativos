/*
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 13/08/2024
Materia:Sistemas Operativos
Tema: Gestión de memoria
Tópico: Reserva de memoria con la función calloc().
*La función calloc reserva un espacio de memoria del tamaño especificado.
*Los espacios  de igual tamño y de memoria contigua.
*La asignación es dinámica y útil para complejas estructuras de datos.
*La función calloc inicializa los espacios reservados en 0.
*Devuelve un puntero al inicio del espacio reservado.
*/
#include  <stdio.h> //Biblioteca para entrada y salida de datos
#include <stdlib.h> //Biblioteca para funciones de memoria

int main(){
  int *p1=calloc(4,sizeof(int)); //Reserva memoria para 4 enteros e inicializa cada byte a 0
  int *puntero=calloc(10,sizeof(int)); //Reserva memoria para 10 enteros e inicializa cada byte a 0
  int *p3=calloc(5,sizeof *p3); //Reeserva memoria para 5 enteros e inicializa cada byte a 0
  // calloc(5, sizeof *p3) es equivalente a calloc(5, sizeof(int))

  
  //BUCLE PARA RELLENAR LOS ESPACIOS

   printf("Construcción y cálculo de la secuencia de los primeros 10 términos\n");
  for(int i=0; i<10; i++){
    *(puntero+i)=i; //Asigna el valor de 'i' a la posición 'i' en el bloque de memoria
    printf("El valor de la secuencia es %d\n",i, *(puntero+i)); // Imprime el valor actual de la secuencia
  }
  //LIBERACIÓN O RETORNO DE MEMORIA
  free(p1); // Libera la memoria reservada para 'p1'
  free(p3); // Libera la memoria reservada para 'p3'
  free(puntero); // Libera la memoria reservada para 'puntero'

  return 0;
}
