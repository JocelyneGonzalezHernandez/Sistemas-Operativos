/************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 06/08/2024
Materia:Sistemas Operativos
Tema: Evaluación del rendimiento de sistemas de cómputo
Descripción:
  -La evaluación del rendimiento de sistemas de cómputo implica analizar diversas métricas y factores que influyen en cómo se comporta un sistema bajo diferentes cargas.
  -Utilizar hilos y  gestionar eficientemente la memoria, son estrategias para mejorar y medir el rendimiento en sistemas modernos.
  -El tiempo de ejecución mide cuánto tarda un programa en completarse.
  -Los hilos permiten ejecutar varias tareas simultáneamente (en paralelo o concurrencia) y
  pueden mejorar significativamente el rendimiento en sistemas con múltiples núcleos.
*************************************************************************/

#include  <stdio.h> //Biblioteca para entrada y salida de datos
#include <time.h> //Biblioteca para funciones de tiempo
#include <stdlib.h> //Biblioteca para funciones de memoria

#define data_reserva (1024*1024*64*3)  
//Tamaño de la reserva de memoria

static double mem_chunck[data_reserva]; //Bloque de memoria estática

void iniciarMatriz(int sz, double *a, double *b, double *c){  //Funcion para inicializar matriz
  int i,j,k;

  for (k=0; k<sz; k++)
    {
      for(j=0; j<sz; j++)
        {
          a[j+k*sz]=2.3*(j+k); //Asigna valores a la matriz A
          b[j+k*sz]=3.2*(j-k); //Asigna valores a la matriz B
          c[j+k*sz]=1.3; //Asigna valores a la matriz C
        }
    }
}

void multiplicarMatriz(int sz, double *a, double *b, double *c){ //Funcion para multiplicar matrices
  int i,j,k;
  double *pa, *pb, *pc, sumaTemp;

  //Multiplica matrices A y B y asigna a C el resultado
    for (k=0; k<sz; k++)
      {
        for(j=0; j<sz; j++)
          {
           sumaTemp=0.0;
            pa=a+(k*sz); //Apunta al inicio de la fila K de la matriz A
            pb = b+j; //Apunta al inicio de la columna J de la matriz B
            for(i=sz; i>0; i--, pa++, pb+=sz){
              sumaTemp += (*pa * *pb); //Suma los productos de los elementos de la fila K de la matriz A y la columna J de la matriz B
            }
            c[k*sz+j]=sumaTemp; //Asigna el resultado acumulado a la matriz C
          }
      }
}

//Función para imprimir matrices
void imprimirMatriz(int sz, double *a){  //Debe ser N en lugar de sz
  int j,k;
  for (k=0; k<sz; k++)
    {
      for(j=0; j<sz; j++)
        {
          printf("%f  ", a[j+k*sz]); //Imprime un elemento de la matriz
        }
      printf("\n");
    }
  printf("-------------------------------------------------------------------\n"); //Separador de matrices
}

int main(int argc, char *argv[]){
  
  if(argc<3){ //Verifica que se hayayn pasado los argumentos necesarios
    printf("./matmult matrizSize Hilos\n");
    return -1;
  }

  int N= (int)atof(argv[1]); //// Convierte el segundo argumento a entero (tamaño de la matriz)
  int H= (int)atof(argv[2]);// Convierte el tercer argumento a entero (número de hilos)

  double *a, *b, *c; //Apuntadores

  clock_t start, end;      //Variables para almacenar los tiempos de inicio y fin
  double tiempoEjecucion;  //Variable para almacenar el tiempo total de ejecución
  
  //Reserva de memoria inicial de matrices
  a= mem_chunck; //Asigna el inicio de la reserva de memoria a 'a'
  b= a + N*N; //Asigna la siguiente parte del bloque de memoria a 'b'
  c= b + N*N; //Asigna la parte final del bloque de memoria a 'c'

  printf("\n\nValores ingresados:\n");
  printf("Matriz Size (NxN): %dx%d\n", N,N); //Imprime el tamaño de la matriz
  printf("Número de hilos (H):%d\n\n\n", H); //Imprime el número de hilos

  iniciarMatriz(N, a, b, c); //Inicializa las matrices A, B y C
  imprimirMatriz(N, a); //Imprime la matriz A
  imprimirMatriz(N, b); //Imprime la matriz B
  
  
   // Medición de tiempo para la multiplicación
  start = clock();   //Inicia el contador
  multiplicarMatriz(N,a,b,c); //Multiplica las matrices A y B y asigna el resultado a la matriz C
  end = clock();     //Termina el contador
  
  printf("-----------------------------RESULTADO-----------------------------\n");
  imprimirMatriz(N,c); //Imprime la matriz resultante C
  
  
  tiempoEjecucion = (double)(end - start) / CLOCKS_PER_SEC; //Calcula el tiempo en segundos
  printf("\nTiempo de ejecución: %f segundos\n", tiempoEjecucion);   //Imprime el tiempo de ejecución
  

  return 0;
}
