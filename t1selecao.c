#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Venda de passagens T1

int main()
{
    int numpass, cod, ida, pontuacaoint, escolha;
    char seg, idavol;
    float valorbase, valordesconto, valorseg, valorfinal, percentdif, pontuacao, valorpassagem, taxa;

    printf ("Bem vindo a pagina de compra de passagens da estacao rodoviaria!\n\n");
    printf ("Informe o numero de passagens a serem compradas: ");
    scanf ("%d",&numpass);
        if (numpass < 1) {
            printf ("A quantidade de passagens eh invalida\n"); return 0;}

    printf ("Qual o codigo do destino da viagem?\n1 - Litoral 2 - Capital 3 - Serra\n4 - Fronteira 5 - Interestadual\n");
    scanf ("%d",&cod);
        if ((cod < 1) || (cod > 5)) {
                printf ("Codigo do destino da viagem invalido. Tente novamente!\n"); return 0;}

    printf ("Sua(s) passagem(ns) inclui(em) seguro? S - sim ou N - nao\n");
    scanf (" %char",&seg);
    printf ("Sua compra inclui ida e volta? S - sim ou N - nao\n");
    scanf (" %c",&idavol);


    if ((idavol == 'S') || (idavol == 's')){
        ida = 2;
        taxa = 1.50*numpass;
    } else {
        ida = 1;
        taxa = 0;}

    switch (cod) {
        case 1: valorbase = 216.72 * numpass * ida;
            valorpassagem = 216.72;
        break;
        case 2: valorbase = 157.36 * numpass * ida;
            valorpassagem = 157.36;
        break;
        case 3: valorbase = 182.19 * numpass * ida;
            valorpassagem = 182.19;
        break;
        case 4: valorbase = 259.41 * numpass * ida;
            valorpassagem = 259.41;
        break;
        case 5: valorbase = 368.92 * numpass * ida;
            valorpassagem = 368.92;
        break;
        default: printf ("Codigo do destino da viagem invalido. Tente novamente!\n"); return 0;
    }

    switch (numpass) {
        case 1: valordesconto = 0;
            break;
        case 2: valordesconto = ((valorpassagem *0.91) + valorpassagem)*ida;
            break;
        case 3: valordesconto = (((valorpassagem*0.89) + (valorpassagem*0.87) + valorpassagem))*ida;
            break;
        case 4: valordesconto = ((valorpassagem) + ((3*valorpassagem)*0.85)) *ida;
            break;
        default: if (numpass >=5) {
                    valordesconto = (valorpassagem*numpass*ida)*0.84;}
    }

    if ((seg == 'S') || (seg == 's')) {
            valorseg = (0.0216*valorpassagem)*numpass;
    } else { valorseg = 0;}

    if (valordesconto == 0) {
            valorfinal = valorbase + valorseg + taxa;
    } else {
            valorfinal = valordesconto + valorseg + taxa;}

    percentdif = ((valorbase - valorfinal)/valorbase) *100;
    pontuacao = floor(valorfinal/120);
    pontuacaoint = pontuacao;

    printf ("O valor base da compra, sem acrescimos ou descontos, eh %.2f\n",valorbase);

        if (valordesconto != 0) {
            printf ("O valor da compra, considerando o desconto do combo, eh %.2f\n",valordesconto);
            printf ("O valor do desconto eh %.2f\n",valorbase-valordesconto); }

        if (valorseg != 0) {
            printf ("O valor da compra, considerando o acrescimo do seguro, eh %.2f\n",valordesconto+valorseg);
            printf ("O valor do seguro eh %.2f\n",valorseg); }

    printf ("O valor final da compra eh %.2f\n",valorfinal);
    printf ("O percentual de diferenca entre o valor base e o valor final eh %.2f%%\n",percentdif);
    printf ("A pontuacao obtida na compra eh %.2f\n",pontuacao);

    switch (pontuacaoint) {
        case 0: case 1: printf ("Voce nao tem direito a nenhum bonus :(\n"); break;
        case 2: case 3: printf ("Escolha seu premio: 1 - barra de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 4: printf ("Escolha seu premio:\n1 - 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 5: printf ("Escolha seu premio:\n1 - garrafa de agua\n2 - 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 6: printf ("Escolha seu premio:\n1 - 3 barras de cereal\n2 - garrafa de agua\n");
                        scanf("%d",&escolha);
                        break;
        case 7: printf ("Escolha seu premio:\n1 - 3 barras de cereal\n2 - garrafa de agua e barra de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 8: printf ("Escolha seu premio:\n1 - 4 barras de cereal\n2 - garrafa de agua e barra de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 9: printf ("Escolha seu premio:\n1 - 4 barras de cereal\n2 - garra de agua e 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 10: printf("Escolha seu premio:\n1 - 5 barras de cereal\n2 - 2 garrafas de agua\n3 - 1 garrafa de agua e 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 11: printf("Escolha seu premio:\n1 - 5 barras de cereal\n2 - 2 garrafas de agua\n3 - 1 garrafa de agua e 3 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 12: printf("Escolha seu premio:\n1 - 6 barras de cereal\n2 - 2 garrafas de agua e 1 barra de cereal\n3 - 1 garrafa de agua e 3 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 13: printf("Escolha seu premio:\n1 - 6 barras de cereal\n2 - 2 garrafas de agua e 1 barra de cereal\n3 - 1 garrafa de agua e 4 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 14: printf("Escolha seu premio:\n1 - 7 barras de cereal\n2 - 2 garrafas de agua e 2 barras de cereal\n3 - 1 garrafa de agua e 4 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 15: printf("Escolha seu premio:\n1 - 7 barras de cereal\n2 - 3 garrafas de agua\n3 - 1 garrafa de agua e 5 barras de cereal\n4 - 2 garrafas de agua e 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 16: printf("Escolha seu premio:\n1 - 8 barras de cereal\n2 - 3 garrafas de agua\n3 - 1 garrafa de agua e 5 barras de cereal\n4 - 2 garrafas de agua e 3 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 17: printf("Escolha seu premio:\n1 - 8 barras de cereal\n2 - 3 garrafas de agua e 1 barra de cereal\n3 - 1 garrafa de agua e 6 barras de cereal\n4 - 2 garrafas de agua e 3 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 18: printf("Escolha seu premio:\n1 - 9 barras de cereal\n2 - 3 garrafas de agua e 1 barra de cereal\n3 - 1 garrafa de agua e 6 barras de cereal\n4 - 2 garrafas de agua e 4 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 19: printf("Escolha seu premio:\n1 - 9 barras de cereal\n2 - 3 garrafas de agua e 2 barras de cereal\n3 - 1 garrafa de agua e 7 barras de cereal\n4 - 2 garrafas de agua e 4 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        case 20: printf("Escolha seu premio:\n1 - 10 barras de cereal\n2 - 4 garrafas de agua\n3 - 1 garrafa de agua e 7 barras de cereal\n4 - 2 garrafas de agua e 5 barras de cereal\n3 - 3 garrafas de agua e 2 barras de cereal\n");
                        scanf("%d",&escolha);
                        break;
        default: printf ("Voce atingiu uma quantidade alta de pontos, pegue garrafas de agua e barras de cereal a vontade! (valido apenas para o que for consumido durante a viagem)\n");
                        break;
        }
        printf ("Compra concluida :D\n");
    return 0;
}
