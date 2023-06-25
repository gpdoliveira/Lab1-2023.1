#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <allegro5/allegro_image.h>

#define MENU_FILE "1.png"
#define HELP_FILE "2.png"
#define RECORD_FILE "3.png"
#define JOGO_FILE "4.png"
#define SAIR_FILE "5.png"
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

struct pecaindividual{
    int valor;
    int localizacao;

};

struct pecas{
    int x,y;
    int matriz[2][2];
    int slot;
    int clicou;
    int qtd;
};
struct tabuleiro{
    int x,y;
    int x2,y2;
    int ocupado;
    int valor;
};
struct slot1{
    int vazio;
    int x;
    int y;
};
struct slot2{
    int vazio;
    int x;
    int y;
};
struct slot3{
    int vazio;
    int x;
    int y;
};
int pontuacao=0;

ALLEGRO_BITMAP *menu =NULL;
ALLEGRO_BITMAP *help =NULL;
ALLEGRO_BITMAP *record =NULL;
ALLEGRO_BITMAP *jogo =NULL;
ALLEGRO_BITMAP *sair =NULL;
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
    dado0 = al_load_bitmap(D0_FILE);
    dado1 = al_load_bitmap(D1_FILE);
    dado2 = al_load_bitmap(D2_FILE);
    dado3 = al_load_bitmap(D3_FILE);
    dado4 = al_load_bitmap(D4_FILE);
    dado5 = al_load_bitmap(D5_FILE);
    dado6 = al_load_bitmap(D6_FILE);
}

void printaPeca(struct pecas *vetordepecas,int contadordepecas) {
    switch (vetordepecas[contadordepecas].matriz[0][0]){
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

    switch (vetordepecas[contadordepecas].matriz[0][1]){
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

    switch (vetordepecas[contadordepecas].matriz[1][0]){
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

    switch (vetordepecas[contadordepecas].matriz[1][1]){
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


void printaSomas (ALLEGRO_FONT* font,struct tabuleiro matriztab[5][5]){
    int c1=0,c2=0,c3=0,c4=0,c5=0,l1=0,l2=0,l3=0,l4=0,l5=0;

    for (int i=0;i<5;i++){
        if (matriztab[i][0].valor!=-1)
        c1+=matriztab[i][0].valor;
    }
    if (c1==10){
        c1=0;
        for (int i=0;i<5;i++){
        matriztab[i][0].valor=0;
        matriztab[i][0].ocupado=0;
        pontuacao=1;
    }
    }
    for (int i=0;i<5;i++){
        if (matriztab[i][1].valor!=-1)
        c2+=matriztab[i][1].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[i][2].valor!=-1)
        c3+=matriztab[i][2].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[i][3].valor!=-1)
        c4+=matriztab[i][3].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[i][4].valor!=-1)
        c5+=matriztab[i][4].valor;
    }

    for (int i=0;i<5;i++){
        if (matriztab[0][i].valor!=-1)
        l1+=matriztab[0][i].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[1][i].valor!=-1)
        l2+=matriztab[1][i].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[2][i].valor!=-1)
        l3+=matriztab[2][i].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[3][i].valor!=-1)
        l4+=matriztab[3][i].valor;
    }
    for (int i=0;i<5;i++){
        if (matriztab[4][i].valor!=-1)
        l5+=matriztab[4][i].valor;
    }

    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC, ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", c1);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+dadodiff, ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", c2);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(2*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", c3);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(3*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", c4);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaC+(4*dadodiff), ySomaC, ALLEGRO_ALIGN_CENTRE, "%d", c5);

    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL, ALLEGRO_ALIGN_CENTRE, "%d", l1);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+dadodiff, ALLEGRO_ALIGN_CENTRE, "%d", l2);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(2*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", l3);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(3*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", l4);
    al_draw_textf(font, al_map_rgb(255, 255, 255), xSomaL, ySomaL+(4*dadodiff), ALLEGRO_ALIGN_CENTRE, "%d", l5);
}

