1. Compilar el archivo fuente .c que necesite y llamar al ejecutable MM_ejecutable
   `gcc archivo.c -o MM_ejecutable`
2. Asegurarse de que el archivo lanza.pl es ejecutable
3. De ser así, ejecutarlo de la siguiente manera  perl `.\lanza.pl`
4. Si la ejecución fue exitosa, se debió crear una carpeta llamada DatosEjeción y se mostrará en pantalla el tamaño de la matriz que se está multiplicando y el número de hilos.

   
El archivo lanza.pl ha sido adaptado para ejecutarse en Windows PowerShell. Si está trabajando en un sistema Linux, utilice la siguiente versión de lanza.pl:

# Ruta y nombre del ejecutable
$Path = `pwd`;
chomp($Path);
$Nombre_Ejecutable = "MM_ejecutable";

# Crear la carpeta DatosEjecucion si no existe
mkdir "$Path/DatosEjecucion" unless -d "$Path/DatosEjecucion";

# Configuración de la batería de experimentos
@Tamanos_Matriz = (2600, 2800, 3000, 3200, 3400, 3600, 3800, 4000);
@Num_Hilos = (1, 2, 4, 8);
$Repeticiones = 30;

# Ejecuta la batería de experimentos
foreach $size (@Tamanos_Matriz) {
    foreach $hilo (@Num_Hilos) {
        # Define el archivo de salida en la carpeta DatosEjecucion
        $file = "$Path/DatosEjecucion/${Nombre_Ejecutable}-${size}-Hilos-${hilo}.dat";
        
        for ($i = 0; $i < $Repeticiones; $i++) {
            # Ejecuta el programa y guarda la salida en el archivo correspondiente
            system("$Path/$Nombre_Ejecutable $size $hilo >> \"$file\"");
            print "$Path/$Nombre_Ejecutable $size $hilo \n";  # Muestra la ejecución actual en la terminal
        }
    }
}



