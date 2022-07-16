#include "Food.h"
#include<cstdlib>

#define width 170
#define height 40

void Food::gen_food()
{
    pos.X=rand()%(width-2)+1;
    pos.Y=rand()%(height-2)+1;
}

COORD Food::get_pos()
{
    return pos;
}
