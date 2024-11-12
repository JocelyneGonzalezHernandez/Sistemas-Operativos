# Proyecto Sistema Noticias
 Proyecto : Sistema de Comunicación entre Publicador y Suscriptores
    Fecha    : 11/112024
    Materia  : Sistemas Operativos
    Profesor : John Corredor Franco
    
Descripción:  Este programa implementa un sistema de comunicación mediante tuberías FIFO, 
permitiendo que un publicador envíe noticias a suscriptores interesados en categorías específicas.

Autores:
     - Jocelyne González
     - Laura Garzón
     - Juan Diego Romero
     - Carlos Rojas

## Ejemplo de Ejecución
Sigue estos pasos para ejecutar el sistema completo:

Abre tres terminales.

En la Terminal 1, ejecuta el sistema de comunicación:
$ ./sistema -p pipePSC -s pipeSSC -t 5

En la Terminal 2, ejecuta el suscriptor:
$ ./suscriptor -s pipeSSC

Ingrese las categorías deseadas (por ejemplo, A, C).

En la Terminal 3, ejecuta el publicador:
$ ./publicador -p pipePSC -f noticias.txt -t 2

El suscriptor comenzará a recibir las noticias que coincidan con las categorías seleccionadas. El sistema de comunicación distribuirá las noticias enviadas por el publicador.
* Detener el Sistema
Una vez terminado el envío de noticias a los suscriptores, el sistema de comunicación esperará el tiempo que usted haya indicado a que se publiquen nuevas noticias. Si dicho tiempo de espera es superado, se enviará una notificación al suscriptor y se cerrará la comunicación tanto del SC como del suscriptor y ambos programas finalizarán.

