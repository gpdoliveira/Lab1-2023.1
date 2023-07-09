#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MENU_FILE "1.png"
#define HELP_FILE "2.png"
#define RECORD_FILE "3.png"
#define JOGO_FILE "4.png"
#define SAIR_FILE "5.png"
#define OVER_FILE "6.png"
#define D0_FILE "dado0.png"
#define D1_FILE "dado1.png"
#define D2_FILE "dado2.png"
#define D3_FILE "dado3.png"
#define D4_FILE "dado4.png"
#define D5_FILE "dado5.png"
#define D6_FILE "dado6.png"

#define TAMXTELA 1080
#define TAMYTELA 720
#define XXMENU 991
#define YXMENU 92
#define RXMENU 36
#define XhelpMENU 89
#define YhelpMENU 92
#define RhelpMENU 36
#define X1menu 390
#define X2menu 690
#define Y1menu 530
#define Y2menu 621
#define Y1menuj 270
#define Y2menuj 360
#define X1sair 387
#define X2sair 693
#define Y1sair 414
#define Y2sair 487
#define dadodiff 90
#define xSomaC 390
#define ySomaC 45
#define xSomaL 815
#define ySomaL 112
#define y1Girar 632
#define y2Girar 664
#define x1SS 387
#define y1SS 293
#define x2SS 693
#define y2SS 400

struct pecaindividual{
    int valor;
    int localizacao;
};
struct pecas{
    int x,y;
    struct pecaindividual pecaunit[2][2];
    int slot;
    int clicou;
    int qtd;
    int idpeca;
};
struct tabuleiro{
    int x,y;
    int x2,y2;
    int ocupado;
    int valor;
    int id;
};
struct slot1{
    int vazio;
    int x;
    int y;
    int idpeca;
};
struct slot2{
    int vazio;
    int x;
    int y;
    int idpeca;
};
struct slot3{
    int vazio;
    int x;
    int y;
    int idpeca;
};
int pontuacao=0,lastpontuacao=0,combos=0,multilinha=0,comboseq=0;;
int tabconcluidos=0,bombasdisp=0,undodisp=0,girardisp=0;
ALLEGRO_BITMAP *menu =NULL;
ALLEGRO_BITMAP *help =NULL;
ALLEGRO_BITMAP *record =NULL;
ALLEGRO_BITMAP *jogo =NULL;
ALLEGRO_BITMAP *sair =NULL;
ALLEGRO_BITMAP *over =NULL;
ALLEGRO_BITMAP *dado0 =NULL;
ALLEGRO_BITMAP *dado1 =NULL;
ALLEGRO_BITMAP *dado2 =NULL;
ALLEGRO_BITMAP *dado3 =NULL;
ALLEGRO_BITMAP *dado4 =NULL;
ALLEGRO_BITMAP *dado5 =NULL;
ALLEGRO_BITMAP *dado6 =NULL;

void alocaImagens(){
    menu = al_load_bitmap(MENU_FILE);
    help = al_load_bitmap(HELP_FILE);
    record = al_load_bitmap(RECORD_FILE);
    jogo = al_load_bitmap(JOGO_FILE);
    sair = al_load_bitmap(SAIR_FILE);
    over = al_load_bitmap(OVER_FILE);
    dado0 = al_load_bitmap(D0_FILE);
    dado1 = al_load_bitmap(D1_FILE);
    dado2 = al_load_bitmap(D2_FILE);
    dado3 = al_load_bitmap(D3_FILE);
    dado4 = al_load_bitmap(D4_FILE);
    dado5 = al_load_bitmap(D5_FILE);
    dado6 = al_load_bitmap(D6_FILE);
}

void linhasApaga(int lin, struct tabuleiro matriztab[5][5], struct pecas *vetordepecas, int contadorpecas ){

    switch (lin){
        case 0:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==1 || vetordepecas[i].pecaunit[a][b].localizacao==2 || vetordepecas[i].pecaunit[a][b].localizacao==3 || vetordepecas[i].pecaunit[a][b].localizacao==4 || vetordepecas[i].pecaunit[a][b].localizacao==5){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 1:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==6 || vetordepecas[i].pecaunit[a][b].localizacao==7 || vetordepecas[i].pecaunit[a][b].localizacao==8 || vetordepecas[i].pecaunit[a][b].localizacao==9 || vetordepecas[i].pecaunit[a][b].localizacao==10){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 2:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==11 || vetordepecas[i].pecaunit[a][b].localizacao==12 || vetordepecas[i].pecaunit[a][b].localizacao==13 || vetordepecas[i].pecaunit[a][b].localizacao==14 || vetordepecas[i].pecaunit[a][b].localizacao==15){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 3:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==16 || vetordepecas[i].pecaunit[a][b].localizacao==17 || vetordepecas[i].pecaunit[a][b].localizacao==18 || vetordepecas[i].pecaunit[a][b].localizacao==19 || vetordepecas[i].pecaunit[a][b].localizacao==20){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 4:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==21 || vetordepecas[i].pecaunit[a][b].localizacao==22 || vetordepecas[i].pecaunit[a][b].localizacao==23 || vetordepecas[i].pecaunit[a][b].localizacao==24 || vetordepecas[i].pecaunit[a][b].localizacao==25){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
    }
}

void colunasApaga(int col, struct tabuleiro matriztab[5][5], struct pecas *vetordepecas, int contadorpecas){

    switch (col){
        case 0:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==1 || vetordepecas[i].pecaunit[a][b].localizacao==6 || vetordepecas[i].pecaunit[a][b].localizacao==11 || vetordepecas[i].pecaunit[a][b].localizacao==16 || vetordepecas[i].pecaunit[a][b].localizacao==21){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 1:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==2 || vetordepecas[i].pecaunit[a][b].localizacao==7 || vetordepecas[i].pecaunit[a][b].localizacao==12 || vetordepecas[i].pecaunit[a][b].localizacao==17 || vetordepecas[i].pecaunit[a][b].localizacao==22){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 2:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==3 || vetordepecas[i].pecaunit[a][b].localizacao==8|| vetordepecas[i].pecaunit[a][b].localizacao==13 || vetordepecas[i].pecaunit[a][b].localizacao==18 || vetordepecas[i].pecaunit[a][b].localizacao==23){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 3:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==4 || vetordepecas[i].pecaunit[a][b].localizacao==9 || vetordepecas[i].pecaunit[a][b].localizacao==14 || vetordepecas[i].pecaunit[a][b].localizacao==19 || vetordepecas[i].pecaunit[a][b].localizacao==24){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
        case 4:
        for (int i=0;i<contadorpecas;i++){
            for (int a=0;a<2;a++){
                for (int b=0;b<2;b++){
                    if (vetordepecas[i].pecaunit[a][b].localizacao==5 || vetordepecas[i].pecaunit[a][b].localizacao==10 || vetordepecas[i].pecaunit[a][b].localizacao==15 || vetordepecas[i].pecaunit[a][b].localizacao==20 || vetordepecas[i].pecaunit[a][b].localizacao==25){
                        vetordepecas[i].pecaunit[a][b].localizacao=-1;
                    }
                }
            }
        }
        break;
    }
}

