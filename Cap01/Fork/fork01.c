/*******************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:03/09/2024
Materia: Sistemas Operativos
Tema:Introducción a procesos con Fork
Descripción:
*Fork: 
  -Al ser invocado crea un proceso "hijo" y uno "padre".
  -Cada uno de estos al ser invocados tienen diferentes espacios de memoria (2 procesos diferentes).
  -Son idénticos hasta que el programador determine lo contrario.
  -El proceso hijo siempre tendrá un id = 0.
  -Con lo cual siempre podremos identificar el proceso hijo, y a su vez enviarle un proceso diferente.
*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Incluye funciones relacionadas con procesos de Unix
#include <sys/types.h>//Incluye el tipo de dato pid_t utilizado para los IDs de proceso

int main(){
  int id;
  
  printf("\n\nHola profesionales en formación\n"); //Imprime un mensaje inicial antes de crear el proceso hijo
  
  //Se crean los procesos diferentes
  id = fork(); //Retorna el ID del proceso hijo al proceso padre, y 0 al proceso hijo.
  
  if (id > 0)  //Si el proceso es el padre
  {
    printf("\n\nSoy el proceso PADRE ID = %d\n", getpid());//Imprime el ID del proceso padre.
  } 
  else if (id == 0) //Sino, si el proceso es el hijo
  {
    //printf("\n\nSoy el proceso PADRE ID = %d\n", getpid());
    printf("\n\nSoy el proceso HIJO ID = %d\n", getpid()); // Imprime el ID del proceso hijo.
  }
  else  // fork() falló. Este bloque se ejecuta si id es negativo.
  {
    printf("\n\nError al crear el FORK\n");
  }

  return 0;
}
