#include "grafo_matriz.h"

int main()
{
    Grafo *g = cria_grafo(5, 0, 0);

    preenche_vertices(g);
    preenche_arestas(g);

    mostra_grafo(g);

    percurso_largura(g);

    printf ("\n");

    printf ("\n\n%d", busca_profundidade(2, 0, g));
}