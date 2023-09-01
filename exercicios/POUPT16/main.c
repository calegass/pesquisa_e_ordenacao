#include "arvore_multipla.h"
int compara (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    Nom* tree = cria_nom(1);
    int nro_casos;
    int nro_nos;
    int *pais;
    int i;

    scanf("%d", &nro_casos);
    while (nro_casos > 0)
    {
        scanf("%d", &nro_nos);
        pais = (int*)malloc(sizeof(int)*(nro_casos)-1);
        qsort(pais,nro_nos-1, sizeof(int), compara);
        for (i=2; i<=nro_nos; i++)
            insere(tree, i, pais[i]);


        nro_casos--;
    }
    mostra(tree);

    return 0;
}

