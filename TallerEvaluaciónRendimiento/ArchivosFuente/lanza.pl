#!/usr/bin/perl
#**************************************************************
# Pontificia Universidad Javeriana
# Autor: Jocelyne Gonzalez Hernandez
# Fecha: 08/11/2024
# Materia: Sistemas Operativos
# Tema: Taller de Evaluación de Rendimiento
# Descripción: Script de automatización para ejecutar MM_ejecutable en diversas configuraciones en Windows PowerShell.
#**************************************************************

use Cwd;  # Para usar la función getcwd() en lugar de 'pwd' y obtener la ruta del directorio actual.

# Ruta y nombre del ejecutable
$Path = getcwd();  # Obtiene la ruta del directorio de trabajo actual.
chomp($Path);  # Elimina cualquier salto de línea final en la ruta.
$Nombre_Ejecutable = "MM_ejecutable.exe";  # Nombre del archivo ejecutable que se va a ejecutar en los experimentos.

# Crear la carpeta DatosEjecucion si no existe
unless (-d "$Path/DatosEjecucion") {  # Verifica si el directorio "DatosEjecucion" no existe.
    mkdir "$Path/DatosEjecucion";     # Si no existe, crea el directorio para almacenar los datos de ejecución.
}

# Configuración de la batería de experimentos
@Tamanos_Matriz = (800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200);  # Diferentes tamaños de matriz a probar.
@Num_Hilos = (1, 2, 4, 8);  # Diferentes cantidades de hilos a usar en cada experimento.
$Repeticiones = 30;  # Número de repeticiones por configuración para promediar resultados y reducir variabilidad.

# Ejecuta la batería de experimentos
foreach my $size (@Tamanos_Matriz) {  # Itera sobre cada tamaño de matriz.
    foreach my $hilo (@Num_Hilos) {   # Itera sobre cada cantidad de hilos.
        
        # Define el archivo de salida en la carpeta DatosEjecucion
        my $file = "$Path/DatosEjecucion/${Nombre_Ejecutable}-${size}-Hilos-${hilo}.dat";  # Nombre del archivo de salida para almacenar los resultados específicos de esta combinación de tamaño e hilos.

        for (my $i = 0; $i < $Repeticiones; $i++) {  # Repite el experimento el número de veces especificado.
            
            # Ejecuta el programa y guarda la salida en el archivo correspondiente
            system("\"$Path\\$Nombre_Ejecutable\" $size $hilo >> \"$file\"");  # Llama al ejecutable con los parámetros actuales de tamaño e hilos, y redirige la salida al archivo de datos.
            
            # Muestra la ejecución actual en la terminal
            print "$Path\\$Nombre_Ejecutable $size $hilo \n";  # Imprime el comando ejecutado, indicando el progreso en la terminal.
        }
    }
}
