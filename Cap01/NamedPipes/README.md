# Named Pipes

Named Pipes es un mecanismo de comunicación inter-procesos (IPC) que permite a los procesos intercambiar datos de manera eficiente en un sistema operativo. A diferencia de los pipes anónimos, los named pipes tienen un nombre asociado, lo que permite que los procesos se conecten a ellos independientemente de su relación de parentesco. Este enfoque facilita la comunicación entre procesos que pueden no estar relacionados o que se ejecutan en diferentes momentos.

## Características

- **Comunicación bidireccional:** Permite la comunicación en ambas direcciones entre el cliente y el servidor.
- **Acceso concurrente:** Varios procesos pueden acceder a un named pipe al mismo tiempo, facilitando la sincronización.
- **Portabilidad:** Los named pipes son compatibles con múltiples plataformas y sistemas operativos.
- **Los named pipes son efectivos para la comunicación entre procesos, facilitando el intercambio de mensajes en aplicaciones concurrentes**

## Uso
- **Crear un Named Pipe:** Para crear un named pipe, puedes usar la función `mknod` en sistemas Unix/Linux.
  -  Ejemplo `mknod(FIFO_FILE, S_IFIFO | 0640, 0)`
    -  `FIFO_FILE`: Este es el nombre del archivo FIFO que se va a crear.
    -  `S_IFIFO | 0640`: Este argumento especifica el modo de creación del archivo. Se compone de dos partes:
        - **S_IFIFO**: Este macro indica que el archivo que se va a crear es un FIFO (First In, First Out), que es un tipo de archivo especial que permite la comunicación entre procesos.
        - **0640**: Este es un modo de permisos en formato octal. Define quién puede leer y escribir en el FIFO:
          - 0: No hay permisos para el propietario.
          - 6: Permiso de lectura y escritura para el propietario (4+2).
          - 4: Permiso de lectura para el grupo.
          - 0: Sin permisos para otros usuarios.
        - **0**:Especificar el valor de dispositivo, que no se utiliza en el caso de los FIFOs.
  
- **Apertura del FIFO**: Los procesos pueden abrir el named pipe en modo lectura o escritura.
  - Para lectura: `open(FIFO_FILE, O_RDONLY)`
  - Para escritura: `open(FIFO_FILE, O_WRONLY)`

- **Lectura y escritura**:
  - Leer del pipe: `read(ArchivoDesc, BusMensaje, sizeof(BusMensaje))`
  - Escribir en el pipe: `write(ArchivoDesc, BusMensaje, strlen(BusMensaje))`
  
- **Cierre del FIFO**: Siempre cerrar el descriptor después de usarlo.
  - Ejemplo: `close(ArchivoDesc)`

