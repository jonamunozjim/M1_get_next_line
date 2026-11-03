*Este proyecto ha sido creado como parte del currículo de 42 por jmunoz-j.*

<div align="right">
  <strong>Languages:</strong>
  <a href="README.md">English</a> ｜ 
  <a href="README_es.md">Español</a>
</div>

# Get Next Line

## Descripción

El objetivo de este proyecto es programar la función `get_next_line`, que lee de un descriptor de archivo y devuelve una sola línea cada vez que se llama, terminando con su correspondiente carácter de salto de línea (`\n`). Si se llama dentro de un bucle, permite leer un archivo entero línea por línea de manera eficiente, gestionando la memoria estrictamente sin dejar fugas (leaks).

## Explicación y justificación del algoritmo

Para poder leer el texto en bloques (definidos por `BUFFER_SIZE`) y no perder los caracteres restantes después de un salto de línea, el núcleo del algoritmo se basa en el uso de una **variable estática** (`static char *stor`). Esta variable "recuerda" el texto sobrante entre una llamada a la función y la siguiente.

En la parte *Bonus*, esta variable se transforma en un array de punteros (`static char *stor[1024]`), usando el propio `fd` como índice para permitir leer de múltiples archivos simultáneamente sin que sus textos se mezclen.

El algoritmo se divide lógicamente en tres pasos o funciones principales:

1. **Lectura y acumulación (`get_line`):**
   Leemos del archivo usando `read()` en fragmentos de `BUFFER_SIZE`. Los datos leídos se concatenan a nuestra variable estática `stor` usando `ft_strjoin`. Este proceso se repite en un bucle hasta que se detecta un carácter de salto de línea (`\n`) en el texto acumulado o hasta que `read` devuelve 0 (Fin de Archivo). Se ha implementado una protección especial para liberar la memoria correctamente si `read` devuelve `-1` (error de lectura).

2. **Extracción de la línea (`extract_line`):**
   Una vez que tenemos el texto necesario en `stor`, iteramos a través de la string hasta que encontramos el primer `\n` (o el final de la string `\0`). Asignamos la memoria exacta requerida para esa línea (incluyendo el `\n`) usando `ft_substr` y la devolvemos.

3. **Limpieza del resto (`clean_line`):**
   Todo el texto que queda a la derecha del `\n` en nuestra variable estática pertenece a líneas futuras. Calculamos la longitud exacta de este resto y lo extraemos en una nueva variable (de nuevo, usando `ft_substr`). Liberamos la memoria del antiguo `stor` para evitar fugas y lo actualizamos con este nuevo resto. Si no queda texto sobrante, la variable estática se establece de forma segura a `NULL`.

## Instrucciones de compilación y ejecución

Para compilar el proyecto dentro de tus propios programas, debes incluir los archivos fuente y definir el tamaño del búfer de lectura usando la flag `-D BUFFER_SIZE=n`.

**Ejemplo de compilación (tamaño de búfer 42):**

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

**Para probar la versión Bonus (múltiples FDs):**

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

*Nota: Es posible compilar sin declarar explícitamente el `BUFFER_SIZE`, ya que el archivo de cabecera `.h` incluye una guarda de seguridad que asigna un valor por defecto.*

## Recursos y uso de IA

**Recursos de aprendizaje:**

* [Variables Estáticas en C](https://es.wikipedia.org/wiki/Variable_est%C3%A1tica) - Concepto fundamental para retener el estado de la memoria.

* [Descriptores de Archivo (File Descriptors)](https://es.wikipedia.org/wiki/Descriptor_de_archivo) - Comprender cómo el SO maneja los archivos abiertos.

* Páginas del Manual de Linux (`man read`, `man malloc`, `man free`).

**Uso de Inteligencia Artificial:**
Durante el desarrollo de este proyecto, la IA se utilizó bajo un enfoque estrictamente pedagógico para consolidar conocimientos. No se utilizó para generar código fuente directo, sino más bien como un tutor de apoyo para:

* Entender e interpretar los mensajes de error de los testers (ej. errores de compilación).

* Rastrear visualmente el flujo de memoria para prevenir punteros colgantes (dangling pointers) y resolver fugas de memoria en casos extremos como errores de lectura.