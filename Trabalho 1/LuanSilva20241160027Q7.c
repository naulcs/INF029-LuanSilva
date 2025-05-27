#include <stdio.h>
#include <string.h>



int cacaPalavra(char matriz[100][100], int linhas, int colunas, char palavra[])
{
    int len = strlen(palavra);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Para cada direção
            int horizotal[] = {-1,-1,-1, 0, 0, 1, 1, 1};
            int vertical[] = {-1, 0, 1,-1, 1,-1, 0, 1};

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
                    printf("Encontrada na posição (%d,%d), direção (%d,%d)\n", i, j, horizotal[d], vertical[d]);
                    return 1;
                }
            }
        }
    }

    printf("Palavra não encontrada.\n");
    return 0;
}


int main() {
    char matriz[100][100] = {
        {'R','A','T','A'},
        {'X','B','A','T'},
        {'C','A','R','O'},
        {'P','A','L','A'}
    };

    cacaPalavra(matriz, 4, 4, "RATA");   
    cacaPalavra(matriz, 4, 4, "ATA");   
    cacaPalavra(matriz, 4, 4, "ATOA");    

}
