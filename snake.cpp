#include "snake.h"
#include <windows.h>

#define width 170
#define height 40

Snake::Snake(COORD pos,int v)
{
    this->pos=pos;
    length=1;
    direction='n';
    vel=v;
    body.push_back(pos);
}

void Snake::grow()
{
    length++;
}
bool Snake::eaten(COORD food)
{
    if(pos.X==food.X && pos.Y==food.Y)
        return true;
    else
        return false;
}

vector <COORD> Snake::get_body()
{
    return body;
}

COORD Snake::head_pos()
{
    return pos;
}

void Snake::change_direction(char d)
{
    direction=d;
}

void Snake::move_snake()
{
    switch(direction)
    {
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }
    body.push_back(pos);
    if(body.size()>length)
    {
        body.erase(body.begin());
    }
}

void Snake::teleport()
{
    if(pos.Y>height-2)
     pos.Y=1;
   if(pos.Y<1)
     pos.Y=height-2;
   if(pos.X>width-2)
     pos.X=1;
   if(pos.X<1)
    pos.X=width-2;

}

bool Snake::collided()
{
    for(int i=0;i<body.size()-1;i++)
    {
        if(body[i].X==pos.X && body[i].Y==pos.Y)
            return true;
    }
    return false;
}


