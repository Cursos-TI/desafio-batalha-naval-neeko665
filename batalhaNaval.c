#include <stdio.h>

int main() {
    int tamtabuleiro = 10, tamanhonavio = 3;
    int agua = 0, navio = 3;

    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (agua é representado como 0)
    for (i = 0; i < tamtabuleiro; i++) {
        for (j = 0; j < tamtabuleiro; j++) {
            tabuleiro[i][j] = agua;
        }
    }

    // Coordenadas iniciais dos navios
    int linhahorizontal = 2, colunahorizontal = 4;
    int linhavertical = 5, colunavertical = 1;
    int coloquehorizontal = 1, coloquevertical = 1;

    // Verificação do navio horizontal
    for (i = 0; i < tamanhonavio; i++) {
        int c = colunahorizontal + i;
        if (c >= tamtabuleiro || tabuleiro[linhahorizontal][c] != agua) {
            coloquehorizontal = 0;
            break;
        }
    }

    // Coloca o navio horizontal se possível
    if (coloquehorizontal) {
        for (i = 0; i < tamanhonavio; i++) {
            int c = colunahorizontal + i;
            tabuleiro[linhahorizontal][c] = navio;
        }
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Verificação do navio vertical
    for (i = 0; i < tamanhonavio; i++) {
        int l = linhavertical + i;
        if (l >= tamtabuleiro || tabuleiro[l][colunavertical] != agua) {
            coloquevertical = 0;
            break;
        }
    }

    // Coloca o navio vertical se possível
    if (coloquevertical) {
        for (i = 0; i < tamanhonavio; i++) {
            int l = linhavertical + i;
            tabuleiro[l][colunavertical] = navio;
        }
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Batalha Naval:\n");
    printf("\n   ");

    for (char letra = 'A'; letra < 'A' + tamtabuleiro; letra++) {//Para colocar as letras na coluna horizontal
        printf("%c ", letra);
    }
    printf("\n");

    for (i = 0; i < tamtabuleiro; i++) {
         printf("%2d ", i + 1);  // para colocar os numeros na coluna vertical
        for (j = 0; j < tamtabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
