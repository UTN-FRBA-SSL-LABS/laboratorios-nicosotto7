#include "Conversion.h"

/*
 * Conversion.c — Funciones de conversion entre tipos
 */

/* ── ToInteger — tiene un bug, encontrarlo y corregirlo ─────────────────── */

int ToInteger(const char *s) {
    int signo     = 1;
    int resultado = 0;
    if (*s == '-') { signo = -1; s++; }
    for (; *s != '\0'; s++)
        resultado = resultado * 10 + (*s - '0');
    return signo * resultado;  /* corregido: multiplica signo por resultado */
}