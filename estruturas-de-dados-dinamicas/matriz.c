#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int linhas, colunas;
    float *conteudo;
} matrizFloat;

int mf_criar(matrizFloat *, int, int);
int mf_destruir(matrizFloat *);

void mf_mostrar(matrizFloat);
int mf_estaVazia(matrizFloat);
int mf_validarNumeroLinhaNumeroColuna(int, int, matrizFloat);

int mf_alterarValor(int, int, float, matrizFloat *);
float mf_retornarValor(int, int, matrizFloat);

int mf_criarIdentidade(int, matrizFloat *);

int mf_somar(matrizFloat *, matrizFloat *, matrizFloat *);
int mf_subtrair(matrizFloat *, matrizFloat *, matrizFloat *);

int mf_multiplicarPorEscalar(float, matrizFloat *, matrizFloat *);
int mf_multiplicar(matrizFloat *, matrizFloat *, matrizFloat *);

int mf_inserirLinha(matrizFloat *);
int mf_inserirColuna(matrizFloat *);

int mf_removerLinha(matrizFloat *, int);
int mf_removerColuna(matrizFloat *, int);

int main()
{
    int i, j;

    int rSoma;
    int rMultEscalar;
    int rMult;

    int rInserirLinhaM1;
    int rInserirLinhaM2;

    int rRemoverLinhaM1;
    int rRemoverLinhaM2;

    int rInserirColunaM1;
    int rInserirColunaM2;

    int rRemoverColunaM1;

    matrizFloat m1;
    matrizFloat m2;

    matrizFloat mSoma;
    matrizFloat mMultEscalar;
    matrizFloat mMult;

    mf_criar(&m1, 10, 10);
    mf_criar(&m2, 10, 1);

    printf("======== Criando m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);
    mf_mostrar(m1);

    printf("======== Criando m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);
    mf_mostrar(m2);

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            mf_alterarValor(i, j, 5.5f * i + j, &m1);

    for (i = 0; i < 10; i++)
        for (j = 0; j < 1; j++)
            mf_alterarValor(i, j, 2.3f * i + j, &m2);

    printf("======== Alterando m1 ========\n\n");
    mf_mostrar(m1);

    printf("======== Alterando m2 ========\n\n");
    mf_mostrar(m2);

    rSoma = mf_somar(&m1, &m2, &mSoma);

    printf("======== mSoma = m1 + m2 ========\n\n");

    if (rSoma)
        mf_mostrar(mSoma);
    else
        printf("Soma inválida ...\n\n");

    rMultEscalar = mf_multiplicarPorEscalar(10.3f, &m1, &mMultEscalar);

    printf("======== mMultEscalar = 10.3f * m1 ========\n\n");

    if (rMultEscalar)
        mf_mostrar(mMultEscalar);
    else
        printf("Multiplicação por escalar inválida ...\n\n");

    rMult = mf_multiplicar(&m1, &m2, &mMult);

    printf("======== mMult = m1 * m2 ========\n\n");

    if (rMult)
        mf_mostrar(mMult);
    else
        printf("Multiplicação entre m1 e m2 inválida ...\n\n");

    rInserirLinhaM1 = mf_inserirLinha(&m1);

    printf("======== Inserindo linha em m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if (rInserirLinhaM1)
        mf_mostrar(m1);
    else
        printf("Inserção de linha inválida ...\n\n");

    rInserirColunaM1 = mf_inserirColuna(&m1);

    printf("======== Inserindo coluna em m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if (rInserirColunaM1)
        mf_mostrar(m1);
    else
        printf("Inserção de coluna inválida ...\n\n");

    rRemoverLinhaM1 = mf_removerLinha(&m1, 5);

    printf("======== Removendo linha 5 de m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if (rRemoverLinhaM1)
        mf_mostrar(m1);
    else
        printf("Remoção de linha inválida ...\n\n");

    rRemoverColunaM1 = mf_removerColuna(&m1, 3);

    printf("======== Removendo coluna 3 de m1 (%dx%d) ========\n\n", m1.linhas, m1.colunas);

    if (rRemoverColunaM1)
        mf_mostrar(m1);
    else
        printf("Remoção de coluna inválida ...\n\n");

    rInserirLinhaM2 = mf_inserirLinha(&m2);

    printf("======== Inserindo linha em m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);

    if (rInserirLinhaM2)
        mf_mostrar(m2);
    else
        printf("Inserção de linha inválida ...\n\n");

    rInserirColunaM2 = mf_inserirColuna(&m2);

    printf("======== Inserindo coluna em m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);

    if (rInserirColunaM2)
        mf_mostrar(m2);
    else
        printf("Inserção de coluna inválida ...\n\n");

    rRemoverLinhaM2 = mf_removerLinha(&m2, 3);

    printf("======== Removendo linha 3 de m2 (%dx%d) ========\n\n", m2.linhas, m2.colunas);

    if (rRemoverLinhaM2)
        mf_mostrar(m2);
    else
        printf("Remoção de linha inválida ...\n\n");

    mf_destruir(&m1);
    mf_mostrar(m1);

    mf_destruir(&m2);
    mf_mostrar(m2);

    if (rSoma)
    {
        mf_destruir(&mSoma);
        mf_mostrar(mSoma);
    }

    if (rMultEscalar)
    {
        mf_destruir(&mMultEscalar);
        mf_mostrar(mMultEscalar);
    }

    if (rMult)
    {
        mf_destruir(&mMult);
        mf_mostrar(mMult);
    }
}

int mf_criar(matrizFloat *m, int linhas, int colunas)
{
    int i;

    if (linhas <= 0 || colunas <= 0)
        return 0;

    float *conteudo = (float *)malloc((linhas * colunas) * sizeof(float));

    if (conteudo == NULL)
        return 0;

    m->linhas = linhas;
    m->colunas = colunas;
    m->conteudo = conteudo;

    for (i = 0; i < (linhas * colunas); i++)
        m->conteudo[i] = 0.0f;

    return 1;
}

int mf_destruir(matrizFloat *m)
{
    if (m->conteudo == NULL)
        return 0;

    free(m->conteudo);
    m->conteudo = NULL;

    return 1;
}

void mf_mostrar(matrizFloat m)
{
    int i, j;

    if (m.conteudo == NULL)
    {
        printf("matriz vazia ...\n");
        return;
    }

    for (i = 0; i < m.linhas; i++)
    {
        for (j = 0; j < m.colunas; j++)
            printf("%.2f ", m.conteudo[m.colunas * i + j]);

        printf("\n");
    }

    printf("\n");
}

int mf_estaVazia(matrizFloat m)
{
    return m.conteudo == NULL;
}

int mf_validarNumeroLinhaNumeroColuna(int numLinha, int numColuna, matrizFloat m)
{
    return (numLinha >= 0 && numLinha <= m.linhas - 1) ||
           (numColuna >= 0 && numLinha <= m.colunas - 1);
}

int mf_alterarValor(int numLinha, int numColuna, float novoValor, matrizFloat *m)
{
    if (mf_estaVazia(*m))
        return 0;

    if (mf_validarNumeroLinhaNumeroColuna(numLinha, numColuna, *m) == 0)
        return 0;

    m->conteudo[m->colunas * numLinha + numColuna] = novoValor;
    return 1;
}

float mf_retornarValor(int numLinha, int numColuna, matrizFloat m)
{
    if (mf_estaVazia(m))
        return -1.0f;

    if (mf_validarNumeroLinhaNumeroColuna(numLinha, numColuna, m) == 0)
        return -1.0f;

    return m.conteudo[m.colunas * numLinha + numColuna];
}

int mf_criarIdentidade(int ordem, matrizFloat *m)
{
    int i, j;

    if (ordem <= 0)
        return 0;

    mf_criar(m, ordem, ordem);

    for (i = 0; i < m->linhas; i++)
    {
        for (j = 0; j < m->colunas; j++)
        {
            if (i == j)
                mf_alterarValor(i, j, 1.0f, m);
        }
    }

    return 1;
}

int mf_somar(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m1) ||
        mf_estaVazia(*m2))
        return 0;

    if (m1->linhas != m2->linhas ||
        m1->colunas != m2->colunas)
        return 0;

    mf_criar(mr, m1->linhas, m1->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, mf_retornarValor(i, j, *m1) + mf_retornarValor(i, j, *m2), mr);

    return 1;
}

int mf_subtrair(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m1) ||
        mf_estaVazia(*m2))
        return 0;

    if (m1->linhas != m2->linhas ||
        m1->colunas != m2->colunas)
        return 0;

    mf_criar(mr, m1->linhas, m1->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, mf_retornarValor(i, j, *m1) - mf_retornarValor(i, j, *m2), mr);

    return 1;
}

int mf_multiplicarPorEscalar(float n, matrizFloat *m, matrizFloat *mr)
{
    int i, j;

    if (mf_estaVazia(*m))
        return 0;

    mf_criar(mr, m->linhas, m->colunas);

    for (i = 0; i < mr->linhas; i++)
        for (j = 0; j < mr->colunas; j++)
            mf_alterarValor(i, j, n * mf_retornarValor(i, j, *m), mr);

    return 1;
}

int mf_multiplicar(matrizFloat *m1, matrizFloat *m2, matrizFloat *mr)
{
    int i, j, aux;
    float r;

    if (m1->colunas != m2->linhas)
        return 0;

    mf_criar(mr, m1->linhas, m2->colunas);

    for (i = 0; i < mr->linhas; i++)
    {
        for (j = 0; j < mr->colunas; j++)
        {
            r = 0.0f;

            for (aux = 0; aux < m1->linhas; aux++)
                r += mf_retornarValor(i, aux, *m1) * mf_retornarValor(aux, j, *m2);

            mf_alterarValor(i, j, r, mr);
        }
    }

    return 1;
}

int mf_inserirLinha(matrizFloat *m)
{
    int i;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (mf_estaVazia(*m))
        return 0;

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas + 1) * (m->colunas));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas * m->colunas; i++)
        aux[i] = copia[i];

    for (i = m->linhas * m->colunas; i < tamanho; i++)
        aux[i] = 0.0f;

    m->linhas += 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}

