# Evaluación de Rendimiento
 Rendimiento
Se refiere a la eficiencia con la que un sistema de cómputo realiza una tarea, en este caso, la multiplicación de matrices.
En un sistema de cómputo, el rendimiento puede evaluarse con métricas como el tiempo de ejecución, el uso de recursos (CPU, memoria), y la escalabilidad (cómo responde el sistema al aumentar el tamaño de la tarea o el número de hilos).

La programación en paralelo, la cual se basa en ejecutar procesos simultáneamente mientras se comparte el mismo hardware, esto se realiza mediante el uso de hilos, cada hilo es un proceso distinto para el sistema operativo, pero siendo un subproceso del proceso original, esto hace que un proceso grande y pesado se pueda repartir en varios subprocesos más ligeros, de esta manera esperando que el tiempo de respuesta sea menor al original. En esta investigación mostrará un claro ejemplo de programación paralela, realizando la multiplicación de varias matrices cuadradas y variando el número de hilos involucrados en el proceso, comparando el tiempo promedio (por la ley de los grandes números) en cada uno de estos casos, repitiendo esto en distintas máquinas para una mejor comparación. 
