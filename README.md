# EAFITos 🎓

**EAFITos** es un sistema operativo educativo diseñado para aprender los fundamentos de la programacion de sistemas y la operacion interna de una shell utilizando el lenguaje C.

## 🚀 Objetivos

- Entender la **gestion de procesos** y memoria.
- Aprender sobre **hilos (threads)** y concurrencia.
- Explorar el **sistema de archivos** y llamadas al sistema (syscalls).
- Implementar **estructuras de datos basicas** usadas en kernels.

## 👥 Equipo

Consulta `CONTRIBUTORS.md` para ver la tabla de contribuciones:

- Maximiliano Bustamante — comando `crear` y documentacion asociada.
- Valeria — comando `limpiar` y pruebas.

## 🐚 La Shell de EAFITos

El sistema inicia con una interfaz de linea de comandos (Shell) basica que permite interactuar con el sistema.

### ¿Que son los Argumentos (`args`)?

En una shell, cuando escribes un comando, a menudo necesitas enviarle informacion adicional. Esta informacion se divide en "argumentos".

Internamente en C, esto se maneja mediante un arreglo de cadenas (`char **args`):

- `args[0]`: Es siempre el nombre del comando (ej. `calc`).
- `args[1]`, `args[2]`, etc.: Son los parametros que le pasas al comando.

**Ejemplo en el comando `calc 10 + 5`:**

- `args[0]` -> `"calc"`
- `args[1]` -> `"10"`
- `args[2]` -> `"+"`
- `args[3]` -> `"5"`

## Comandos Disponibles

### Comandos basicos

| Comando  | Argumentos       | Descripcion                                    | Ejemplo          |
| :------- | :--------------- | :--------------------------------------------- | :--------------- |
| `listar` | Ninguno          | Muestra los archivos del directorio actual.    | `listar`         |
| `leer`   | `<archivo>`      | Muestra el contenido de un archivo de texto.   | `leer README.md` |
| `tiempo` | Ninguno          | Muestra la fecha y hora actual del sistema.    | `tiempo`         |
| `calc`   | `<n1> <op> <n2>` | Realiza operaciones aritmeticas (+, -, \*, /). | `calc 10 * 2.5`  |
| `ayuda`  | Ninguno          | Muestra la lista de comandos disponibles.      | `ayuda`          |
| `salir`  | Ninguno          | Termina la sesion de EAFITos.                  | `salir`          |

### Comandos avanzados

| Comando   | Argumentos  | Descripcion                                                        | Ejemplo              | Autor    |
|----------|-------------|--------------------------------------------------------------------|----------------------|----------|
| `crear`  | `<archivo>` | Crea un archivo vacio en el directorio actual (sin sobrescribir). | `crear notas.txt`    | Maximiliano |
| `limpiar`| Ninguno     | Limpia la pantalla de la terminal usando secuencias ANSI.         | `limpiar`            | Valeria  |

#### Uso de `crear`

```text
EAFITos> crear notas.txt
Archivo 'notas.txt' creado exitosamente.
```

Si el archivo ya existe:

```text
EAFITos> crear notas.txt
Error: El archivo 'notas.txt' ya existe.
```

#### Uso de `limpiar`

```text
EAFITos> limpiar
```

La terminal se limpia y el prompt vuelve a aparecer en la parte superior.

## 🛠️ Estructura del Proyecto

- `/src`: Codigo fuente del proyecto (`main.c` contiene el punto de entrada).
- `/include`: Headers (`commands.h`, `shell.h`, etc.).
- `/docs`: Documentacion (incluye `DEVELOPMENT.md` con el detalle de comandos avanzados).
- `Makefile`: Script para automatizar la compilacion.

## ⚡ Como compilar y ejecutar

1. **Compilar**:

   ```bash
   make
   ```

2. **Ejecutar**:

   ```bash
   make run
   # O directamente:
   ./build/sistema_os
   ```

## 📚 Documentacion

El proyecto incluye un sistema de autodocumentacion basado en **Doxygen**. Esto permite generar un sitio web tecnico a partir de los comentarios explicativos en el codigo fuente.

### ¿Que es Doxyfile?

El archivo `Doxyfile` contiene la configuracion necesaria para que Doxygen entienda como analizar nuestro codigo (C), donde buscar los archivos y en que formato generar la salida (HTML).

### Como generar la documentacion

Si tienes Doxygen instalado en tu sistema:

1. Asegurate de estar en la raiz del proyecto.
2. Ejecuta el comando:

   ```bash
   doxygen Doxyfile
   ```

3. Esto creara una carpeta `docs/html`. Abre el archivo `docs/html/index.html` en tu navegador para navegar por la documentacion interactiva de funciones y estructuras.

