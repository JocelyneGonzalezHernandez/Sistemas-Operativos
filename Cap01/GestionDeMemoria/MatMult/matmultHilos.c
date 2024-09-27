/***********************************************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 27/09/2024
Materia:Sistemas Operativos
Tema: Evaluación del rendimiento de sistemas de cómputo
Descripción:
  -La evaluación del rendimiento de sistemas de cómputo implica analizar diversas métricas y 
  factores que influyen en cómo se comporta un sistema bajo diferentes cargas.
  -Utilizar hilos y  gestionar eficientemente la memoria, son estrategias para mejorar y medir el rendimiento en sistemas modernos.
  -El tiempo de ejecución mide cuánto tarda un programa en completarse.
  -Los hilos permiten ejecutar varias tareas simultáneamente (en paralelo o concurrencia) y
  pueden mejorar significativamente el rendimiento en sistemas con múltiples núcleos.
***********************************************************************************************************************************************************/

#include <stdio.h> // Biblioteca para entrada y salida de datos
#include <time.h> // Biblioteca para funciones de tiempo
#include <stdlib.h> // Biblioteca para funciones de memoria
#include <pthread.h> // Biblioteca para hilos

#define data_reserva (1024*1024*64*3)  
// Tamaño de la reserva de memoria

static double mem_chunck[data_reserva]; // Bloque de memoria estática

typedef struct {
    int N;              // Tamaño de la matriz
    int num_of_threads; // Número de hilos
    double *a;         // Matriz A
    double *b;         // Matriz B
    double *c;         // Matriz C
    long rank;         // Identificador del hilo
} ThreadData;

void iniciarMatriz(int sz, double *a, double *b, double *c) { // Función para inicializar matriz
    for (int k = 0; k < sz; k++) {
        for (int j = 0; j < sz; j++) {
            a[j + k * sz] = 2.3 * (j + k); // Asigna valores a la matriz A
            b[j + k * sz] = 3.2 * (j - k); // Asigna valores a la matriz B
            c[j + k * sz] = 1.3; // Asigna valores a la matriz C
        }
    }
}

// Función paralela para multiplicar matrices
void *multiplicarMatriz(void *arg) { 
    ThreadData *data = (ThreadData *)arg; // Convierte el argumento a la estructura de datos
    int N = data->N;
    int rows_per_thr = N / data->num_of_threads; // Filas que procesará cada hilo
    int start_index = data->rank * rows_per_thr; // Índice inicial
    int final_index = (data->rank + 1) * rows_per_thr; // Índice final

    // Asegurarse de que el rango final no exceda el tamaño de la matriz
    if (data->rank == data->num_of_threads - 1) { // Último hilo
        final_index = N; // Este hilo maneja las filas restantes
    }

    for (int i = start_index; i < final_index; i++) {
        for (int j = 0; j < N; j++) {
            double sumaTemp = 0.0;
            for (int k = 0; k < N; k++) {
                sumaTemp += data->a[i * N + k] * data->b[k * N + j]; // Multiplica y acumula
            }
            data->c[i * N + j] = sumaTemp; // Asigna el resultado acumulado a la matriz C
        }
    }
    return NULL;
}

// Función para imprimir matrices
void imprimirMatriz(int sz, double *a) {
    for (int k = 0; k < sz; k++) {
        for (int j = 0; j < sz; j++) {
            printf("%f  ", a[j + k * sz]); // Imprime un elemento de la matriz
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------\n"); // Separador de matrices
}

int main(int argc, char *argv[]) {
      if (argc < 3) { // Verifica que se hayan pasado los argumentos necesarios
        printf("./matmult matrizSize Hilos\n");
        return -1;
    }

    int N = (int)atof(argv[1]); // Convierte el primer argumento a entero (tamaño de la matriz)
    int num_of_threads = (int)atof(argv[2]); // Convierte el segundo argumento a entero (número de hilos)

    clock_t start, end; // Variables para almacenar los tiempos de inicio y fin
    double tiempoEjecucion; // Variable para almacenar el tiempo total de ejecución

    // Reserva de memoria inicial de matrices
    double *a = mem_chunck; // Asigna el inicio de la reserva de memoria a 'a'
    double *b = a + N * N; // Asigna la siguiente parte del bloque de memoria a 'b'
    double *c = b + N * N; // Asigna la parte final del bloque de memoria a 'c'
  
      // Limitar el número de hilos a N si es necesario
    if (num_of_threads > N) {
        num_of_threads = N;
    }

    printf("\n\nValores ingresados:\n");
    printf("Matriz Size (NxN): %dx%d\n", N, N); // Imprime el tamaño de la matriz
    printf("Número de hilos (H): %d\n\n\n", num_of_threads); // Imprime el número de hilos

    iniciarMatriz(N, a, b, c); // Inicializa las matrices A, B y C
    imprimirMatriz(N, a); // Imprime la matriz A
    imprimirMatriz(N, b); // Imprime la matriz B

    pthread_t tid[num_of_threads]; // Crear hilos
    ThreadData thread_data[num_of_threads]; // Crear arreglo de estructuras de datos para los hilos

    // Inicializar datos para cada hilo
    for (long rank = 0; rank < num_of_threads; rank++) {
        thread_data[rank].N = N;
        thread_data[rank].num_of_threads = num_of_threads;
        thread_data[rank].a = a;
        thread_data[rank].b = b;
        thread_data[rank].c = c;
        thread_data[rank].rank = rank; // Asignar el rango de hilo
        pthread_create(&tid[rank], NULL, multiplicarMatriz, (void *)&thread_data[rank]); // Crear el hilo
    }

    // Unir hilos
    for (long rank = 0; rank < num_of_threads; rank++) {
        pthread_join(tid[rank], NULL);
    }

    end = clock(); // Termina el contador
    printf("-----------------------------RESULTADO-----------------------------\n");
    imprimirMatriz(N, c); // Imprime la matriz resultante C

    tiempoEjecucion = (double)(end - start) / CLOCKS_PER_SEC; // Calcula el tiempo en segundos
    printf("\nTiempo de ejecución: %f segundos\n", tiempoEjecucion); // Imprime el tiempo de ejecución

    return 0;
}
