#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMPALAVRA 11

void verificaSequencia(int n,char palavras[n][TAMPALAVRA], int k){
    int i,j,chardiff=0;

    for (i=0;i<n-1;i++){
        k = strlen(palavras[i]);
        for (j=0;j<k;j++){
            if (palavras[i][j]!=palavras[i+1][j]){
                chardiff++;
            }
        }
    }

    if (chardiff==n-1){
        printf ("Cada palavra da sequencia difere da anterior em exatamente uma letra!\n");
        printf (":D");
    } else if (chardiff==0){
        printf ("As palavras da sequencia sao iguais!\n");
        printf (":0");
    } else {
        printf ("Apesar de possuirem o mesmo tamanho, algumas ou todas as palavras da sequencia diferem da palavra anterior a elas em mais de uma letra...\n");
        printf (":(");
    }

}

void verificaTamanho(int n, char palavras[n][TAMPALAVRA]){
    int i,j,vet[n],tamanhodiff=0;

    for (i=0;i<n;i++){
        vet[i] = strlen(palavras[i]);
    }

    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (vet[i]!= vet[j]){
                tamanhodiff++;
            }
        }
    }

    if (tamanhodiff==0){
        printf ("Todas as palavras possuem o mesmo tamanho!\n");
        verificaSequencia(n,palavras,vet[1]);
    } else {
        printf ("As palavras digitadas possuem tamanhos diferentes...\n");
    }
}

void lerPalavras(int n, char palavras[n][TAMPALAVRA]){
    int i;

    for (i=0;i<n;i++){
        printf ("\nInforme a palavra %d:",i+1);
        scanf ("%s",palavras[i]);
    }
    printf ("\n");
}

int main()
{
    int n;
    printf ("--Jogo de Palavras--\n\n");

    do {
        printf ("Informe a quantidade n (inteiro) de palavras a serem digitadas: ");
        scanf ("%d",&n);
    } while (n<1);

    char palavras[n][TAMPALAVRA];

    lerPalavras(n,palavras);
    verificaTamanho(n,palavras);

    return 0;
}
