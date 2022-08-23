# Actividad 1.1 Implementación de la técnica de programación "divide y vencerás"

Se implementó el algoritmo Merge Sort para ordenamiento de una lista de n números reales (double) de mayor a menor. Estos datos se reciben medinate la entrada estandar utilizando redireccionaminto de entrada de un ambiente linux.

## Complejidad

La complejidad del algoritmo es **O(n log n)** que a su vez también lo es en el peor escenario.

## Ejecutar el programa
Entrada estandar:
```
$ g++ main.cpp -o main
$ ./main
```

Redireccionamiento de entrada:
```
$ g++ main.cpp -o main
$ ./main < ./test/test.txt
```

## Casos de prueba

1- Caso de prueba donde los elementos están en orden completamente inverso. Representa el peor escenario para este algoritmo.

**Entrada**
- n = 7 
- [1.5,2.05,2.1,2.2,3.5,4.3,5.6]

**Salida**
```bash
Original --------------------------

[1.5,2.05,2.1,2.2,3.5,4.3,5.6]

Resultado --------------------------

[5.6,4.3,3.5,2.2,2.1,2.05,1.5]

**Salida**

------------------------------------
```

2- Caso de prueba donde la lista solo tiene un elemento, en este caso no es necesario comenzar a dividir por lo que retorna la misma lista.

**Entrada**

- n = 1
- [5.5] 

**Salida**

```bash
Original --------------------------

[5.5]

Resultado --------------------------

[5.5]

------------------------------------
```

3- Caso de prueba donde se ingresa una lista vacía al algoritmo. Al no tener datos que ordenar el algoritmo debereá retornar la misma lista vacía.

**Entrada**
- n = 0
- []

**Salida**

```bash
Original --------------------------

[]

Resultado --------------------------

[]

------------------------------------
```

4- Caso de prueba estandar donde existen mutliples números en orden aleatorio. El uso promedio, mostrará la entrada en orden de mayor a menor considerando negativos y números duplicados.

**Entrada**
- n = 9
- [2.4,5.9,6.5,-1.36,5.9,2.8,7.1,10,-13.4] 

**Salida**
```bash
Original --------------------------

[2.4,5.9,6.5,-1.36,5.9,2.8,7.1,10,-13.4]

Resultado --------------------------

[10,7.1,6.5,5.9,5.9,2.8,2.4,-1.36,-13.4]

------------------------------------
```

4- Caso de prueba estandar donde la entrada ya está ordenada de la forma deseada. Se verifica el uso correcto del algoritmo si retorna la misma entrada.

**Entrada**
- n = 5
- [5.4,4.9,3.2,2.7,1.26] 

**Salida**
```bash
Original --------------------------

[5.4,4.9,3.2,2.7,1.26]

Resultado --------------------------

[5.4,4.9,3.2,2.7,1.26]

------------------------------------
```

6- Caso de prueba donde se indica un tamaño de arreglo menor a 0. Este caso suelta un mensaje y termina el programa.

**Entrada**
- n = -1

```
No se puede generar una lista de menos que 0 elementos
```