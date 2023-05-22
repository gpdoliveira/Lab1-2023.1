#include <stdio.h>
#include <stdlib.h>

void imprime(int n, float *notas, int *ocorrencias){
    int i,mais=1,j,m;
    float notamais;

    notamais=notas[0];

    for (i=0;i<n;i++){
        m=0;
        for(j=0;j<i;j++){
                if (notas[j]==notas[i]){
                    m++;
                }
        }
        if (m==0){
            printf ("%.1f ocorre %d vez(es)\n",notas[i],ocorrencias[i]);
        }
        if (ocorrencias[i]==mais){
            mais = ocorrencias[i];
            if (notas[i]>notamais){
                notamais = notas[i];
            }
        }
        if (ocorrencias[i]>mais){
            mais = ocorrencias[i];
            notamais = notas[i];
        }

    }
    printf ("\n%.1f eh a nota mais frequente\n",notamais);
}

void verifica(float *notas, int n){
    int i,j,ocorrencias[n],k=0;

    for(i=0;i<n;i++){
        ocorrencias[i]=1;
    }

    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (notas[i]==notas[j]){
                ocorrencias[k] +=1;
            }
        }
        k++;
    }
    imprime(n,notas,ocorrencias);
}

void lernotas (int n){
    float notas[n];
    int i;

    for (i=0;i<n;i++){
        scanf ("%f",&notas[i]);
    }
    printf ("\n");
    printf ("Para n = %d e a sequencia {",n);
    for (i=0;i<n;i++){
        printf ("%.1f ",notas[i]);
    }
    printf ("}\n\n");
    verifica(notas,n);
}

int main()
{
    int n;
    printf ("-Frequencia de ocorrencias-\n");

    do {
    printf ("\nInforme a quantidade de notas que serao digitadas (numero entre 1 e 100):");
    scanf ("%d",&n);
    } while (n<=0 || n>100);

    lernotas(n);
    return 0;
}
