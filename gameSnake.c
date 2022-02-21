#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


int largura = 20, altura = 20;
int x,y, gameOver, pointX, pointY, flag, continuidade, tamanho;

int tailX[50], tailY[50];


void update();
void draw();
void setup();
void input();

int main(){
    tamanho = 0;
    setup();
    while(gameOver == 0){
        //velocidade da cobra
        Sleep(150);
        draw();
        input();
        update();
        printf("Score: %d", tamanho);
    }

    printf("\n\n Fim de Jogo!");
    getch();
    return 0;
}

void draw(){
    system("cls");

    for (int i = 0; i < altura; i++){

            for(int j = 0; j < largura; j++)
            {
                //aumento da cobra
                if(x==pointX && y==pointY)
                {
                    Beep(600,250);
                    tamanho++;
                    label3:
                    pointX = rand() % 18;
                    if(pointX == 0)
                    {
                    goto label3;
                    }

                    label4:
                    pointY = rand() % 18;
                    if(pointY == 0)
                    {
                        goto label4;
                    }
                }

                if(i == 0 || i == altura - 1 || j==0 || j == largura - 1)
                {
                    //parede do jogo
                    printf("%c", 178);
                }else{
                    int ch=0;
                    if(pointX==i && pointY==j)
                        printf("%c", 1);

                    else if(x==i && y==j)
                        printf("%c", 254);
                	//area do jogo
                	else
                    {

                        for(int k=0; k<tamanho; k++)
                        {
                            if(i == tailX[k] && j == tailY[k])
                            {
                                printf("%c", 254);
                                ch=1;
                            }
                        }
                        if(ch==0)
                            printf(" ");
                }
            }
            }
            printf("\n");
    }


}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void setup(){
    gameOver = 0;
    x = largura/2;
    y = altura/2;

label1:
    pointX = rand() % altura;
    if(pointX == 0)
        {
            goto label1;
        }

label2:
    pointY = rand() % largura;
    if(pointY == 0)
        {
            goto label2;
        }
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void update()
{
    int vetPrevX = tailX[0];
    int vetPrevY = tailY[0];

    int vet2PrevX, vet2PrevY;

    tailX[0] = x;
    tailY[0] = y;

    for(int k = 1; k < tamanho; k++)
    {
        vet2PrevX = tailX[k];
        vet2PrevY = tailY[k];
        tailX[k] = vetPrevX;
        tailY[k] = vetPrevY;
        vetPrevX = vet2PrevX;
        vetPrevY = vet2PrevY;
    }

   switch(flag)
   {
    case 1:

        x--;
        break;
    case 2:
        x++;
        break;

   case 3:
        y--;
        break;

   case 4:
        y++;
        break;
   }
   //Fim de jogo
   if((x==0)||(y==0)||(y==altura-1)||(x==largura-1))
        gameOver = 1;

}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void input()
{
    continuidade = 0;
    if(kbhit()){
       switch(getch())
       {
       case'w':
           if(flag==2)
                continuidade = 1;

           if(continuidade==0)
            flag = 1;

            break;

        case's':
            if(flag==1)
                continuidade = 1;

           if(continuidade==0)
                flag = 2;
            break;

        case'a':
            if(flag==4)
                continuidade = 1;

           if(continuidade==0)
                flag = 3;
            break;

        case'd':
            if(flag==3)
                continuidade = 1;

           if(continuidade==0)
                flag = 4;
            break;

       case 'x':
            //sair
            gameOver=1;
            break;

       }



    }
}
