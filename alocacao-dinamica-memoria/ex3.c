#include <stdio.h>
#include <stdlib.h>

/*
Sim, se você utilizar a função free() após cada alocação de memória, não haverá memory leak. No entanto, em condições normais, você não deve chamar a função free() imediatamente após cada chamada de malloc() se você pretende continuar utilizando os dados alocados posteriormente. O free() é geralmente chamado quando a memória não é mais necessária.
*/

int main()
{
    // Número de alocações desejado
    int num_allocations = 1000;

    for (int i = 0; i < num_allocations; i++)
    {
        // Aloca um número de ponto flutuante na área de heap
        float *ptr = (float *)malloc(sizeof(float));

        // Verifica se a alocação foi bem-sucedida
        if (ptr == NULL)
        {
            printf("Erro na alocação de memória.\n");
            return 1; // Retorna 1 para indicar erro
        }

        // Atribui um valor ao número de ponto flutuante
        *ptr = 3.14;

        // Imprime o conteúdo alocado
        printf("Conteúdo alocado: %f\n", *ptr);

        // Desaloca a memória alocada
        free(ptr);
    }

    return 0; // Retorna 0 para indicar sucesso
}
