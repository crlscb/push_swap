*Este proyecto ha sido creado como parte del currículo de 42 por cescobio, damiguel.*

# Push_swap

## Descripción

**Push_swap** es un proyecto cuyo objetivo es ordenar de forma ascendente una lista de números utilizando dos stacks (`a` y `b`) y un conjunto limitado de operaciones.

El objetivo principal es minimizar el número de operaciones necesarias, lo que convierte el problema en un desafío de optimización algorítmica más que de ordenación tradicional.

## Operaciones disponibles

| Operación | Descripción |
|----------|-------------|
| `sa` | Intercambia los dos primeros elementos del stack A |
| `sb` | Intercambia los dos primeros elementos del stack B |
| `ss` | `sa` y `sb` a la vez |
| `pa` | Mueve el primer elemento de B a A |
| `pb` | Mueve el primer elemento de A a B |
| `ra` | Rota A: el primero pasa al final |
| `rb` | Rota B: el primero pasa al final |
| `rr` | `ra` y `rb` a la vez |
| `rra` | Rota A al revés |
| `rrb` | Rota B al revés |
| `rrr` | `rra` y `rrb` a la vez |

La complejidad no es solo ordenarlos, sino hacerlo con el **menor número posible de movimientos**, lo que implica implementar algoritmos de la forma más eficiente posible.

El programa recibe una lista de enteros como argumentos y devuelve la secuencia de operaciones requeridas para dejar el `stack A` completamente ordenado.

## Instrucciones

### Compilación

```
make
```

Esto generará el ejecutable:
```
./push_swap
```
## Ejecución
```
./push_swap 2 1 3 6
```
La salida esperada será la secuencia de operaciones necesarias para dejar el stack A ordenado (ejemplo):
```
ra
pb
rra
pb
pb
pb
pa
pa
pa
pa
```

## Algoritmos y decisiones técnicas

**Estrategia general**:
El proyecto implementa un algoritmo de ordenación distinto dependiendo de:
- El tamaño del input
- El nivel de desorden del stack

El nivel de desorden se calcula analizando cuántos elementos están fuera de su posición ordenada.

### Selección de algoritmo

| Desorden | Algoritmo | Estrategia | Complejidad |
|----------|----------|-----------|------------|
| < 0.2 | `simple_sort` | Selection sort (stacks) | O(n²) |
| < 0.5 | `medium_sort` | División en chunks | O(n√n) |
| ≥ 0.5 | `complex_sort` | Radix Sort (LSD) | O(n log n) |

### Justificación de los algoritmos

#### 🔹 Simple Sort

**Idea:**
Seleccionar el mínimo y moverlo a B repetidamente.

**Cómo funciona:**
- Se busca el mínimo
- Se rota hasta arriba (`ra` / `rra`)
- Se envía a B (`pb`)
- Se reconstruye A (`pa`)

**Ventajas:**
- Muy eficiente en listas casi ordenadas
- Bajo número de operaciones en casos simples

---

#### 🔹 Medium Sort (Chunking)

**Idea:**
Dividir los valores en rangos y procesarlos por bloques.

**Cómo funciona:**
- Se divide el rango en chunks
- Se envían a B los valores dentro del rango
- Se rota A cuando no encajan
- Se reconstruye A desde B

**Ventajas:**
- Reduce el problema en partes manejables
- Mejora el rendimiento en listas medianas

---

#### 🔹 Complex Sort (Radix Sort)

**Idea:**
Ordenar usando la representación binaria de los índices.

**Cómo funciona:**
- Se asigna un índice a cada elemento
- Se recorren los bits (LSB → MSB)
- `0` → `pb` (va a B)
- `1` → `ra` (se queda en A)
- Se reconstruye con `pa`

**Ventajas:**
- Complejidad O(n log n)
- Muy eficiente en listas grandes
- No requiere comparaciones directas

---

### Operaciones binarias utilizadas

Para la implementación de Radix Sort se utilizan operaciones binarias:

- `>>` (shift right): desplaza los bits hacia la derecha
- `& 1`: permite obtener el bit menos significativo

Estas operaciones permiten analizar cada número bit a bit y decidir si debe moverse al stack B o mantenerse en A.

#### Ejemplo

Número: `5` → binario: `101`

- bit 0 → `1` → se queda en A (`ra`)
- bit 1 → `0` → va a B (`pb`)
- bit 2 → `1` → se queda en A (`ra`)

### Decisión técnica clave

Se ha optado por una **estrategia adaptativa**, en lugar de usar un único algoritmo, para:

- Optimizar el número de operaciones
- Adaptarse a diferentes inputs
- Mejorar el rendimiento global del programa

Este enfoque permite obtener mejores resultados que una implementación basada únicamente en el tamaño del input.

## Características

- Selección dinámica de algoritmo según el nivel de desorden
- Implementación de Radix Sort adaptado a stacks
- Optimización de rotaciones para reducir movimientos
- Manejo de diferentes tamaños de input

## Contribuciones

- **cescobio**
  - Parseo y de argumentos
  - Validación de datos (duplicados, formato, orden)
  - Implementación de todas las operaciones (`push`, `swap`, `rotate`, `reverse rotate`)
  - Implementación del sistema de stacks (creación de nodos, inicialización y cálculo de desorden)
  - Implementación de `simple_sort`
  - Implementación de Radix Sort (`complex_sort`)

- **damiguel**
  - Estructuración del proyecto (organización de carpetas)
  - Sistema de flags (`--simple`, `--medium`, `--complex`, `--adaptive`)
  - Modo benchmark (`--bench`) y métricas de rendimiento
  - Implementación de `medium_sort` (chunking)
  - Función `printf` y comprobaciones adicionales
  - Implementación del split para los argumentos

## Recursos

- https://visualgo.net/en/sorting
- https://en.wikipedia.org/wiki/Radix_sort
- https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
- https://www.programiz.com/c-programming/bitwise-operators

Estos recursos han sido especialmente útiles para comprender las operaciones binarias utilizadas en la implementación del algoritmo Radix Sort.