void printaPeca(struct pecas *vetordepecas,int contadordepecas) {
    if (vetordepecas[contadordepecas].pecaunit[0][0].localizacao!=-1){
        switch (vetordepecas[contadordepecas].pecaunit[0][0].valor){
        case 0:
            al_draw_bitmap(dado0,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 1:
            al_draw_bitmap(dado1,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 2:
            al_draw_bitmap(dado2,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 3:
            al_draw_bitmap(dado3,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 4:
            al_draw_bitmap(dado4,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 5:
            al_draw_bitmap(dado5,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        case 6:
            al_draw_bitmap(dado6,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y,1);
            break;
        }
    }

    if (vetordepecas[contadordepecas].pecaunit[0][1].localizacao!=-1){
        switch (vetordepecas[contadordepecas].pecaunit[0][1].valor){
        case 0:
            al_draw_bitmap(dado0,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 1:
            al_draw_bitmap(dado1,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 2:
            al_draw_bitmap(dado2,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 3:
            al_draw_bitmap(dado3,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 4:
            al_draw_bitmap(dado4,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 5:
            al_draw_bitmap(dado5,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        case 6:
            al_draw_bitmap(dado6,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y,1);
            break;
        }
    }

    if (vetordepecas[contadordepecas].pecaunit[1][0].localizacao!=-1){
        switch (vetordepecas[contadordepecas].pecaunit[1][0].valor){
        case 0:
            al_draw_bitmap(dado0,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 1:
            al_draw_bitmap(dado1,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 2:
            al_draw_bitmap(dado2,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 3:
            al_draw_bitmap(dado3,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 4:
            al_draw_bitmap(dado4,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 5:
            al_draw_bitmap(dado5,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 6:
            al_draw_bitmap(dado6,vetordepecas[contadordepecas].x,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        }
    }

    if (vetordepecas[contadordepecas].pecaunit[1][1].localizacao!=-1){
        switch (vetordepecas[contadordepecas].pecaunit[1][1].valor){
        case 0:
            al_draw_bitmap(dado0,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 1:
            al_draw_bitmap(dado1,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 2:
            al_draw_bitmap(dado2,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 3:
            al_draw_bitmap(dado3,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 4:
            al_draw_bitmap(dado4,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 5:
            al_draw_bitmap(dado5,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        case 6:
            al_draw_bitmap(dado6,vetordepecas[contadordepecas].x+dadodiff,vetordepecas[contadordepecas].y+dadodiff,1);
            break;
        }
    }
}

int somaC(int p,struct tabuleiro matriztab[5][5],int somacol[5],struct pecas *vetordepecas,int contadorpecas,int *vetcol,int *contvet){
    for (int i=0;i<5;i++){
        if (matriztab[i][p].valor!=-1)
        somacol[p]+=matriztab[i][p].valor;
    }
    if (somacol[p]==10){
        somacol[p]=0;
        for (int i=0;i<5;i++){
            matriztab[i][p].valor=0;
            if (matriztab[i][p].ocupado==1){
                matriztab[i][p].ocupado=0;
                lastpontuacao=pontuacao;
                pontuacao+=1;
            }
        }
        vetcol[*contvet]=p;
        (*contvet)++;
        return 1;
    }
    return 0;
}

int somaL(int p,struct tabuleiro matriztab[5][5],int somalin[5],struct pecas *vetordepecas,int contadorpecas,int *vetlin,int *contvet){
    for (int i=0;i<5;i++){
        if (matriztab[p][i].valor!=-1)
        somalin[p]+=matriztab[p][i].valor;
    }
    if (somalin[p]==10){
        somalin[p]=0;
        for (int i=0;i<5;i++){
            matriztab[p][i].valor=0;
            if (matriztab[p][i].ocupado==1){
                matriztab[p][i].ocupado=0;
                lastpontuacao=pontuacao;
                pontuacao+=1;
            }
        }
         vetlin[*contvet]=p;
        (*contvet)++;
        return 1;
    }
    return 0;
}

int calculaSomas(int somacol[5],int somalin[5],struct pecas *vetordepecas,struct tabuleiro matriztab[5][5],int contadorpecas){
    int vetlin[5],vetcol[5];
    int contvet1=0;
    int contvet2=0;
    int cont=0;

    for(int i=0;i<5;i++){
        somacol[i]=0;
        somalin[i]=0;
    }
    for (int i=0;i<5;i++){
        cont+=somaC(i,matriztab,somacol,vetordepecas,contadorpecas,vetcol,&contvet1);
        cont+=somaL(i,matriztab,somalin,vetordepecas,contadorpecas,vetlin,&contvet2);
    }

    if (cont>0){
        if (cont>=2){
            multilinha++;
            pontuacao+=7*cont;
        }

        for (int i=0;i<contvet1;i++){
            colunasApaga(vetcol[i],matriztab,vetordepecas,contadorpecas);
        }
        for (int i=0;i<contvet2;i++){
            linhasApaga(vetlin[i],matriztab,vetordepecas,contadorpecas);
        }

        if (cont==1) {
            while(calculaSomas(somacol,somalin,vetordepecas,matriztab,contadorpecas)){
                comboseq++;
                pontuacao+=5;
            }
        }
    }
    combos=multilinha+comboseq;
    return cont;
}

void verificaBonus(int *maxcombo,int *maxpont,int *maxtab){
    if (lastpontuacao!=pontuacao){
        if (combos>=*maxcombo){
            bombasdisp++;
            *maxcombo+=10;
        }
        if(pontuacao>=*maxpont){
            girardisp++;
            *maxpont+=50;
        }
        if (tabconcluidos>=*maxtab){
            undodisp++;
            *maxtab+=5;
        }
        if (undodisp>1)
            undodisp=1;
    }
}

void printaSomas (ALLEGRO_FONT* font,int somacol[5],int somalin[5]){
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC, ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", somacol[0]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+dadodiff, ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", somacol[1]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(2*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", somacol[2]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(3*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", somacol[3]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(4*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", somacol[4]);

    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL, ALLEGRO_ALIGN_CENTRE, "%d", somalin[0]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+dadodiff, ALLEGRO_ALIGN_CENTRE, "%d", somalin[1]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(2*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", somalin[2]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(3*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", somalin[3]);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(4*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", somalin[4]);
}

int ehGameOver(struct tabuleiro matriztab[5][5], struct pecas *vetordepecas, struct slot1 *s1){
    int i,j,casasvazias=0,casasduplasvazias=0,casastriplasvazias=0;

    if (!(bombasdisp>0 || undodisp>0 || girardisp>0)){
        switch (vetordepecas[s1->idpeca].qtd){
            case 1:
                if (s1->vazio==0){
                    return 1;
                }
                else {
                    for (i=0;i<5;i++){
                        for (j=0;j<5;j++){
                            if (matriztab[i][j].ocupado==0){
                                casasvazias++;
                            }
                        }
                    }
                    if (casasvazias==0){
                        return 1;
                    }
                }
            break;
            case 2:
                if (s1->vazio==0){
                    return 1;
                }
                else {
                    if (vetordepecas[s1->idpeca].pecaunit[0][1].valor!=-1){
                        for (i=0;i<5;i++){
                            for (j=0;j<4;j++){
                                if (matriztab[i][j].ocupado==0){
                                    if (matriztab[i][j+1].ocupado==0){
                                        casasduplasvazias++;
                                    }
                                }
                            }
                        }
                        if (casasduplasvazias==0){
                            return 1;
                        }
                    } else {
                        for (i=0;i<4;i++){
                            for (j=0;j<5;j++){
                                if (matriztab[i][j].ocupado==0){
                                    if (matriztab[i+1][j].ocupado==0){
                                        casasduplasvazias++;
                                    }
                                }
                            }
                        }
                        if (casasduplasvazias==0){
                            return 1;
                        }
                    }
                }
            break;
            case 3:
                if (s1->vazio==0){
                    return 1;
                } else {
                    if (vetordepecas[s1->idpeca].pecaunit[0][1].valor!=-1 && vetordepecas[s1->idpeca].pecaunit[1][1].valor!=-1){
                        for (i=0;i<4;i++){
                            for (j=0;j<4;j++){
                                if (matriztab[i][j].ocupado==0){
                                    if (matriztab[i][j+1].ocupado==0 && matriztab[i+1][j+1].ocupado==0){
                                            casastriplasvazias++;
                                    }
                                }
                            }
                        }
                        if (casastriplasvazias==0){
                            return 1;
                        }
                    } else if (vetordepecas[s1->idpeca].pecaunit[1][0].valor!=-1 && vetordepecas[s1->idpeca].pecaunit[0][1].valor!=-1){
                        for (i=0;i<4;i++){
                            for (j=0;j<4;j++){
                                if (matriztab[i][j].ocupado==0){
                                    if (matriztab[i][j+1].ocupado==0 && matriztab[i+1][j].ocupado==0){
                                            casastriplasvazias++;
                                    }
                                }
                            }
                        }
                        if (casastriplasvazias==0){
                            return 1;
                        }
                    } else if (vetordepecas[s1->idpeca].pecaunit[1][0].valor!=-1 && vetordepecas[s1->idpeca].pecaunit[1][1].valor!=-1){
                        for (i=0;i<4;i++){
                            for (j=0;j<4;j++){
                                if (matriztab[i][j].ocupado==0){
                                    if (matriztab[i+1][j+1].ocupado==0 && matriztab[i+1][j].ocupado==0){
                                            casastriplasvazias++;
                                    }
                                }
                            }
                        }
                        if (casastriplasvazias==0){
                            return 1;
                        }
                    }
                }
            break;
        }
    }
    return 0;
}

int verificaCasat2(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    if (vetordepecas[i].pecaunit[0][1].valor!=-1){
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a][b+1].x && vetordepecas[i].x+87.8 < matriztab[a][b+1].x2 && vetordepecas[i].y > matriztab[a][b+1].y && vetordepecas[i].y < matriztab[a][b+1].y2 && matriztab[a][b+1].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                    matriztab[a][b].ocupado=1;
                    vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                    matriztab[a][b+1].valor=vetordepecas[i].pecaunit[0][1].valor;
                    matriztab[a][b+1].ocupado=1;
                    vetordepecas[i].pecaunit[0][1].localizacao=matriztab[a][b+1].id;
                    vetordepecas[i].clicou=0;
                    switch(vetordepecas[i].slot){
                        case 1:
                            s1->vazio=0;
                            break;
                        case 2:
                            s2->vazio=0;
                            break;
                        case 3:
                            s3->vazio=0;
                            break;
                    }
                    vetordepecas[i].slot=0;
                    encontrou=1;
                }
            }
        }
        if (encontrou==0){
            switch(vetordepecas[i].slot){
                case 1:
                    vetordepecas[i].x=s1->x;
                    vetordepecas[i].y=s1->y;
                    break;
                case 2:
                    vetordepecas[i].x=s2->x;
                    vetordepecas[i].y=s2->y;
                    break;
                case 3:
                    vetordepecas[i].x=s3->x;
                    vetordepecas[i].y=s3->y;
                    break;
            }
            vetordepecas[i].clicou=0;
        }
    } else if (vetordepecas[i].pecaunit[1][0].valor!=-1){
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                    matriztab[a][b].ocupado=1;
                    vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                    matriztab[a+1][b].valor=vetordepecas[i].pecaunit[1][0].valor;
                    matriztab[a+1][b].ocupado=1;
                    vetordepecas[i].pecaunit[1][0].localizacao=matriztab[a+1][b].id;
                    vetordepecas[i].clicou=0;
                    switch(vetordepecas[i].slot){
                        case 1:
                            s1->vazio=0;
                            break;
                        case 2:
                            s2->vazio=0;
                            break;
                        case 3:
                            s3->vazio=0;
                            break;
                    }
                    vetordepecas[i].slot=0;
                    encontrou=1;
                }
            }
        }
        if (encontrou==0){
            switch(vetordepecas[i].slot){
                case 1:
                    vetordepecas[i].x=s1->x;
                    vetordepecas[i].y=s1->y;
                    break;
                case 2:
                    vetordepecas[i].x=s2->x;
                    vetordepecas[i].y=s2->y;
                    break;
                case 3:
                    vetordepecas[i].x=s3->x;
                    vetordepecas[i].y=s3->y;
                    break;
            }
            vetordepecas[i].clicou=0;
        }
    }
    return encontrou;
}

int verificaCasat3(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    if(vetordepecas[i].pecaunit[0][0].valor==-1){
        printf("oii");
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x+87.8 > matriztab[a][b+3].x && vetordepecas[i].x+87.8 < matriztab[a][b+3].x2
                     && vetordepecas[i].y > matriztab[a][b+3].y && vetordepecas[i].y < matriztab[a][b+3].y2 && matriztab[a][b+3].ocupado==0
                     && vetordepecas[i].x+87.8 > matriztab[a+1][b+3].x && vetordepecas[i].x+87.8 < matriztab[a+1][b+3].x2
                     && vetordepecas[i].y+87.8 > matriztab[a+1][b+3].y && vetordepecas[i].y+87.8 < matriztab[a+1][b+3].y2 && matriztab[a+1][b+3].ocupado==0
                    && vetordepecas[i].x > matriztab[a+1][b+2].x && vetordepecas[i].x < matriztab[a+1][b+2].x2 &&
                    vetordepecas[i].y+87.8 > matriztab[a+1][b+2].y && vetordepecas[i].y+87.8 < matriztab[a+1][b+2].y2 && matriztab[a+1][b+2].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b+2].x;
                    vetordepecas[i].y=matriztab[a][b+2].y;
                    matriztab[a][b+2].valor=vetordepecas[i].pecaunit[0][1].valor;
                    matriztab[a][b+3].ocupado=1;
                    vetordepecas[i].pecaunit[0][1].localizacao=matriztab[a][b+2].id;
                    matriztab[a+1][b+2].valor=vetordepecas[i].pecaunit[1][1].valor;
                    matriztab[a+1][b+3].ocupado=1;
                    vetordepecas[i].pecaunit[1][1].localizacao=matriztab[a+1][b+2].id;
                    matriztab[a+1][b+1].valor=vetordepecas[i].pecaunit[1][0].valor;
                    matriztab[a+1][b+2].ocupado=1;
                    vetordepecas[i].pecaunit[1][0].localizacao=matriztab[a+1][b+1].id;
                    vetordepecas[i].clicou=0;
                    switch(vetordepecas[i].slot){
                        case 1:
                            s1->vazio=0;
                            break;
                        case 2:
                            s2->vazio=0;
                            break;
                        case 3:
                            s3->vazio=0;
                            break;
                    }
                    vetordepecas[i].slot=0;
                    encontrou=1;
                }
            }
        }
        if (encontrou==0){
            switch(vetordepecas[i].slot){
                case 1:
                    vetordepecas[i].x=s1->x;
                    vetordepecas[i].y=s1->y;
                    break;
                case 2:
                    vetordepecas[i].x=s2->x;
                    vetordepecas[i].y=s2->y;
                    break;
                case 3:
                    vetordepecas[i].x=s3->x;
                    vetordepecas[i].y=s3->y;
                    break;
            }
            vetordepecas[i].clicou=0;
        }
    } else
    if (vetordepecas[i].pecaunit[0][1].valor!=-1){
        if (vetordepecas[i].pecaunit[1][0].valor!=-1){
            for (a=0;a<5;a++){
                for (b=0;b<5;b++){
                    if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a][b+1].x && vetordepecas[i].x+87.8 < matriztab[a][b+1].x2 && vetordepecas[i].y > matriztab[a][b+1].y && vetordepecas[i].y < matriztab[a][b+1].y2 && matriztab[a][b+1].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                        vetordepecas[i].x=matriztab[a][b].x;
                        vetordepecas[i].y=matriztab[a][b].y;
                        matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                        matriztab[a][b].ocupado=1;
                        vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                        matriztab[a][b+1].valor=vetordepecas[i].pecaunit[0][1].valor;
                        matriztab[a][b+1].ocupado=1;
                        vetordepecas[i].pecaunit[0][1].localizacao=matriztab[a][b+1].id;
                        matriztab[a+1][b].valor=vetordepecas[i].pecaunit[1][0].valor;
                        matriztab[a+1][b].ocupado=1;
                        vetordepecas[i].pecaunit[1][0].localizacao=matriztab[a+1][b].id;
                        vetordepecas[i].clicou=0;
                        switch(vetordepecas[i].slot){
                            case 1:
                                s1->vazio=0;
                                break;
                            case 2:
                                s2->vazio=0;
                                break;
                            case 3:
                                s3->vazio=0;
                                break;
                        }
                        vetordepecas[i].slot=0;
                        encontrou=1;
                    }
                }
            }
            if (encontrou==0){
                switch(vetordepecas[i].slot){
                    case 1:
                        vetordepecas[i].x=s1->x;
                        vetordepecas[i].y=s1->y;
                        break;
                    case 2:
                        vetordepecas[i].x=s2->x;
                        vetordepecas[i].y=s2->y;
                        break;
                    case 3:
                        vetordepecas[i].x=s3->x;
                        vetordepecas[i].y=s3->y;
                        break;
                }
                vetordepecas[i].clicou=0;
            }
        } else {
            for (a=0;a<5;a++){
                for (b=0;b<5;b++){
                    if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a][b+1].x && vetordepecas[i].x+87.8 < matriztab[a][b+1].x2 && vetordepecas[i].y > matriztab[a][b+1].y && vetordepecas[i].y < matriztab[a][b+1].y2 && matriztab[a][b+1].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a+1][b+1].x && vetordepecas[i].x+87.8 < matriztab[a+1][b+1].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b+1].y && vetordepecas[i].y+87.8 < matriztab[a+1][b+1].y2 && matriztab[a+1][b+1].ocupado==0){
                        vetordepecas[i].x=matriztab[a][b].x;
                        vetordepecas[i].y=matriztab[a][b].y;
                        matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                        matriztab[a][b].ocupado=1;
                        vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                        matriztab[a][b+1].valor=vetordepecas[i].pecaunit[0][1].valor;
                        matriztab[a][b+1].ocupado=1;
                        vetordepecas[i].pecaunit[0][1].localizacao=matriztab[a][b+1].id;
                        matriztab[a+1][b+1].valor=vetordepecas[i].pecaunit[1][1].valor;
                        matriztab[a+1][b+1].ocupado=1;
                        vetordepecas[i].pecaunit[1][1].localizacao=matriztab[a+1][b+1].id;
                        vetordepecas[i].clicou=0;
                        switch(vetordepecas[i].slot){
                            case 1:
                                s1->vazio=0;
                                break;
                            case 2:
                                s2->vazio=0;
                                break;
                            case 3:
                                s3->vazio=0;
                                break;
                        }
                        vetordepecas[i].slot=0;
                        encontrou=1;
                    }
                }
            }
            if (encontrou==0){
                switch(vetordepecas[i].slot){
                    case 1:
                        vetordepecas[i].x=s1->x;
                        vetordepecas[i].y=s1->y;
                        break;
                    case 2:
                        vetordepecas[i].x=s2->x;
                        vetordepecas[i].y=s2->y;
                        break;
                    case 3:
                        vetordepecas[i].x=s3->x;
                        vetordepecas[i].y=s3->y;
                        break;
                }
                vetordepecas[i].clicou=0;
            }
        }
    } else if (vetordepecas[i].pecaunit[1][0].valor!=-1){
        if (vetordepecas[i].pecaunit[1][1].valor!=-1){
            for (a=0;a<5;a++){
                for (b=0;b<5;b++){
                    if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a+1][b+1].x && vetordepecas[i].x+87.8 < matriztab[a+1][b+1].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b+1].y && vetordepecas[i].y+87.8 < matriztab[a+1][b+1].y2 && matriztab[a+1][b+1].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                        vetordepecas[i].x=matriztab[a][b].x;
                        vetordepecas[i].y=matriztab[a][b].y;
                        matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                        matriztab[a][b].ocupado=1;
                        vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                        matriztab[a+1][b].valor=vetordepecas[i].pecaunit[1][0].valor;
                        matriztab[a+1][b].ocupado=1;
                        vetordepecas[i].pecaunit[1][0].localizacao=matriztab[a+1][b].id;
                        matriztab[a+1][b+1].valor=vetordepecas[i].pecaunit[1][1].valor;
                        matriztab[a+1][b+1].ocupado=1;
                        vetordepecas[i].pecaunit[1][1].localizacao=matriztab[a+1][b+1].id;
                        vetordepecas[i].clicou=0;
                        switch(vetordepecas[i].slot){
                            case 1:
                                s1->vazio=0;
                                break;
                            case 2:
                                s2->vazio=0;
                                break;
                            case 3:
                                s3->vazio=0;
                                break;
                        }
                        vetordepecas[i].slot=0;
                        encontrou=1;
                    }
                }
            }
            if (encontrou==0){
                switch(vetordepecas[i].slot){
                    case 1:
                        vetordepecas[i].x=s1->x;
                        vetordepecas[i].y=s1->y;
                        break;
                    case 2:
                        vetordepecas[i].x=s2->x;
                        vetordepecas[i].y=s2->y;
                        break;
                    case 3:
                        vetordepecas[i].x=s3->x;
                        vetordepecas[i].y=s3->y;
                        break;
                }
                vetordepecas[i].clicou=0;
            }
        }
    }
    return encontrou;
}

int verificaCasa(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    switch (vetordepecas[i].qtd){
        case 1:
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].pecaunit[0][0].valor;
                    matriztab[a][b].ocupado=1;
                    vetordepecas[i].clicou=0;
                    vetordepecas[i].pecaunit[0][0].localizacao=matriztab[a][b].id;
                    switch(vetordepecas[i].slot){
                        case 1:
                            s1->vazio=0;
                            break;
                        case 2:
                            s2->vazio=0;
                            break;
                        case 3:
                            s3->vazio=0;
                            break;
                    }
                    vetordepecas[i].slot=0;
                    encontrou=1;
                }
            }
        }
        if (encontrou==0){
            switch(vetordepecas[i].slot){
                case 1:
                    vetordepecas[i].x=s1->x;
                    vetordepecas[i].y=s1->y;
                    break;
                case 2:
                    vetordepecas[i].x=s2->x;
                    vetordepecas[i].y=s2->y;
                    break;
                case 3:
                    vetordepecas[i].x=s3->x;
                    vetordepecas[i].y=s3->y;
                    break;
            }
            vetordepecas[i].clicou=0;
        }
            break;

        case 2:
            encontrou=verificaCasat2(vetordepecas,i,matriztab,s1,s2,s3);
            break;
        case 3:
            encontrou=verificaCasat3(vetordepecas,i,matriztab,s1,s2,s3);
            break;
    }
    return encontrou;
}

void Bomba(struct tabuleiro matriztab[5][5],struct pecas *vetordepecas,int contadorpecas){
    int col=0,lin=0,combinacao=0;

    combinacao= rand() % 3 +1;
    lin= rand() % 5;
    col= rand() % 5;

    switch (combinacao){
    case 1:
        for (int i=0;i<5;i++){
            matriztab[lin][i].valor=0;
            matriztab[lin][i].ocupado=0;

        }
        linhasApaga(lin,matriztab,vetordepecas,contadorpecas);
        if (lin==4){
            lin--;
        } else if (lin==0){
            lin++;
        } else {
            lin--;
        }
        for (int i=0;i<5;i++){
            matriztab[lin][i].valor=0;
            matriztab[lin][i].ocupado=0;

        }
        linhasApaga(lin,matriztab,vetordepecas,contadorpecas);
        break;
    case 2:
        for (int i=0;i<5;i++){
            matriztab[i][col].valor=0;
            matriztab[i][col].ocupado=0;

        }
        colunasApaga(col,matriztab,vetordepecas,contadorpecas);
        if (col==4){
            col--;
        } else if (col==0){
            col++;
        } else {
            col--;
        }
        for (int i=0;i<5;i++){
            matriztab[i][col].valor=0;
            matriztab[i][col].ocupado=0;
        }
        colunasApaga(col,matriztab,vetordepecas,contadorpecas);
        break;
    case 3:
        for (int i=0;i<5;i++){
            matriztab[lin][i].valor=0;
            matriztab[lin][i].ocupado=0;
        }
        linhasApaga(lin,matriztab,vetordepecas,contadorpecas);
        for (int i=0;i<5;i++){
            matriztab[i][col].valor=0;
            matriztab[i][col].ocupado=0;
        }
        colunasApaga(col,matriztab,vetordepecas,contadorpecas);
        break;
    }
}

void fjogarOn(int minutos,int segundos,int *contadorpecas,struct pecas *vetordepecas,ALLEGRO_FONT *font,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3,int *overOn,int *jogarOn,int somacol[5],int somalin[5]){
    al_draw_bitmap(jogo,0,0,0);
    al_draw_textf(font, al_map_rgb(0, 0, 0), 982, 240, ALLEGRO_ALIGN_CENTRE, "%d", pontuacao);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 80, 690, ALLEGRO_ALIGN_CENTRE, "Combos: %d", combos);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 260, 690, ALLEGRO_ALIGN_CENTRE, "Bombas restantes: %d", bombasdisp);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 810, 690, ALLEGRO_ALIGN_CENTRE, "Giros restantes: %d", girardisp);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 470, 690, ALLEGRO_ALIGN_CENTRE, "Tabuleiros concluidos: %d", tabconcluidos);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 650, 690, ALLEGRO_ALIGN_CENTRE, "Disponivel: %d", undodisp);
    al_draw_textf(font, al_map_rgb(0, 0, 0), 982, 430, ALLEGRO_ALIGN_CENTRE, "%d:%d", minutos, segundos);

    for (int i=0;i<*contadorpecas;i++){
        printaPeca(vetordepecas,i);
    }
    printaSomas(font,somacol,somalin);
    int teste1=0,teste2=0,teste3=0;
    if (s1->vazio==1 || s2->vazio==1 || s3->vazio==1){
        teste1 = ehGameOver(matriztab,vetordepecas,s1);
        teste2 = ehGameOver(matriztab,vetordepecas,s2);
        teste3 = ehGameOver(matriztab,vetordepecas,s3);
    }
    if (teste1==1 && teste2==1 && teste3==1){
        *jogarOn=0;
        *overOn=1;
    }
}

