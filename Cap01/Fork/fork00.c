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
*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Incluye funciones relacionadas con procesos de Unix, como fork()

int main(){
  //La llamada a fork() retorna dos veces: una vez en el proceso padre y otra en el proceso hijo.
  
  fork();   //Se crea el proceso hijo con la misma información
  printf("\n\nHola profesionales en formación\n"); //Este mensaje será mostrado por el proceso padre e hijo

  return 0;
}
