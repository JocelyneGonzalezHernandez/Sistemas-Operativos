# EVALUACIÓN DEL RENDIMIENTO

Para evaluar el rendimiento de la máquina virtual 10.43.103.148, se ejecutaron dos programas de multiplicación de matrices con tamaños de 1000x1000 y 2000x2000. Las pruebas se realizaron utilizando 1, 2 y 4 hilos, con el objetivo de observar y comparar los tiempos de ejecución de cada algoritmo.

Los resultados se registraron en una hoja de cálculo, donde se calcularon los promedios. Posteriormente, se creó una gráfica de barras para facilitar la comparación visual de los tiempos de ejecución.

![GRÁFICO](Sistemas-Operativos/MaquinasVirtuales/Evaluacion/Archivo/EvaluacionRendimiento.png)

- En ambos métodos de multiplicación de matrices (clásico y transpuesta), a medida que se aumenta el número de hilos de 1 a 4, el tiempo de ejecución disminuye, lo cual es un efecto esperado al distribuir la carga de trabajo en múltiples hilos.
- En matrices de tamaño 1000 x 1000 y 2000 x 2000, el uso de 4 hilos reduce casi a la mitad el tiempo de ejecución en comparación con 1 hilo.
- En promedio, la multiplicación con la matriz transpuesta (MM_TRANSPUESTA) toma menos tiempo que el método clásico (MM_CLASICO) para ambos tamaños de matrices, Esto sugiere que el método de transpuesta podría estar optimizado para mejorar el acceso a la memoria y aprovechar mejor el almacenamiento en caché.
- Al observar los promedios de tiempos para cada configuración de hilos, podemos notar que el uso de 4 hilos en la multiplicación de matrices transpuestas es la configuración más eficiente en términos de tiempo de ejecución.
- A medida que el tamaño de la matriz aumenta de 1000 x 1000 a 2000 x 2000, los tiempos de ejecución aumentan para ambos métodos. 