void inicializaTab(struct tabuleiro matriztab[5][5]){
    int xtab=342,ytab=72,casa=1;

    for (int i=0;i<5;i++){
        xtab=342;
        for (int j=0;j<5;j++){
            matriztab[i][j].ocupado=0;
            matriztab[i][j].valor=0;
            matriztab[i][j].x=xtab;
            matriztab[i][j].y=ytab;
            matriztab[i][j].x2=xtab+87.8;
            matriztab[i][j].y2=ytab+87.8;
            xtab+=87.8;
        }
        ytab+=87.8;
    }
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
             matriztab[i][j].id=casa;
             casa++;
        }
    }
}

void inicializaVPecas(struct pecas *vetordepecas){

    for(int i=0;i<200;i++){
        vetordepecas[i].pecaunit[0][0].valor = 1;
        vetordepecas[i].pecaunit[0][1].valor = rand() % 3 -1;
        vetordepecas[i].pecaunit[1][0].valor = rand() % 3 -1;
        vetordepecas[i].pecaunit[1][1].valor = rand() % 3 -1;
        vetordepecas[i].clicou=0;
        vetordepecas[i].qtd=4;
        vetordepecas[i].idpeca=i;
    }

    for(int i=0;i<200;i++){
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                if (vetordepecas[i].pecaunit[a][b].valor==0 || vetordepecas[i].pecaunit[a][b].valor==1)
                    vetordepecas[i].pecaunit[a][b].valor= rand() % 7;
            }
        }
    }

    for (int i=0;i<200;i++){
        if (vetordepecas[i].pecaunit[0][0].valor!=-1 && vetordepecas[i].pecaunit[0][1].valor!=-1 && vetordepecas[i].pecaunit[1][0].valor!=-1 && vetordepecas[i].pecaunit[1][1].valor!=-1){
            int var,var2;
            var =rand() % 2;
            var2 =rand() % 2;
            if (var==var2 && var==0){
                var2=1;
            }
            vetordepecas[i].pecaunit[var][var2].valor=-1;
        }
        if (vetordepecas[i].pecaunit[0][0].valor!=-1 && vetordepecas[i].pecaunit[0][1].valor==-1 && vetordepecas[i].pecaunit[1][0].valor==-1 && vetordepecas[i].pecaunit[1][1].valor!=-1){
            vetordepecas[i].pecaunit[0][1].valor=rand() % 7;
        }
        if (vetordepecas[i].pecaunit[0][0].valor==-1 && vetordepecas[i].pecaunit[0][1].valor!=-1 && vetordepecas[i].pecaunit[1][0].valor!=-1 && vetordepecas[i].pecaunit[1][1].valor==-1){
            vetordepecas[i].pecaunit[0][0].valor=rand() % 7;
        }
        if (vetordepecas[i].pecaunit[0][0].valor==-1 && vetordepecas[i].pecaunit[0][1].valor==-1 && vetordepecas[i].pecaunit[1][0].valor==-1 && vetordepecas[i].pecaunit[1][1].valor==-1){
            vetordepecas[i].pecaunit[0][0].valor=rand() % 7;
        }
    }

    for (int i=0;i<200;i++){
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                vetordepecas[i].pecaunit[a][b].localizacao=-1;
                if (vetordepecas[i].pecaunit[a][b].valor==-1)
                    vetordepecas[i].qtd-=1;
            }
        }
    }
}

