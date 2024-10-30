/*******************************************************************************************************
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
*******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>  // Para usar la función sleep()

// Contador compartido entre los hilos productores y consumidores
int counter = 0;
int max = 4;  // Número de hilos de productores y consumidores

// Declaración de mutexes para la sincronización de hilos
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;  // Protege el acceso a 'counter'
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;    // Protege la condición de productor
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;    // Protege la condición de consumidor

// Variables de condición para la sincronización entre productores y consumidores
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;  // Condición para los productores
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;  // Condición para los consumidores

// Declaración de funciones para los hilos productores y consumidores
void *productor(void *arg);
void *consumidor(void *arg);

int main() {
    pthread_t proHilo[max], conHilo[max];  // Arreglos de hilos de productores y consumidores
    int i;

    // Crear los hilos de productores y consumidores
    for (i = 0; i < max; i++) {
        pthread_create(&proHilo[i], NULL, &productor, NULL);  // Crear hilo productor
        pthread_create(&conHilo[i], NULL, &consumidor, NULL); // Crear hilo consumidor
    }

    // Esperar a que todos los hilos terminen
    for (i = 0; i < max; i++) {
        pthread_join(proHilo[i], NULL);  // Espera a que el hilo productor termine
        pthread_join(conHilo[i], NULL);  // Espera a que el hilo consumidor termine
    }

    return 0;
}

// Función para el hilo productor
void *productor(void *arg) {
    while (1) {
        pthread_mutex_lock(&condp_mutex);  // Bloquear el mutex de productor
        while (counter >= 10) {  // Si el contador ha llegado al límite, esperar
            pthread_cond_wait(&condVarProd, &condp_mutex);  // Espera a que un consumidor consuma
        }
        pthread_mutex_unlock(&condp_mutex);  // Liberar el mutex de productor

        // Bloquear el acceso al contador y producir un "elemento"
        pthread_mutex_lock(&counter_mutex);
        counter++;  // Incrementar el contador compartido
        printf("Soy productor %ld, valor contador = %d\n", pthread_self(), counter);
        pthread_cond_signal(&condVarCons);  // Señalar a los consumidores para que consuman
        pthread_mutex_unlock(&counter_mutex);  // Desbloquear el contador

        if (counter == 5) {
            sleep(1);  // Pausa para simular tiempo de espera cuando el contador llega a 5
        }
    }
    return NULL;
}

// Función para el hilo consumidor
void *consumidor(void *arg) {
    while (1) {
        sleep(1);  // Simular el tiempo de consumo
        pthread_mutex_lock(&condc_mutex);  // Bloquear el mutex de consumidor
        while (counter <= 0) {  // Si el contador es cero, esperar a que haya elementos
            pthread_cond_signal(&condVarProd);  // Señalar a los productores para que produzcan
            pthread_cond_wait(&condVarCons, &condc_mutex);  // Esperar a que el contador suba
        }
        pthread_mutex_unlock(&condc_mutex);  // Liberar el mutex de consumidor

        // Bloquear el acceso al contador y consumir un "elemento"
        pthread_mutex_lock(&counter_mutex);
        if (counter > 0) {  // Verificar si el contador es mayor que cero
            printf("Soy consumidor %ld, valor contador = %d\n", pthread_self(), counter);
            counter--;  // Decrementar el contador compartido
        }
        pthread_cond_signal(&condVarProd);  // Señalar a los productores para producir
        pthread_mutex_unlock(&counter_mutex);  // Desbloquear el contador
    }
    return NULL;
}
