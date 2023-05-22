#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void desenho_dados(int dado){
    switch (dado){
        case 1:
            printf (" -----\n");
            printf ("|     |\n|  O  |\n|     |\n");
            printf (" -----\n");
            break;
        case 2:
            printf (" -----\n");
            printf ("|    O|\n|     |\n|O    |\n");
            printf (" -----\n");
            break;
        case 3:
            printf (" -----\n");
            printf ("|    O|\n|  O  |\n|O    |\n");
            printf (" -----\n");
            break;
        case 4:
            printf (" -----\n");
            printf ("|O   O|\n|     |\n|O   O|\n");
            printf (" -----\n");
            break;
        case 5:
            printf (" -----\n");
            printf ("|O   O|\n|  O  |\n|O   O|\n");
            printf (" -----\n");
            break;
        case 6:
            printf (" -----\n");
            printf ("|O   O|\n|O   O|\n|O   O|\n");
            printf (" -----\n");
            break;
    }
}

int dados (int soupc){
    int dadoB,dadoV,pontuacao;
    if(soupc==1){printf ("Dados do PLAYER2: \n");} else{
    printf ("Voce rolou os dados: \n");}
    srand((unsigned)time(NULL));
    dadoB = 1 + rand() % 6;
    dadoV = 1 + rand() % 6;
    printf ("Dado BRANCO\n");
    desenho_dados(dadoB);
    printf ("Dado VERMELHO\n");
    desenho_dados(dadoV);
    pontuacao = dadoB + dadoV;
    if (dadoV == 6){
            pontuacao += 6;}
    printf ("Pontuacao da rodada: %d\n",pontuacao);
    return pontuacao;
}

int jogada(){
    int pontuacao=0,teste;
    do {
        printf ("Pressione 1 para rolar os dados ou 2 para passar a vez...\n");
        scanf ("%d",&teste);
    } while (teste != 1 && teste != 2);

    if (teste ==1){
        pontuacao = dados(0);}
    else {printf ("Voce pulou a vez...\n");}
    return pontuacao;
}
/*a jogada do computador possui funcao propria e atua com base na seguinte logica:
    - na primeira jogada a pontuacao eh 0 entao ele deve rolar os dados
    - na segunda e na terceira jogadas ele analisa se ha possibilidade de passar 21 facilmente ou nao(se pontuacao maior que 11)
    - no entanto, se existe chance de passar e o pc estiver perdendo, ele tenta a sorte e joga novamente a fim de vencer o jogador
 */
int jogada_pc(int pontuacaoatual, int i,int soupc,int padver){
    int pontuacao=0;
    switch (i){
    case 1:
        pontuacao = dados(soupc);
        return pontuacao;
        break;
    case 3: case 5:
        if (pontuacaoatual <=11){
            pontuacao = dados(soupc);
            return pontuacao;
        } else if (pontuacaoatual < padver && pontuacaoatual < 21){
            pontuacao = dados(soupc);
            return pontuacao;}
        else {
            printf ("PLAYER2 pulou a vez...\n");
            return pontuacao;
        }
        break;
    default: return pontuacao;
    }
}

void limpar_tela(){
    int continuar;
    do {
        printf ("Pressione 1 para continuar o jogo... ");
        scanf ("%d",&continuar);
    } while (continuar !=1);
    system ("cls");
}

void resultado (int p1, int p2){
    if (p1 == p2 && p1 == 0){
        printf ("EMPATE <3\n");
    }
    if (p1 > 21){
        if (p2 > 21){
            printf ("EMPATE <3\n");
        } else {
            if (p2 !=0){
            printf ("!!!!!!!!PLAYER2 VENCEU!!!!!!!!\n");}
            }
    } else if (p2 > 21 && p1 !=0){
        printf ("!!!!!!!!PLAYER1 VENCEU!!!!!!!!\n");}
     else if (21-p1 == 21-p2 && p1 != 0 && p2 != 0){
        printf ("EMPATE <3\n");
    } else if (21-p1 > 21-p2 && p2 != 0){
        printf ("!!!!!!!!PLAYER2 VENCEU!!!!!!!!\n");}
        else {
            if (p1 != 0){
             printf ("!!!!!!!!PLAYER1 VENCEU!!!!!!!!\n");
            }
        }
    printf ("PLAYER1 %d X %d PLAYER2\n",p1,p2);
}

int main()
{
    char jogardnv;
    do{
    printf("==============================VERMELHO E BRANCO==============================\n\n");

    int mododejogo=0;
    printf ("Bem vindo ao jogo!");

    do {
        printf (" Selecione um dos modos disponiveis:\n * PlayerxPlayer (aperte 1)\n * PlayerxComputer (aperte 2)\n");
        scanf ("%d",&mododejogo);
    } while (mododejogo != 1 && mododejogo != 2);

    char inicio;
    do {
        printf ("Pressione S para iniciar...\n");
        scanf (" %c",&inicio);
    } while (inicio != 'S' && inicio != 's');
    system("cls");

    int i,pontuacao1=0,pontuacao2=0;
    if (mododejogo ==1){
        for (i=0;i<6;i++){
            printf ("<Rodada %d>\n\n",i+1);
            if (i%2==0){
                printf ("PLAYER1, faca sua jogada:\n");
                pontuacao1 += jogada();
                printf ("Pontuacao total: %d\n",pontuacao1);
                printf ("Pontuacao total do adversario: %d\n",pontuacao2);
                limpar_tela();
            }
            else {
                printf ("PLAYER2, faca sua jogada:\n");
                pontuacao2 += jogada();
                printf ("Pontuacao total: %d\n",pontuacao2);
                printf ("Pontuacao total do adversario: %d\n",pontuacao1);
                limpar_tela();
            }
        }
        resultado(pontuacao1,pontuacao2);
    } else {
        for (i=0;i<6;i++){
            printf ("<Rodada %d>\n\n",i+1);
            if (i%2==0){
                printf ("PLAYER1, faca sua jogada:\n");
                pontuacao1 += jogada();
                printf ("Pontuacao total: %d\n",pontuacao1);
                printf ("Pontuacao total do adversario: %d\n",pontuacao2);
                limpar_tela();
            }
            else {
                int soupc=1;
                printf ("PLAYER2 fez sua jogada...\n");
                pontuacao2 += jogada_pc(pontuacao2,i,soupc,pontuacao1);
                printf ("Pontuacao total: %d\n",pontuacao2);
                printf ("Pontuacao total do adversario: %d\n",pontuacao1);
                limpar_tela();
            }
        }
    resultado(pontuacao1,pontuacao2);
    }
    printf ("\nDeseja jogar novamente? S ou N\n");
    scanf (" %c",&jogardnv);
    system("cls");
    }while(jogardnv != 'n' && jogardnv != 'N');
    return 0;
}