void preencheSlots(struct pecas *vetordepecas,int *contadorpecas,struct slot1 *s1,struct slot2 *s2, struct slot3 *s3){

    vetordepecas[*contadorpecas].x = s1->x;
    vetordepecas[*contadorpecas].y = s1->y;
    vetordepecas[*contadorpecas].slot = 1;
    for (int a=0;a<2;a++){
        for (int b=0;b<2;b++){
            vetordepecas[*contadorpecas].pecaunit[a][b].localizacao=0;
        }
    }
    s1->idpeca=*contadorpecas;
    (*contadorpecas)++;
    s1->vazio=1;

    vetordepecas[*contadorpecas].x = s2->x;
    vetordepecas[*contadorpecas].y = s2->y;
    vetordepecas[*contadorpecas].slot = 2;
    for (int a=0;a<2;a++){
        for (int b=0;b<2;b++){
            vetordepecas[*contadorpecas].pecaunit[a][b].localizacao=0;
        }
    }
    s2->idpeca=*contadorpecas;
    (*contadorpecas)++;
    s2->vazio=1;

    vetordepecas[*contadorpecas].x = s3->x;
    vetordepecas[*contadorpecas].y = s3->y;
    vetordepecas[*contadorpecas].slot = 3;
    for (int a=0;a<2;a++){
        for (int b=0;b<2;b++){
            vetordepecas[*contadorpecas].pecaunit[a][b].localizacao=0;
        }
    }
    s3->idpeca=*contadorpecas;
    (*contadorpecas)++;
    s3->vazio=1;
}

