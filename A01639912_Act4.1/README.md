# Actividad 4.1 Implementación Intersección y proximidad aplicando geometría computacional.
Implementación de geometría computacional donde se busca determinar de dos segmentos de recta se intersecctan ubicadas en un plano cartesiano. Retorna falso si no hay intersección y veradero si existe una.
## Complejidad de tiempo

**O(n log n)** n representando la cantidad de puntos en los segmentos a & b que se revise su intersección
## Ejecutar el programa
Entrada estandar:
```
$ g++ main.cpp -o main
$ ./main
```

Redireccionamiento de entrada:
```
$ g++ main.cpp -o main
$ ./main < ./test/test1.txt
```

## Casos de prueba 
Estos casos de prueba están considerados con 2 colores máximo

1-
**Entrada**
- N = 8
- 1
5
4
5
2
5
10
1
3
2
10
3
6
4
9
4

**Salida**
```bash
1
0
```
2-
**Entrada**
- N = 8
- 3
2
10
3
2
1
5
4
5
10
1
6
4
9
4
5
**Salida**
```bash
1
1
```

3-
**Entrada**
- N = 12
- 15
2
6
9
10
2
3
7
14
1
5
6
9
4
3
13
11
9
8
4
6
3
4
14

**Salida**
```bash
0
0
0
```

4-
**Entrada**
- N = 12
- 6
3
4
14
15
2
6
1
5
6
13
11
9
14
9
8
4
2
3
9
4
2
3
7

**Salida**
```bash
0
1
1
```