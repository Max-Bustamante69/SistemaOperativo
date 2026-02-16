# Historial de Cambios (Changelog)

El objetivo de este archivo es llevar un registro cronologico de las versiones, nuevas funcionalidades y correcciones de errores del sistema operativo.

## [v1.1.0] - 2026-02-16

### Agregado

- **Comando avanzado `crear <archivo>`** (Maximiliano): crea archivos vacios sin sobrescribir.
- **Comando avanzado `limpiar`** (Valeria): limpia la pantalla usando secuencias ANSI (sin `system()`).
- **Documentacion de desarrollo** en `docs/DEVELOPMENT.md`.
- Actualizacion de `README.md` para describir comandos avanzados y equipo.
- `CONTRIBUTORS.md` con tabla de contribucion del equipo.

## [v1.0.0] - 2026-02-04

### Agregado

- **Shell Interactiva**: Bucle REPL funcional.
- **Comandos basicos**: `listar`, `leer`, `tiempo`, `calc`, `ayuda`, `salir`.
- **Arquitectura modular**: Separacion en `core`, `commands`, `utils`.
- **Sistema de documentacion**: Soporte para Doxygen.

### Cambios

- Migracion de `main.c` monolitico a estructura modular.

