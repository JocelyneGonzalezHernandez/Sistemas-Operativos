/*
Autor: Jocelye Gonzalez
Fecha: 30/07/2024
Materia: Sistemas Operatviso
Tema: Argumentos de entrada en C
*/

#include <stdio.h>

/*Al inicio debe enviar el programa con el valor de la edad
  Se presentan una serie de preguntas que el usuario debe responder*/

int main(int argc, char *argv[])  // 
{
  printf("Ha ingresado [%d]: \n ", argc);  //Se imprime como entero la cantidad de argumentos
  printf("Ha ingresado la edad: %s\n", argv[1]); //Se imprime como string el argumento número 1 (el segundo en posicón)
  printf("Ha ingresado el mes: %s\n", argv[2]);  //Se imprime como string el argumento número 2 (el tercero en posicón)
  
  printf("\n"); //Salto de línea
  
  return 0;
}
