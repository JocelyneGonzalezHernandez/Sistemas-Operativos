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
  -El proceso hijo siempre tendrá un id = 0
  -Con lo cual siempre podremos identificar el proceso hijo, y a su vez enviarle un proceso diferente
  **SE PUEDE COMUNICAR ENTRE PROCESOS CON LA FUNCIÓN PIPE().
    *Crea una tubería, que envia datos, etc., de forma unidireccional entre el padre y el proceso Hijo
*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //Incluye funciones relacionadas con procesos de Unix
#include <sys/types.h> //Para el tipo de dato pid_t

int main(){
  pid_t proceso;
  int id, aux;
  printf("\n\n\tPROGRAMA PRINCIPAL\n");
  printf("\n\tCreación de PIPES entre procesos\n");


  int tuberia[2]; //Se crean un  arreglo para identificar el INICIO Y EL FIN DEL PIPE
  char string[]="Hola, te envio este mensaje: PROFESIONAL EN FORMACIÓN"; //Se crea el mensaje a enviar
  char lectorMensaje[80];//Se crea un bus de memmoria para el envío

  pipe(tuberia);  //Se crea el PIPE 
  proceso = fork();
  
  if (proceso > 0)
  { 
    //El padre recibe el mensaje
    printf("\n\nSección del PADRE\n");
    close(tuberia[1]); //Se cierra el extremo de lectura (lado salida)
    aux = read(tuberia[0], lectorMensaje,sizeof(lectorMensaje));//Se lee el mensaje
    printf("MENSAJE RECIBIDO: %s\n", lectorMensaje);

  } 
  else if (proceso  == 0)
  {
    //El hijo envía el mensaje
    printf("\n\nSección del HIJO\n");
    close(tuberia[0]); //Se cierra el lado de lectura (lado entrada)
    write(tuberia[1], string, (strlen(string)+1)); //Se envía el mensaje
    printf("MENSAJE ENVIADO\n");
    exit(0); //Finalizo este proceso
  }
  else 
  {
    printf("\n\nError al crear el FORK\n");
  }
  
  printf("\nFIN DEL PROGRAMA\n");

  return 0;
}
