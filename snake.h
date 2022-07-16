#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include<vector>

using namespace std;
class Snake
{
    public:
        Snake(COORD pos,int v);
        COORD head_pos();
        void change_direction(char d);
        void move_snake();
        void teleport();
        vector <COORD> get_body();
        void grow();
        bool eaten(COORD food);
        bool collided();


    private:
        int length;
        char direction;
        int vel;
        COORD pos;
        vector <COORD> body;

};

#endif // SNAKE_H
