#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolardados (int free, int rank, int doublee, int max){
    int Dado1,Dado2,escolha2,jogoudnv=0;
    char escolha1;
    printf ("Seus dados foram jogados: \n");
    srand((unsigned)time(NULL));
    Dado1 = 1 + rand() % 6;
    Dado2 = 1 + rand() % 6;

    printf ("%d e %d\n",Dado1,Dado2);
    printf ("Deseja rolar os dados novamente? S ou N\n");
    scanf (" %c",&escolha1);

    if(escolha1 == 's' || escolha1 == 'S') {
    printf ("'1' - rolar ambos '2' - rolar o primeiro '3' - para rolar o segundo\n");
    scanf ("%d",&escolha2);
    jogoudnv += 1;

    switch (escolha2){
    case 1: Dado1 = 1 + rand() % 6;
            Dado2 = 1 + rand() % 6;
            printf ("Seus dados foram jogados: \n");
            printf ("%d e %d\n",Dado1,Dado2);
            break;
    case 2:
            Dado1 = 1 + rand() % 6;
            printf ("Seus dados foram jogados: \n");
            printf ("%d e %d\n",Dado1,Dado2);
            break;
    case 3:
            Dado2 = 1 + rand() % 6;
            printf ("Seus dados foram jogados: \n");
            printf ("%d e %d\n",Dado1,Dado2);
            break;
    default:printf ("Jogada invalida\n");
    }
    }

    int pontuacao;
    pontuacao = jogada(Dado1, Dado2, jogoudnv,free,rank,doublee,max);
    return pontuacao;
}

/*void dados(){
    printf ("------\n")

    switch (){
        case 1: printf ("")

*/

}
int jogada (int Dado1, int Dado2, int jogoudnv, int free, int rank, int doublee, int max){
    char escolha;
    int pontuacao=0, anular=0;

    if(!(free==0||((Dado2 == Dado1+1 || Dado1 == Dado2+1) && rank==0)||(Dado1 == Dado2 && Dado1 != 6 && doublee==0)||(Dado1 == Dado2 && Dado1 == 6 && max==0))==1){
        anular=1;
    }

    if(anular==0){
        printf ("Marque uma das seguintes posicoes na tabela: ");
    }
    else{
        printf("Marque uma posicao para anular: ");
    }

    if(anular==0){
        if (free==0) {printf ("F ");}
        if (rank==0 && (Dado2 == Dado1+1 || Dado1 == Dado2+1)) {printf ("R ");}
        if (doublee==0 && (Dado1 == Dado2 && Dado1 != 6)) {printf ("D ");}
        if (max==0 && (Dado1 == Dado2 && Dado1 == 6)) {printf ("M ");}
        printf ("\n");
        scanf (" %c",&escolha);
        switch (escolha){
        case 'F':
            pontuacao = Dado1 + Dado2;
            free += 1;
            break;

        case 'R':
            if(Dado2 == Dado1+1 || Dado1 == Dado2+1){
                if (jogoudnv == 0){
                    pontuacao += 25;}
                else {pontuacao += 20;}
            rank += 1;
            }else {printf ("Escolha invalida, fim de jogo!"); return 0;}
            break;

        case 'D':
            if (Dado1 == Dado2 && Dado1 != 6){
                if (jogoudnv == 0) {
                    pontuacao += 35;}
                else {pontuacao += 30;}
            doublee += 1;
            }else {printf ("Escolha invalida, fim de jogo!");return 0;}
            break;

        case 'M':
            if (Dado1 == Dado2 && Dado1 == 6){
                if (jogoudnv == 0) {
                    pontuacao += 55;}
                else {pontuacao += 50;}
            max += 1;}
            else {printf ("Escolha invalida, fim de jogo!");return 0;}
            break;
        }
    }
    else{
        if (free==0) {printf ("F ");}
        if (rank==0) {printf ("R ");}
        if (doublee==0) {printf ("D ");}
        if (max==0) {printf ("M ");}
        printf ("\n");
        scanf (" %c",&escolha);
        switch (escolha){
            case 'F':
                pontuacao = -1;
                free += 1;
                break;

            case 'R':
                pontuacao = -2;
                rank += 1;
                break;

            case 'D':
                pontuacao = -3;
                doublee += 1;
                break;

            case 'M':
                pontuacao = -4;
                max += 1;
                break;
        }
    }
    if (pontuacao<0){
            printf ("Pontuacao da rodada: 0\n\n");}
    else {
    printf ("Pontuacao da rodada: %d\n\n",pontuacao);}
    return pontuacao;
}

