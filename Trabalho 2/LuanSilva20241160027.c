#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "LuanSilva20241160027.h"

int* vetorPrincipal[TAM];
int qtdElementos[TAM];
int tamEstrutura[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }

    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }
    
    int indice = posicao - 1;

    if (vetorPrincipal[indice] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    vetorPrincipal[indice] = (int*) malloc(tamanho * sizeof(int));

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    tamEstrutura[indice] = tamanho;
    qtdElementos[indice] = 0;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    if (qtdElementos[indice] >= tamEstrutura[indice])
    {
        return SEM_ESPACO;
    }

    vetorPrincipal[indice][qtdElementos[indice]] = valor;
    qtdElementos[indice]++;
    
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (qtdElementos[indice] == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    qtdElementos[indice]--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (qtdElementos[indice] == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int posicao_encontrada = -1;
    for (int i = 0; i < qtdElementos[indice]; i++)
    {
        if (vetorPrincipal[indice][i] == valor)
        {
            posicao_encontrada = i;
            break;
        }
    }

    if (posicao_encontrada == -1)
    {
        return NUMERO_INEXISTENTE;
    }
    
    for (int j = posicao_encontrada; j < qtdElementos[indice] - 1; j++)
    {
        vetorPrincipal[indice][j] = vetorPrincipal[indice][j + 1];
    }
    
    qtdElementos[indice]--;

    return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for (int i = 0; i < qtdElementos[indice]; i++)
    {
        vetorAux[i] = vetorPrincipal[indice][i];
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for (int i = 0; i < qtdElementos[indice]; i++)
    {
        vetorAux[i] = vetorPrincipal[indice][i];
    }

    int n = qtdElementos[indice];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int contador_geral = 0;

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            for (int j = 0; j < qtdElementos[i]; j++)
            {
                vetorAux[contador_geral] = vetorPrincipal[i][j];
                contador_geral++;
            }
        }
    }

    if (contador_geral == 0)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else
    {
        return SUCESSO;
    }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int contador_geral = 0;

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            for (int j = 0; j < qtdElementos[i]; j++)
            {
                vetorAux[contador_geral] = vetorPrincipal[i][j];
                contador_geral++;
            }
        }
    }

    if (contador_geral == 0)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    for (int i = 0; i < contador_geral - 1; i++)
    {
        for (int j = 0; j < contador_geral - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int tamanho_final = tamEstrutura[indice] + novoTamanho;

    if (tamanho_final < 1)
    {
        return NOVO_TAMANHO_INVALIDO;
    }

    int* novo_ponteiro = (int*) realloc(vetorPrincipal[indice], tamanho_final * sizeof(int));

    if (novo_ponteiro == NULL)
    {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice] = novo_ponteiro;
    tamEstrutura[indice] = tamanho_final;

    if (qtdElementos[indice] > tamanho_final)
    {
        qtdElementos[indice] = tamanho_final;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (qtdElementos[indice] == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    return qtdElementos[indice];
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No* cabecote = NULL;
    No* ultimo = NULL;
    int primeiro_elemento = 1;

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            for (int j = 0; j < qtdElementos[i]; j++)
            {
                if (primeiro_elemento)
                {
                    cabecote = (No*) malloc(sizeof(No));
                    if (cabecote == NULL)
                    {
                        return NULL;
                    }
                    cabecote->prox = NULL;
                    ultimo = cabecote;
                    primeiro_elemento = 0;
                }

                No* novo_no = (No*) malloc(sizeof(No));
                if (novo_no == NULL)
                {
                    return NULL;
                }
                
                novo_no->conteudo = vetorPrincipal[i][j];
                novo_no->prox = NULL;
                
                ultimo->prox = novo_no;
                ultimo = novo_no;
            }
        }
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No* no_atual;
    int i = 0;

    if (inicio == NULL)
    {
        return;
    }

    no_atual = inicio->prox;

    while (no_atual != NULL)
    {
        vetorAux[i] = no_atual->conteudo;
        no_atual = no_atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No* no_atual = *inicio;
    No* proximo_no;

    while (no_atual != NULL)
    {
        proximo_no = no_atual->prox;
        free(no_atual);
        no_atual = proximo_no;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
     for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
        qtdElementos[i] = 0;
        tamEstrutura[i] = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
      for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]);
        }
    }
}
