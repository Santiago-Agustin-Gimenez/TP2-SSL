# TP2 — Escáner de la calculadora

Implementación del escáner léxico para la calculadora definida en el TP.

## Archivos

- `scanner.h` — tokens (enum `Token`) y declaraciones públicas del escáner.
- `scanner.c` — implementación del escáner, dirigida por la tabla de
  transición documentada en `tabla.md`.
- `main.c` — programa de prueba: lee una línea de la entrada estándar,
  se la pasa al escáner y va imprimiendo cada token/lexema reconocido
  hasta el `TOKEN_FDT`.
- `tabla.md` — documentación completa de la tabla de transición: qué es
  cada estado, cada columna, qué tokens se reconocen y qué errores puede
  devolver el escáner.