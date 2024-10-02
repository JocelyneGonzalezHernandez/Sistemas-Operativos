/*******************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:01/10/2024
Materia: Sistemas Operativos
Tema:Introducción a procesos con Fork
Descripción:
*Fork: 
  -Al ser invocado crea un proceso "hijo" y uno "padre".
  -Cada uno de estos al ser invocados tienen diferentes espacios de memoria (2 procesos diferentes).
  -Son idénticos hasta que el programador determine lo contrario.
  -El proceso hijo siempre tendrá un id = 0.
  -Con lo cual siempre podremos identificar el proceso hijo, y a su vez enviarle un proceso diferente.
  -El padre siempre tendrá un proceso hiijo, pero el hijo no siempre se convertirá en proceso padre.
  -Al ser una bifurcación, el número de procesos creados en la iteración será (2^n)
*******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
 
void creacion_fork(int linea){
     pid_t proceso;
     proceso = fork();  //Crea un nuevo proceso. fork() retorna el ID del proceso
     if(proceso<0){  //fork() falló. Este bloque se ejecuta si id es negativo.
         printf("Error creación proceso\n");
         exit(1);
     } else if (proceso==0)  // Código ejecutado por el proceso hijo
         printf("%d: Proceso =HIJO=: %d\n",linea, getpid());   //"linea" se utiliza para identificar el número de iteración del bucle 
     else          // Código ejecutado por el proceso padre
         printf("%d: Proceso =PADRE= %d\n",linea, getpid());
}
  
int main(int argc, char *argv[]){
      int p = (int) atoi(argv[1]);  //Convierte el argumento a entero
      for(int i=0; i<p; i++)
          creacion_fork(i);  // Crea un proceso por cada iteración
  
  
      printf("\n---\n\n");
      return 0;
}