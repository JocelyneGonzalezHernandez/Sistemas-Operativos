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
#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida para usar printf y scanf

/* Función que imprime un mensaje de bienvenida */
void bienvenida() {
  printf("Hola mundo\n");          // Imprime "Hola mundo"
  printf("\t\t Bienvenidos \n");  // Imprime "Bienvenidos" con tabulación para formato
}

/* Función que suma dos enteros introducidos por el usuario */
void suma2enteros() {
  int num1, num2; // Variables para almacenar los enteros introducidos por el usuario
  
  // Solicita al usuario el primer entero
  printf("Ingrese el Primer entero: \n");
  scanf("%d", &num1);  // Lee el primer entero desde la entrada estándar y lo almacena en num1
  
  // Solicita al usuario el segundo entero
  printf("Ingrese el segundo entero:\n");
  scanf("%d", &num2);  // Lee el segundo entero desde la entrada estándar y lo almacena en num2
  
  int suma = num1 + num2;  // Calcula la suma de los dos enteros
  printf("Resultado: %d\n", suma);  // Imprime el resultado de la suma
}

/* Función que calcula el área de una circunferencia dada por el usuario */
void areacircunferencia() { 
  float radio;    // Variable para almacenar el radio de la circunferencia
  float pi = 3.1416;  // Valor de pi con precisión de 4 decimales
  
  // Solicita al usuario el radio de la circunferencia
  printf("Ingrese el radio: ");
  scanf("%f", &radio);  // Lee el radio desde la entrada estándar y lo almacena en radio
  
  float area = radio * radio * pi;  // Calcula el área de la circunferencia usando la fórmula A = pi * r^2
  printf("\nEl área es: %0.2f\n", area);  // Imprime el área con dos decimales de precisión
}

// Función principal del programa
int main(int argc, char *argv[]) {
    bienvenida();           // Llama a la función de bienvenida
    suma2enteros();        // Llama a la función que suma dos enteros introducidos por el usuario
    areacircunferencia();  // Llama a la función que calcula el área de una circunferencia
    
    return 0; // Finaliza el programa y devuelve 0, indicando éxito
}
