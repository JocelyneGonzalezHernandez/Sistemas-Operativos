# Compilación Modular
Un programa en C puede consistir en varios ficheros fuentes. Cada uno contendrá un módulo, que incluirá sus propias funciones, variables y tipos de datos.
Algunos de estos componentes serán públicos (utilizables por otros módulos) y otros privados.
Cada módulo puede ser compilado de manera independiente y luego enlazado para formar el programa final.

# Archivo de Encabezado
 Tienen la extensión .h
 Son archivos que contienen declaraciones de funciones, definiciones de estructuras, constantes y macros que se pueden compartir entre diferentes archivos fuente.

 # Archivo de Implementación
 Generalmente tiene la extensión .c
 Es donde se define el código real de las funciones y estructuras declaradas en los archivos de encabezado (.h).
 Este archivo contiene la lógica que ejecuta las funciones y el comportamiento que se espera de las estructuras. 
 
# Makefile
Para simplificar el proceso de compilación, se puede utilizar un archivo Makefile, que define las reglas y comandos necesarios para compilar el programa. En este archivo, se especifica el compilador a utilizar, las opciones de compilación y las dependencias entre los módulos. Con un solo comando, como make, es posible compilar todo el proyecto, generando el ejecutable a partir de los archivos objeto.
