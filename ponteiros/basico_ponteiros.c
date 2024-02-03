#include <stdio.h>

int main(void)
{

    // * = referência
    // & = derreferência

    int a1 = 10, a2 = 110;
    int y = 0;

    int *p1 = &a1, *p2 = &a2;

    printf("endereco = %p, valor = %d\n", &p1, a1);
    printf("endereco = %p, valor = %d\n\n", &p2, a2);

    *p1 = 20;  // equivalente a1 = 20
    *p2 = 220; // equivalente a1 = 220

    printf("endereco = %p, valor = %d\n", &p1, a1);
    printf("endereco = %p, valor = %d\n\n", &p2, a2);

    y = *p1 + 20;
    printf("valor = %d\n\n", y);
}
