/*

ASCII:
      
      Seta Direita:   77   =   'l'
      Seta Esquerda:  75   =   'j'
      Seta Baixo:     80   =   'k'
      Seta Cima:      72   =   'i'
            
PACMAN RUDIMENTAR
Versão Terminal

*/

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define DIM 15
#define COL 11
#define WALL -80

#define RES_Y 480
#define RES_X 640
#define RES_Y1 464
#define RES_X1 848

#define BL 42
#define AB 14
#define AC 33

#define COR_AM 13300000
#define COR_AZ 1000
#define COR_ROSA -1

#define TEMPOZ 8

    typedef struct fase{
            int fase[COL][DIM];
            int x, y;
            int pontos;
            }Tfase;
    Tfase lvl_1;

    typedef struct fildi{
            int pac[COL][DIM];
            int graph[RES_X][RES_Y];
            }Tpos;

    Tpos gh1, gh2, gh3;
    int *posr = &gh3.pac[6][8];
    int *posb = &gh1.pac[5][8];
    int *posg = &gh2.pac[5][7];
            
    Tpos field;
    int *pos = &field.pac[0][0];
    

    typedef struct fantasma{
            int x;
            int y;
            }Tfantasma;
    Tfantasma fant;


    char *phant, ch, PACMAN[DIM][DIM], aux, aux2=' ';
    char  Maux=' ';
    int i, c, j, col=DIM/2, lin=DIM-1, pts=0, remaing=0, M1=DIM/2, M2=DIM/2, move=0, life = 3;

/* ---- NOMES DAS FUNÇÕES ----

zeraVariaveis();
zeraMatriz();
criaField();
telaOp();


** do{
** ch = getch();


phanton_move();
pacman_move();
insprime();
check_win();
dead_check();


** }while(ch!='q');

var_zera();
EXIT_GAME();

*/

/*

Inicia variáveis

*/

void posicao(){
     
     }

void zeraVariaveis()
{
     PACMAN[DIM][DIM], aux, aux2=' ';
     Maux=' ';
     col=DIM/2; 
     lin=DIM-1; 
     pts=0; 
     remaing=0;
     M1=DIM/2; 
     M2=DIM/2; 
     move=0; 
     life = 3;     
}
/*

Zerando a Matriz(PACMAN)

*/
void zeraMatriz()
{
    for(i=0; i<DIM; i++){
             for(c=0; c<DIM; c++){
             PACMAN[i][c]=' ';
             }
    }
}

/*

Colocando os pontos

*/
void fase(int x, int y){
    for(x=0; x<DIM; x++){
             for(y=0; y<COL; y++){
             if(y==1&&x!=0&&x!=DIM-1&&x!=DIM/2||y==COL-2&&x!=0&&x!=DIM-1&&x!=DIM/2||x==1&&y!=COL-1&&y!=0&&y!=COL/2||x==DIM-2&&y!=0&&y!=COL/2&&y!=COL-1){ 
                                         lvl_1.fase[x][y]=2;
                                         }
             else if(x==0&&y==0||x==0&&y==COL-1||x==DIM-1&&y==COL-1||x==DIM-1&&y==0){
                  lvl_1.fase[x][y]=2;
                  }
             else {
                   lvl_1.fase[x][y]=1;
                   remaing++;
                  }
             }
    }

          // Posiçao PacChuqMan e seus amiguenhos Ghosts
             PACMAN[DIM-1][DIM/2]='<';
             PACMAN[DIM/2][DIM/2]='M';
             phant= &PACMAN[DIM-1][DIM/2];
}

/*

TELA DE BOAS VINDAS

*/
void telaOp(){
     printf("    __   __   __          __             \n");
     printf("   |  | |  | |    |\\  /| |  | |\\  |     \n");
     printf("   |__| |__| |    | \\/ | |__| | \\ |     \n");
     printf("   |    |  | |    |    | |  | |  \\|      \n");
     printf("   |    |  | |__  |    | |  | |   |      v. 0.3\n\n");
     printf("   Aperte Enter para comecar a jogar.\n\n1 Player <start>\n2 Player <start>\n\n\nby: Murillo Vieira");
getchar();
}

/*

IMPRIMINDO A CADA VEZ

*/
void insprime(){

   system("cls");

   printf(" *Vidas: ");
   for(i=0; i<life; i++){
       printf("%c", 3);
       }
   printf("\n\n *Pontos: %4d\n\n",pts);

          for(i=0; i<DIM; i++){
             for(c=0; c<DIM; c++){
             printf("%c",PACMAN[i][c]);
                 if(PACMAN[i][c]==-79&&PACMAN[i][c+1]==-79&&PACMAN[i][c]==-79&&PACMAN[i][c-1]==-79||PACMAN[i][c]==-79&&PACMAN[i][c+1]==-79)
                    printf("%c",WALL);
                 else
                    printf(" ");
             }
          printf("\n");
          }

}

