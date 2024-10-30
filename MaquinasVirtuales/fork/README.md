# Fork

## fork()
Es una llamada al sistema que se utiliza para crear un nuevo proceso. Este nuevo proceso se llama proceso hijo, y es una copia casi exacta del proceso que la llamó, conocido como proceso padre.
Ambos procesos pueden ejecutar código de manera concurrente, pero cada uno tiene su propio contexto de ejecución.

### Proceso padre
Después de la llamada a `fork()`, el proceso padre continúa su ejecución.
  - Si `fork()` se ejecuta correctamente, el proceso padre recibe un valor positivo que es el ID del proceso hijo.
  - Si `fork()` falla, el proceso padre recibe -1 y debe manejar el error apropiadamente.

### Proceso hijo
Es el nuevo proceso creado por la llamada a `fork()` en el proceso padre.
El proceso hijo tiene una copia casi exacta del contexto del padre, incluyendo sus variables y espacio de memoria.
  - Puede ejecutar su propio código, permitiendo la realización de tareas independientes del padre.
  - El proceso hijo recibe 0 como valor de retorno de `fork()`, lo que lo identifica como el proceso hijo.
  - Si hay un error en la creación del proceso, este no recibirá un valor de retorno positivo ni negativo, ya que no será creado.

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
