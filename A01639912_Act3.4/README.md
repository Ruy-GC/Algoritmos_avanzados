# Actividad 3.4 Implementación de "Graph coloring"
Implementación del algoritmo de graph coloring para asignar colores a los nodos del grafo sin que se repitan con sus nodos adyacentes. COnsiderando un limitante a la cantidad de colores, impuesto desde el programa, no por el usuario.

## Complejidad de tiempo

**O(V*(V+C))** V siendo vertices y C la cantidad de coilores establecida
Esto se debe a que la implementación utilizada recorre todos los nodos adyacentes para cada nodo además de justo después de recorrer los nodos adyacentes tiene que revisar la lista de colores que fueron utilizados por estos para definir el nuevo color.

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
Estos casos de prueba están considerados con 2 colores máximo

1-
**Entrada**
- N = 4
- matriz = {{0,1,1,1},
{1,0,1,0},
{1,1,0,1},
{1,0,1,0}}

**Salida**
```bash
0 1 1 1 
1 0 1 0 
1 1 0 1
1 0 1 0
No es posible asignar colores a los nodos
```
2-
**Entrada**
- N = 4
- matriz = {{0,1,0,1},
{1,0,1,0},
{0,1,0,1},
{1,0,1,0}}

**Salida**
```bash
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
Node: 0, Assigned Color: 0
Node: 1, Assigned Color: 1
Node: 2, Assigned Color: 0
Node: 3, Assigned Color: 1
```
Estos casos toman 3 colores como máximo

3-
**Entrada**
- N = 5
- matriz = {{0,0,1,0,1},
{0,0,1,1,1},
{1,1,0,1,0},
{0,1,1,0,1},
{1,1,0,1,0}}

**Salida**
```bash
0 0 1 0 1
0 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Node: 0, Assigned Color: 0
Node: 1, Assigned Color: 0
Node: 2, Assigned Color: 1
Node: 3, Assigned Color: 2
Node: 4, Assigned Color: 1
```

4-
**Entrada**
- N = 6
- matriz = {{0,1,0,1,0,0},
{1,0,1,0,0,1},
{0,1,0,1,1,0},
{1,0,1,0,1,1},
{0,0,1,1,0,0}
{0,1,0,1,0,0}}

**Salida**
```bash
0 1 0 1 0 0
1 0 1 0 0 1
0 1 0 1 1 0
1 0 1 0 1 1
0 0 1 1 0 0
0 1 0 1 0 0
Node: 0, Assigned Color: 0
Node: 1, Assigned Color: 1
Node: 2, Assigned Color: 0
Node: 3, Assigned Color: 1
Node: 4, Assigned Color: 2
Node: 5, Assigned Color: 0
```