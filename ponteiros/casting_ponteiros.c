#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // ERRO COMUM 1:
    char c = 'A'; // char ocupa 1 byte (8 bits)
    char *pc = &c;

    printf("O endereço de c = %p\n", pc);
    printf("O conteúdo de c = %c\n\n", c);

    int *int_pc = (int *)pc; // O inteiro ocupa 4 bytes (32 bits)

    printf("O endereço de c = %p\n", int_pc);
    printf("O conteúdo de int_pc = %d\n\n", *int_pc);

    printf("\n\n\n");

    // ERRO COMUM 2:

    // 1 byte = 8 bits = 10010011
    // 2^8 =
    int a = 1025;
    int *pa = &a;

    printf("O endereço de a = %p\n", pa);
    printf("O conteúdo de a = %d\n\n", a);

    char *pc2 = (char *)pa;

    printf("O endereço de pc = %p\n", pc2);
    printf("O conteúdo de pc = %d\n\n", *pc2);

    return 0;
}
