# Actividad 3.2 Implementación de "Dijkstra and Floyd"

Se implementaron los algoriitmos de Dijkstra y Floyd en un grafo ponderado dirigido con el fin de obtener la distancia más corta entre los nodos del grafo.

## Complejidad de tiempo

- **Dijkstra:** O(E log V) E siendo las aristas y V los vertices
- **Floyd:** O(n^3)

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

**Entrada**
- n = 4 
- matriz = {{0 2 -1 3},
{-1 0 1 5},
{2 3 0 -1},
{3 -1 4 0}}


**Salida**
```bash
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0

Dijkstra :
node 0 to node 0: 0
node 0 to node 1: 2
node 0 to node 2: 3
node 0 to node 3: 3
node 1 to node 0: 3
node 1 to node 1: 0
node 1 to node 2: 1
node 1 to node 3: 5
node 2 to node 0: 2
node 2 to node 1: 3
node 2 to node 2: 0
node 2 to node 3: 5
node 3 to node 0: 3
node 3 to node 1: 5
node 3 to node 2: 4
node 3 to node 3: 0

Floyd:
0 2 3 3
3 0 1 5
2 3 0 5
3 5 4 0
```

**Entrada**
- n = 4 
- matriz = {{0 5 -1 10},
{-1 0 3 -1},
{-1 -1 0 1 },
{-1 -1 -1 0}}

**Salida**
```bash
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Dijkstra :
node 0 to node 0: 0
node 0 to node 1: 5
node 0 to node 2: 8
node 0 to node 3: 9
node 1 to node 0: INF
node 1 to node 1: 0
node 1 to node 2: 3
node 1 to node 3: 4
node 2 to node 0: INF
node 2 to node 1: INF
node 2 to node 2: 0
node 2 to node 3: 1
node 3 to node 0: INF
node 3 to node 1: INF
node 3 to node 2: INF
node 3 to node 3: 0

Floyd:
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0
```