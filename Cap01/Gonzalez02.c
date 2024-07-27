/***************************************************
Autor: Jocelyne Gonzalez Hernández.
Fecha: 23/07/2024
Materia: Sistemas Operativos
Tema: Programación en C V.2
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
  int num1, num2; 
  printf("Ingrese el Primer entero: \n");
  scanf("%d", &num1);
  printf("Ingrese el segundo entero:\n");
  scanf("%d", &num2);
  
  int suma = num1 + num2;
  printf("Resultado: %d\n", suma);
}

/*Función que calcule el área de una circunferecia*/
void areacircunferencia(){ 
  float radio;
  float pi=3.1416;
  printf("Ingrese el radio: ");
  scanf("%f", &radio);
  float area = radio * radio * pi;
  printf("\nEl área es: %0.2f\n", area);
}

//Función principal
 int main(int argc, char *argv[]) {
    bienvenida();
    suma2enteros();
    areacircunferencia();
   
  return 0;
}
