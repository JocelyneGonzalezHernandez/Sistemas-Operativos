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

****************************************************************************************************************************************/

/****************************************************************************************************************************************
                                                         CLIENTE
****************************************************************************************************************************************/
#include <stdio.h>         // Incluir la biblioteca estándar para entrada/salida
#include <sys/stat.h>     // Incluir la biblioteca para manejar la información del estado de archivos
#include <sys/types.h>    // Incluir definiciones de tipos
#include <fcntl.h>        // Incluir la biblioteca para manejar el control de archivos
#include <unistd.h>       // Incluir la biblioteca para manejar funciones de POSIX (como close, read, write)
#include <string.h>       // Incluir la biblioteca para manejar funciones de manipulación de cadenas

#define FIFO_FILE "MYFIFO"
int main() {
   int ArchivoDesc;          // Variable para almacenar el descriptor de archivo del FIFO
    int fin_proceso;         // Variable para indicar el fin del proceso
    int cadena;              // Variable para almacenar la longitud de la cadena ingresada
    char BusMensaje[80];     // Buffer para almacenar el mensaje a enviar
    char senalFin[5];        // Buffer para almacenar la señal de fin


    printf("\n \t\t >>>>>>>>>>>>>INICIO CLIENTE<<<<<<<<<<<<<<<< \n");
    printf("FIFO_CLIENT: Envía mensajes indefinidamente, para terminar ingresa \"fin\"\n");
    ArchivoDesc = open(FIFO_FILE,O_WRONLY);  // Abrir el FIFO en modo escritura
    strcpy(senalFin, "fin");

   while (1) {  // Bucle infinito para enviar mensajes
        printf("Ingrese mensaje: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin); // Leer la cadena ingresada por el usuario
        cadena = strlen(BusMensaje);  // Obtener la longitud de la cadena ingresada
        BusMensaje[cadena - 1] = '\0';  // Reemplazar el salto de línea al final de la cadena por un terminador nulo
        
        fin_proceso = strcmp(BusMensaje, senalFin);
        printf("FINAL DEL PROCESO %d\n", fin_proceso);  
      
        if (fin_proceso != 0) {  // Si la cadena no es "fin"
              write(ArchivoDesc, BusMensaje, strlen(BusMensaje));  // Escribir el mensaje en el FIFO
              printf("Mensaje enviado: \"%s\" y el tamaño es %d\n\n", BusMensaje, (int)    strlen(BusMensaje));
        } 
        else {  // Si la cadena es "fin"
              write(ArchivoDesc, BusMensaje, strlen(BusMensaje));  // Escribir el mensaje "fin" en el FIFO para indicar el fin del proceso
              printf("Mesaje enviado: \"%s\" y el tamaño es %d\n", BusMensaje, (int)strlen(BusMensaje));
              close(ArchivoDesc); // Cerrar el descriptor de archivo del FIFO
              break;  //Salir del bucle
        }
   }
   return 0;
}
