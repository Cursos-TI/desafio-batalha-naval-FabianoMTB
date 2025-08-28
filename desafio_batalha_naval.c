#include <stdio.h>

#define NAVIO 3 

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
    int linhaNavioHorizontal = 2;  // linha 3 (posição vertical)
    int colunaNavioHorizontal = 4; // coluna E (horizontal)

    int linhaNavioVertical = 5;    // linha 6
    int colunaNavioVertical = 7;   // coluna H

    // 3. Posicionar navio horizontal (tamanho 3)
    if (colunaNavioHorizontal + NAVIO <= 10) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + j] = 3;
        }
    }

    // 4. Posicionar navio vertical (tamanho 3)
    if (linhaNavioVertical + NAVIO <= 10) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 0) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
            }
        }
    }

    // 5. Exibir o tabuleiro formatado
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