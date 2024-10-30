# POSIX

POSIX (interfaz de sistema operativo portátil para UNIX) es un conjunto de estándares para interfaces y especificaciones que admiten la portabilidad y la compatibilidad entre sistemas similares a UNIX.

El estándar define varias funciones, como el manejo de archivos, la gestión de procesos y llamada al sistema API. POSIX fomenta la compatibilidad multiplataforma y las operaciones en Sistemas Linux.

# HILOS (THREADS)
Un hilo (thread) es la unidad más pequeña de procesamiento que un sistema operativo puede gestionar y ejecutar. A diferencia de los procesos (que son instancias de programas en ejecución), los hilos comparten el mismo espacio de memoria dentro de un proceso, lo que permite que varios hilos puedan acceder y modificar datos comunes rápidamente. Los hilos son útiles para dividir una tarea en subtareas que pueden ejecutarse en paralelo, aprovechando mejor los recursos de un procesador, especialmente en sistemas con múltiples núcleos.

# PTHREADS
pthread es la biblioteca de hilos en C que implementa el estándar POSIX para la programación multihilo. Su nombre proviene de POSIX threads (hilos de POSIX) y es el conjunto de funciones en C más comúnmente utilizado para crear, ejecutar y gestionar hilos en sistemas que cumplen con el estándar POSIX, como Linux y otros sistemas Unix-like.

pthread incluye funciones para:

- Crear y terminar hilos (pthread_create, pthread_exit)
- Sincronizar hilos con mecanismos como mutexes (pthread_mutex_t) y variables de condición (pthread_cond_t), los cuales ayudan a prevenir conflictos de acceso a recursos compartidos.
- Esperar la finalización de un hilo (pthread_join)
