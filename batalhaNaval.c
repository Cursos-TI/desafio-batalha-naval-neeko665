#include <stdio.h>
#include <stdlib.h>

// agora usando o #define para os valores e tamanhos

#define tamtabuleiro 10
#define tamnavio 3
#define agua 0
#define navio 3
#define habilidade 5
#define tamanhoHabilidade 5  // tamanho fixo das matrizes de habilidade (5x5)
#define tamanhoOctaedro 3



void exibirTabuleiro(int tabuleiro[tamtabuleiro][tamtabuleiro]) {
    printf("\nTabuleiro Batalha Naval com Habilidades:\n\n");
    printf("   ");
    for (char letra = 'A'; letra < 'A' + tamtabuleiro; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < tamtabuleiro; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < tamtabuleiro; j++) {
            if (tabuleiro[i][j] == agua) {
                printf("0 ");  // água
            } else if (tabuleiro[i][j] == navio) {
                printf("3 ");  // navio
            } else if (tabuleiro[i][j] == habilidade) {
                printf("5 ");  // habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[tamtabuleiro][tamtabuleiro], int habilidadeMat[tamanhoHabilidade][tamanhoHabilidade], int origemLinha, int origemColuna) {
    int offset = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (habilidadeMat[i][j] == 1) {
                int linhaTab = origemLinha - offset + i;
                int colunaTab = origemColuna - offset + j;

                if (linhaTab >= 0 && linhaTab < tamtabuleiro && colunaTab >= 0 && colunaTab < tamtabuleiro) {
                    if (tabuleiro[linhaTab][colunaTab] == agua) {
                        tabuleiro[linhaTab][colunaTab] = habilidade;
                    }
                }
            }
        }
    }
}

void aplicarHabilidade3x3(int tabuleiro[tamtabuleiro][tamtabuleiro], int habilidadeMat[tamanhoOctaedro][tamanhoOctaedro], int origemLinha, int origemColuna) {
    int offset = tamanhoOctaedro / 2;

    for (int i = 0; i < tamanhoOctaedro; i++) {
        for (int j = 0; j < tamanhoOctaedro; j++) {
            if (habilidadeMat[i][j] == 1) {
                int linhaTab = origemLinha - offset + i;
                int colunaTab = origemColuna - offset + j;

                if (linhaTab >= 0 && linhaTab < tamtabuleiro && colunaTab >= 0 && colunaTab < tamtabuleiro) {
                    if (tabuleiro[linhaTab][colunaTab] == agua) {
                        tabuleiro[linhaTab][colunaTab] = habilidade;
                    }
                }
            }
        }
    }
}



int main (){

    int tabuleiro [tamtabuleiro][tamtabuleiro];
    int posicao, i, j, l, c;     // Posicionando navios (horizontal, vertical, diagonal1, diagonal2)
    int octaedroPequeno[tamanhoOctaedro][tamanhoOctaedro] = {0};





    // iniciando o tabuleiro
   for ( i = 0; i < tamtabuleiro; i++)
   {
   for ( j = 0; j < tamtabuleiro; j++)
   {
    tabuleiro[i][j] = agua;
   }
   
   }

  
  //navio horizontal

  int linhahorizontal = 1, colunahorizontal = 4;
  posicao = 1;

    for ( i = 0; i < tamnavio; i++)
    {
        c = colunahorizontal + i;
        if (c >= tamtabuleiro || tabuleiro[linhahorizontal][c] != agua)
        {
            posicao = 0;
            break;
        }
        
    }

    if (posicao)
    {
       for ( i = 0; i < tamnavio; i++)
       {
         tabuleiro[linhahorizontal][colunahorizontal + i] = navio;
        
       }
       
    }else
    {
        printf("Não foi possivel posicionar o navio horizontal.\n");
    }
    
    //Navio Vertical
    int linhavertical = 5, colunavertical = 0;
    posicao = 1;

    for ( i = 0; i < tamnavio; i++)
    {
        l = linhavertical + i;
        if (l >= tamtabuleiro || tabuleiro[l][colunavertical] != agua)

        {
           posicao = 0;
           break;
        }
        
    }
    if (posicao)
    {
        for ( i = 0; i < tamnavio; i++)
        {
           tabuleiro[linhavertical + i][colunavertical] = navio;
        }
        
    }else
    {
        printf("Não foi possivel posicionar o navio vertical. \n");
    }

    // navio diagonal 1

    int linhadiagonal1 = 1, colunadiagonal1 = 0;
    posicao = 1;

    for ( i = 0; i < tamnavio; i++)
    {
        l = linhadiagonal1 + i;
        c = colunadiagonal1 + i;
        if (l >= tamtabuleiro || c >= tamtabuleiro || tabuleiro[l][c] != agua)
        {
            posicao = 0;
            break;
        }
        
    }
    
    if (posicao)
    {
        for ( i = 0; i < tamnavio; i++)
        {
           tabuleiro[linhadiagonal1 + i][colunadiagonal1 + i] = navio;
        }
        
    } else
    {
        printf("Não foi possivel posicionar o navio diagonal 1.\n");
    }

    // navio diagonal 2
    int linhadiagonal2 = 1, colunadiagonal2 = 9;
    posicao = 1;
    for ( i = 0; i < tamnavio; i++)
    {
        l = linhadiagonal2 + i;
        c = colunadiagonal2 - i;
        if (l >= tamtabuleiro || c < 0 || tabuleiro[l][c] != agua)
        {
            posicao = 0;
            break;
        }
        
    }
    if (posicao)
    {
        for ( i = 0; i < tamnavio; i++)
        {
           tabuleiro[linhadiagonal2 + i][colunadiagonal2 - i] = navio;
        }
        
    }else
    {
        printf("Não foi possivel posicionar o navio diagonal 2 .\n");
    }

    // Matrizes de habilidades
    int cone[tamanhoHabilidade][tamanhoHabilidade] = {0};
    int cruz[tamanhoHabilidade][tamanhoHabilidade] = {0};
    int octaedro[tamanhoHabilidade][tamanhoHabilidade] = {0};

    // Criando CONE
    for (i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (j >= tamanhoHabilidade / 2 - i && j <= tamanhoHabilidade / 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Criando CRUZ
    for (i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (i == tamanhoHabilidade / 2 || j == tamanhoHabilidade / 2) {
                cruz[i][j] = 1;
            }
        }
    }

     // Criando OCTAEDRO 
for (i = 0; i < tamanhoOctaedro; i++) {
    for (int j = 0; j < tamanhoOctaedro; j++) {
        if (abs(i - tamanhoOctaedro / 2) + abs(j - tamanhoOctaedro / 2) <= tamanhoOctaedro / 2) {
            octaedroPequeno[i][j] = 1;
        }
    }
}


  // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 9, 2);       // canto inferior-esquerdo
    aplicarHabilidade(tabuleiro, cruz, 4, 4);       // centro
    aplicarHabilidade3x3(tabuleiro, octaedroPequeno, 7, 7);   // canto inferior direito


    // exibir o tabuleiro
    printf("\nTabuleiro Batalha Naval:\n\n");
         exibirTabuleiro(tabuleiro);

    



return 0;

}