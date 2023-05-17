#ifndef grafo_matriz_h
#define grafo_matriz_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo
{
    int ordem, *vertices, **adjacencias, eh_direcionado, eh_valorado;
} Grafo;



#endif