void undo(struct pecas *vetordepecas, struct slot1 *s1,struct slot2 *s2,struct slot3 *s3,struct tabuleiro matriztab[5][5],int encaixou){

    if (s1->vazio==0){
        vetordepecas[encaixou].x=s1->x;
        vetordepecas[encaixou].y=s1->y;
        for (int a=0;a<5;a++){
            for (int b=0;b<5;b++){
                if (matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][1].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][1].localizacao){
                    matriztab[a][b].valor=0;
                    matriztab[a][b].ocupado=0;
                }
            }
        }
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                vetordepecas[encaixou].pecaunit[a][b].localizacao=0;
            }
        }
        s1->vazio=1;
        vetordepecas[encaixou].slot=1;
    } else if (s2->vazio==0){
        vetordepecas[encaixou].x=s2->x;
        vetordepecas[encaixou].y=s2->y;
        for (int a=0;a<5;a++){
            for (int b=0;b<5;b++){
                if (matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][1].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][1].localizacao){
                    matriztab[a][b].valor=0;
                    matriztab[a][b].ocupado=0;
                }
            }
        }
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                vetordepecas[encaixou].pecaunit[a][b].localizacao=0;
            }
        }
        s2->vazio=1;
        vetordepecas[encaixou].slot=2;
    } else if (s3->vazio==0){
        vetordepecas[encaixou].x=s3->x;
        vetordepecas[encaixou].y=s3->y;
        for (int a=0;a<5;a++){
            for (int b=0;b<5;b++){
                if (matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[0][1].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][0].localizacao || matriztab[a][b].id==vetordepecas[encaixou].pecaunit[1][1].localizacao){
                    matriztab[a][b].valor=0;
                    matriztab[a][b].ocupado=0;
                }
            }
        }
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                vetordepecas[encaixou].pecaunit[a][b].localizacao=0;
            }
        }
        s3->vazio=1;
        vetordepecas[encaixou].slot=3;
    }
}

