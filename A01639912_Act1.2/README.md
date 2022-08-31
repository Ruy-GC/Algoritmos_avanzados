# Actividad 1.2 Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"

Se utilizaron las tecnicas de "programación dinámica" y de "algoritmos avaros" para resolver el problema de cambio de monedas. El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea) que representan las diferentes denominaciones disponibles de las monedas. Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto. La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación, de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, primero utilizando programación dinámica, y luego utilizando un algoritmo avaro. 
## Complejidad

La complejidad de tiempo de ambos algoritmos es  de **O(n)** debido a que en ambos casos se realizan operaciones de manera lineal hasta que se llega a una solución.
- Avaro: se realizan operaciones matemáticas segun la cantidad de opciones de monedas
- Dinámico: Se genera un arreglo de Q-P espacios t se recorre una solam vez realizando las operaciones pertinenetes.

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

1- Se presentan denominaciones que pueden dar mutliples soluciones para devolver el cambio al cliente. En este caso se muestra como el algoritmo avaro soluciona el problema pero no de forma óptima mientras que el basado en programación dinámica si lo hace

**Entrada**
- N = 3
- coins = [10,7,1]
- P = 10
- Q = 25

**Salida**
```bash
Algoritmo Avaro:
-----------------------------------

10
1
1
1
1
1

Modenas utilizadas: 6

-----------------------------------

Programacion Dinamica:
-----------------------------------

7
7
1

Modenas utilizadas: 3

-----------------------------------
```

2- Presentan denominaciones que pueden dar multiples soluciones. Este caso demuestra como el algoritmo avaro al puede no llegar a unba solución adecuada la solo pensar en el corto plazo buscando restar las cantidades más grandes sin preocuparse de la sposibilidades a futuro.

**Entrada**
- N = 4
- coins = [6,5,3,2]
- P = 10
- Q = 20

**Salida**

```bash
Algoritmo Avaro:
-----------------------------------

6
5
3
3
2
2
Modenas utilizadas: 6

-----------------------------------

Programacion Dinamica:
-----------------------------------

5
5

Modenas utilizadas: 2

-----------------------------------
```

3- Se demuestra una situación donde ambos algoritmos logran llegar a una solución óptima. En este caso aunque ambos lograron una solución óptima aquí se puede apreciar los benefgicios de los algoritmos avaros ya que este realiza muchas menos operaciones para llegar al resultado.

**Entrada**
- N = 3
- coins = [5,4,3]
- P = 20
- Q = 33

**Salida**

```bash
Algoritmo Avaro:
-----------------------------------

5
5
3

Modenas utilizadas: 3

-----------------------------------

Programacion Dinamica:
-----------------------------------

5
5
3

Modenas utilizadas: 3

-----------------------------------
```

4- Ninguno de los dos algoritmos puede llegar a una solución con las denominaciones proporcionadas ocasionando que no se genere la lista de monedas utilizadas.

**Entrada**
- N = 4
- coins = [10,6,5,4]
- P = 10
- Q = 13

**Salida**

```bash
Algoritmo Avaro:
-----------------------------------


Modenas utilizadas: 0

-----------------------------------

Programacion Dinamica:
-----------------------------------


Modenas utilizadas: 0

-----------------------------------
```