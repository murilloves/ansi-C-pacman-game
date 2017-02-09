#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "BIBLIOTECAS/ALLEGRO.c"


/*Funções para o tempo ser contado*/
int tempo;
int time_sec;
int time_ghost;

void aumenta_time()
    {
     tempo++;
    }
     END_OF_FUNCTION(aumeta_time);

void aumenta_sec()
    {
     time_sec++;
    }
     END_OF_FUNCTION(aumeta_time);
     
void desenha_ghost_rd();
     
/**********************************/

int main(){
    
    init();
    int x, y, key_ant=0, y2,x2, life=3;


/*Declarando variáveis para BITMAPS que serão utilizados durante a execução do jogo*/
BITMAP *imagem, *imagem2, *imagem3, *imagem4, *imagem5, *imagem6, *imagem7, *imagem8;
BITMAP *pac_x0, *pac_x1, *pac_x2, *pac_x3, *pac_x4, *pac_x5, *pac_x6, *pac_x7 ;
BITMAP *ghr_1, *ghr_2, *ghr_3, *ghr_4, *ghb_1, *ghb_2, *ghb_3, *ghb_4, *ghg_1, *ghg_2, *ghg_3, *ghg_4;

BITMAP *wall_1;
/**********************************************************************************/


/*Variaveis que armazenarão os rostos do Pacman*/

/*Direita*/
imagem  = load_bitmap("IMG/Pacman/pacr_0.bmp", NULL);
imagem2 = load_bitmap("IMG/Pacman/pacr_3.bmp", NULL);
imagem3 = load_bitmap("IMG/Pacman/pacr_2.bmp", NULL);
imagem4 = load_bitmap("IMG/Pacman/pacr_1.bmp", NULL);
/*Esquerda*/
imagem5 = load_bitmap("IMG/Pacman/pacl_0.bmp", NULL);
imagem6 = load_bitmap("IMG/Pacman/pacl_3.bmp", NULL);
imagem7 = load_bitmap("IMG/Pacman/pacl_2.bmp", NULL);
imagem8 = load_bitmap("IMG/Pacman/pacl_1.bmp", NULL);
/*Cima*/
pac_x0 = load_bitmap("IMG/Pacman/pacu_0.bmp", NULL);
pac_x1 = load_bitmap("IMG/Pacman/pacu_3.bmp", NULL);
pac_x2 = load_bitmap("IMG/Pacman/pacu_2.bmp", NULL);
pac_x3 = load_bitmap("IMG/Pacman/pacu_1.bmp", NULL);
/*Baixo*/
pac_x4 = load_bitmap("IMG/Pacman/pacd_0.bmp", NULL);
pac_x5 = load_bitmap("IMG/Pacman/pacd_3.bmp", NULL);
pac_x6 = load_bitmap("IMG/Pacman/pacd_2.bmp", NULL);
pac_x7 = load_bitmap("IMG/Pacman/pacd_1.bmp", NULL);
/**************************************************/


/*Variáveis que irão armazenar as formas dos fantasmas*/

/*Blue*/
ghb_1 = load_bitmap("IMG/Ghost/ghb_1.bmp", NULL);
ghb_2 = load_bitmap("IMG/Ghost/ghb_2.bmp", NULL);
ghb_3 = load_bitmap("IMG/Ghost/ghb_3.bmp", NULL);
ghb_4 = load_bitmap("IMG/Ghost/ghb_4.bmp", NULL);
/*Green*/
ghg_1 = load_bitmap("IMG/Ghost/ghg_1.bmp", NULL);
ghg_2 = load_bitmap("IMG/Ghost/ghg_2.bmp", NULL);
ghg_3 = load_bitmap("IMG/Ghost/ghg_3.bmp", NULL);
ghg_4 = load_bitmap("IMG/Ghost/ghg_4.bmp", NULL);
/*Red*/
ghr_1 = load_bitmap("IMG/Ghost/ghr_1.bmp", NULL);
ghr_2 = load_bitmap("IMG/Ghost/ghr_2.bmp", NULL);
ghr_3 = load_bitmap("IMG/Ghost/ghr_3.bmp", NULL);
ghr_4 = load_bitmap("IMG/Ghost/ghr_4.bmp", NULL);
/***********************************************/


/*CHAMADAS DE FUNÇÔES TEMPORIZADORES E CONTADORES*/
LOCK_VARIABLE(tempo);
LOCK_FUNCTION(aumenta_time);
install_int(aumenta_time, 30);

LOCK_VARIABLE(time_sec);
LOCK_FUNCTION(aumenta_sec);
install_int(aumenta_sec, 450);

/****************************/


/*TELA INICIAL DO PACMAN*/
while(!key[KEY_ENTER]&&!key[KEY_ESC]){
     BITMAP *im  = load_bitmap("IMG/init_scr.bmp", NULL);
     draw_sprite(screen, im, 0, 0);
}
/************************/


/*Definindo resolução do jogo e das figuras que serão utizadas*/
int res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, RES_X1, RES_Y1, 0, 0);
BITMAP *frame_buffer = create_bitmap( RES_X1, RES_Y1);
BITMAP *bufac = create_bitmap( 42, 42); 
BITMAP *buf_ghg = create_bitmap( 42, 42);
BITMAP *buf_ghb = create_bitmap( 42, 42);
BITMAP *buf_ghr = create_bitmap( 42, 42);
BITMAP *buf_score = create_bitmap( 100, 100);
/***************************************/


