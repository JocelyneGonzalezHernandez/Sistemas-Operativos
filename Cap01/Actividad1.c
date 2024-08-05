/*
Autor: Jocelye Gonzalez
Fecha: 30/07/2024
Materia: Sistemas Operatviso
Tema: Argumentos de entrada en C
*/

#include <stdio.h>

/*Pedir 8 entradas y hacer algo*/

//Este programa recibirá 8 argumentos que serán números enteros y posteriormente los sumará

int main(int argc, char *argv[])
{
  int suma=0; //Inicializar suma en 0
  
  printf("Ingresó 8 números enteros, ahora voy imprimirlos y sumarlos\n");
  
    
    for (int i=1; i<9; i++) //Bucle que recorre los argumentos omitiendo el argumento 0, que es el nombre del programa
    {
       printf("Ha ingresado el número: %s\n", argv[i]); //Imprime el argumento actual
      
      suma=suma+atoi(argv[i]); //Convierte  el argumento a entero y lo suma

    }
 
  printf("\n");
  printf("Suma: %d\n", suma); //Imprime la suma total de los 8 números
  return 0;
}
