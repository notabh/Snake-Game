#include <iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>


#include"snake.h"
#include"Food.h"

using namespace std;
#define width 170
#define height 40
Snake snake({10,10},1);
Food food;

void board()
{
   vector<COORD> body=snake.get_body();
   for(int i=0;i<height;i++)
   {
       cout<<"\t\t\t#";
       for(int j=1;j<width-1;j++)
       {
           if(i==0 | i==height-1)
            cout<<"#";
           else if(i==snake.head_pos().Y && j==snake.head_pos().X)
            cout<<"0";
           else  if(i==food.get_pos().Y && j==food.get_pos().X)
            cout<<"*";
           else
           {
               bool isbody=false;
               for(int k=0;k<body.size()-1;k++)
               {
                   if(i==body[k].Y && j==body[k].X)
                   {
                      cout<<"o";
                      isbody=true;
                      break;
                   }
               }
               if(!isbody)
                cout<<" ";
           }

       }
       cout<<"#\n";
   }
}

int main()
{
    int score=0;
    srand(time(NULL));
    food.gen_food();
    while(true)
    {
        cout<<"Your Score="<<score<<endl;
       board();
       if(kbhit())
       {
           switch(getch())
         {
           case 'w':snake.change_direction('u');break;
           case 's':snake.change_direction('d');break;
           case 'a':snake.change_direction('l');break;
           case 'd':snake.change_direction('r');break;
         }
       }

       if(snake.eaten(food.get_pos()))
      {
        snake.grow();
        food.gen_food();
        score+=10;
      }

      if(snake.collided())
      {
          cout<<"GAME OVER"<<endl;
          cout<<"Your Final Score="<<score<<endl;
          return 0;
      }

       snake.move_snake();
       snake.teleport();
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0, 0});
    }
    return 0;
}
