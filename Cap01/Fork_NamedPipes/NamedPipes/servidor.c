/****************************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 24/09/2024
Materia: Sistemas Operativos
Tema: Named Pipes o FIFO o Tuberia nombrada
Tópico: Comuniación unidireccional
Descripción:
   *Named Pipes:
      -Permiten la comunicación entre dos procesos no relacionados que pueden encontrarse en distintos ordenadores dentro de la misma red.
      -Deben tener un lector y un escritor.
      -Canalización unidireccional o dúplex con nombre para la comunicación entre el servidor de canalización 
      y uno o varios clientes de canalización.
      -Todas las instancias de una named pipe comparten el mismo nombre

   *Comunicación unidireccional:
      -Permite que un proceso (CLIENTE) envíe datos a otro, 
      de manera que el proceso destino (SERVIDOR) sólo puede recibir esos datos.

                                                         SERVIDOR                                                      ****************************************************************************************************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"

int main() {
   int ArchivoDesc;          // Variable para almacenar el descriptor de archivo del FIFO
   char BusMensaje[80];      // Buffer para almacenar el mensaje recibido
   char final[10];          // Buffer para almacenar la señal de fin
   int fin;                 // Variable para indicar el resultado de la comparación con la señal de fin
   int cantidadBytes;       // Variable para almacenar la cantidad de bytes leídos del FIFO
   
   printf("\n \t\t >>>>>>>>>>>>>INICIO SERVIDOR<<<<<<<<<<<<<<<< \n");
       
   /*Crear el FIFO si no existe*/
   mknod(FIFO_FILE, S_IFIFO|0640, 0); // Crear el FIFO con permisos 0640 (rw-r-----)
   strcpy(final, "fin");
      
   while(1) {  // Bucle infinito para recibir mensajes
      ArchivoDesc = open(FIFO_FILE, O_RDONLY);  // Abrir el FIFO en modo lectura
      cantidadBytes = read(ArchivoDesc, BusMensaje, sizeof(BusMensaje));  // Leer datos del FIFO y almacenarlos en BusMesaje
      BusMensaje[cantidadBytes] = '\0';  // Añadir un terminador nulo al final de la cadena     
      printf("Cadena recibida: \"%s\" y la longitud es %d\n", BusMensaje, (int)strlen (BusMensaje));
      fin = strcmp(BusMensaje, final);
      
      if (fin == 0) { // Si la cadena recibida es "fin"
         close(ArchivoDesc); // Cerrar el descriptor de archivo del FIFO
         break;  //Salir del bucle
      }
   }
   return 0;
}