/************************************************************************************************************************************
 * Pontificia Universidad Javeriana
 * Autor: Jocelyne Gonzalez Hernandez
 * Fecha: 08/11/2024
 * Materia: Sistemas Operativos
 * Tema: Taller de Evaluación de Rendimiento
 * Fichero: fuente de multiplicación de matrices NxN por hilos.
 * Objetivo: Evaluar el tiempo de ejecución del 
 *           algoritmo clásico de multiplicación de matrices.
 *           Se implementa con la Biblioteca POSIX Pthreads.
 * Descripción:
  -La evaluación del rendimiento de sistemas de cómputo implica analizar diversas métricas y 
  factores que influyen en cómo se comporta un sistema bajo diferentes cargas.
  -Utilizar hilos y  gestionar eficientemente la memoria, son estrategias para mejorar y medir el rendimiento en sistemas modernos.
  -El tiempo de ejecución mide cuánto tarda un programa en completarse.
  -Los hilos permiten ejecutar varias tareas simultáneamente (en paralelo o concurrencia) y
  pueden mejorar significativamente el rendimiento en sistemas con múltiples núcleos.
************************************************************************************************************************************/
#include <stdio.h>         // Biblioteca para entrada y salida estándar.
#include <pthread.h>       // Biblioteca para el manejo de hilos POSIX.
#include <unistd.h>        // Biblioteca para constantes POSIX.
#include <stdlib.h>        // Biblioteca para conversión de tipos y funciones de utilidad.
#include <time.h>          // Biblioteca para funciones relacionadas con el tiempo.
#include <sys/time.h>      // Biblioteca para medir el tiempo en microsegundos.

#define DATA_SIZE (1024*1024*64*3) // Tamaño del espacio de memoria asignado para las matrices.

pthread_mutex_t MM_mutex;         // Mutex para sincronizar el acceso compartido.
static double MEM_CHUNK[DATA_SIZE]; // Espacio de memoria estático para almacenar matrices.
double *mA, *mB, *mC;             // Punteros para las matrices A, B y C.

struct parametros {               // Estructura para almacenar los parámetros de los hilos.
    int nH;                       // Número de hilos totales.
    int idH;                      // ID del hilo actual.
    int N;                        // Tamaño de la matriz (NxN).
};

struct timeval start, stop;       // Estructuras para medir el tiempo de ejecución.

void llenar_matriz(int SZ) {      // Función para inicializar matrices con valores.
    srand48(time(NULL));          // Inicializa la semilla para valores aleatorios.
    for (int i = 0; i < SZ*SZ; i++) {
        mA[i] = 1.1 * i;          // Asigna valores a mA.
        mB[i] = 2.2 * i;          // Asigna valores a mB.
        mC[i] = 0;                // Inicializa mC con ceros.
    }   
}

void print_matrix(int sz, double *matriz) { // Función para imprimir una matriz si el tamaño es pequeño.
    if (sz < 12) {                 // Imprime solo si el tamaño es menor que 12.
        for (int i = 0; i < sz*sz; i++) {
            if (i % sz == 0) printf("\n");
            printf(" %.3f ", matriz[i]);
        }   
        printf("\n>-------------------->\n");
    }
}

void inicial_tiempo() {            // Función para iniciar el conteo de tiempo.
    gettimeofday(&start, NULL);
}

void final_tiempo() {              // Función para detener el conteo y mostrar el tiempo.
    gettimeofday(&stop, NULL);
    stop.tv_sec -= start.tv_sec;
    printf("\n:-> %9.0f µs\n", (double)(stop.tv_sec*1000000 + stop.tv_usec));
}

void *mult_thread(void *variables) { // Función de multiplicación para cada hilo.
    struct parametros *data = (struct parametros *)variables;
    
    int idH = data->idH;           // ID del hilo.
    int nH  = data->nH;            // Número de hilos.
    int N   = data->N;             // Tamaño de la matriz.

    // Rango de filas asignadas al hilo.
    int ini = (N / nH) * idH;
    int fin = (N / nH) * (idH + 1);

    // Multiplicación de matrices en el rango asignado.
    for (int i = ini; i < fin; i++) {
        for (int j = 0; j < N; j++) {
            double *pA, *pB, sumaTemp = 0.0;
            pA = mA + (i * N);       // Puntero a la fila de mA.
            pB = mB + (j * N);       // Puntero a la columna de mB.
            for (int k = 0; k < N; k++, pA++, pB++) {
                sumaTemp += (*pA * *pB); // Producto y suma acumulada.
            }
            mC[i * N + j] = sumaTemp;   // Almacena el resultado en mC.
        }
    }

    pthread_mutex_lock(&MM_mutex);    // Bloquea el mutex (no hace nada aquí en realidad).
    pthread_mutex_unlock(&MM_mutex);  // Desbloquea el mutex.
    pthread_exit(NULL);               // Finaliza el hilo.
}

int main(int argc, char *argv[]) {  // Función principal.
    if (argc < 2) {                 // Verifica los argumentos necesarios.
        printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
        return -1;  
    }
    int SZ = atoi(argv[1]);         // Tamaño de la matriz (NxN).
    int n_threads = atoi(argv[2]);  // Número de hilos.

    pthread_t p[n_threads];         // Arreglo de identificadores de hilos.
    pthread_attr_t atrMM;           // Atributos para la configuración de los hilos.

    // Asigna espacio para las matrices en MEM_CHUNK.
    mA = MEM_CHUNK;
    mB = mA + SZ * SZ;
    mC = mB + SZ * SZ;

    llenar_matriz(SZ);              // Llenado de las matrices.
    print_matrix(SZ, mA);           // Imprime matriz A.
    print_matrix(SZ, mB);           // Imprime matriz B.

    inicial_tiempo();               // Inicia el conteo de tiempo.
    pthread_mutex_init(&MM_mutex, NULL);  // Inicializa el mutex.
    pthread_attr_init(&atrMM);           // Inicializa los atributos de hilo.
    pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE); // Los hilos pueden ser unidos.

    for (int j = 0; j < n_threads; j++) {
        struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
        datos->idH = j;             // Asigna ID de hilo.
        datos->nH = n_threads;      // Número de hilos.
        datos->N = SZ;              // Tamaño de la matriz.
        pthread_create(&p[j], &atrMM, mult_thread, (void *)datos); // Crea el hilo.
    }

    for (int j = 0; j < n_threads; j++)
        pthread_join(p[j], NULL);   // Espera a que todos los hilos terminen.
    final_tiempo();                 // Detiene el conteo de tiempo y muestra el tiempo total.

    print_matrix(SZ, mC);           // Imprime la matriz resultante.

    pthread_attr_destroy(&atrMM);   // Destruye los atributos del hilo.
    pthread_mutex_destroy(&MM_mutex); // Destruye el mutex.
    pthread_exit(NULL);             // Termina el programa.
}