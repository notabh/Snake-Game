#ifndef FOOD_H
#define FOOD_H

#include<windows.h>

class Food
{
    public:
        COORD get_pos();
        void gen_food();


    private:
        COORD pos;

};

#endif // FOOD_H