void giraPeca(struct pecas *vetordepecas,struct slot1 *s1){
    if (s1->vazio==1){
        switch(vetordepecas[s1->idpeca].qtd){
        case 2:
            if (vetordepecas[s1->idpeca].pecaunit[1][0].valor!=-1){
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=vetordepecas[s1->idpeca].pecaunit[1][0].valor;
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=-1;
            } else if (vetordepecas[s1->idpeca].pecaunit[0][1].valor!=-1){
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=vetordepecas[s1->idpeca].pecaunit[0][0].valor;
                vetordepecas[s1->idpeca].pecaunit[0][0].valor=vetordepecas[s1->idpeca].pecaunit[0][1].valor;
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=-1;
            }
            break;
        case 3:
            if (vetordepecas[s1->idpeca].pecaunit[0][1].valor==-1){
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=vetordepecas[s1->idpeca].pecaunit[1][1].valor;
                vetordepecas[s1->idpeca].pecaunit[1][1].valor=vetordepecas[s1->idpeca].pecaunit[1][0].valor;
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=vetordepecas[s1->idpeca].pecaunit[0][0].valor;
                vetordepecas[s1->idpeca].pecaunit[0][0].valor=-1;
            } else
            if (vetordepecas[s1->idpeca].pecaunit[0][0].valor==-1){
                vetordepecas[s1->idpeca].pecaunit[0][0].valor=vetordepecas[s1->idpeca].pecaunit[0][1].valor;
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=vetordepecas[s1->idpeca].pecaunit[1][1].valor;
                vetordepecas[s1->idpeca].pecaunit[1][1].valor=vetordepecas[s1->idpeca].pecaunit[1][0].valor;
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=-1;
            } else
            if (vetordepecas[s1->idpeca].pecaunit[1][0].valor==-1){
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=vetordepecas[s1->idpeca].pecaunit[0][0].valor;
                vetordepecas[s1->idpeca].pecaunit[0][0].valor=vetordepecas[s1->idpeca].pecaunit[0][1].valor;
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=vetordepecas[s1->idpeca].pecaunit[1][1].valor;
                vetordepecas[s1->idpeca].pecaunit[1][1].valor=-1;
            } else
            if (vetordepecas[s1->idpeca].pecaunit[1][1].valor==-1){
                vetordepecas[s1->idpeca].pecaunit[1][1].valor=vetordepecas[s1->idpeca].pecaunit[1][0].valor;
                vetordepecas[s1->idpeca].pecaunit[1][0].valor=vetordepecas[s1->idpeca].pecaunit[0][0].valor;
                vetordepecas[s1->idpeca].pecaunit[0][0].valor=vetordepecas[s1->idpeca].pecaunit[0][1].valor;
                vetordepecas[s1->idpeca].pecaunit[0][1].valor=-1;
            }
            break;
        }
    }
}

void tabConc(struct tabuleiro matriztab[5][5]){
    int cont=0;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (matriztab[i][j].ocupado==0)
                cont++;
        }
    }
    if (cont==25){
        pontuacao+=10;
        tabconcluidos++;
    }
}

void reseta(int *contadorpecas,struct slot1 *s1,struct slot2 *s2,struct slot3 *s3,struct tabuleiro matriztab[5][5],int *minutos,int *segundos,int *menuOn,int *primeirotab){
    *contadorpecas=0;
    s1->vazio=0;
    s2->vazio=0;
    s3->vazio=0;
    for(int a=0;a<5;a++){
        for (int b=0;b<5;b++){
            matriztab[a][b].ocupado=0;
            matriztab[a][b].valor=0;
        }
    }
    pontuacao=0;
    *minutos=0;
    *segundos=0;
    *menuOn=1;
    *primeirotab=0;
    pontuacao=0;
    lastpontuacao=0;
    combos=0;
    tabconcluidos=0;
    bombasdisp=0;
    undodisp=0;
    girardisp=0;
}

void guardaRecord(int minutos,int segundos){
    FILE *arq;
    arq = fopen("recordtens.txt","w");

    fprintf(arq,"%d %d %d",pontuacao,minutos,segundos);
    fclose(arq);
}

