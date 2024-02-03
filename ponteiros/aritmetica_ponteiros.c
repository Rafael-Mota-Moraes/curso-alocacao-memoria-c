#include <stdio.h>
#include <stdlib.h>

size_t strlen(char *);

int main(void)
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i = 0;
    int *p = a;
    int *pBase = a;

    char *s1 = "ABCDEFGHIJK";

    printf("&a[0] = %p / a[0] = %d\n\n", p, *p);

    // Operação de incremento (1a forma)

    for (int i = 0; i < 10; i++)
    {
        p = pBase + i;
        printf("&a[%d] = %p / a[%d] = %d\n", i, p, i, *p);
    }

    printf("\n\n\n");

    // Operação de incremento (2a forma)
    p = a;
    for (i = 0; i < 10; i++)
    {
        printf("&a[%d] = %p / a[%d] = %d\n", i, p + i, i, *(p + i));
    }

    printf("\n\n\n");
    // CUIDADO! Nunca fazer dessa forma
    p = a;

    for (i = 0; i < 10; i++)
    {
        p = pBase + i * sizeof(int);
        printf("&a[%d] = %p / a[%d] = %d\n", i, p, i, *p);
    }

    printf("\n\n\n");

    printf("Tamanho de '%s' = %d\n", s1, (int)strlen(s1));
}

size_t strlen(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;

    return (size_t)(p - s);
}
