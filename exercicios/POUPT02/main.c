#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150

typedef struct
{
    int** msg;
    int* vertices;
    int* visitados;
    int** adjacencias;
} Grafo;

typedef struct
{
    int T1, T2;
    char A1[MAX], A2[MAX], A3[MAX];
} Msg;

void prof(Grafo* g, int vertice, int M)
{
    g->msg[vertice][M] = 1;
    g->visitados[vertice] = 1;

    for(int i = 0; i < g->vertices[vertice]; i++) {
        int v = g->adjacencias[vertice][i];
        if(!g->visitados[v]){
            prof(g, v, M);
        }
    }
}

Grafo *cria_g(int n)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->msg = (int**)malloc((n + 1) * sizeof(int*));
    g->vertices = (int*)calloc(n + 1, sizeof(int));
    g->visitados= (int*)calloc(n + 1, sizeof(int));
    g->adjacencias = (int**)malloc((n + 1) * sizeof(int*));

    for (int i = 1; i <= n; i++) {
        g->msg[i] = (int*)calloc(MAX, sizeof(int));
        g->adjacencias[i] = (int*)malloc(n * sizeof(int));
    }
    return g;
}

int main() {
    int N, M;
    int a, T1, T2;
    char A1[MAX], A2[MAX], A3[MAX];

    scanf("%d", &N);
    while (N != 0) {
        M = 0;
        Grafo *g = cria_g(N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a);
            while ( a != 0)
            {
                g->adjacencias[i][g->vertices[i]++] = a;
                scanf("%d", &a);
            }
        }
        Msg* msg = (Msg*)malloc(MAX * sizeof(Msg));
        scanf("%d", &a);
        while (a != 0) {
            scanf("%d", &T1);
            msg[M].T1 = T1;
            scanf("%d", &T2);
            msg[M].T2 = T2;
            scanf("%s", A1);
            strcpy(msg[M].A1, A1);
            scanf("%s", A2);
            strcpy(msg[M].A2, A2);
            scanf("%s", A3);
            strcpy(msg[M].A3, A3);
            memset(g->visitados, 0, (N + 1) * sizeof(int)); 
            prof(g, a, M);
            M++;
            scanf("%d", &a);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%s", A1);
            printf("%s: ", A1);
            for (int j = 0, n; j < M; j++) {
                if (g->msg[i][j]) 
                    n = g->vertices[i];
                else 
                    n = 0;  
                if (n < msg[j].T1) 
                    printf("%s ", msg[j].A1);
                else if (n < msg[j].T2)
                    printf("%s ", msg[j].A2);
                else
                    printf("%s ", msg[j].A3);
            }
            printf("\n");
        }
        free(g);
        free(msg);

        scanf("%d", &N);        
    }
    return 0;
}
