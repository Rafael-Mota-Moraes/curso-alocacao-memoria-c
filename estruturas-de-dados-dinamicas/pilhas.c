#include <stdio.h>
#include <stdlib.h>

struct no
{
    int dado;
    struct no *prox;
};

typedef struct
{
    struct no *topo;
} pilha;

void p_criar(pilha *);
void p_destruir(pilha *);
int p_estaVazia(pilha);
int p_insere(pilha *, int);
void p_mostrar(pilha);
int p_remove(pilha *);
int p_topo(pilha);

int p_tamanho(pilha);
size_t p_tamanhoBytes(pilha);

int main(void)
{

    pilha p;
    p_criar(&p);

    p_insere(&p, 20);
    p_insere(&p, 10);
    p_insere(&p, 0);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));

    p_mostrar(p);

    p_remove(&p);
    p_remove(&p);
    p_remove(&p);

    printf("Tamanho de p em bytes = %ld\n", p_tamanhoBytes(p));

    p_mostrar(p);

    return 0;
}

void p_criar(pilha *p)
{
    p->topo = NULL;
}

void p_destruir(pilha *p)
{
    int i;
    int tamanhoPilha = p_tamanho(*p);

    for (i = 0; i < tamanhoPilha; i++)
        p_remove(p);
}

int p_estaVazia(pilha p)
{
    return p.topo == NULL;
}

int p_insere(pilha *p, int dado)
{
    struct no *aux;

    aux = (struct no *)malloc(sizeof(struct no));

    if (aux == NULL)
        return 0;

    aux->dado = dado;
    aux->prox = p->topo;
    p->topo = aux;

    return 1;
}

void p_mostrar(pilha p)
{
    struct no *aux;
    aux = p.topo;

    if (p_estaVazia(p))
        printf("Pilha está vazia...\n");
    else
    {
        while (aux != NULL)
        {
            printf("Dado: %d\n", aux->dado);
            aux = aux->prox;
        }
    }
}

int p_tamanho(pilha p)
{
    int contador;
    struct no *aux;

    contador = 0;
    aux = p.topo;

    if (p_estaVazia(p))
        return 0;
    else
    {
        while (aux != NULL)
        {
            contador += 1;
            aux = aux->prox;
        }
    }

    return contador;
}

size_t p_tamanhoBytes(pilha p)
{
    int tamanhoPilha;
    struct no aux;
    if (p_estaVazia(p))
        return (size_t)0;

    tamanhoPilha = p_tamanho(p);
    return (size_t)(sizeof(p) + sizeof(aux) * tamanhoPilha);
}

int p_remove(pilha *p)
{
    struct no *aux;
    if (p_estaVazia(*p))
        return -1;

    aux = p->topo;
    p->topo = aux->prox;

    aux->dado = 0;
    aux->prox = NULL;

    free(aux);
    return aux->dado;
}

int p_topo(pilha p)
{
    if (p_estaVazia(p))
        return -1;

    return p.topo->dado;
}
