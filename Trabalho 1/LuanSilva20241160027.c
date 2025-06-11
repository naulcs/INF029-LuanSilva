// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Luan Silva Pereira
//  email: naul.cs@hotmail.com
//  Matrícula: 20241160027
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016
//gcc corretor.c LuanSilva20241160027.c -o programa

// #################################################

#include <stdio.h>
#include "LuanSilva20241160027.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  DataQuebrada dq = quebraData(data);

  int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (dq.iAno <= 0 || dq.iAno > 2025 || dq.iMes < 1 || dq.iMes > 12)
    datavalida = 0;

  if (dq.iMes == 2)
  {
    if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0))
    {
      diasMes[2] = 29;
    }
  }

  if (dq.iDia < 1 || dq.iDia > diasMes[dq.iMes])
    datavalida = 0;

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DiasMesesAnos dma;

  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }
  else
  {
    DataQuebrada inicio = quebraData(datainicial);
    DataQuebrada fim = quebraData(datafinal);

    if (
        fim.iAno < inicio.iAno ||
        (fim.iAno == inicio.iAno && fim.iMes < inicio.iMes) ||
        (fim.iAno == inicio.iAno && fim.iMes == inicio.iMes && fim.iDia < inicio.iDia))
    {
      dma.retorno = 4;
      return dma;
    }

    int anos = fim.iAno - inicio.iAno;
    int meses = fim.iMes - inicio.iMes;
    int dias = fim.iDia - inicio.iDia;

    if (dias < 0)
    {
      int mesAnterior = fim.iMes - 1;
      int anoAux = fim.iAno;

      if (mesAnterior == 0)
      {
        mesAnterior = 12;
        anoAux--;
      }

      int diasMesAnterior;
      if (mesAnterior == 2)
      {
        if ((anoAux % 4 == 0 && anoAux % 100 != 0) || (anoAux % 400 == 0))
        {
          diasMesAnterior = 29;
        }
        else
        {
          diasMesAnterior = 28;
        }
      }
      else if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior == 11)
      {
        diasMesAnterior = 30;
      }
      else
      {
        diasMesAnterior = 31;
      }

      dias += diasMesAnterior;
      meses--;
    }

    if (meses < 0)
    {
      meses += 12;
      anos--;
    }

    dma.qtdAnos = anos;
    dma.qtdMeses = meses;
    dma.qtdDias = dias;
    dma.retorno = 1;

    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
   int qtdOcorrencias = 0;
  if (!isCaseSensitive && c >= 'A' && c <= 'Z')
  {
    c = c + 32;
  }

  for (int i = 0; texto[i] != '\0'; i++)
  {
   char atual = texto[i];
   if (!isCaseSensitive && atual >= 'A' && atual <= 'Z') {
            atual = atual + 32;
        }
        if (atual == c)
        {
            qtdOcorrencias++;
        }
}
return qtdOcorrencias;
}
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int indicePos = 0;
    int i = 0; 
    int posLetra = 1; 

    int tamBusca = strlen(strBusca);

    while (strTexto[i] != '\0')
    {
        int tamChar;

        unsigned char c = (unsigned char)strTexto[i];
        if ((c & 0x80) == 0x00) tamChar = 1;           
        else if ((c & 0xE0) == 0xC0) tamChar = 2;      
        else if ((c & 0xF0) == 0xE0) tamChar = 3;      
        else if ((c & 0xF8) == 0xF0) tamChar = 4;     
        else tamChar = 1; 

        if (strncmp(&strTexto[i], strBusca, tamBusca) == 0)
        {
            int j = 0;
            int letrasBusca = 0;
            while (j < tamBusca)
            {
                unsigned char cb = (unsigned char)strBusca[j];
                int tamB;
                if ((cb & 0x80) == 0x00) tamB = 1;
                else if ((cb & 0xE0) == 0xC0) tamB = 2;
                else if ((cb & 0xF0) == 0xE0) tamB = 3;
                else if ((cb & 0xF8) == 0xF0) tamB = 4;
                else tamB = 1;

                j += tamB;
                letrasBusca++;
            }

            posicoes[indicePos++] = posLetra;
            posicoes[indicePos++] = posLetra + letrasBusca - 1;
            qtdOcorrencias++;

            i += tamBusca;
            posLetra += letrasBusca;
            continue;
        }

        i += tamChar;
        posLetra++;
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
int invertido = 0;
    
    while(num != 0) {
        int digito = num % 10;          
        invertido = invertido * 10 + digito; 
        num = num / 10;               
    }
    
    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{

  char strBase[50], strBusca[50];
  sprintf(strBase,"%d", numerobase);
  sprintf(strBusca, "%d", numerobusca);

  int tamBase = strlen(strBase);
  int tamBusca = strlen(strBusca);

  int qtdOcorrencias=0;

  for (int i = 0; i <= tamBase - tamBusca; i++)
  {
    int encontrou = 1;

    for (int j = 0; j < tamBusca; j++)
    {
      if (strBase[i +j] != strBusca[j])
      {
        encontrou = 0;
        break;
      }
      
    }
    if (encontrou)
    {
      qtdOcorrencias++;
    }    
  }
  

  return qtdOcorrencias;
}



int q7(char matriz[8][10], char palavra[])
{
    int linhas = 8;
    int colunas = 10;
    int len = strlen(palavra);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int horizotal[] = {-1,-1,-1, 0, 0, 1, 1, 1};
            int vertical[]  = {-1, 0, 1,-1, 1,-1, 0, 1};

            for (int d = 0; d < 8; d++) {
                int x = i, y = j, k;

                for (k = 0; k < len; k++) {
                    int nx = x + k * horizotal[d];
                    int ny = y + k * vertical[d];

                    if (nx < 0 || ny < 0 || nx >= linhas || ny >= colunas)
                        break;

                    if (matriz[nx][ny] != palavra[k])
                        break;
                }

                if (k == len) {
                    return 1;
                }
            }
        }
    }

    return 0;
}


DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++)
  {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sDia[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++)
  {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2)
  {                 // testa se tem 1 ou dois digitos
    sMes[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++)
  {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4)
  {                 // testa se tem 2 ou 4 digitos
    sAno[i] = '\0'; // coloca o barra zero no final
  }
  else
  {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
