#include <stdio.h>
#include <string.h>

void tabuleiro (char tab [3][3]){ 

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


