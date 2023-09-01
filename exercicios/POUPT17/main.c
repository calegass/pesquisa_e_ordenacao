#include <stdio.h>
#include <stdlib.h>

struct nod
{
    void* info;
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct listad
{
        Nod *ini;
        Nod *fim;
};
typedef struct listad Listad;

typedef struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
    int eh_direcionado;
    int eh_valorado;
    int *visitados;
}Grafo;

int * cria_inteiro (int n)
{ int *a = malloc(sizeof(int));
    *a = n;
    return a;
}

Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod* cria_nod(void* valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}

Listad* insere_fim_listad(Listad* L, void* valor)
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {


        if(L->ini == NULL)
        {
            L->ini = L->fim = novo;
        }
        else
        {
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

void* remove_inicio_listad(Listad *L)
{
    Nod* aux;
    void* resposta = NULL; 
    if (L!=NULL)
        if (L->ini != NULL)
        {
            aux = L->ini;

            if (L->ini != L->fim)
            {
                L->ini->prox->ant = NULL;
                L->ini = L->ini->prox;
            }
            else
                L->ini = L->fim = NULL;

            resposta = aux->info;
            free(aux);
        }
    return resposta;
}

int eh_vazia_listad(Listad *L)
{
    if (L == NULL || L->ini == NULL)
        return 1;
    else
        return 0;
}

Listad* cria_fila()
{
    return cria_listad();
}

Listad* enqueue(Listad *f, void* elemento)
{
    return insere_fim_listad(f, elemento);
}

void* dequeue(Listad *f)
{
    return remove_inicio_listad(f);
}

int eh_vazia_fila(Listad *f)
{
    return eh_vazia_listad(f);
}

Grafo *cria_grafo(int n, int valorado, int direcionado)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->eh_direcionado = direcionado;
    g->eh_valorado = valorado;
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int **)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    

    return g;
}

void preenche_vertices(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->vertices[i] = i + 1;
}

void limpa(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->visitados[i] = 0;
}

int buscando_profundidade(int origem, int destino, Grafo *g)
{
    if(origem == destino)
    return 1;

    g->visitados[origem] = 1;
    for(int i = 0; i < g->ordem; i++)
        if(g->adjacencias[origem][i] >= 1 && !g->visitados[i])
            if(buscando_profundidade(i, destino, g))
                return 1;
    
    return 0;
}

int busca_profundidade(int origem, int destino, Grafo *g)
{
    limpa(g);
    return buscando_profundidade(origem, destino, g);
}

int main()
{
    int E, L, Lcount, i_matriz, j_matriz, quant, caminhos_corretos; 
    E = L = Lcount = i_matriz = j_matriz = quant = caminhos_corretos = 0;

    scanf ("%d", &E);
    scanf ("%d", &L);
    
    while (E != 0 && L != 0)
    {
        caminhos_corretos = 0;
        quant ++;
        Grafo *g = cria_grafo(E, 0, 0);
        preenche_vertices (g);

        for (int i = 0; i < g->ordem; i++)
            for (int j = 0; j < g->ordem; j++)
            {
                g->adjacencias[i][j] = 0; // ERRO
            }

        for (Lcount = 0; Lcount < L; Lcount++) 
        {
            scanf ("%d", &i_matriz);
            scanf ("%d", &j_matriz);
            g->adjacencias[i_matriz - 1][j_matriz - 1] = 1; // ERRO
            g->adjacencias[j_matriz - 1][i_matriz - 1] = 1; // ERRO
        }

        for (int i = 0; i < g->ordem; i++)
            for (int j = 0; j < g->ordem; j++)
                if (busca_profundidade (i, j, g) == 1)
                    caminhos_corretos ++;


        printf ("Teste %d\n", quant);
        if (caminhos_corretos == g->ordem * g->ordem)
            printf ("normal\n");
        else
            printf ("falha\n");
        printf ("\n");

        scanf ("%d", &E);
        scanf ("%d", &L);
        g = NULL;
        free (g);
    }
    return 0;
}