char analisedados (int Dado1, int Dado2, int free, int rank, int doublee, int max){
    if (Dado1 == 6 && Dado1 == Dado2 && max == 0){
        return 'N';
    } else if ((Dado2 == Dado1+1 || Dado1 == Dado2+1) && rank == 0){
        return 'N';
    } else if (Dado1 == Dado2 && Dado1 != 6 && doublee == 0){
        return 'N';
    } else if ((Dado1 + Dado2) <= 6 || free == 1){
        return 'S';
    } else {return 'N';}

}

int rolardadosjogada_pc(int free, int rank, int doublee, int max){
    int Dado1,Dado2,jogoudnv=0;
    char teste1;
    printf ("Os dados do P2 foram jogados: \n");
    srand((unsigned)time(NULL));
    Dado1 = 1 + rand() % 6;
    Dado2 = 1 + rand() % 6;
    printf ("%d e %d\n",Dado1,Dado2);

    teste1 = analisedados(Dado1,Dado2,free,rank,doublee,max);

    if( teste1 == 'S') {
    jogoudnv += 1;
    printf ("Os dados do P2 foram jogados novamente: \n");
    Dado1 = 1 + rand() % 6;
    Dado2 = 1 + rand() % 6;
    printf ("%d e %d\n",Dado1,Dado2);}

    int pontuacao=0,anular=0;

    if(!(free==0||(Dado2 == Dado1+1 || Dado1 == Dado2+1 && rank==0)||(Dado1 == Dado2 && Dado1 != 6 && doublee==0)||(Dado1 == Dado2 && Dado1 == 6 && max==0))==1){
        anular=1;
    }

    if(anular==0){
        printf ("P2 deve marcar uma das seguintes posicoes na tabela: ");
    }
    else{
        printf("P2 deve marcar uma posicao para anular: ");
    }

    if(anular==0){
        if (free==0) {printf ("F ");}
        if (rank==0 && (Dado2 == Dado1+1 || Dado1 == Dado2+1)) {printf ("R ");}
        if (doublee==0 && (Dado1 == Dado2 && Dado1 != 6)) {printf ("D ");}
        if (max==0 && (Dado1 == Dado2 && Dado1 == 6)) {printf ("M ");}
        printf ("\n");
        if(Dado2 == Dado1+1 || Dado1 == Dado2+1){
            if (jogoudnv == 0){
                pontuacao += 25;}
            else {pontuacao += 20;}
            rank += 1;
        }else if (Dado1 == Dado2 && Dado1 != 6){
            if (jogoudnv == 0) {
                pontuacao += 35;}
            else {pontuacao += 30;}
            doublee += 1;
        }else if (Dado1 == Dado2 && Dado1 == 6){
            if (jogoudnv == 0) {
                pontuacao += 55;}
            else {pontuacao += 50;}
            max += 1;}
        else {
            pontuacao = Dado1 + Dado2;
            free += 1;
        }
    }
    else{
        if (free==0) {printf ("F ");}
        if (rank==0) {printf ("R ");}
        if (doublee==0) {printf ("D ");}
        if (max==0) {printf ("M ");}
        printf ("\n");
        if (max ==0){
                pontuacao = -4;
                max += 1;
         } else if (doublee == 0){
                pontuacao = -3;
                doublee += 1;
         } else if (rank == 0){
                pontuacao = -2;
                rank += 1;
         } else {
                pontuacao = -1;
                free += 1;
         }
        }
    if (pontuacao<0){
            printf ("Pontuacao da rodada: 0\n\n");}
    else {
    printf ("Pontuacao da rodada: %d\n\n",pontuacao);}
    return pontuacao;
}

char analise (int pontuacao){
      if(pontuacao == -1){
        return 'F';
      }
      if(pontuacao == -2){
        return 'R';
      }
      if(pontuacao == -3){
        return 'D';
      }
      if(pontuacao == -4){
        return 'M';
      }

      if (pontuacao<20){
            return 'F';
      } else if (pontuacao<30) {
            return 'R';
      } else if (pontuacao<40){
            return 'D';
      }
      return 'M';
}

void tabela_user (int p1, int p2, int p3, int p4, int ptotal){
    char c1[3],c2[3],c3[3],c4[3];
    if (p1<0){
    sprintf(c1,"%c",'-');}
    else{sprintf (c1,"%d",p1);}
    if (p2<0){
    sprintf(c2,"%c",'-');}
    else{sprintf (c2,"%d",p2);}
    if (p3<0){
    sprintf(c3,"%c",'-');}
    else{sprintf (c3,"%d",p3);}
    if (p4<0){
    sprintf(c4,"%c",'-');}
    else{sprintf (c4,"%d",p4);}
    printf ("\tTABELA DA PARTIDA\n");
    printf ("\tFREE\tRANK\tDOUBLE\tMAX\n");
    printf("PLAYER1\t%s\t%s\t%s\t%s\tPontuacao total: %d",c1,c2,c3,c4,ptotal);
}

