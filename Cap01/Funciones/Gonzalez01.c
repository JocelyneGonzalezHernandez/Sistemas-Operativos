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
#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida

/* Función que imprime un mensaje de bienvenida */
void bienvenida() {
  printf("Hola mundo\n");          // Imprime "Hola mundo"
  printf("\t\t Bienvenidos \n");  // Imprime "Bienvenidos" con tabulación para formato
}

/* Función que suma dos enteros y muestra el resultado */
void suma2enteros() {
  int num1 = 5;   // Primer entero a sumar
  int num2 = 16;  // Segundo entero a sumar
  
  printf("Primer entero: %d\n", num1); // Imprime el primer entero
  printf("Segundo entero: %d\n", num2); // Imprime el segundo entero
  
  int suma = num1 + num2;  // Calcula la suma de los dos enteros
  printf("Resultado: %d\n", suma);  // Imprime el resultado de la suma
}

/* Función que calcula el área de una circunferencia y muestra el resultado */
void areacircunferencia() { 
  int radio = 5;          // Radio de la circunferencia
  float pi = 3.1416;      // Valor de pi con precisión de 4 decimales
  
  printf("El radio es : %d cm\n", radio); // Imprime el valor del radio
  
  float area = radio * radio * pi;  // Calcula el área de la circunferencia usando la fórmula A = pi * r^2
  printf("El área es: %0.2f\n", area);  // Imprime el área con dos decimales de precisión
}

// Función principal del programa
int main(int argc, char *argv[]) {
    bienvenida();           // Llama a la función de bienvenida
    suma2enteros();        // Llama a la función que suma dos enteros
    areacircunferencia();  // Llama a la función que calcula el área de una circunferencia
   
    return 0; // Finaliza el programa y devuelve 0, indicando éxito
}
