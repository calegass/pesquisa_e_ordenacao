#include "arvoreb.h"

Arvoreb *cria_arvoreb(int ordem)
{
    Arvoreb *nova = (Arvoreb *)malloc(sizeof(Arvoreb));

    nova->raiz = NULL;
    nova->ordem = ordem;
    nova->altura = 0;
    return nova;
}

Nob *cria_nob()
{
    Nob *novo = (Nob *)malloc(sizeof(Nob)), novo2;

    novo->folha = 1;
    novo->pai = NULL;
    novo->qtd_chaves = 0;
    novo->lista_chaves = cria_listad();

    return novo;
}

Listad *divide_lista(Listad *L, int n)
{
    Listad *L2 = cria_listad();
    Nod *aux = L->ini;
    while (n > 1)
    {
        aux = aux->prox;
        n--;
    }
    L2->fim = L->fim;
    L->fim = aux;
    L2->ini = aux->prox;
    L2->ini->ant = NULL;
    L->fim->prox = NULL;
    return L2;
}

Listad* insere_ordenado_lista(Listad* lista_nos,
                     Chave *chave_nova)
{

    Nod *aux = lista_nos->ini;
   
    while (aux != NULL 
        && chave_nova->valor_chave > get_valor_chave(aux)) 
    {
            aux = aux->prox;
    }
    if (aux == lista_nos->ini)
    {
        lista_nos = insere_inicio_listad(lista_nos,(void*)chave_nova);
    }
    else
    {
        if (aux == NULL)
            lista_nos = insere_fim_listad(lista_nos,(void*)chave_nova);
        else
        {
            Nod* novo = cria_nod((void*)chave_nova);
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
    return lista_nos;
}

int get_valor_chave(Nod* aux)
{
    return ((Chave*) aux->info)->valor_chave;
}