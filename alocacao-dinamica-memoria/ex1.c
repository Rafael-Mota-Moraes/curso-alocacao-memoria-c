#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    if (array == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }

    printf("Array de inteiros com %d elementos, todos inicializados com 0:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
