#include <iostream>

using namespace std;
#define width 50
#define height 30
int x=10,y=10;
void board()
{
   for(int i=0;i<height;i++)
   {
       cout<<"\t\t\t#";
       for(int j=1;j<width-1;j++)
       {
           if(i==0 | i==height-1)
            cout<<"#";
           else
            cout<<" ";
       }
       cout<<"#\n";
   }

}

int main()
{
    cout<<"Is yhe hvdjsk kwhusns mjshysns "
    board();
    return 0;
}
