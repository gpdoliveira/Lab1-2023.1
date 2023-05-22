#include <stdio.h>
#include <stdlib.h>

void instrucoes(){
    printf ("--Gira Matriz--\n\n");
    printf (" 1 - gira a primeira camada da matriz no sentido anti-horario\n");
    printf (" 2 - gira a segunda camada da matriz no sentido horario\n");
    printf (" 3 - gira a terceira camada da matriz no sentido anti-horario\n\n");
}

void imprimeMatriz (char matriz[7][7]){
    int i,j;

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            printf (" %c  ",matriz[i][j]);
        }
        printf ("\n\n");
    }
}

void testa(char matriz[7][7]){
    int i,j,cruz=0,x=0,cruzinv=0,xinv=0;

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if (i==j){
                if (matriz[i][j]=='O'){
                    x++;
                }
            }
            if (i+j==6){
                if (matriz[i][j]=='X'){
                    x++;
                }
            }
        }
    }

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if (i==j){
                if (matriz[i][j]=='X'){
                    xinv++;
                }
            }
            if (i+j==6){
                if (matriz[i][j]=='O'){
                    xinv++;
                }
            }
        }
    }

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if (i==3){
                if (matriz[i][j]=='O'){
                    cruz++;
                }
            }
            if (j==3){
                if (matriz[i][j]=='X'){
                    cruz++;
                }
            }
        }
    }

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if (i==3){
                if (matriz[i][j]=='X'){
                    cruzinv++;
                }
            }
            if (j==3){
                if (matriz[i][j]=='O'){
                    cruzinv++;
                }
            }
        }
    }

    if (cruz == 12 || cruzinv ==12){
        printf ("CRUZ DESENHADA NA TELA!\n");
    }
    if (x == 12 || xinv == 12){
        printf ("X DESENHADO NA TELA!\n");
    }
}

void camadaVerde (char matriz[7][7]){
    int i,j;
    char copia[7][7];

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            copia[i][j]=matriz[i][j];
        }
    }

    for (i=2;i<5;i++){
        for (j=2;j<5;j++){
            if (i!=3 || j!=3){
                if (i==2 && j!=4){
                    matriz[i][j]=copia[i][j+1];
                }
                if (j==2 && i!=2){
                    matriz[i][j]=copia[i-1][j];
                }
                if (i==4 && j!=2){
                    matriz[i][j]=copia[i][j-1];
                }
                if (j==4 && i!=4){
                    matriz[i][j]=copia[i+1][j];
                }
            }
        }
    }
    imprimeMatriz(matriz);
    testa(matriz);
}

void camadaPreta (char matriz[7][7]){
    int i,j;
    char copia[7][7];

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            copia[i][j]=matriz[i][j];
        }
    }
    for (i=1;i<6;i++){
        for (j=1;j<6;j++){
            if (!(j>=2 && j<=4 && i>=2 && i<=4)){
                if (i==1 && j!=1){
                    matriz[i][j]=copia[i][j-1];
                }
                if (j==5 && i!=1){
                    matriz[i][j]=copia[i-1][j];
                }
                if (i==5 && j!=5){
                    matriz[i][j]=copia[i][j+1];
                }
                if (j==1 && i!=5){
                    matriz[i][j]=copia[i+1][j];
                }
            }
        }
    }
    imprimeMatriz(matriz);
    testa(matriz);
}

void camadaVermelha(char matriz[7][7]){
    int i,j;
    char copia[7][7];

    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            copia[i][j]=matriz[i][j];
        }
    }

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if (!(j>=1 && j<=5 && i>=1 && i<=5)){
                if (j==0 && i!=0){
                    matriz[i][j]=copia[i-1][j];
                }
                if (i==6 && j!=0){
                    matriz[i][j]=copia[i][j-1];
                }
                if (j==6 && i!=6){
                    matriz[i][j]=copia[i+1][j];
                }
                if (i==0 && j!=6){
                    matriz[i][j]=copia[i][j+1];
                }
            }
        }
    }
    imprimeMatriz(matriz);
    testa(matriz);
}


void matrizInicial(char matriz[7][7]){
    int i,j;

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            if ((i==0 && j==0)||(i==1 && j==5)||(i==2 && j==3)||(i==4 && j==3)||(i==5 && j ==1)||(i==6 && j==6)){
                matriz[i][j] = 'O';
            } else if ((i==0 && j==6)||(i==1 && j==1)||(i==3 && j==2)||(i==3 && j==4)||(i==5 && j ==5)||(i==6 && j==0)){
                matriz[i][j] = 'X';
            } else {
                matriz[i][j] = '.';
            }
        }
    }

    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            printf (" %c  ",matriz[i][j]);
        }
        printf ("\n\n");
    }
}

int main() {
    int continuar=4;
    char matriz[7][7];

    instrucoes();
    matrizInicial(matriz);

    do{
        printf ("\nQual camada voce deseja movimentar? (0 para encerrar)\n");
        scanf ("%d",&continuar);

        switch (continuar){
            case 1:
                system("cls");
                instrucoes();
                camadaVermelha(matriz);
                break;
            case 2:
                system("cls");
                instrucoes();
                camadaPreta(matriz);
                break;
            case 3:
                system("cls");
                instrucoes();
                camadaVerde(matriz);
                break;
        }
    }while (continuar!=0);
    return 0;
}
