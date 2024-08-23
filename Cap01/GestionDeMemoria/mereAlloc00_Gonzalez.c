/*****************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 23/08/2024
Materia:Sistemas Operativos
Tema: Gestión de memoria
Tópico: Redimensión de memoria con la función realloc().

*Utilizado para cambiar el tamaño de un bloque de memoria previamente asignado.
*La función puede mover el bloque de memoria a una nueva ubicación (cuya dirección es devuelta por la función).
*El contenido del bloque de memoria se conserva hasta el menor de los tamaños nuevo y antiguo, incluso si el bloque *se mueve a una nueva ubicación. Si el nuevo tamaño es mayor, el valor de la porción recién asignada es indeterminado.
*En caso de que ptr sea un puntero nulo, la función se comporta como malloc, asignando un nuevo bloque de tamaño bytes y devolviendo un puntero a su inicio.
*****************************************************************/

#include <stdio.h>       //Biblioteca para entrada y salida de datos
#include <stdlib.h>      //Biblioteca para funciones de memoria
/*****************************************************************
@brief Redimensiona un bloque de memoria y muestra información sobre el tamaño anterior y el nuevo tamaño.
@param ptr Puntero al puntero que apunta al bloque de memoria que se redimensiona.
@param nuevo_tamano Nuevo tamaño del bloque de memoria.
@param old_size Puntero a una variable que almacena el tamaño anterior del bloque de memoria.
@return No retorna ningún valor. Termina el programa en caso de error.
*****************************************************************/
void redimensionar_memoria(int** ptr, int nuevo_tamano, size_t* old_size) {
    int* temp = (int*) realloc(*ptr, nuevo_tamano * sizeof(int)); //Redimensionar el bloque de memoria apuntado por ptr al nuevo tamaño

    // Verifica si realloc fue exitoso
    if (temp != NULL) {
        // Verifica si realloc movió el bloque de memoria
        if (*ptr == temp) {
            printf("realloc ajustó el tamaño del bloque existente en la misma dirección: %p\n", (void*)temp);
        } else {
            printf("realloc asignó un nuevo bloque de memoria en una nueva dirección: %p\n", (void*)temp);
        }
        printf("Tamaño anterior: %zu bytes, Nuevo tamaño: %zu bytes\n", *old_size, nuevo_tamano * sizeof(int)); // Imprime el tamaño anterior y el nuevo tamaño
        *old_size = nuevo_tamano * sizeof(int);  // Actualiza el tamaño anterior al nuevo tamaño
        *ptr = temp;  // Actualiza el puntero al nuevo bloque de memoria
    } else {
      // Si realloc falla, libera la memoria original y termina el programa con un error
        puts("Error al (re)asignar memoria");
        free(*ptr);
        exit(1);
    }
}

/*****************************************************************
@brief Solicita al usuario que ingrese un número y lo agrega al arreglo.
@param numeros Doble puntero al bloque de memoria que almacena los números.
@param contador Puntero a la variable que cuenta los números almacenados.
@param old_size Puntero a una variable que almacena el tamaño anterior del bloque de memoria.
@return No retorna ningún valor.
*****************************************************************/
void agregar_numero(int** numeros, int* contador, size_t* old_size) {
    int entrada;
    printf("Ingrese un número entero: "); // Solicita al usuario que ingrese un número enter
    scanf("%d", &entrada); // Lee el número ingresado por el usuario
    (*contador)++; //Incremetna el contador de números
    redimensionar_memoria(numeros, *contador, old_size); //Redimensiona la memoria para incluir el nuevo número
    (*numeros)[*contador - 1] = entrada; // Almacena el número ingresado en el último índice del arreglo
}

/*****************************************************************
@brief Elimina el último número del arreglo.
@param numeros Doble puntero al bloque de memoria que almacena los números.
@param contador Puntero a la variable que cuenta los números almacenados.
@param old_size Puntero a una variable que almacena el tamaño anterior del bloque de memoria.
@return No retorna ningún valor.
*****************************************************************/
void eliminar_numero(int** numeros, int* contador, size_t* old_size) {
  // Verifica si hay números para eliminar
    if (*contador > 0) {
        (*contador)--;// Decrementa el contador de números
        redimensionar_memoria(numeros, *contador, old_size);  // Redimensiona la memoria para reflejar el nuevo tamaño
    } else {
        printf("No hay números para eliminar\n"); // Muestra un mensaje si no hay números para eliminar
    }
}

/*****************************************************************
@brief Muestra los números almacenados en el arreglo.
@param numeros Puntero al bloque de memoria que almacena los números.
@param contador Número de elementos en el arreglo.
@return No retorna ningún valor.
*****************************************************************/
void mostrar_numeros(int* numeros, int contador) {
    printf("Números finales: "); // Imprime un encabezado para los números
    for (int n = 0; n < contador; n++) {
        printf("%d ", numeros[n]); //Imprime cada número almacenado, seguido de un espacio
    }
    printf("\n");
}

int main() {
    int contador = 0; // Contador de números almacenados
    int* numeros = NULL; // Puntero al bloque de memoria que almacena los números
    size_t old_size = 0;  // Variable para guardar el tamaño anterior

    // Bucle principal que continúa hasta que se seleccione la opción de terminar
    while (1) {
        int opcion;
        printf("\nElija una opción:\n");
        printf("1. Agregar número\n");
        printf("2. Eliminar último número\n");
        printf("3. Terminar\n");
        printf("Opción: ");
        scanf("%d", &opcion); // Lee la opción seleccionada por el usuario  

      // Ejecuta la acción correspondiente según la opción del usuario
        if (opcion == 1) {
            agregar_numero(&numeros, &contador, &old_size);// Llama a la función para agregar un número
        } else if (opcion == 2) { 
            eliminar_numero(&numeros, &contador, &old_size); // Llama a la función para eliminar el último número
        } else if (opcion == 3) {
            break; // Sale del bucle y termina el programa si la opción es 3
        } else {
            printf("Opción no válida, intente nuevamente.\n"); // Muestra un mensaje si la opción ingresada no es válida
        }
    }  
    mostrar_numeros(numeros, contador); // Muestra los números finales almacenados en el arreglo
    free(numeros);// Libera la memoria asignada

    return 0;
}