int mf_inserirColuna(matrizFloat *m)
{
    int i, j;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (mf_estaVazia(*m))
        return 0;

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas) * (m->colunas + 1));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas; i++)
    {
        for (j = 0; j < m->colunas + 1; j++)
        {
            if (j == m->colunas)
                aux[(m->colunas + 1) * i + j] = 0.0f;
            else
                aux[(m->colunas + 1) * i + j] = copia[m->colunas * i + j];
        }
    }

    m->colunas += 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}

int mf_removerLinha(matrizFloat *m, int numLinha)
{
    int i, j;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (numLinha < 0 ||
        numLinha >= m->linhas)
        return 0;

    if (mf_estaVazia(*m))
        return 0;

    if (m->linhas == 1)
    {
        free(m->conteudo);
        m->conteudo = NULL;
        return 1;
    }

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas - 1) * (m->colunas));
    aux = (float *)malloc(tamanho * sizeof(float));

    for (i = 0; i < m->linhas; i++)
        for (j = 0; j < m->colunas; j++)
            if (i != numLinha)
            {
                if (i < numLinha)
                    aux[m->colunas * i + j] = copia[m->colunas * i + j];
                else if (i > numLinha)
                    aux[m->colunas * (i - 1) + j] = copia[m->colunas * i + j];
            }

    m->linhas -= 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}

int mf_removerColuna(matrizFloat *m, int numColuna)
{
    int i, j, k;

    float *aux = NULL, *copia = NULL;
    size_t tamanho = (size_t)0;

    if (numColuna < 0 ||
        numColuna >= m->colunas)
        return 0;

    if (mf_estaVazia(*m))
        return 0;

    if (m->colunas == 1)
    {
        free(m->conteudo);
        m->conteudo = NULL;
        return 1;
    }

    copia = m->conteudo;

    tamanho = (size_t)((m->linhas) * (m->colunas - 1));
    aux = (float *)malloc(tamanho * sizeof(float));

    k = 0;
    for (i = 0; i < m->linhas; i++)
        for (j = 0; j < m->colunas; j++)
            if (j != numColuna)
            {
                aux[k] = copia[m->colunas * i + j];
                k++;
            }

    m->colunas -= 1;
    m->conteudo = aux;
    free(copia);

    return 1;
}