void verificaCasat2(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    if (vetordepecas[i].matriz[0][1]!=-1){
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a][b+1].x && vetordepecas[i].x+87.8 < matriztab[a][b+1].x2 && vetordepecas[i].y > matriztab[a][b+1].y && vetordepecas[i].y < matriztab[a][b+1].y2 && matriztab[a][b+1].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                    matriztab[a][b].ocupado=1;
                    matriztab[a][b+1].valor=vetordepecas[i].matriz[0][1];
                    matriztab[a][b+1].ocupado=1;
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
    } else if (vetordepecas[i].matriz[1][0]!=-1){
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                    matriztab[a][b].ocupado=1;
                    matriztab[a+1][b].valor=vetordepecas[i].matriz[1][0];
                    matriztab[a+1][b].ocupado=1;
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

void verificaCasat3(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    if (vetordepecas[i].matriz[0][1]!=-1){
        if (vetordepecas[i].matriz[1][0]!=-1){
            for (a=0;a<5;a++){
                for (b=0;b<5;b++){
                    if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a][b+1].x && vetordepecas[i].x+87.8 < matriztab[a][b+1].x2 && vetordepecas[i].y > matriztab[a][b+1].y && vetordepecas[i].y < matriztab[a][b+1].y2 && matriztab[a][b+1].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                        vetordepecas[i].x=matriztab[a][b].x;
                        vetordepecas[i].y=matriztab[a][b].y;
                        matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                        matriztab[a][b].ocupado=1;
                        matriztab[a][b+1].valor=vetordepecas[i].matriz[0][1];
                        matriztab[a][b+1].ocupado=1;
                        matriztab[a+1][b].valor=vetordepecas[i].matriz[1][0];
                        matriztab[a+1][b].ocupado=1;
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
                        matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                        matriztab[a][b].ocupado=1;
                        matriztab[a][b+1].valor=vetordepecas[i].matriz[0][1];
                        matriztab[a][b+1].ocupado=1;
                        matriztab[a+1][b+1].valor=vetordepecas[i].matriz[1][1];
                        matriztab[a+1][b+1].ocupado=1;
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
    } else if (vetordepecas[i].matriz[1][0]!=-1){
        if (vetordepecas[i].matriz[1][1]!=-1){
            for (a=0;a<5;a++){
                for (b=0;b<5;b++){
                    if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0 && vetordepecas[i].x+87.8 > matriztab[a+1][b+1].x && vetordepecas[i].x+87.8 < matriztab[a+1][b+1].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b+1].y && vetordepecas[i].y+87.8 < matriztab[a+1][b+1].y2 && matriztab[a+1][b+1].ocupado==0 && vetordepecas[i].x > matriztab[a+1][b].x && vetordepecas[i].x < matriztab[a+1][b].x2 && vetordepecas[i].y+87.8 > matriztab[a+1][b].y && vetordepecas[i].y+87.8 < matriztab[a+1][b].y2 && matriztab[a+1][b].ocupado==0){
                        vetordepecas[i].x=matriztab[a][b].x;
                        vetordepecas[i].y=matriztab[a][b].y;
                        matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                        matriztab[a][b].ocupado=1;
                        matriztab[a+1][b].valor=vetordepecas[i].matriz[1][0];
                        matriztab[a+1][b].ocupado=1;
                        matriztab[a+1][b+1].valor=vetordepecas[i].matriz[1][1];
                        matriztab[a+1][b+1].ocupado=1;
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
}

void verificaCasa(struct pecas *vetordepecas,int i,struct tabuleiro matriztab[5][5],struct slot1 *s1,struct slot2 *s2,struct slot3 *s3){
    int a,b,encontrou=0;

    switch (vetordepecas[i].qtd){
        case 1:
        for (a=0;a<5;a++){
            for (b=0;b<5;b++){
                if (vetordepecas[i].x > matriztab[a][b].x && vetordepecas[i].x < matriztab[a][b].x2 && vetordepecas[i].y > matriztab[a][b].y && vetordepecas[i].y < matriztab[a][b].y2 && matriztab[a][b].ocupado==0){
                    vetordepecas[i].x=matriztab[a][b].x;
                    vetordepecas[i].y=matriztab[a][b].y;
                    matriztab[a][b].valor=vetordepecas[i].matriz[0][0];
                    matriztab[a][b].ocupado=1;
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
            break;

        case 2:
            verificaCasat2(vetordepecas,i,matriztab,s1,s2,s3);
            break;
        case 3:
            verificaCasat3(vetordepecas,i,matriztab,s1,s2,s3);
            break;
    }
}


int main(void) {
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TIMER *cronometro = NULL;
    ALLEGRO_EVENT_QUEUE *fila_cronometro = NULL;
    ALLEGRO_MOUSE_STATE state;

    double tempo;
    double lastTempo = 0;

    al_init();
    al_init_font_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();

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

    int rodando = 1, situacao = 0, menuOn = 1, ajudaOn = 0, jogarOn = 0, sairOn =0, recordOn = 0, mouseX, mouseY;
    int minutos=0,segundos=0;

    struct pecas vetordepecas[100];
    struct tabuleiro matriztab[5][5];
    int xtab=342,ytab=72;

    int contadorpecas=0;
    int clicou=0;

    srand(time(NULL));

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

    for(int i=0;i<100;i++){
        vetordepecas[i].matriz[0][0] = 1;
        vetordepecas[i].matriz[0][1] = rand() % 3 -1;
        vetordepecas[i].matriz[1][0] = rand() % 3 -1;
        vetordepecas[i].matriz[1][1] = rand() % 3 -1;
        vetordepecas[i].clicou=0;
        vetordepecas[i].qtd=4;
    }

    for(int i=0;i<100;i++){
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                if (vetordepecas[i].matriz[a][b]==0){
                    vetordepecas[i].matriz[a][b]=-1;
                }
                if (vetordepecas[i].matriz[a][b]==1){
                    vetordepecas[i].matriz[a][b]= 1+ rand() % 6;
                }
            }
        }
    }
    for (int i=0;i<100;i++){
        if (vetordepecas[i].matriz[0][0]!=-1 && vetordepecas[i].matriz[0][1]!=-1 && vetordepecas[i].matriz[1][0]!=-1 && vetordepecas[i].matriz[1][1]!=-1){
            int var;
            var = rand() % 2;
            vetordepecas[i].matriz[var][var]=-1;
        }
        if (vetordepecas[i].matriz[0][0]!=-1 && vetordepecas[i].matriz[0][1]==-1 && vetordepecas[i].matriz[1][0]==-1 && vetordepecas[i].matriz[1][1]!=-1){
            vetordepecas[i].matriz[0][1]=rand() % 7;
        }
        if (vetordepecas[i].matriz[0][0]==-1 && vetordepecas[i].matriz[0][1]!=-1 && vetordepecas[i].matriz[1][0]!=-1 && vetordepecas[i].matriz[1][1]==-1){
            vetordepecas[i].matriz[0][0]=rand() % 7;
        }
        if (vetordepecas[i].matriz[0][0]==-1 && vetordepecas[i].matriz[0][1]==-1 && vetordepecas[i].matriz[1][0]==-1 && vetordepecas[i].matriz[1][1]==-1){
            vetordepecas[i].matriz[0][0]=rand() % 7;
        }
    }

    for (int i=0;i<100;i++){
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                if (vetordepecas[i].matriz[a][b]==-1)
                    vetordepecas[i].qtd-=1;
            }
        }
    }

    while (rodando) {


        if (s1.vazio==0 && s2.vazio==0 && s3.vazio==0){
            vetordepecas[contadorpecas].x = s1.x;
            vetordepecas[contadorpecas].y = s1.y;
            vetordepecas[contadorpecas].slot = 1;
            contadorpecas++;
            s1.vazio=1;

            vetordepecas[contadorpecas].x = s2.x;
            vetordepecas[contadorpecas].y = s2.y;
            vetordepecas[contadorpecas].slot = 2;
            contadorpecas++;
            s2.vazio=1;

            vetordepecas[contadorpecas].x = s3.x;
            vetordepecas[contadorpecas].y = s3.y;
            vetordepecas[contadorpecas].slot = 3;
            contadorpecas++;
            s3.vazio=1;
        }

        lastTempo = tempo;
        tempo = al_get_time();

        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = 0;
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
                   sairOn =1;
                   jogarOn=0;
                } else if (sairOn == 1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                   sairOn =0;
                   jogarOn=1;
                }


                if (sairOn == 1 && evento.mouse.button & 1 && mouseX < X2sair && mouseX > X1sair && mouseY < Y2sair && mouseY > Y1sair){
                   sairOn =0;
                   contadorpecas=-1;
                   s1.vazio=0;
                   s2.vazio=0;
                   s3.vazio=0;
                   menuOn=1;
                }
                if (menuOn == 1 && evento.mouse.button & 1 && (sqrt((XXMENU-mouseX)*(XXMENU-mouseX)+(YXMENU-mouseY)*(YXMENU-mouseY))<=RXMENU)){
                   rodando = 0;
                }
                if (menuOn == 1 && evento.mouse.button & 1 && (sqrt((XhelpMENU-mouseX)*(XhelpMENU-mouseX)+(YhelpMENU-mouseY)*(YhelpMENU-mouseY))<=RhelpMENU)){
                    ajudaOn=1;
                    menuOn=0;
                } else if ((ajudaOn == 1 || recordOn ==1) && evento.mouse.button & 1 && (sqrt((XhelpMENU-mouseX)*(XhelpMENU-mouseX)+(YhelpMENU-mouseY)*(YhelpMENU-mouseY))<=RhelpMENU)){
                    ajudaOn=0;
                    recordOn=0;
                    menuOn=1;
                }

                if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s1.x+dadodiff && mouseX > s1.x && mouseY < s1.y+dadodiff && mouseY > s1.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==1){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

                 if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s2.x+dadodiff && mouseX > s2.x && mouseY < s2.y+dadodiff && mouseY > s2.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==2){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

                 if (jogarOn==1 && evento.mouse.button & 1 && mouseX < s3.x+dadodiff && mouseX > s3.x && mouseY < s3.y+dadodiff && mouseY > s3.y){
                    for (int i=0;i<contadorpecas;i++){
                        if (vetordepecas[i].slot==3){
                            vetordepecas[i].clicou=1;
                        }
                    }
                }

            }  else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                for (int i=0;i<contadorpecas;i++){
                    if (vetordepecas[i].clicou==1){
                        vetordepecas[i].x=mouseX;
                        vetordepecas[i].y=mouseY;
                        verificaCasa(vetordepecas,i,matriztab,&s1,&s2,&s3);
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

        if (recordOn==1)
            al_draw_bitmap(record,0,0,0);

        if (jogarOn==1){
            al_draw_bitmap(jogo,0,0,0);
            al_draw_textf(font, al_map_rgb(0, 0, 0), 982, 240, ALLEGRO_ALIGN_CENTRE, "%d", pontuacao);
            al_draw_textf(font, al_map_rgb(0, 0, 0), 982, 430, ALLEGRO_ALIGN_CENTRE, "%d:%d", minutos, segundos);

            for (int i=0;i<contadorpecas;i++){
                printaPeca(vetordepecas,i);
            }

            printaSomas(font,matriztab);
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

    return 0;
}
