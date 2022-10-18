# Actividad 3.3 Implementación de "Knapsack problem"
Implementación que resuelve el problema de la mochila obteniendo la ganacia máxima posible basandonos en la capacidad de la mochila para cargar peso, los valores de ganacia y los pesos de los elementos a insertar.

## Complejidad de tiempo

**O(N*W):** Siendo N la cantidad de elementos presentes en el problemas y W la capacidad de la mochila.

Esto se debe a que la implementación utilizada emplea la programación dinámica utilizando una matriz de dimensiones N*W que utiliza los valores previos para determinar si incluir el elemento o cambiar algubo que ya se ha incluido.

## Ejecutar el programa
Entrada estandar:
```
$ g++ main.cpp -o main
$ ./main
```

Redireccionamiento de entrada:
```
$ g++ main.cpp -o main
$ ./main < ./test/test_1.txt
```

## Casos de prueba 

1-
**Entrada**
- N = 3
- valores = {1,2,3}
- pesos = {4,5,1}
- W = 4

**Salida**
```bash
Cantidad de elementos: 3
Valores:
1
2
3
Pesos:
4
5
1
Capacidad: 4
Ganacia Máxima:3
```
2-
**Entrada**
- N = 5
- valores = {2,2,4,5,3}
- pesos = {3,1,3,4,2}
- W = 7

**Salida**
```bash
Cantidad de elementos: 5
Valores:
2
2
4
5
3
Pesos:
3
1
3
4
2
Capacidad: 7
Ganacia Máxima:10
```

3-
**Entrada**
- N = 3
- valores = {6,10,12}
- pesos = {1,2,3}
- W = 5

**Salida**
```bash
Cantidad de elementos: 3
Valores:
6
10
12
Pesos:
1
2
3
Capacidad: 5
Ganacia Máxima:22
```

4-
**Entrada**
- N = 4
- valores = {5,6,2,3}
- pesos = {4,6,7,8}
- W = 2

**Salida**
```bash
Cantidad de elementos: 4
Valores:
5
6
2
3
Pesos:
4
6
7
8
Capacidad: 2
Ganacia Máxima:0
```