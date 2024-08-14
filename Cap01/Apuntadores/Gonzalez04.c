/*
Autor: Jocelye Gonzalez
Fecha: 30/07/2024
Materia: Sistemas Operatviso
Tema: Argumentos de entrada en C  //Apuntadores
*/

#include <stdio.h>

/*Al inicio debe enviar el programa con el valor de la edad
  Se presentan una serie de preguntas que el usuario debe responder*/

int main(int argc, char *argv[])
{
  
  int x= 120;  //El contenido de la variable X es 120
  int *p = x; //p apunta a la dirección de memoria de la variable X
  printf("El valor de X es: %d\n", x); //Imprime el valor de X
  printf("La dirección de X es: %p\n", p); //Imprime la dirección de mememoria de X, en formato hexadecimal con %p
  
  int vector[7] = {5,10,20,30,40,50,80}; //Declaración de un vector de 7 números enteros
  int *p1 = vector; //El puntero p1 está inicializado con la dirección de memoria del primero elemento del vector
  int *p2 = vector+2; //El puntero p2 está inicializado con la dirección de memoria del tercer elemento del vector
  int diferencia = p2-p1; //Calcular la diferencia entre los valores del los dos punteros (cantidad de elementos entre ellos)
  
  printf("\n El valor p1 es de:%p\n", p1); //Imprime la dirección almacenada en el puntero p1
  printf("\n El valor p2 es de:%p\n", p2); //Imprime la dirección almacenada en el puntero p2
  printf("\n El valor resta es de:%p\n", diferencia);//Imprime la diferencia calculada
  
  printf("\n");
  
  return 0;
}
