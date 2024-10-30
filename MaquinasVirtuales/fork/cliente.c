/****************************************************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 29/10/2024
Materia: Sistemas Operativos
Tema: Named Pipes o FIFO o Tuberia nombrada
Tópico: Comuniación bidireccional
Descripción:
   *Named Pipes:
      -Permiten la comunicación entre dos procesos no relacionados que pueden encontrarse en distintos ordenadores dentro de la misma red.
      -Deben tener un lector y un escritor.
      -Canalización unidireccional o dúplex con nombre para la comunicación entre el servidor de canalización 
      y uno o varios clientes de canalización.
      -Todas las instancias de una named pipe comparten el mismo nombre

   *Comunicación bidireccional:
      -Permite que un proceso (CLIENTE) envíe datos a otro, 
      de manera que el proceso destino (SERVIDOR) pueda leer y escribar datos en respuesta.

                                                         CLIENTE - SERVIDOR
****************************************************************************************************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//Define la ruta del archivo FIFO (pipe con nombre)
#define FIFO_FILE "/tmp/fifo_twoway"

int main() {
    int fd; // Descriptor de archivo para el FIFO
    int fin_proceso; // Indicador para saber si el usuario ha ingresado "fin"
    int longitud_cadena; // Longitud de la cadena ingresada por el usuario
    int bytes_leidos; // Número de bytes leídos del FIFO
    char buffer_lectura[80]; // Buffer para almacenar la cadena ingresada o recibida
    char fin_str[5]; // Cadena que representa "fin"

    printf("FIFO_CLIENTE: Envíe mensajes infinitamente, para terminar ingrese \"fin\"\n");  // Muestra un mensaje al usuario indicando cómo finalizar el programa

    fd = open(FIFO_FILE, O_CREAT | O_RDWR, 0);  // Abre el FIFO en modo lectura/escritura, y lo crea si no existe

    strcpy(fin_str, "fin");  // Copia la cadena "fin" en la variable fin_str

    // Bucle infinito para enviar mensajes
    while (1) {
        
        printf("Ingrese cadena: ");  // Solicita al usuario que ingrese una cadena
        fgets(buffer_lectura, sizeof(buffer_lectura), stdin);  // Lee la cadena ingresada por el usuario
        longitud_cadena = strlen(buffer_lectura);  // Calcula la longitud de la cadena
        buffer_lectura[longitud_cadena - 1] = '\0';  // Elimina el carácter de salto de línea al final de la cadena

        fin_proceso = strcmp(buffer_lectura, fin_str);  // Compara la cadena ingresada con la cadena "fin"

        // Si la cadena ingresada no es "fin"
        if (fin_proceso != 0) {
            write(fd, buffer_lectura, strlen(buffer_lectura));  // Envía la cadena al FIFO
            printf("FIFO_CLIENTE: Cadena enviada: \"%s\" y la longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura)); // Imprime la cadena enviada y su longitud
            bytes_leidos = read(fd, buffer_lectura, sizeof(buffer_lectura)); // Lee la respuesta del servidor
            buffer_lectura[bytes_leidos] = '\0'; // Añade un terminador nulo al final de la cadena recibida
            printf("FIFO_CLIENTE: Cadena recibida: \"%s\" y la longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));  // Imprime la cadena recibida y su longitud
        } else {
            write(fd, buffer_lectura, strlen(buffer_lectura)); // Si la cadena es "fin", la envía y cierra el descriptor del archivo
            printf("FIFO_CLIENTE: Cadena enviada: \"%s\" y la longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));
            close(fd); // Cierra el FIFO
            break; // Sale del bucle y finaliza el programa
        }
    }
    return 0;
}
