/*******************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:29/10/2024
Materia: Sistemas Operativos
Tema:Posix / Threads
Descripción:
-Un hilo (thread) es la unidad más pequeña de procesamiento que un sistema operativo puede gestionar y ejecutar.
-Los hilos son útiles para dividir una tarea en subtareas que pueden ejecutarse en paralelo, 
aprovechando mejor los recursos de un procesador, especialmente en sistemas con múltiples núcleos.
-pthread es la biblioteca de hilos en C que implementa el estándar POSIX para la programación multihilo.
-POSIX (interfaz de sistema operativo portátil para UNIX) es un conjunto de estándares para interfaces y 
especificaciones que admiten la portabilidad y la compatibilidad entre sistemas similares a UNIX.
*******************************************************************************************************************/
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>

// Función que ejecutará cada hilo, imprime el número de trabajo asignado al hilo
static void *funcion(void *argumentos) {
    size_t job = *(size_t *)argumentos;  // Obtener el valor del trabajo (job) a realizar
    printf("\n\t Job %zu \n", job);      // Imprimir el identificador del trabajo
    return NULL;                         // Termina el hilo
}

int main(int argc, char *argv[]) {
    // Verificar que se haya pasado un argumento de línea de comandos
    if (argc != 2) {
        printf("Uso: %s <numero_de_hilos>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);          // Convertir el argumento a entero, representa el número de hilos
    size_t jobs[N];                 // Arreglo que representa los trabajos a asignar
    pthread_t hilos[N];             // Arreglo de hilos

    // Inicialización de trabajos y creación de hilos
    for (int i = 0; i < N; i++) {
        jobs[i] = i;  // Asignar un identificador de trabajo
        // Crear un hilo que ejecuta la función 'funcion' con el trabajo actual
        pthread_create(&hilos[i], NULL, funcion, jobs + i);
    }

    // Esperar a que todos los hilos terminen su ejecución
    for (int i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);  // Esperar a que el hilo 'i' termine
    }

    return 0;
}