void tabela_pc (int p1, int p2, int p3, int p4, int ptotal){
    char c1[3],c2[3],c3[3],c4[3];
    if (p1<0){
    sprintf(c1,"%c",'-');}
    else{sprintf (c1,"%d",p1);}
    if (p2<0){
    sprintf(c2,"%c",'-');}
    else{sprintf (c2,"%d",p2);}
    if (p3<0){
    sprintf(c3,"%c",'-');}
    else{sprintf (c3,"%d",p3);}
    if (p4<0){
    sprintf(c4,"%c",'-');}
    else{sprintf (c4,"%d",p4);}
    printf ("\tTABELA DA PARTIDA\n");
    printf ("\tFREE\tRANK\tDOUBLE\tMAX\n");
    printf("PLAYER2\t%s\t%s\t%s\t%s\tPontuacao total: %d",c1,c2,c3,c4,ptotal);
}

int main()
{
    int partida=3, rodada=8,cont1,cont2,pontuacao_user,pontuacao_pc,letra,pfinal_user=0,pfinal_pc=0;
    printf("MAIOR SOMA DE 3\n\n");

    for (cont1=0;cont1<partida;cont1++){
            int free1=0,free2=0,rank1=0,rank2=0,doublee1=0,doublee2=0,max1=0,max2=0,p1=0,p1pc=0,p2pc=0,p3pc=0,p4pc=0,p2=0,p3=0,p4=0,ptotal=0,iniciar=0,ptotal_pc=0;
            for (cont2=0;cont2<rodada;cont2++){
                int continuar=0;
                if (cont2%2==0){
                printf ("Partida %d de 3\nRodada %d\nTurno PLAYER1\n\n",cont1+1,cont2+1);
                pontuacao_user = rolardados(free1,rank1,doublee1,max1);
                letra = analise(pontuacao_user);
                switch (letra){
                    case 'F': free1 = 1; p1 = pontuacao_user; break;
                    case 'R': rank1 = 1; p2 = pontuacao_user; break;
                    case 'D': doublee1 = 1; p3 = pontuacao_user; break;
                    case 'M': max1 = 1; p4 = pontuacao_user; break;
                }
                if (pontuacao_user > 0){
                    ptotal += pontuacao_user;
                }
                tabela_user(p1,p2,p3,p4,ptotal);
                }else {
                    printf ("Partida %d de 3\nRodada %d\nTurno PLAYER2\n\n",cont1+1,cont2+1);
                    pontuacao_pc = rolardadosjogada_pc(free2,rank2,doublee2,max2);
                    letra = analise(pontuacao_pc);
                    switch (letra){
                        case 'F': free2 = 1; p1pc = pontuacao_pc; break;
                        case 'R': rank2 = 1; p2pc = pontuacao_pc; break;
                        case 'D': doublee2 = 1; p3pc = pontuacao_pc; break;
                        case 'M': max2 = 1; p4pc = pontuacao_pc; break;
                    }
                    if (pontuacao_pc > 0){
                    ptotal_pc += pontuacao_pc;}
                    tabela_pc(p1pc,p2pc,p3pc,p4pc,ptotal_pc);
                }
                printf ("\n\nAperte 1 para continuar\n");
                scanf ("%d",&continuar);
                if (continuar == 1){
                    system("cls");}
            }
            printf ("Partida %d finalizada. P1 %d X P2 %d\n\n",cont1+1,ptotal,ptotal_pc);
            if (ptotal < ptotal_pc){
                printf ("P2 venceu!!!\n\n");
                pfinal_pc +=1;
            } else {
                if ( ptotal == ptotal_pc){ printf ("Empate!!!\n\n");}
                else { printf ("P1 venceu!!!\n\n");
                        pfinal_user +=1;}
            }
            if (cont1 <2){
            printf ("Pressione 1 para iniciar a proxima partida\n");}
            else {printf ("Pressione 1 para revelar o campeao\n");}
            scanf ("%d",&iniciar);
            if (iniciar ==1){
                system("cls");}
    }
    printf ("O torneio chegou ao fim! ");
    if (pfinal_pc > pfinal_user){printf ("O vencedor foi o PLAYER2!\n");}
    else {printf ("O vencedor foi o PLAYER1!\n");}
    return 0;
}
