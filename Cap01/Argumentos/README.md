# Argumentos
El lenguaje C permite que se puedan introducir argumentos en línea de comandos, es decir, en el momento de la ejecución del programa. 

La declaración de estos argumentos se hace en la función `main()`, de la siguiente manera: `main( int argc, char *argv[])`.

- El primer argumento se suele llamar argc
  - Es un entero cuyo valor es el número de argumentos pasados al programa, incluyendo como argumento el nombre del propio programa.
- Al segundo argumento se suele llamar argv.
  - Es un vector de punteros a carácter.
  - apunta a cada caracter de la cadena correspondiente.
