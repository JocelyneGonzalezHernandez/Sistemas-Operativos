/***************************************************
Autor: Jocelyne Gonzalez Hernández.
Fecha: 23/07/2024
Materia: Sistemas Operativos
Tema: Programación en C
Requerimientos:
  -Función que sume 2 enteros
  -Función que calcule el área de una circunferecia
  -Función que de la bienvenida
***************************************************/
#include <stdio.h>  //

/*Función de bienvenida*/
void bienvenida() {
  printf ("Hola mundo\n");
  printf("\t\t Bienvenidos \n");
}

/*Función que sume dos enteros*/
void suma2enteros(){
  printf("Primer entero: 5\n");
  printf("Primer entero: 16\n");
  
  int suma = 5 + 16;
  printf("Resultado: %d\n", suma);
}

/*Función que calcule el área de una circunferecia*/
void areacircunferencia(){ 
  int radio=5;
  float pi=3.1416;
  printf("El radio es : %d cm\n", radio);
  
  float area = radio * radio * pi;
  printf("El área es: %0.2f\n", area);
}

//Función principal
 int main(int argc, char *argv[]) {
    bienvenida();
    suma2enteros();
    areacircunferencia();
   
  return 0;
}
