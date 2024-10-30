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

                                                         SERVIDOR - CLIENTE                                                      
****************************************************************************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Define la ruta del archivo FIFO
#define FIFO_FILE "/tmp/fifo_twoway"

void invertir_cadena(char *); // Prototipo de la función que invierte una cadena

int main() {
    int fd; // Descriptor de archivo para el FIFO
    char buffer_lectura[80]; // Buffer para almacenar la cadena leída del FIFO
    char fin[10]; // Cadena que representa "fin"
    int fin_proceso; // Indicador para saber si se ha recibido la cadena "fin"
    int bytes_leidos; // Número de bytes leídos del FIFO

    mkfifo(FIFO_FILE, S_IFIFO | 0640); // Crear el FIFO con permisos específicos si no existe
    strcpy(fin, "fin"); // Copia la cadena "fin" en la variable fin

    fd = open(FIFO_FILE, O_RDWR); // Abre el FIFO en modo lectura/escritura

    // Bucle infinito para recibir y procesar mensajes
    while (1) {
        bytes_leidos = read(fd, buffer_lectura, sizeof(buffer_lectura)); // Lee datos del FIFO y almacena el número de bytes leídos
        buffer_lectura[bytes_leidos] = '\0'; // Añade un terminador nulo al final de la cadena leída
        printf("FIFOSERVIDOR: Cadena recibida: \"%s\" y la longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));// Imprime la cadena recibida y su longitud

       fin_proceso = strcmp(buffer_lectura, fin); // Compara la cadena recibida con la cadena "fin"

        // Si la cadena recibida es "fin", cierra el FIFO y sale del bucle
        if (fin_proceso == 0) {
            close(fd); // Cierra el descriptor del archivo
            break; // Sale del bucle
        }

       invertir_cadena(buffer_lectura);// Invierte la cadena recibida
        printf("FIFOSERVIDOR: Cadena invertida enviada: \"%s\" y la longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura)); // Imprime la cadena invertida y su longitud
        write(fd, buffer_lectura, strlen(buffer_lectura)); // Envía la cadena invertida de vuelta al FIFO
        sleep(2);// Duerme durante 2 segundos para dar tiempo al cliente a leer el mensaje
    }
    return 0;
}

// Función que invierte una cadena
void invertir_cadena(char *str) {
    int ultimo, limite, primero; // Variables de índice
    char temp; // Variable temporal para intercambiar caracteres

    // Calcula los índices del primer y último carácter
    ultimo = strlen(str) - 1;
    limite = ultimo / 2; // Límite hasta la mitad de la cadena
    primero = 0;

    // Intercambia los caracteres hasta llegar a la mitad de la cadena
    while (primero < ultimo) {
        temp = str[primero];
        str[primero] = str[ultimo];
        str[ultimo] = temp;
        primero++;
        ultimo--;
    }
    return;
}
