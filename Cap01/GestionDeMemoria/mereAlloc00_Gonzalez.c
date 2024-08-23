/*****************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha: 23/08/2024
Materia:Sistemas Operativos
Tema: Gestión de memoria
Tópico: Redimensión de memoria con la función realloc().

*Utilizado para cambiar el tamaño de un bloque de memoria previamente asignado.
*La función puede mover el bloque de memoria a una nueva ubicación (cuya dirección es devuelta por la función).
*El contenido del bloque de memoria se conserva hasta el menor de los tamaños nuevo y antiguo, incluso si el bloque *se mueve a una nueva ubicación. Si el nuevo tamaño es mayor, el valor de la porción recién asignada es indeterminado.
*En caso de que ptr sea un puntero nulo, la función se comporta como malloc, asignando un nuevo bloque de tamaño bytes y devolviendo un puntero a su inicio.
*****************************************************************/
