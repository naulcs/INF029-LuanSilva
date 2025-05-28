#include <stdio.h>
#include <string.h>

void abrirTabuleiro (char tab [3][3]){ 

    for (int i = 0; i < 3; i++)
    {
        
    for (int j = 0; j < 3; j++)
    {
tab [i][j] = ' ';
    }
    
    }
    
}

void mostrarTabuleiro(char tabuleiro[3][3]) {
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c  %c | %c | %c\n", 'A' + i, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("  ---|---|---\n");
    }
}


int jogadaValida (char jogada[], int *linha, int *coluna){

if (strlen(jogada) != 2)
{
return 0;
}

char letra = jogada[0];
char numero = jogada[1];

if (letra >= 'a' && letra <= 'z'){
    letra = letra - 32;
}

if (letra < 'A' || letra > 'C')
{
    return 0;
}

if (numero < '1' || numero > '3')
{
    return 0;
}


*linha = letra - 'A';
*coluna = numero - '1';

return 1;

}


int verificarVitoria (char tabuleiro[3][3], char simbolo){
    for (int i = 0; i < 3; i++){
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo)
        {
return 1;
        }
        if (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo) 
        {
return 1 ;
       }
        
    }

    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo)
    {
        return 1;
    }
     if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo)
    {
        return 1;
    }

    return 0;
}


int main ( ){

    char tabuleiro [3] [3];
    abrirTabuleiro (tabuleiro);

    int jogador= 1;
    int jogadas = 0;
    char simbolo;
    char jogada[3];
    int linha, coluna;
    
    while (1)
    {
        mostrarTabuleiro(tabuleiro);
        simbolo = (jogador == 1) ? 'X' : 'O';

        printf ( "Jogador %d infrome a jogada \n", jogador);
        scanf ("%s", jogada);

        if (!jogadaValida(jogada, &linha, &coluna))
        {
           printf("jogada invalida, tente novamente \n");
           continue;
        }
        
        if (tabuleiro[linha][coluna] != ' ')
        {
            printf("posição ocupada, tente novamente \n");
           continue;
        }
        
        tabuleiro[linha][coluna] = simbolo;
        jogadas++;

        if (verificarVitoria(tabuleiro, simbolo))
        {
           mostrarTabuleiro(tabuleiro);
           printf("Parabens, jogador %d venceu ", jogador);
           break;
        }
        
        if (jogadas == 9)
        {
          mostrarTabuleiro(tabuleiro);
            printf("Empate! Ninguém venceu.\n");
            break;
        }
        
        jogador = (jogador == 1) ? 2 : 1;
    }
    
}