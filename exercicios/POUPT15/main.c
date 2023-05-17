#include <stdio.h>
#include <stdlib.h>

struct no
{
        int info, fb;
        struct no *esq, *dir;
};

typedef struct no No;

No* cria_no(int info)
{
    No* novo = (No*) malloc(sizeof(No));
    novo->esq = novo->dir = NULL;
    novo->info  = info;
    novo->fb = 0;
    return novo;
}

No* abb_insere(No* raiz, int info)
{
    No* q = raiz;
    No* p = NULL; //pai do q
    int flag = 0;

    while(q != NULL && flag != 1)
    {
        p = q;
        if(q->info < info)
            q = q->dir;
        else if(q->info > info)
            q = q->esq;
        else
            //igual
            flag = 1;
    }
    if (!flag) // flag == false
    {
        if (raiz != NULL)
            if (p->info < info)
                p->dir = cria_no(info);
            else
                p->esq = cria_no(info);
        else
            raiz = cria_no(info);
    }

    return raiz;
}

void recalcula_fb_abb(No *candidato, int info)
{
    No *aux = candidato;
    while (aux->info != info)
    {
        if (info < aux->info)
        {
            aux->fb++;
            aux = aux->esq;
        }
        else
        {
            aux->fb--;
            aux = aux->dir;
        }
    }
}

int abb_em_ordem(No* raiz)
{
    int big = 0, erro = 0;
    if(raiz != NULL)
    {
        abb_em_ordem(raiz->esq);
        big = raiz->fb;
        abb_em_ordem(raiz->dir);
    }
    if (big >= 2 || big <= -2)
    {
        erro = 1;
        return erro;
    }
}

int main ()
{
    No* arvore = NULL;
    int tam, info, erro = 0;

    scanf ("%d", &tam);

    for (int i = 0; i < tam; i++)
    {
        scanf ("%d", &info);
        arvore = NULL;
        while (info != -1)
        {
            arvore = abb_insere (arvore, info);
            recalcula_fb_abb (arvore, info);
            scanf ("%d", &info);
        }
        erro = abb_em_ordem (arvore);
        if (erro == 1)
            printf ("nao\n");
        else
            printf ("sim\n");
    }
    return 0;
}