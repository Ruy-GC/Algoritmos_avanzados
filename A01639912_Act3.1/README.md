# Actividad 3.1 Implementación de Tries

Se implementó la estructura de datos "Trie", la cual es una estructura como un arbol para la busqueda de llaves e identifiación de texto con una complejidad igual a la longitud del string que se va a buscar. Se implementaron las funcionalidades de inserción y busqueda además de mostar el recorrido completo del Trie utilizando DFS.

## Complejidad de tiempo

- **Inserción:** O(n) n siendo la longitud de la palabra a insertar
- **Busqueda:** O(n)
- **DFS:** O(v) siendo v la cantidad de vertices del trie

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

1- Se insertan palabras con caracteres dentro de las 26 letras del alfabeto inglés y se busca con los mismos criterios.

**Entrada**
- N = 2
- palabras = ["hola","computadora"]
- M = 2
- busqueda = ["hola","compu"]

**Salida**
```bash
-----------------------------------
2
1: hola
2: computadora
-----------------------------------
2
1: hola
2: compu

Recorrido DFS----------------------
->h->o->l->a->c->o->m->p->u->t->a->d->o->r->a->
-----------------------------------
hola: True
compu: False
-----------------------------------
```

2- No se insertan palabras en el trie y se intenta una busqueda

**Entrada**
- N = 0
- palabras = []
- M = 2
- busqueda = ["hola","compu"]

**Salida**
```bash
-----------------------------------
0
-----------------------------------
2
1: hola
2: compu

Recorrido DFS----------------------
->
-----------------------------------
hola: False
compu: False
-----------------------------------
```

3- Se insertan datos en el Trie pero no se realizan busquedas
**Entrada**
- N = 2
- palabras = ["hola","computadora"]
- M = 0
- busqueda = []

**Salida**
```bash
-----------------------------------
2
1: hola
2: computadora
-----------------------------------
0

Recorrido DFS----------------------
->h->o->l->a->c->o->m->p->u->t->a->d->o->r->a->
-----------------------------------
-----------------------------------
```

4- Se insertan caracteres que no están en las 26 letras del alfabeto inglés
**Entrada**
- N = 2
- palabras = ["niño","hola"]
- M = 2
- busqueda = ["niño","hola"]

**Salida**
```bash
-----------------------------------
2
1: niño
2: hola
-----------------------------------
2
1: niño
2: hora

Recorrido DFS----------------------
->n->i->h->o->l->a->
-----------------------------------
niño: True
hora: False
-----------------------------------
```