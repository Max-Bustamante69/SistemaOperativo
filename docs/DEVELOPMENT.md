# Documentacion de Desarrollo - Comandos Avanzados

Este documento describe el proceso tecnico seguido para la implementacion de los comandos avanzados de EAFITos, como parte del Reto 1 de Sistemas Operativos.

## Contexto

La version base (v1.0.0) de EAFITos incluye 6 comandos basicos:
`listar`, `leer`, `tiempo`, `calc`, `ayuda` y `salir`.

Para un equipo de 2 personas, el reto exige **8 comandos en total**:
6 basicos + 2 avanzados.

Los dos comandos avanzados seleccionados por el equipo fueron:

1. `crear <archivo>` — Crea un archivo vacio (autor: Maximiliano Bustamante).
2. `limpiar` — Limpia la pantalla de la terminal (autora: Valeria).

---

## Comando: `crear <archivo>` (Maximiliano Bustamante)

### Descripcion

El comando `crear` permite generar un archivo vacio en el directorio de trabajo actual,
de forma similar al comando `touch` de Unix, evitando sobrescribir archivos existentes.

### Pasos de implementacion

1. **Prototipo** en `include/commands.h`:

   ```c
   void cmd_crear(char **args);
   ```

2. **Implementacion** en `src/commands/file_commands.c`:

   - Valida que `args[1]` tenga el nombre del archivo.
   - Verifica si el archivo ya existe con `fopen(nombre, "r")`.
   - Si no existe, lo crea con `fopen(nombre, "w")`.
   - Cierra siempre el archivo con `fclose` para evitar fugas de recursos.

3. **Registro en la tabla de comandos** (`src/core/shell_loop.c`):

   ```c
   char *nombres_comandos[] = { ..., "crear", ... };
   void (*func_comandos[])(char **) = { ..., &cmd_crear, ... };
   ```

4. **Ayuda**: se incluyo en `cmd_ayuda` dentro de `basic_commands.c`
   bajo la seccion de "Comandos avanzados".

### Funciones de C utilizadas

| Funcion   | Libreria   | Uso principal                                 |
|----------|-----------|-----------------------------------------------|
| `fopen`  | `<stdio.h>` | Abrir/crear archivos en distintos modos       |
| `fclose` | `<stdio.h>` | Cerrar archivos y liberar recursos del sistema |
| `printf` | `<stdio.h>` | Mensajes de informacion y error para el usuario |

---

## Comando: `limpiar` (Valeria)

### Descripcion

El comando `limpiar` borra el contenido visible de la terminal y reposiciona
el cursor en la esquina superior izquierda, similar al comando `clear` de Unix.

Una restriccion importante del reto es **no usar `system()`**, por lo que
la implementacion se basa en secuencias de escape ANSI y funciones de la
libreria estandar.

### Pasos de implementacion

1. **Prototipo** en `include/commands.h`:

   ```c
   void cmd_limpiar(char **args);
   ```

2. **Implementacion** en `src/commands/system_commands.c`:

   ```c
   void cmd_limpiar(char **args) {
       (void)args; // No se usan argumentos
       printf("\033[2J\033[H");
       fflush(stdout);
   }
   ```

   Donde:

   - `\033[2J` limpia toda la pantalla.
   - `\033[H` mueve el cursor a la posicion (1,1).

3. **Registro en la tabla de comandos** (`src/core/shell_loop.c`):

   ```c
   char *nombres_comandos[] = { ..., "crear", "limpiar" };
   void (*func_comandos[])(char **) = { ..., &cmd_crear, &cmd_limpiar };
   ```

4. **Ayuda**: se agrego una linea en `cmd_ayuda` indicando:

   ```text
   limpiar: Limpia la pantalla de la terminal.
   ```

### Funciones de C utilizadas

| Funcion   | Libreria   | Uso principal                        |
|----------|-----------|--------------------------------------|
| `printf` | `<stdio.h>` | Enviar secuencias ANSI a la terminal |
| `fflush` | `<stdio.h>` | Forzar el envio inmediato al stdout  |

---

## Patron de extension de comandos

Para agregar un nuevo comando a EAFITos se siguen siempre los mismos pasos:

1. Declarar el prototipo en `include/commands.h`.
2. Implementar la funcion en el modulo adecuado (`basic_commands.c`, `file_commands.c`,
   `system_commands.c`, etc.).
3. Registrar el comando en los arreglos `nombres_comandos[]`
   y `func_comandos[]` en `src/core/shell_loop.c`.
4. Documentar el uso en:
   - `cmd_ayuda` (para que el usuario lo descubra desde la shell).
   - `README.md` y este archivo (`docs/DEVELOPMENT.md`).

Este flujo de trabajo se aplico tanto para `crear` (Maximiliano) como para `limpiar` (Valeria),
garantizando un diseño modular y facil de extender.

