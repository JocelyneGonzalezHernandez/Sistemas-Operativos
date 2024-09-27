# Pipe 
Las PIPE (tuberías) son un mecanismo para poner en comunicación los procesos padre e hijo.

- Se comporta como un falso fichero en el que ambos pueden leer y escribir.
- Tendremos dos procesos, padre e hijo. Entre ellos se creará una tubería que emplearán para leer y escribir.
Para ello usaremos un array de enteros de dos posiciones. El [0] será de lectura, y el [1] de escritura.
- Es bidireccional pero sólo puede usarse en uno de los dos sentidos.

## Tipos de Pipes

### Pipes anónimos

- **Unnamed Pipes.**
- Son pipes que se crean usando la llamada a sistema pipe().
- Se utilizan para la comunicación entre procesos relacionados, como un proceso padre y un proceso hijo.
- Su uso es generalmente limitado al mismo proceso o a procesos que tienen un vínculo de parentesco.

### Pipes nombrados
- **Named Pipes**
- Se crean usando la llamada a sistema mkfifo()o mknod().
- A diferencia de los pipes anónimos, pueden ser utilizados por procesos que no tienen relación de parentesco, ya que son identificados por un nombre en el sistema de archivos.

