# Gestión de Memoria en C

En C, la gestión de memoria dinámica es fundamental para el manejo de datos cuyo tamaño puede cambiar en tiempo de ejecución. 
Las funciones principales utilizadas para gestionar memoria dinámica son `malloc`, `realloc` y `calloc`.

## malloc()
Es una función que asigna un bloque de memoria dinámica de un tamaño específico en bytes y devuelve un puntero al comienzo del bloque. Se usa cuando necesitas un bloque de memoria de un tamaño específico que puede no ser conocido en tiempo de compilación. La memoria no se inicializa, por lo que puede contener datos residuales.

### void* calloc(size_t num, size_t size);
- num: Número de elementos.
- size: Tamaño en bytes de cada elemento.
- 
## calloc()
Asigna memoria para un número específico de elementos y los inicializa a cero. Es útil cuando se necesita inicializar todos los bytes de la memoria asignada a cero.

### void* realloc(void* ptr, size_t size);
- ptr: Puntero al bloque de memoria previamente asignado.
- size: Nuevo tamaño en bytes.
- 
## realloc()
Cambia el tamaño de un bloque de memoria previamente asignado con malloc o calloc. Puede ampliar o reducir el tamaño del bloque.

Devuelve un puntero al nuevo bloque de memoria, que puede ser en una ubicación diferente. Si realloc no puede cambiar el tamaño, devuelve NULL y el bloque original permanece sin cambios.

### void* realloc(void* ptr, size_t size);
- ptr: Puntero al bloque de memoria previamente asignado.
- size: Nuevo tamaño en bytes.
