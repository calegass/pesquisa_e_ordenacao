#include <stdio.h> 
#include <stdlib.h>

#define TAM_MAX 100000

int merge (int *array_1, int tamanho_1, int *array_2, int tamanho_2,
            int *array_resultante, int *contador) // junta os dois arrays que já estão ordenados
{
    int i = 0, // contador do array_1
    j = 0, // contador do array_2
    k = 0; // contador do array_resultante

    while (i < tamanho_1 && j < tamanho_2)
        if (array_1[i] < array_2[j])
            array_resultante[k++] = array_1[i++];
        else
        {
            array_resultante[k++] = array_2[j++];
            (*contador) += tamanho_1 - i;
        }

    while (i < tamanho_1)
        array_resultante[k++] = array_1[i++];

    while (j < tamanho_2)
        array_resultante[k++] = array_2[j++];

    return k;
}

void mergeSort (int *v, int esq, int dir, int *contador) // função que ordena
{
    if (esq + 1 >= dir)
        return;

    int meio = (esq + dir) / 2,
    *array_1 = malloc (sizeof(int) * meio),
    *array_2 = malloc (sizeof(int) * (dir - meio)),
    *array_resultante = malloc (sizeof(int) * (dir - esq)),
    tam_array_1 = meio - esq,
    tam_array_2 = dir - meio,
    tam_array_result; 

    for (int i = esq; i < meio; i++)
        array_1[i - esq] = v[i];

    for (int i = meio; i < dir; i++)
        array_2[i - meio] = v[i];

    mergeSort (array_1, 0, meio - esq, contador);
    mergeSort (array_2, 0, dir - meio, contador);

    tam_array_result = merge (array_1, tam_array_1, array_2, tam_array_2, array_resultante, contador);

    for (int i = 0; i < tam_array_result; i++)
        v[esq + i] = array_resultante[i];
}

int main ()
{
    
    int v[TAM_MAX],
    contador; // número de inversões

    int n;
    scanf ("%d", &n);
    
    while (n != 0)
    {
        contador = 0;

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        mergeSort (v, 0, n, &contador);

        if (contador % 2)
            printf ("Marcelo\n");
        else
            printf ("Carlos\n");

        scanf ("%d", &n);
    }

    return 0;
}