void printaRecord(ALLEGRO_FONT *font){
    FILE *arq;
    arq = fopen("recordtens.txt","r");
    int ponts,mins,segs;

    fscanf(arq,"%d %d %d",&ponts,&mins,&segs);

    al_draw_textf(font, al_map_rgb(255, 255, 255), 250, 290, ALLEGRO_ALIGN_CENTRE, "Pontuacao: %d Timer: %d:%d",ponts,mins,segs);
    fclose(arq);
}

void salvaJogo(int somacol[5], int somalin[5], int contadorpecas, int minutos, int segundos, int clicou, int encaixou, int primeirotab, struct pecas *vetordepecas, struct tabuleiro matriztab[5][5], struct slot1 *s1, struct slot2 *s2, struct slot3 *s3) {
    FILE *arq;
    arq = fopen("jogosalvotens.txt", "w");

    for (int i = 0; i < 5; i++) {
        fprintf(arq,"%d ", somacol[i]);
    }
    for (int i = 0; i < 5; i++) {
        fprintf(arq,"%d ", somalin[i]);
    }
    fprintf(arq,"%d %d %d %d %d\n", pontuacao, minutos, segundos, contadorpecas, primeirotab);
    for (int i = 0; i < 200; i++) {
        fprintf(arq,"%d %d %d %d %d %d", vetordepecas[i].x, vetordepecas[i].y, vetordepecas[i].slot, vetordepecas[i].clicou, vetordepecas[i].qtd, vetordepecas[i].idpeca);
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                fprintf(arq,"%d %d", vetordepecas[i].pecaunit[a][b].valor, vetordepecas[i].pecaunit[a][b].localizacao);
            }
        }
    }
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            fprintf(arq,"%d %d %d %d %d %d %d", matriztab[a][b].x, matriztab[a][b].y, matriztab[a][b].x2, matriztab[a][b].y2, matriztab[a][b].ocupado, matriztab[a][b].valor, matriztab[a][b].id);
        }
    }
    fprintf(arq,"%d %d %d %d", s1->idpeca, s1->vazio, s1->x, s1->y);
    fprintf(arq,"%d %d %d %d", s2->idpeca, s2->vazio, s2->x, s2->y);
    fprintf(arq,"%d %d %d %d", s3->idpeca, s3->vazio, s3->x, s3->y);
    fprintf(arq,"%d %d %d %d %d %d", lastpontuacao, combos, tabconcluidos, bombasdisp, undodisp, girardisp);
    fclose(arq);
}

void continuaJogo(int *somacol, int *somalin, int *contadorpecas, int *minutos, int *segundos, int *clicou, int *encaixou, int *primeirotab, struct pecas *vetordepecas, struct tabuleiro matriztab[5][5], struct slot1 *s1, struct slot2 *s2, struct slot3 *s3) {
    FILE *arq;
    arq = fopen("jogosalvotens.txt", "r");

    for (int i = 0; i < 5; i++) {
        fscanf(arq,"%d", &somacol[i]);
    }
    for (int i = 0; i < 5; i++) {
        fscanf(arq,"%d", &somalin[i]);
    }
    fscanf(arq,"%d %d %d %d %d", &pontuacao, &minutos, &segundos, &contadorpecas,&primeirotab);
    for (int i = 0; i < 200; i++) {
        fscanf(arq,"%d %d %d %d %d %d", &vetordepecas[i].x, &vetordepecas[i].y, &vetordepecas[i].slot, &vetordepecas[i].clicou, &vetordepecas[i].qtd, &vetordepecas[i].idpeca);
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                fscanf(arq,"%d %d", &vetordepecas[i].pecaunit[a][b].valor, &vetordepecas[i].pecaunit[a][b].localizacao);
            }
        }
    }
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            fscanf(arq,"%d %d %d %d %d %d %d", &matriztab[a][b].x, &matriztab[a][b].y, &matriztab[a][b].x2, &matriztab[a][b].y2, &matriztab[a][b].ocupado, &matriztab[a][b].valor, &matriztab[a][b].id);
        }
    }
    fscanf(arq,"%d %d %d %d", &s1->idpeca, &s1->vazio, &s1->x, &s1->y);
    fscanf(arq,"%d %d %d %d", &s2->idpeca, &s2->vazio, &s2->x, &s2->y);
    fscanf(arq,"%d %d %d %d", &s3->idpeca, &s3->vazio, &s3->x, &s3->y);
    fscanf(arq,"%d %d %d %d %d %d", &lastpontuacao, &combos, &tabconcluidos, &bombasdisp, &undodisp, &girardisp);
    fclose(arq);
}

