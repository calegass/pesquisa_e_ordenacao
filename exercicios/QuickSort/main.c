#include <stdio.h>

#define MAX 25

void quicksort (int v[MAX], int primeiro, int ultimo)
{
    int i, j, pivo, temp;

    if (primeiro < ultimo)
    {
        pivo = primeiro;
        i = primeiro;
        j = ultimo;
        
        while (i < j)
        {
            while (v[i] <= v[pivo] && i < ultimo) i++;
            while (v[j] > v[pivo]) j--;
        
            if (i < j)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        temp = v[pivo];
        v[pivo] = v[j];
        v[j] = temp;
        
        quicksort (v, primeiro, j - 1);
        quicksort (v, j + 1, ultimo);
    }
}

int main ()
{
    int i, quant, v[MAX];

    printf ("Quantidade: ");
    scanf ("%d", &quant);

    for (i = 0; i < quant; i++)
    {
        printf ("%d: ", i + 1);
        scanf ("%d", &v[i]);
    }

    quicksort (v, 0, quant - 1);

    printf ("Ordem: ");

    for (i = 0; i < quant; i++)
        printf (" %d", v[i]);

    return 0;
}