#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
float aumentoPercentual(int valor, float percentual);
float descontoPercentual(int valor, float percentual);
void swap(int a, int b);

int main()
{
    int a = 20, b = 10;
    printf("max(a, b) = %d\n", max(a, b));
    printf("min(a, b) = %d\n", min(a, b));

    printf("aumentoPercentual(b, 10) = %.2f\n", aumentoPercentual(b, 10.0));
    printf("descontoPercentual(b, 10) = %.2f\n", descontoPercentual(b, 10.0));

    printf("a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("a = %d, b = %d\n", a, b); // não vai funcionar como deveria
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int min(int a, int b)
{
    if (a > b)
        return b;

    return a;
}

float aumentoPercentual(int valor, float percentual)
{
    return (float)(valor + (valor * percentual / 100));
}

float descontoPercentual(int valor, float percentual)
{
    return (float)(valor - (valor * percentual / 100));
}

void swap(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
