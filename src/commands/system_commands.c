/**
 * @file system_commands.c
 * @brief Comandos de utilería del sistema.
 * 
 * Contiene comandos que afectan al sistema o la sesión completa de la shell,
 * como la calculadora y la limpieza de pantalla.
 */

#include <stdio.h>
#include <stdlib.h> // Para atof (ASCII to Float conversion)
#include "commands.h"

/**
 * @brief Comando CALC (Calculadora)
 * 
 * Realiza operaciones aritméticas básicas entre dos números.
 * Sintaxis esperada: calc <num1> <operador> <num2>
 * 
 * @param args Lista de argumentos donde:
 *             args[1]: Primer operando (cadena)
 *             args[2]: Operador (+, -, *, /)
 *             args[3]: Segundo operando (cadena)
 */
void cmd_calc(char **args) {
    // 1. Validación de argumentos. Necesitamos exáctamente 3 partes después del comando.
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL) {
        printf("Uso: calc <num1> <operador> <num2>\nEjemplo: calc 5 + 3\n");
        return;
    }

    // 2. Conversión de tipos (Parsing)
    // atof(): Convierte una cadena numérica a un float (double precision).
    float n1 = atof(args[1]);
    char op = args[2][0]; // Tomamos el primer caracter del argumento operador
    float n2 = atof(args[3]);
    float res = 0;

    // 3. Lógica de selección (Switch)
    switch(op) {
        case '+': 
            res = n1 + n2; 
            break;
        case '-': 
            res = n1 - n2; 
            break;
        case '*': 
        case 'x': // Permitimos 'x' como alias de multiplicación
            res = n1 * n2; 
            break;
        case '/': 
            // Manejo de caso borde: División por cero
            if (n2 == 0) {
                printf("Error: División por cero no permitida.\n");
                return;
            }
            res = n1 / n2; 
            break;
        default:
            printf("Error: Operador '%c' no reconocido. Use +, -, * o /.\n", op);
            return;
    }

    // 4. Salida
    // %.2f formatea el float para mostrar solo 2 decimales.
    printf("Resultado: %.2f\n", res);
}

/**
 * @brief Comando LIMPIAR (clear)
 *
 * Limpia la pantalla de la terminal utilizando secuencias de escape ANSI
 * y posiciona el cursor en la esquina superior izquierda.
 *
 * A diferencia de usar system(\"clear\"), que está penalizado en el reto,
 * este comando utiliza únicamente funcionalidades de la librería estándar
 * y códigos ANSI, lo que lo hace más portable y seguro.
 *
 * @param args Argumentos del comando (ignorados).
 * @author Valeria
 */
void cmd_limpiar(char **args) {
    (void)args; // No se usan argumentos en este comando

    // Secuencias ANSI:
    //  - \033[2J : Limpia toda la pantalla
    //  - \033[H  : Mueve el cursor a la posición (fila 1, columna 1)
    printf("\033[2J\033[H");
    fflush(stdout);
}
