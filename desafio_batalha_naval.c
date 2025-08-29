#include <stdio.h>
#include <stdlib.h>

#define NAVIO 3 
#define AFETADO 5

int main() {
    // Vetor com as letras das colunas
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];  // Tabuleiro fixo 10x10

    // 1. Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir posições iniciais dos navios
    int linhaNavioHorizontal = 2;  // linha 3
    int colunaNavioHorizontal = 4; // coluna E

    int linhaNavioVertical = 5;    // linha 6
    int colunaNavioVertical = 7;   // coluna H

    int linhaNavioDiagonal1 = 0;   // começa em [1][1]
    int colunaNavioDiagonal1 = 0;

    int linhaNavioDiagonal2 = 4;   // começa em [5][7]
    int colunaNavioDiagonal2 = 6;

    // 3. Posicionar navio horizontal (tamanho 3)
    if (colunaNavioHorizontal + NAVIO <= 10) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + j] = NAVIO;
        }
    }

    // 4. Posicionar navio vertical (tamanho 3)
    if (linhaNavioVertical + NAVIO <= 10) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 0) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
            }
        }
    }

    // 5. Posicionar navio diagonal principal (↘)
    if (linhaNavioDiagonal1 + NAVIO <= 10 && colunaNavioDiagonal1 + NAVIO <= 10) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] == 0) {
                tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = NAVIO;
            }
        }
    }

    // 6. Posicionar navio diagonal secundária (↙)
    if (linhaNavioDiagonal2 + NAVIO <= 10 && colunaNavioDiagonal2 - NAVIO >= -1) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] == 0) {
                tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = NAVIO;
            }
        }
    }

   // 7. Criar habilidades especiais
    // ===============================

   // Matrizes 5x5 para habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Preencher Cone (apontando para baixo)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

      // Preencher Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }

        // Preencher Octaedro (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            octaedro[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }

    // 8. Definir origens das habilidades no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 1;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctaLinha = 4, origemOctaColuna = 8;

    // Função para aplicar habilidade no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha, coluna;


             // Cone
            if (cone[i][j] == 1) {
                linha = origemConeLinha + i;
                coluna = origemConeColuna + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = AFETADO;
                }
            }

            // Cruz
            if (cruz[i][j] == 1) {
                linha = origemCruzLinha + i - 2;
                coluna = origemCruzColuna + j - 2;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = AFETADO;
                }
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                linha = origemOctaLinha + i - 2;
                coluna = origemOctaColuna + j - 2;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = AFETADO;
                }
            }
        }
    }

    // 9. Exibir o tabuleiro formatado
    printf(" **TABULEIRO BATALHA NAVAL** \n\n");

    // Cabeçalho com letras (colunas)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", colunas[j]);
    }
    printf("\n");

    // Linhas com números + conteúdo
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // imprime número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}