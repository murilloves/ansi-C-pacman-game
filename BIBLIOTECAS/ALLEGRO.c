#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "FUNCTION.c"

void init();
void deinit();


/* 
   THIS FUNCTION CREATES THE SHAPE OF THE LEVEL 
   SEPARATING REGIONS PACMAN CAN ENTER (attributed with the value of '0')
   AND THE REGIONS PACMAN CAN'T ENTER (attributed with the value of '1')
*/

/* 
   FUNÇÃO QUE 'CRIA' O ESTERIÓTIPO DA FASE 
   DIFERENCIANDO OS CAMPOS(quadrados) TANGÍVEIS (valor 0)
   DAQUELES QUE NÃO PODEM SER INVADIDOS (valor 1)
*/
void verifica_fase_1(){

lvl_1.x=0;
lvl_1.y=0;


     for (i=0; i<DIM; i++){
     for (j=0; j<DIM; j++){
          lvl_1.fase[i][j]=0;
     }
     }
          i=0;
          for(j=0; j<DIM; j++){
              if(i==0&&(j==4||j==10)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=1;
          for(j=0; j<DIM; j++){
              if(i==1&&(j==1||j==2||j==4||j==6||j==7||j==8||j==10||j==12||j==13)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=2;
          for(j=0; j<DIM; j++){
              if(j==1||j==7||j==13){
                   lvl_1.fase[i][j]=1;
                   }}
          i=3;
          for(j=0; j<DIM; j++){
              if(i==3&&(j==1||(j>=3&&j<6)||j==13||(j>=9&&j<12))){
                   lvl_1.fase[i][j]=1;
                   }}
          i=4;
          for(j=0; j<DIM; j++){
              if(i==4&&(j>=5&&j<12&&j!=10)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=5;
          for(j=0; j<DIM; j++){
              if(i==5&&(j==1||j==3||(j>=5&&j<10)||j==11||j==13)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=6;
          for(j=0; j<DIM; j++){
              if(i==6&&((j>=3&&j<10)&&j!=4)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=7;
          for(j=0; j<DIM; j++){
              if(i==7&&(j==3||j==4||j==11||j==10||j==1||j==13)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=8;
          for(j=0; j<DIM; j++){
              if(i==8&&(j==1||j==6||j==7||j==8||j==13)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=9;
          for(j=0; j<DIM; j++){
              if(i==9&&(j==1||j==2||j==4||j==10||j==12||j==13)){
                   lvl_1.fase[i][j]=1;
                   }}
          i=10;
          for(j=0; j<DIM; j++){
              if(i==10&&(j>=4&&j<11&&j!=7)){
                   lvl_1.fase[i][j]=1;
                   }}
          
}

/* VIDAS PACMAN */
/* PACMAN's LIVES */
void vidas(int vidas){
     int i;
     textout_ex(screen, font, "VIDAS", 650, 200, makecol(200, 100, 200), _textmode);
     for(i=0; i<vidas; i++){
     circlefill(screen, 690+(i*50), 230, 15, 13300000);
     triangle(screen, 690+(i*50), 230, 720+(i*50), 220, 720+(i*50), 240, 0);
     }
}

/* 
 * TEXT : NUMBERS (digit score board) 
 */
/* 
 * TEXTO : NUMEROS (algarismos)
 */
void algarismo(int num, int j, int i, int cor){
     if(num==0){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+8, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+16, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==1){
     textout_ex(screen, font, "     ", j, i, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "     ", j, i+32, cor, _textmode);
     }
     if(num==2){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+16, cor, _textmode);
     textout_ex(screen, font, " |   ", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==3){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "  --|", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==4){
     textout_ex(screen, font, "     ", j, i, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "  --|", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "     ", j, i+32, cor, _textmode);
     }
     if(num==5){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |   ", j, i+8, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==6){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |   ", j, i+8, cor, _textmode);
     textout_ex(screen, font, " |-- ", j, i+16, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==7){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+32, cor, _textmode);
     }
     if(num==8){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+8, cor, _textmode);
     textout_ex(screen, font, " |--|", j, i+16, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
     if(num==9){
     textout_ex(screen, font, "  -- ", j, i, cor, _textmode);
     textout_ex(screen, font, " |  |", j, i+8, cor, _textmode);
     textout_ex(screen, font, "  --|", j, i+16, cor, _textmode);
     textout_ex(screen, font, "    |", j, i+24, cor, _textmode);
     textout_ex(screen, font, "  -- ", j, i+32, cor, _textmode);
     }
}

/* PRINT THE POINTS ON SCREEN */
/* FUNÇÃO QUE IMPRIME A PONTUAÇÃO NA TELA */
void imprime_pontos(int pontos, BITMAP *buffer){
     clear(buffer);
     textprintf_ex ( buffer , font , 0, 0, makecol (155, 100, 200), -1  , "PONTOS");
     draw_sprite(screen, buffer, 650, 30);
     int a,b,c,d;
     int posx=670, posy=40;

     a=pontos/1000;
     b=pontos/100 - a*10;
     c=pontos/10  - a*100 - b*10;
     d=pontos     - a*1000 - b*100 -c*10;
     algarismo(a, posx    , posy, -1);
     algarismo(b, posx+40 , posy, -1);
     algarismo(c, posx+80 , posy, -1);
     algarismo(d, posx+120, posy, -1);
}


/* FUNÇÃO QUE IMPRIME O TEMPO */
void imprime_tempo(int tempo, BITMAP *buffer){
     clear(buffer);
     textprintf_ex ( buffer , font , 0, 0, makecol (200, 100, 200), -1  , "Tempo:");
     draw_sprite(screen, buffer, 650, 30);
     int a,b,c,d;

     a=tempo/1000;
     b=tempo/100 - a*10;
     c=tempo/10  - a*100 - b*10;
     d=tempo     - a*1000 - b*100 -c*10;
     algarismo(a,650,40,-1);
     algarismo(b,690,40,-1);
     algarismo(c,730,40,-1);
     algarismo(d,770,40,-1);
}

/* DRAW 'COINS' ON SCREEN */
/* FUNÇÃO QUE DESENHA BOLINHAS NOS 'quadrados' CORRETOS */
void come_cheetos(BITMAP *cheetos){
     for(i=0; i<DIM; i++){
         for(c=0; c<COL; c++){
         if(lvl_1.fase[c][i]==0)
         circlefill (cheetos, (i*BL)+21, (c*BL)+21, 3, 13300000);
         }
     }
         circlefill (cheetos, (4*BL)+21, (6*BL)+21, 9, 13300000);
         circlefill (cheetos, (10*BL)+21, (4*BL)+21, 9, 13300000);
     draw_sprite (screen, cheetos, 0, 0);
}

/* PRINT 'PAUSE' TEXT */
/* TEXTO PAUSE: IMPRESSÃO MANUAL*/
void texto_pause(int i, int j,int cor, BITMAP* frame){
     textout_ex(screen, font, "                               ", 320-j, 270-i, cor, _textmode);
     textout_ex(screen, font, "  ___   ___         ___   ___  ", 320-j, 268-i, cor, _textmode);
     textout_ex(screen, font, " |   | |   | |   | |     |     ", 320-j, 278-i, cor, _textmode);
     textout_ex(screen, font, " |   | |   | |   | |     |     ", 320-j, 286-i, cor, _textmode);
     textout_ex(screen, font, " |___| |___| |   | |___  |___  ", 320-j, 294-i, cor, _textmode);
     textout_ex(screen, font, " |     |   | |   |     | |     ", 320-j, 302-i, cor, _textmode);
     textout_ex(screen, font, " |     |   | |   |     | |     ", 320-j, 310-i, cor, _textmode);
     textout_ex(screen, font, " |     |   | |___|  ___| |___  ", 320-j, 318-i, cor, _textmode);
     textout_ex(screen, font, "                               ", 320-j, 326-i, cor, _textmode);     
     
     textprintf_ex ( screen , font , 650, 5, makecol (-20, 100, 200), -1  ,"----- JOGO PAUSADO -----");
}

/* PRINT 'READY?' TEXT */
/* TEXTO READY?: IMPRESSÃO MANUAL*/
void texto_ready(int i, int j,int cor){
     textout_ex(screen, font, "                                 ", 320-j, 270-i, cor, _textmode);
     textout_ex(screen, font, "  ___   ___  ___   __          ___ ", 320-j, 268-i, cor, _textmode);
     textout_ex(screen, font, " |   | |    |   | |  \\  \\   / /   \\ ", 320-j, 278-i, cor, _textmode);
     textout_ex(screen, font, " |   | |    |   | |   |  \\ /      | ", 320-j, 286-i, cor, _textmode);
     textout_ex(screen, font, " |___| |___ |___| |   |   |       /  ", 320-j, 294-i, cor, _textmode);
     textout_ex(screen, font, " | \\   |    |   | |   |   |      /  ", 320-j, 302-i, cor, _textmode);
     textout_ex(screen, font, " |  \\  |    |   | |   |   |     |  ", 320-j, 310-i, cor, _textmode);
     textout_ex(screen, font, " |   \\ |___ |   | |__/    |     |  ", 320-j, 318-i, cor, _textmode);
     textout_ex(screen, font, "                                .  ", 320-j, 326-i, cor, _textmode);     
}

/* PRINT 'GO!!!' TEXT */
/* TEXTO GO!!!: IMPRESSÃO MANUAL*/
void texto_go(int i, int j,int cor){
     textout_ex(screen, font, "               | | |   ", 320-j, 270-i, cor, _textmode);
     textout_ex(screen, font, "  ___    ___   | | |   ", 320-j, 268-i, cor, _textmode);
     textout_ex(screen, font, " |   |  |   |  | | |   ", 320-j, 278-i, cor, _textmode);
     textout_ex(screen, font, " |      |   |  | | |   ", 320-j, 286-i, cor, _textmode);
     textout_ex(screen, font, " |      |   |  | | |   ", 320-j, 294-i, cor, _textmode);
     textout_ex(screen, font, " | --|  |   |  | | |   ", 320-j, 302-i, cor, _textmode);
     textout_ex(screen, font, " |   |  |   |  | | |   ", 320-j, 310-i, cor, _textmode);
     textout_ex(screen, font, " |___|  |___|  | | |   ", 320-j, 318-i, cor, _textmode);
     textout_ex(screen, font, "               . . .   ", 320-j, 326-i, cor, _textmode);     
}

/* FUNÇÂO PAUSA O JOGO*/
void pause_p(BITMAP *frame){

    blit(screen,frame, 0,0, 0,0, RES_X, RES_Y);
    int i=60, j=120, cor=-1, pause=1;

texto_pause(i,j,cor,frame);
    
      while(pause==1&&!key[KEY_ESC]){
      rest(1);
      
      if(keypressed()==key[KEY_ENTER])
      pause=0;
      }
      blit(frame,screen, 0,0, 0,0, RES_X, RES_Y);
      rectfill(screen, 640, 5, 840, 15, 0);

}

/* FONTE*/

/* DRAW THE ENTIRELY LEVEL */
void desenha_fase_1(BITMAP *btmp, int cor, int n){
     /* Horizontais
     void hline (BITMAP *bmp, int x1, int y, int x2, int color);
     */
     hline( btmp, (BL*1)+AB+n, (BL*1)+AB+n, (BL*2)+AC+n, cor);
     hline( btmp, (BL*1)+AB+n, (BL*1)+AC+n, (BL*2)+AC+n, cor);
     hline( btmp, (BL*1)+AB+n, (BL*9)+AB+n, (BL*2)+AC+n, cor);
     hline( btmp, (BL*1)+AB+n, (BL*9)+AC+n, (BL*2)+AC+n, cor);

     hline( btmp, (BL*3)+AB+n, (BL*3)+AB+n, (BL*5)+AC+n, cor);
     hline( btmp, (BL*3)+AB+n, (BL*3)+AC+n, (BL*5)+AC+n, cor);
     hline( btmp, (BL*3)+AB+n, (BL*7)+AB+n, (BL*4)+AC+n, cor);
     hline( btmp, (BL*3)+AB+n, (BL*7)+AC+n, (BL*4)+AC+n, cor);

     hline( btmp, (BL*4)+AB+n, (BL*10)+AB+n, (BL*6)+AC+n, cor);
     hline( btmp, (BL*4)+AB+n, (BL*10)+AC+n, (BL*6)+AC+n, cor);

     hline( btmp, (BL*5)+AB+n, (BL*4)+AB+n, (BL*6)+AC+n, cor);
     hline( btmp, (BL*5)+AB+n, (BL*4)+AC+n, (BL*6)+AC+n, cor);
     hline( btmp, (BL*5)+AB+n, (BL*6)+AB+n, (BL*9)+AC+n, cor);
     hline( btmp, (BL*5)+AB+n, (BL*6)+AC+n, (BL*9)+AC+n, cor);

     hline( btmp, (BL*6)+AB+n, (BL*1)+AB+n, (BL*8)+AC+n, cor);
     hline( btmp, (BL*6)+AB+n, (BL*1)+AC+n, (BL*8)+AC+n, cor);
     hline( btmp, (BL*6)+AB+n, (BL*8)+AB+n, (BL*8)+AC+n, cor);
     hline( btmp, (BL*6)+AB+n, (BL*8)+AC+n, (BL*8)+AC+n, cor);

     hline( btmp, (BL*8)+AB+n, (BL*4)+AB+n, (BL*9)+AC+n, cor);
     hline( btmp, (BL*8)+AB+n, (BL*4)+AC+n, (BL*9)+AC+n, cor);
     hline( btmp, (BL*8)+AB+n, (BL*10)+AB+n, (BL*10)+AC+n, cor);
     hline( btmp, (BL*8)+AB+n, (BL*10)+AC+n, (BL*10)+AC+n, cor);
     
     hline( btmp, (BL*9)+AB+n, (BL*3)+AB+n, (BL*11)+AC+n, cor);
     hline( btmp, (BL*9)+AB+n, (BL*3)+AC+n, (BL*11)+AC+n, cor);

     hline( btmp, (BL*10)+AB+n, (BL*7)+AB+n, (BL*11)+AC+n, cor);
     hline( btmp, (BL*10)+AB+n, (BL*7)+AC+n, (BL*11)+AC+n, cor);

     hline( btmp, (BL*12)+AB+n, (BL*1)+AB+n, (BL*13)+AC+n, cor);
     hline( btmp, (BL*12)+AB+n, (BL*1)+AC+n, (BL*13)+AC+n, cor);
     hline( btmp, (BL*12)+AB+n, (BL*9)+AB+n, (BL*13)+AC+n, cor);
     hline( btmp, (BL*12)+AB+n, (BL*9)+AC+n, (BL*13)+AC+n, cor);
     
/* COMPLEMENTOS (PEQUENAS LINHAS)*/
   hline( btmp, BL*4+AB+n, BL*1+AC+n, BL*4+AC+n, cor);
   hline( btmp, BL*10+AB+n, BL*1+AC+n, BL*10+AC+n, cor);

   hline( btmp, BL*7+AB+n, BL*2+AC+n, BL*7+AC+n, cor);

   hline( btmp, BL*1+AB+n, BL*3+AC+n, BL*1+AC+n, cor);
   hline( btmp, BL*13+AB+n, BL*3+AC+n, BL*13+AC+n, cor);

   hline( btmp, BL*3+AB+n, BL*5+AB+n, BL*3+AC+n, cor);
   hline( btmp, BL*11+AB+n, BL*5+AC+n, BL*11+AC+n, cor);

   hline( btmp, BL*1+AB+n, BL*7+AB+n, BL*1+AC+n, cor);
   hline( btmp, BL*13+AB+n, BL*7+AB+n, BL*13+AC+n, cor);

   hline( btmp, (BL*4)+AB+n, (BL*9)+AB+n, (BL*4)+AC+n, cor);
   hline( btmp, (BL*10)+AB+n, (BL*9)+AB+n, (BL*10)+AC+n, cor);

/*Quadradinhos da linha numero 5*/
   hline( btmp, (BL*1)+AB+n, (BL*5)+AB+n, (BL*1)+AC+n, cor);
   hline( btmp, (BL*13)+AB+n, (BL*5)+AB+n, (BL*13)+AC+n, cor);

   hline( btmp, (BL*1)+AB+n, (BL*5)+AC+n, (BL*1)+AC+n, cor);
   hline( btmp, (BL*13)+AB+n, (BL*5)+AC+n, (BL*13)+AC+n, cor);

     /* Verticais
     void vline(BITMAP *bmp, int x, int y1, int y2, int color);
     */

vline( btmp, 634, 0, 480, -1);
vline( btmp, 635, 0, 480, -1);
vline( btmp, 633, 0, 480, -1);

     vline( btmp, (BL*1)+AB+n,  (BL*1)+AB+n, RES_Y-(BL*8)+AB+n, cor);
     vline( btmp, (BL*1)+AC+n,  (BL*1)+AB+n, RES_Y-(BL*8)+AB+n, cor);
     vline( btmp, (BL*1) +AB+n, (BL*7)+AB+n, RES_Y-(BL*2)+AB+n, cor);
     vline( btmp, (BL*1) +AC+n, (BL*7)+AB+n, RES_Y-(BL*2)+AB+n, cor);

     vline( btmp, (BL*3)+AB+n,  (BL*5)+AB+n, RES_Y-(BL*4)+AB+n, cor);
     vline( btmp, (BL*3)+AC+n,  (BL*5)+AB+n, RES_Y-(BL*4)+AB+n, cor);

     vline( btmp, (BL*5)+AB+n,  (BL*3)+AB+n, RES_Y-(BL*5)+AB+n, cor);
     vline( btmp, (BL*5)+AC+n,  (BL*3)+AB+n, RES_Y-(BL*5)+AB+n, cor);

     vline( btmp, (BL*4)+AB+n, (BL*0)+n,  (BL*1)+AC+n, cor);
     vline( btmp, (BL*4)+AC+n, (BL*0)+n,  (BL*1)+AC+n, cor);
     vline( btmp, (BL*4)+AB+n, (BL*9)+AB+n, (BL*10)+AC+n, cor);
     vline( btmp, (BL*4)+AC+n, (BL*9)+AB+n, (BL*10)+AC+n, cor);

     vline( btmp, (BL*7)+AB+n,  (BL*1)+AB+n, (BL*2)+AC+n, cor);
     vline( btmp, (BL*7)+AC+n,  (BL*1)+AB+n, (BL*2)+AC+n, cor);

     vline( btmp, (BL*9)+AB+n,  (BL*3)+AB+n, RES_Y-(BL*5)+AB+n, cor);
     vline( btmp, (BL*9)+AC+n,  (BL*3)+AB+n, RES_Y-(BL*5)+AB+n, cor);

     vline( btmp, (BL*10)+AB+n, (BL*0)+n,  (BL*1)+AC+n, cor);
     vline( btmp, (BL*10)+AC+n, (BL*0)+n,  (BL*1)+AC+n, cor);
     vline( btmp, (BL*10)+AB+n, (BL*9)+AB+n, (BL*10)+AC+n, cor);
     vline( btmp, (BL*10)+AC+n, (BL*9)+AB+n, (BL*10)+AC+n, cor);

     vline( btmp, (BL*11)+AB+n, (BL*3)+AB+n, RES_Y-(BL*6)+AB+n, cor);
     vline( btmp, (BL*11)+AC+n, (BL*3)+AB+n, RES_Y-(BL*6)+AB+n, cor);

     vline( btmp, (BL*13)+AB+n, (BL*7)+AB+n, RES_Y-(BL*2)+AB+n, cor);
     vline( btmp, (BL*13)+AC+n, (BL*7)+AB+n, RES_Y-(BL*2)+AB+n, cor);
     vline( btmp, (BL*13)+AB+n, (BL*1)+AB+n, RES_Y-(BL*8)+AB+n, cor);
     vline( btmp, (BL*13)+AC+n, (BL*1)+AB+n, RES_Y-(BL*8)+AB+n, cor);

/* COMPLEMENTOS (PEQUENAS COLUNAS)*/
   vline( btmp, BL*2+AC+n, BL*1+AB+n, BL*1+AC+n, cor);
   vline( btmp, BL*2+AC+n, BL*9+AB+n, BL*9+AC+n, cor);

   vline( btmp, BL*4+AC+n, BL*7+AB+n, BL*7+AC+n, cor);
   vline( btmp, BL*5+AC+n, BL*3+AB+n, BL*3+AC+n, cor);
   vline( btmp, BL*11+AC+n, BL*3+AB+n, BL*3+AC+n, cor);
   vline( btmp, BL*11+AC+n, BL*7+AB+n, BL*7+AC+n, cor);

   vline( btmp, BL*6+AC+n, BL*4+AB+n, BL*4+AC+n, cor);
   vline( btmp, BL*6+AC+n, BL*10+AB+n, BL*10+AC+n, cor);

   vline( btmp, BL*8+AC+n, BL*1+AB+n, BL*1+AC+n, cor);
   vline( btmp, BL*8+AC+n, BL*8+AB+n, BL*8+AC+n, cor);

   vline( btmp, BL*3+AB+n, BL*3+AB+n, BL*3+AC+n, cor);
   vline( btmp, BL*6+AB+n, BL*1+AB+n, BL*1+AC+n, cor);
   vline( btmp, BL*6+AB+n, BL*8+AB+n, BL*8+AC+n, cor);
   vline( btmp, BL*8+AB+n, BL*4+AB+n, BL*4+AC+n, cor);
   vline( btmp, BL*8+AB+n, BL*10+AB+n, BL*10+AC+n, cor);

   vline( btmp, BL*9+AB+n, BL*3+AB+n, BL*3+AC+n, cor);
   vline( btmp, BL*10+AB+n, BL*7+AB+n, BL*7+AC+n, cor);
   vline( btmp, BL*12+AB+n, BL*1+AB+n, BL*1+AC+n, cor);
   vline( btmp, BL*12+AB+n, BL*9+AB+n, BL*9+AC+n, cor);

/*Quadradinhos da linha numero 5*/
   vline( btmp, (BL*1)+AB+n, (BL*5)+AB+n, (BL*5)+AC+n, cor);
   vline( btmp, (BL*13)+AB+n, (BL*5)+AB+n, (BL*5)+AC+n, cor);

   vline( btmp, (BL*1)+AC+n, (BL*5)+AB+n, (BL*5)+AC+n, cor);
   vline( btmp, (BL*13)+AC+n, (BL*5)+AB+n, (BL*5)+AC+n, cor);


     /* Desenha na tela */
     draw_sprite(screen, btmp, 0, 0);     
}

int fase_1(int x, int y){
    for(x=0; x<DIM; x++){
             for(y=0; y<COL; y++){
             
             if(y==1&&x!=0&&x!=DIM-1&&x!=DIM/2) 
                lvl_1.fase[x][y]=2;
                return(1);
             if(x==DIM-2&&y!=0&&y!=COL/2&&y!=COL-1)
                lvl_1.fase[x][y]=2;
                return(1);
             if(y==COL-2&&x!=0&&x!=DIM-1&&x!=DIM/2)
                lvl_1.fase[x][y]=2;
                return(1);
             if(x==1&&y!=COL-1&&y!=0&&y!=COL/2)
                lvl_1.fase[x][y]=2;
                return(1);
                
             if(x==0&&y==0||x==0&&y==COL-1||x==DIM-1&&y==COL-1||x==DIM-1&&y==0){
                  lvl_1.fase[x][y]=2;
                return(1);
                  }
             else {
                   lvl_1.fase[x][y]=1;
                   remaing++;
                return(0);
                  }
             }
    }
}

/* DRAW PACMAN'S RIGHT DIRECTION */
/* Desenha Pacman Direção: Direita*/
void desenha_pac_r(BITMAP *imagem, BITMAP *imagem2, BITMAP *imagem3, BITMAP *imagem4, int x, int y, BITMAP *buffer, int tempo){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, imagem, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, imagem2, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, imagem3, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, imagem4, 0, 0);
     }
     draw_sprite(screen, buffer, x, y);
     vline(screen, x-2, y, y+42, 0);
     vline(screen, x-1, y, y+42, 0);
}

/* DRAW PACMAN'S LEFT DIRECTION */
/* Desenha Pacman Direção: Esquerda*/
void desenha_pac_l(BITMAP *imagem5, BITMAP *imagem6, BITMAP *imagem7, BITMAP *imagem8, int x, int y, BITMAP *buffer, int tempo ){
     clear_to_color(buffer,0);

     if(tempo%4==0){
     draw_sprite(buffer, imagem5, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, imagem6, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, imagem7, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, imagem8, 0, 0);
     }
     draw_sprite(screen, buffer, x, y);
     vline(screen, x+40, y, y+42, 0);
     vline(screen, x+41, y, y+42, 0);
}

/* DRAW PACMAN'S UP DIRECTION */
/* Desenha Pacman Direção: Cima*/
void desenha_pac_up(BITMAP *pac_x0, BITMAP *pac_x1, BITMAP *pac_x2, BITMAP *pac_x3, int x, int y, BITMAP *buffer, int tempo ){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, pac_x0, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, pac_x1, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, pac_x2, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, pac_x3, 0, 0);
     }
     draw_sprite(screen, buffer, x , y);
     hline(screen, x, y+42, x+42, 0);
     hline(screen, x, y+43, x+42, 0);

}

/* DRAW PACMAN'S DOWN DIRECTION */
/* Desenha Pacman Direção: Baixo*/
void desenha_pac_down(BITMAP *pac_x4, BITMAP *pac_x5, BITMAP *pac_x6, BITMAP *pac_x7, int x, int y, BITMAP *buffer, int tempo ){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, pac_x4, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, pac_x5, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, pac_x6, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, pac_x7, 0, 0);
     }
     draw_sprite(screen, buffer, x, y);
     hline(screen, x, y-1, x+42, 0);
     hline(screen, x, y-2, x+42, 0);

}

/*------------------------------------------------------------------------------------------*/

                      /* Desenha Ghost Vermelho -- Direção: Indefinida*/

void desenha_ghost_red(BITMAP *gh1, BITMAP *gh2, BITMAP *gh3, BITMAP *gh4, BITMAP *buffer, int tempo ){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, gh1, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, gh2, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, gh3, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, gh4, 0, 0);
     }
     draw_sprite(screen, buffer, 7*BL, 5*BL);
}


                        /* Desenha Ghost Azul -- Direção: Indefinida*/
                        
                        
void desenha_ghost_blue(BITMAP *gh1, BITMAP *gh2, BITMAP *gh3, BITMAP *gh4, BITMAP *buffer, int tempo ){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, gh1, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, gh2, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, gh3, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, gh4, 0, 0);
     }
     draw_sprite(screen, buffer, 6*BL, 5*BL);
}

                         /* Desenha Ghost Verde -- Direção: Indefinida*/


void desenha_ghost_green(BITMAP *gh1, BITMAP *gh2, BITMAP *gh3, BITMAP *gh4, BITMAP *buffer, int tempo ){
     clear(buffer);

     if(tempo%4==0){
     draw_sprite(buffer, gh1, 0, 0);
     }
     
     if(tempo%4==1){
     draw_sprite(buffer, gh2, 0, 0);
     }

     if(tempo%4==2){
     draw_sprite(buffer, gh3, 0, 0);
     }
     
     if(tempo%4==3){
     draw_sprite(buffer, gh4, 0, 0);
     }
     draw_sprite(screen, buffer, 8*BL, 5*BL);
}

/*---------------------------------------------------------------------------------*/


/*Função que inicializa as instruções e funções da biblioteca ALLEGRO*/
void init()
{
     int depth, res;

     allegro_init();

               depth = desktop_color_depth();
               if(depth==0) depth = 24;
               set_color_depth(depth);

     res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 480, 320, 0, 0);


         if (res != 0) {
         //allegro_message();
         exit(-1);
         }

      install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL); 
            
      install_timer();

      install_keyboard();

      install_mouse();

} 


void deinit()
{
clear_keybuf();
}

