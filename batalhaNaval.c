#include <stdio.h>

// agora usando o #define para os valores e tamanhos

#define tamtabuleiro 10
#define tamnavio 3
#define agua 0
#define navio 3

int main (){

    int tabuleiro [tamtabuleiro][tamtabuleiro];
    int i, j;



    // iniciando o tabuleiro
   for ( i = 0; i < tamtabuleiro; i++)
   {
   for ( j = 0; j < tamtabuleiro; j++)
   {
    tabuleiro[i][j] = agua;
   }
   
   }
  // variaveis de controle para validação
  int posicao, l, c;
  
  
  //navio horizontal

  int linhahorizontal = 2, colunahorizontal = 4;
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
    int linhavertical = 5, colunavertical = 1;
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

    int linhadiagonal1 = 0, colunadiagonal1 = 0;
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
    int linhadiagonal2 = 4, colunadiagonal2 = 5;
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

    // exibir o tabuleiro
    printf("\nTabuleiro Batalha Naval:\n\n");
     printf("   "); // 3 espaços para alinhar com os números (2 dígitos + espaço extra)
for (char letra = 'A'; letra < 'A' + tamtabuleiro; letra++) {
    printf("%c ", letra);
}
printf("\n");


       for ( i = 0; i < tamtabuleiro; i++)
      { printf("%2d ", i + 1);  // para colocar os numeros na coluna vertical
       for ( j = 0; j < tamtabuleiro; j++)
       {
       printf("%d ", tabuleiro[i][j]);
       }
       printf("\n");


      }
      


return 0;

}