int main(void) {
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TIMER *cronometro = NULL;
    ALLEGRO_EVENT_QUEUE *fila_cronometro = NULL;

    al_init();
    al_init_font_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    ALLEGRO_SAMPLE* musica = al_load_sample("epicsong.wav");

    timer = al_create_timer(1.0/30);
    cronometro = al_create_timer(1.0);
    al_start_timer(timer);
    al_start_timer(cronometro);

    alocaImagens();

    font = al_create_builtin_font();
    fila_eventos = al_create_event_queue();
    fila_cronometro = al_create_event_queue();
    janela = al_create_display(TAMXTELA, TAMYTELA);
    al_set_window_title(janela,"TENS");

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_cronometro, al_get_timer_event_source(cronometro));

    struct slot1 s1 = {0, 23, 22};
    struct slot1 s2 = {0, 23, 207};
    struct slot1 s3 = {0, 23, 392};
    int rodando=1,situacao=0,menuOn=1,ajudaOn=0,jogarOn=0,sairOn=0,recordOn=0,overOn=0, mouseX, mouseY;
    int minutos=0,segundos=0;
    struct pecas vetordepecas[200];
    struct tabuleiro matriztab[5][5];
    int contadorpecas=0;
    int clicou=0;
    int encaixou,primeirotab=0;
    int somacol[5] = {0,0,0,0,0},somalin[5] = {0,0,0,0,0};
    int pontsmaior,minsmaior,segsmaior;
    int maxcombo=10,maxpont=50,maxtab=5;
    FILE *arq;
    arq = fopen("recordtens.txt","r");
    fscanf(arq,"%d %d %d",&pontsmaior,&minsmaior,&segsmaior);

    srand(time(NULL));

    inicializaTab(matriztab);
    inicializaVPecas(vetordepecas);

    while (rodando) {
        al_play_sample(musica,1,0,1,ALLEGRO_PLAYMODE_LOOP,NULL);

        if (s1.vazio==0 && s2.vazio==0 && s3.vazio==0)
            preencheSlots(vetordepecas,&contadorpecas,&s1,&s2,&s3);

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando=0;
            }
            else if (evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                mouseX = evento.mouse.x;
                mouseY = evento.mouse.y;
            }

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                if (menuOn ==1 && evento.mouse.button & 1 && mouseX < X2menu && mouseX > X1menu && mouseY < Y2menuj && mouseY > Y1menuj){
                    menuOn=0;
                    jogarOn=1;
                }
                if (menuOn ==1 && evento.mouse.button & 1 && mouseX < X2menu && mouseX > X1menu && mouseY < Y2menu && mouseY > Y1menu){
                    menuOn=0;
                    recordOn=1;
                }
                if (jogarOn == 1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                   sairOn=1;
                   jogarOn=0;
                } else if (sairOn == 1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                   sairOn =0;
                   jogarOn=1;
                }
                if (menuOn == 1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                   rodando=0;
                }
                if (overOn==1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                    overOn=0;
                    reseta(&contadorpecas,&s1,&s2,&s3,matriztab,&minutos,&segundos,&menuOn,&primeirotab);
                    inicializaVPecas(vetordepecas);
                }

                if (menuOn == 1 && evento.mouse.button & 1 && (sqrt((XhelpMENU-mouseX)*(XhelpMENU-mouseX)+(YhelpMENU-mouseY)*(YhelpMENU-mouseY))<=RhelpMENU)){
                    ajudaOn=1;
                    menuOn=0;
                } else if ((ajudaOn == 1 || recordOn ==1) && evento.mouse.button & 1 && (sqrt((XhelpMENU-mouseX)*(XhelpMENU-mouseX)+(YhelpMENU-mouseY)*(YhelpMENU-mouseY))<=RhelpMENU)){
                    ajudaOn=0;
                    recordOn=0;
                    menuOn=1;
                }

                if (overOn ==1 && evento.mouse.button & 1 && mouseX < 745 && mouseX > 335 && mouseY < 610 && mouseY > 503){
                    overOn=0;
                    jogarOn=1;
                    reseta(&contadorpecas,&s1,&s2,&s3,matriztab,&minutos,&segundos,&menuOn,&primeirotab);
                    inicializaVPecas(vetordepecas);
                }

                if (menuOn==1 && evento.mouse.button & 1 && mouseX < 690 && mouseX > 390 && mouseY < 490 && mouseY > 400){
                    continuaJogo(somacol,somalin,&contadorpecas,&minutos,&segundos,&clicou,&encaixou,&primeirotab,vetordepecas,matriztab,&s1,&s2,&s3);
                    jogarOn=1;
                    menuOn=0;
                }

                if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s1.x+2*dadodiff && mouseX > s1.x && mouseY < s1.y+2*dadodiff && mouseY > s1.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==1){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

                 if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s2.x+2*dadodiff && mouseX > s2.x && mouseY < s2.y+2*dadodiff && mouseY > s2.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==2){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

                 if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s3.x+2*dadodiff && mouseX > s3.x && mouseY < s3.y+2*dadodiff && mouseY > s3.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==3){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

                if (sairOn==1 && evento.mouse.button & 1 && mouseX < x2SS && mouseX > x1SS && mouseY < y2SS && mouseY > y1SS){
                    salvaJogo(somacol,somalin,contadorpecas,minutos,segundos,clicou,encaixou,primeirotab,vetordepecas,matriztab,&s1,&s2,&s3);
                    sairOn=0;
                    reseta(&contadorpecas,&s1,&s2,&s3,matriztab,&minutos,&segundos,&menuOn,&primeirotab);
                    inicializaVPecas(vetordepecas);
                }

                if (sairOn==1 && evento.mouse.button & 1 && mouseX < X2sair && mouseX > X1sair && mouseY < Y2sair && mouseY > Y1sair){
                    sairOn=0;
                    reseta(&contadorpecas,&s1,&s2,&s3,matriztab,&minutos,&segundos,&menuOn,&primeirotab);
                    inicializaVPecas(vetordepecas);
                }

                if (jogarOn==1 && bombasdisp>0 && evento.mouse.button & 1 && mouseX < 342 && mouseX > 42 && mouseY < 678 && mouseY > 587){
                    Bomba(matriztab,vetordepecas,contadorpecas);
                    bombasdisp--;
                }
                if (jogarOn==1 && undodisp==1 && evento.mouse.button & 1 && mouseX < 690 && mouseX > 390 && mouseY < 678 && mouseY > 587){
                    undo(vetordepecas,&s1,&s2,&s3,matriztab,encaixou);
                    undodisp=0;
                }
                if(girardisp>0){
                    if (jogarOn==1 && evento.mouse.button & 1 && mouseX <888 && mouseX > 864 && mouseY < y2Girar && mouseY > y1Girar){
                        giraPeca(vetordepecas,&s1);
                        girardisp--;
                    }
                    if (jogarOn==1 && evento.mouse.button & 1 && mouseX <955 && mouseX > 922 && mouseY < y2Girar && mouseY > y1Girar){
                        giraPeca(vetordepecas,&s2);
                        girardisp--;
                    }
                    if (jogarOn==1 && evento.mouse.button & 1 && mouseX <1016 && mouseX > 982 && mouseY < y2Girar && mouseY > y1Girar){
                        giraPeca(vetordepecas,&s3);
                        girardisp--;
                    }
                }

            }  else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && jogarOn==1){
                for (int i=0;i<contadorpecas;i++){
                    if (vetordepecas[i].clicou==1){
                        vetordepecas[i].x=mouseX;
                        vetordepecas[i].y=mouseY;
                        encaixou=verificaCasa(vetordepecas,i,matriztab,&s1,&s2,&s3);
                        if (encaixou){
                            encaixou=vetordepecas[i].idpeca;
                            primeirotab=1;
                        }
                        verificaBonus(&maxcombo,&maxpont,&maxtab);
                    }
                }
            }

            if (evento.type == ALLEGRO_EVENT_TIMER) {
                if (al_get_timer_count(timer)%240 == 0) {
                    situacao = !situacao;
                }
            }
        }

        if (!al_is_event_queue_empty(fila_cronometro)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_cronometro, &evento);

            if (evento.type == ALLEGRO_EVENT_TIMER && jogarOn==1) {
                segundos++;
                if(segundos==60){
                    segundos=0;
                    minutos++;
                }
            }
        }

        if (menuOn==1)
            al_draw_bitmap(menu,0,0,0);

        if (ajudaOn==1)
            al_draw_bitmap(help,0,0,0);

        if (recordOn==1){
            al_draw_bitmap(record,0,0,0);
            printaRecord(font);
        }

        if(pontuacao>pontsmaior)
            guardaRecord(minutos,segundos);
        else if (pontuacao==pontsmaior){
            if (minsmaior>minutos)
            guardaRecord(minutos,segundos);
        }

        if (overOn==1){
            al_rest(2.0);
            al_draw_bitmap(over,0,0,0);
            al_draw_textf(font, al_map_rgb(0, 0, 0), 600, 460, ALLEGRO_ALIGN_CENTRE, "%d:%d", minutos, segundos);
            al_draw_textf(font, al_map_rgb(0, 0, 0), 600, 405, ALLEGRO_ALIGN_CENTRE, "%d", pontuacao);
        }

        if (jogarOn==1){
            fjogarOn(minutos,segundos,&contadorpecas,vetordepecas,font,matriztab,&s1,&s2,&s3,&overOn,&jogarOn,somacol,somalin);
            if (primeirotab==1)
                tabConc(matriztab);
            calculaSomas(somacol,somalin,vetordepecas,matriztab,contadorpecas);
        }

        if (sairOn==1)
            al_draw_bitmap(sair,0,0,0);

        al_flip_display();
    }

    al_destroy_bitmap(menu);
    al_destroy_bitmap(help);
    al_destroy_bitmap(record);
    al_destroy_bitmap(jogo);
    al_destroy_bitmap(sair);
    al_destroy_bitmap(over);
    al_destroy_bitmap(dado0);
    al_destroy_bitmap(dado1);
    al_destroy_bitmap(dado2);
    al_destroy_bitmap(dado3);
    al_destroy_bitmap(dado4);
    al_destroy_bitmap(dado5);
    al_destroy_bitmap(dado6);
    al_destroy_timer(timer);
    al_destroy_timer(cronometro);
    al_destroy_font(font);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_cronometro);
    al_destroy_sample(musica);

    return 0;
}
