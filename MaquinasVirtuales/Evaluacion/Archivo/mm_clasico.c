/***********************************************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 29/10/2024
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

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define DATA_SIZE (1024*1024*64*3) // Tamaño de la memoria compartida para matrices

// Declaración del mutex para controlar la sincronización
pthread_mutex_t MM_mutex;
static double MEM_CHUNK[DATA_SIZE]; // Espacio de memoria compartida para las matrices
double *mA, *mB, *mC;  // Punteros para las matrices A, B y C

// Estructura que contiene los parámetros de cada hilo
struct parametros{
	int nH;    // Número de hilos
	int idH;   // ID del hilo actual
	int N;     // Dimensión de la matriz NxN
};

// Variables para calcular el tiempo de ejecución
struct timeval start, stop;

// Función para llenar las matrices A y B con valores iniciales
void llenar_matriz(int SZ){ 
	srand48(time(NULL)); // Inicializa el generador de números aleatorios
	for(int i = 0; i < SZ*SZ; i++){
			mA[i] = 1.1*i; // Elementos de la matriz A
			mB[i] = 2.2*i; // Elementos de la matriz B
			mC[i] = 0;     // Inicializa matriz C en 0
		}	
}

// Función para imprimir una matriz (solo se imprime si es menor a tamaño 12x12)
void print_matrix(int sz, double *matriz){
	if(sz < 12){
    		for(int i = 0; i < sz*sz; i++){
     				if(i%sz==0) printf("\n");
            		printf(" %.3f ", matriz[i]);
			}	
    	printf("\n>-------------------->\n");
	}
}

// Función para inicializar el tiempo
void inicial_tiempo(){
	gettimeofday(&start, NULL); // Captura el tiempo de inicio
}

// Función para finalizar y calcular el tiempo transcurrido
void final_tiempo(){
	gettimeofday(&stop, NULL); // Captura el tiempo de finalización
	stop.tv_sec -= start.tv_sec;
	printf("\n:-> %9.0f µs\n", (double) (stop.tv_sec*1000000 + stop.tv_usec)); // Tiempo en microsegundos
}

// Función que ejecutará cada hilo para realizar la multiplicación de matrices
void *mult_thread(void *variables){
	struct parametros *data = (struct parametros *)variables; // Obtiene los parámetros del hilo
	
	int idH = data->idH;          // ID del hilo
	int nH  = data->nH;           // Número de hilos
	int N   = data->N;            // Dimensión de la matriz
	int ini = (N/nH)*idH;         // Índice inicial para la división de trabajo
	int fin = (N/nH)*(idH+1);     // Índice final para la división de trabajo

    // Multiplicación de matrices asignada a este hilo
    for (int i = ini; i < fin; i++){
        for (int j = 0; j < N; j++){
			double *pA, *pB, sumaTemp = 0.0;
			pA = mA + (i*N);        // Apunta al inicio de la fila en matriz A
			pB = mB + j;            // Apunta al inicio de la columna en matriz B
            for (int k = 0; k < N; k++, pA++, pB+=N){
				sumaTemp += (*pA * *pB); // Calcula la multiplicación y suma de cada elemento
			}
			mC[i*N+j] = sumaTemp; // Guarda el resultado en la matriz C
		}
	}

	// Uso de mutex para sincronización al finalizar
	pthread_mutex_lock(&MM_mutex);
	pthread_mutex_unlock(&MM_mutex);
	pthread_exit(NULL); // Termina el hilo
}

int main(int argc, char *argv[]){
	// Validación de argumentos de entrada
	if (argc < 2){
		printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
		return -1;	
	}
    
	int SZ = atoi(argv[1]);       // Tamaño de la matriz NxN
    int n_threads = atoi(argv[2]); // Número de hilos

    pthread_t p[n_threads];       // Arreglo de hilos
    pthread_attr_t atrMM;         // Atributo para los hilos

	// Asigna la memoria compartida para las matrices A, B y C
	mA = MEM_CHUNK;
	mB = mA + SZ*SZ;
	mC = mB + SZ*SZ;

	llenar_matriz(SZ);            // Llena las matrices A y B con valores
	print_matrix(SZ, mA);         // Imprime matriz A (si aplica)
	print_matrix(SZ, mB);         // Imprime matriz B (si aplica)

	inicial_tiempo();             // Inicia la medición de tiempo
	pthread_mutex_init(&MM_mutex, NULL);
	pthread_attr_init(&atrMM);    
	pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

    // Creación de los hilos de trabajo
    for (int j = 0; j < n_threads; j++){
		struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
		datos->idH = j;            // ID del hilo
		datos->nH  = n_threads;    // Total de hilos
		datos->N   = SZ;           // Tamaño de la matriz
        pthread_create(&p[j], &atrMM, mult_thread, (void *)datos); // Crear hilo
	}

    // Esperar a que todos los hilos terminen su ejecución
    for (int j = 0; j < n_threads; j++)
        pthread_join(p[j], NULL);

	final_tiempo();               // Finaliza y muestra el tiempo de ejecución
	
	print_matrix(SZ, mC);         // Imprime el resultado de la matriz C

	// Destruir atributos y liberar recursos
	pthread_attr_destroy(&atrMM);
	pthread_mutex_destroy(&MM_mutex);
	pthread_exit(NULL);
}
