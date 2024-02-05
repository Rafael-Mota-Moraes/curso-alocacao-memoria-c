#include <stdio.h>
#include <stdlib.h>

int main()
{

    char *str = (char *)malloc(4 * sizeof(char));

    if (str == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = '\0';

    printf("Os três primeiros caracteres da string: %c%c%c\n", str[0], str[1], str[2]);

    free(str);

    return 0;
}