texto_ready(60,60,-1); rest(500);
clear(screen);
texto_go(60,0,1000); rest(200);
texto_go(60,0,13300000); rest(200);
texto_go(60,0,-1); rest(200);

//while(!key[KEY_M]){ ii=ii+100000; desenha_fase_1(frame_buffer, ii); rest(1000);}
desenha_fase_1(frame_buffer, 900, -3);
rest(50);
desenha_fase_1(frame_buffer, COR_AZ-100, -1);
rest(50);
desenha_fase_1(frame_buffer, COR_ROSA, 0);
rest(50);
desenha_fase_1(frame_buffer, COR_AZ-100, 1);
rest(50);
desenha_fase_1(frame_buffer, 900, 3);


clear_keybuf();
verifica_fase_1();
rest(100);
come_cheetos(frame_buffer);
vidas(life);

BITMAP *im = load_bitmap("IMG/Pacman/pacr_0.bmp", NULL);
draw_sprite(screen, im, 0, 0);

x=0; y=0;
while (!key[KEY_ESC]) {
while(!keypressed());

while(keypressed()!=key[KEY_ESC]){
            desenha_ghost_red(ghr_1, ghr_2, ghr_3, ghr_4, buf_ghr, time_sec);
            desenha_ghost_blue(ghb_1, ghb_2, ghb_3, ghb_4, buf_ghb, time_sec);
            desenha_ghost_green(ghg_1, ghg_2, ghg_3, ghg_4, buf_ghg, time_sec);
                  if(keypressed()==key[KEY_P])
                  pause_p(frame_buffer);
            if(keypressed())break;
}

      if(keypressed()==key[KEY_RIGHT]&&lvl_1.fase[lvl_1.x][lvl_1.y+1]!=1){key_ant=1;
      while(!key[KEY_ESC]&& KEY_RIGHT &&lvl_1.fase[lvl_1.x][lvl_1.y+1]!=1){
      if(y<RES_X-82){y2=y+42;
      /* PONTUAÇÃO */
      if(lvl_1.fase[lvl_1.x][lvl_1.y+1]==0){
         lvl_1.fase[lvl_1.x][lvl_1.y+1]=-1; 
         lvl_1.pontos+=10;
         imprime_pontos(lvl_1.pontos, buf_score);
         }
            /* Movimento por 'quadrado' de 42x42 */
            while(y<y2 && !key[KEY_ESC]){y=y+2;
            desenha_pac_r(imagem, imagem2, imagem3, imagem4, y, x, bufac, tempo);
            rest(TEMPOZ);
            desenha_ghost_red(ghr_1, ghr_2, ghr_3, ghr_4, buf_ghr, time_sec);
            desenha_ghost_blue(ghb_1, ghb_2, ghb_3, ghb_4, buf_ghb, time_sec);
            desenha_ghost_green(ghg_1, ghg_2, ghg_3, ghg_4, buf_ghg, time_sec);
               if(y==y2-2)            lvl_1.y++;
                  if(keypressed()==key[KEY_P])
                  pause_p(frame_buffer);
            }
            }
            if((keypressed()==key[KEY_LEFT]||keypressed()==key[KEY_UP]||keypressed()==key[KEY_DOWN]))break;
       }}

      if(keypressed()==key[KEY_LEFT]&&lvl_1.fase[lvl_1.x][lvl_1.y-1]!=1){key_ant=2;
      while(!key[KEY_ESC]&& KEY_LEFT &&lvl_1.fase[lvl_1.x][lvl_1.y-1]!=1){
      if(y>0){y2=y-42;
      /* PONTUAÇÃO */
      if(lvl_1.fase[lvl_1.x][lvl_1.y-1]==0){
         lvl_1.fase[lvl_1.x][lvl_1.y-1]=-1; 
         lvl_1.pontos+=10;
         imprime_pontos(lvl_1.pontos, buf_score);
         }
            /* Movimento por 'quadrado' de 42x42 */
            while(y>y2 && !key[KEY_ESC]){desenha_pac_l(imagem5, imagem6, imagem7, imagem8, y, x, bufac, tempo);
            rest(TEMPOZ);y=y-2;
            desenha_ghost_red(ghr_1, ghr_2, ghr_3, ghr_4, buf_ghr, time_sec);
            desenha_ghost_blue(ghb_1, ghb_2, ghb_3, ghb_4, buf_ghb, time_sec);
            desenha_ghost_green(ghg_1, ghg_2, ghg_3, ghg_4, buf_ghg, time_sec);
               if(y==y2+2)            lvl_1.y--;
                  if(keypressed()==key[KEY_P])
                  pause_p(frame_buffer);
            }
            }
            if(keypressed()==key[KEY_RIGHT]||keypressed()==key[KEY_UP]||keypressed()==key[KEY_DOWN])break;
      }}

      if(keypressed()==key[KEY_DOWN]&&lvl_1.fase[lvl_1.x+1][lvl_1.y]!=1){key_ant=3;
      while((!key[KEY_ESC]&& KEY_DOWN)&&lvl_1.fase[lvl_1.x+1][lvl_1.y]!=1){
      if(x<RES_Y-62){x2=x+42;
      /* PONTUAÇÃO */
      if(lvl_1.fase[lvl_1.x+1][lvl_1.y]==0){
         lvl_1.fase[lvl_1.x+1][lvl_1.y]=-1; 
         lvl_1.pontos+=10;
         imprime_pontos(lvl_1.pontos, buf_score);
         }
            /* Movimento por 'quadrado' de 42x42 */
            while(x<x2 && !key[KEY_ESC]){x=x+2;desenha_pac_down(pac_x4, pac_x5, pac_x6, pac_x7, y, x, bufac, tempo);
            rest(TEMPOZ);
            desenha_ghost_red(ghr_1, ghr_2, ghr_3, ghr_4, buf_ghr, time_sec);
            desenha_ghost_blue(ghb_1, ghb_2, ghb_3, ghb_4, buf_ghb, time_sec);
            desenha_ghost_green(ghg_1, ghg_2, ghg_3, ghg_4, buf_ghg, time_sec);
               if(x==x2-2)            lvl_1.x++;
                  if(keypressed()==key[KEY_P])
                  pause_p(frame_buffer);
            }
            }
            if(keypressed()==key[KEY_LEFT]||keypressed()==key[KEY_RIGHT]||keypressed()==key[KEY_UP])break;
      }}

      if(keypressed()==key[KEY_UP]&&lvl_1.fase[lvl_1.x-1][lvl_1.y]!=1){key_ant=4;
      while((!key[KEY_ESC]&& KEY_UP)&&lvl_1.fase[lvl_1.x-1][lvl_1.y]!=1){
      if(x>0){x2=x-42;
      /* PONTUAÇÃO */
      if(lvl_1.fase[lvl_1.x-1][lvl_1.y]==0){
         lvl_1.fase[lvl_1.x-1][lvl_1.y]=-1; 
         lvl_1.pontos+=10;
         imprime_pontos(lvl_1.pontos, buf_score);
         }
            /* Movimento por 'quadrado' de 42x42 */
            while(x>x2 && !key[KEY_ESC]){x=x-2;desenha_pac_up(pac_x0, pac_x1, pac_x2, pac_x3, y, x, bufac, tempo);
            rest(TEMPOZ);
            desenha_ghost_red(ghr_1, ghr_2, ghr_3, ghr_4, buf_ghr, time_sec);
            desenha_ghost_blue(ghb_1, ghb_2, ghb_3, ghb_4, buf_ghb, time_sec);
            desenha_ghost_green(ghg_1, ghg_2, ghg_3, ghg_4, buf_ghg, time_sec);
               if(x==x2+2)            lvl_1.x--;
                  if(keypressed()==key[KEY_P])
                  pause_p(frame_buffer);
            }
            }
            if(keypressed()==key[KEY_LEFT]||keypressed()==key[KEY_DOWN]||keypressed()==key[KEY_RIGHT])break;
      }}
      if(lvl_1.pontos>978&&lvl_1.pontos<999){
	while(lvl_1.pontos>978&&lvl_1.pontos<1000){
	lvl_1.pontos++;
	rest(100);
	imprime_pontos(lvl_1.pontos, buf_score);
	}
	int uo=0;
	clear(screen);
	while(uo<10){
	 texto_ganhou(60, 200, 1000);
	rest(50);
	 texto_ganhou(60, 200, 13300000);
	rest(50);
	 texto_ganhou(60, 200, 13000000);
	rest(50);
	 texto_ganhou(60, 200, -1);
	rest(50);
	 uo++;
	}
	break;
      }

	
}


deinit();

return 0;

}

END_OF_MAIN()


				