/*

PHANTON'S  PART 

*/
void phanton_move(){
move=0;
if(ch==75||ch==77||ch==80||ch==72){
   if(M1==lin){
      if(M2<col&&PACMAN[M1][M2+1]!=-79){
      PACMAN[M1][M2]=Maux;
      M2++; move++;
      Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
      phant= &PACMAN[M1][M2];
      PACMAN[M1][M2]='M';
      }

      if(M2>col&&PACMAN[M1][M2-1]!=-79){
      PACMAN[M1][M2]=Maux;
      M2--;move++;
      Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
      phant= &PACMAN[M1][M2];
      PACMAN[M1][M2]='M';
      }
   }
   
   else if(M1<lin&&PACMAN[M1+1][M2]!=-79&&move==0){
   PACMAN[M1][M2]=Maux;
   M1++;move++;
   Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
   phant= &PACMAN[M1][M2];
   PACMAN[M1][M2]='M';
   }
   
   else if(M1>lin&&PACMAN[M1-1][M2]!=-79&&move==0){
   PACMAN[M1][M2]=Maux;
   M1--;move++;
   Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
   phant= &PACMAN[M1][M2];
   PACMAN[M1][M2]='M';
   }

   if(move==0&&phant!= &PACMAN[lin][col]){

      if(M2<col&&PACMAN[M1][M2+1]!=-79){
      PACMAN[M1][M2]=Maux;
      M2++;move++;
      Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
      phant= &PACMAN[M1][M2];
      PACMAN[M1][M2]='M';
      }
      
      if(M2>col&&PACMAN[M1][M2-1]!=-79){
      PACMAN[M1][M2]=Maux;
      M2--;move++;
      Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
      phant= &PACMAN[M1][M2];
      PACMAN[M1][M2]='M';
      }
  }
  if(move==0)
      if(M2==col||M1==lin){
           if(PACMAN[M1-1][M2]!=-79){
              PACMAN[M1][M2]=Maux;
              M1--;move++;
              Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
              phant= &PACMAN[M1][M2];
              PACMAN[M1][M2]='M';
           }
          if(PACMAN[M1+1][M2]!=-79&&move==0){
              PACMAN[M1][M2]=Maux;
              M1++;move++;
              Maux= PACMAN[M1][M2];
            if(PACMAN[M1][M2]!=' '&&PACMAN[M1][M2]!='.')
               Maux=' ';
              phant= &PACMAN[M1][M2];
              phant= &PACMAN[M1][M2];
              PACMAN[M1][M2]='M';
           }
       }
   }  
}

/* 

Morreu 

*/
void dead_check(){
     
    if(M1==lin&&M2==col){
           life--;
           if(life==0){
           system ("cls");
           printf("\n GAME OVER! \n\n - Aperte qualquer tecla para jogar outra vez.");
           getchar();
           }
           
           printf("\n- YOU ARE DEAD -\n\n\n Faca como o Raul Seixas e 'Tente outra vez!'");
           PACMAN[lin][col]=' ';    PACMAN[M1][M2]=' ';    PACMAN[DIM-1][DIM/2]='<';    lin=DIM-1;    col=DIM/2;     move=-1;
     }
}

/* 

Movimentação PACMAN 

*/
void pacman_move(){
    if(ch==77&&col!=DIM-1&&PACMAN[lin][col+1]!=-79){
               if(PACMAN[lin][col+1]=='.'){
                  remaing--;
                  pts= pts+10;
                  }
               if(PACMAN[lin][col+1]==-72){
                  pts= pts+100;
                  }
               if(col < DIM-1)col++;
               if(col!=DIM){
                      PACMAN[lin][col]='<';
                      PACMAN[lin][col-1]=' ';
                      }
               }
    if(ch==75&&col!=0&&PACMAN[lin][col-1]!=-79){
               if(PACMAN[lin][col-1]=='.'){
                  remaing--;
                  pts= pts+10;
                  }
               if(PACMAN[lin][col-1]==-72){
                  pts= pts+100;
                  }
               if(col > 0)col--;
                      PACMAN[lin][col]='>';
                      PACMAN[lin][col+1]=' ';
               }
    if(ch==80&&lin!=DIM-1&&PACMAN[lin+1][col]!=-79){
               if(PACMAN[lin+1][col]=='.'){
                  remaing--;
                  pts= pts+10;
                  }
               if(PACMAN[lin+1][col]==-72){
                  pts= pts+100;
                  }
               if(lin < DIM-1)lin++;
                      PACMAN[lin][col]='^';
                      PACMAN[lin-1][col]=' ';
               }
    if(ch==72&&lin!=0&&PACMAN[lin-1][col]!=-79){
               if(PACMAN[lin-1][col]=='.'){
                  remaing--;
                  pts= pts+10;
                  }
               if(PACMAN[lin-1][col]==-72){
                  pts= pts+100;
                  }
               if(lin > 0)lin--;
                      PACMAN[lin][col]='v';
                      PACMAN[lin+1][col]=' ';
               }
}

/*

TELA VITÓRIA

*/
void check_win(){
     if(remaing==2){

   system("cls");
   printf("----------  Voce Ganhou UM MILHAO DE REAIS EM BARRAS DE OURO \n----------  Que valem mais do que dinheiroo! ----------");
   printf("\n\n\n -- YOU WIN -- ");
   getchar();
   exit(1);
   }
}
/*
void EXIT_GAME(){
     system("cls");

     printf("Deseja realmente sair?\n - (Y) = Sim\n - (N) = Nao");
     ch=getch();
     if(ch=='y')exit(0);
     else main();
}
*/ 
