#include <iostream>
#include <stdlib.h>t
#include <conio.h>
#include <Windows.h>
#include <iomanip>

enum S { UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4 };
class Cub
{
    int num;
    int x;
    int y;
    int cubNum()
    {
        int r = 1 + (rand() % 1000);
        if (r % 2 == 0)
        {
            return 2;
        }
        return 4;
    }
public:
    Cub()
    {
        num = cubNum();
        x = rand() % 3;
        y = 0;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getNum()
    {
        return num;
    }

};

void step(int* mas,int n);

int main()
{
    int N = 9;
    int* m = new int[N];
    for (int i = 0; i < N; i++)
    {
        m[i] = 0;
    }
   
    step(m, N);
    while (true)
    {
        if (kbhit())
        {
            switch (getch())
            {
            case 72: //UP
                step(m, N);
                break;
            case 80: //DOWN
                step(m, N);
                break;
            case 75: //
                step(m, N);
                break;
            case 77: //RIGHT
                step(m, N);
                break;
            }
        }
    }


}
void move(int *mas,int s,int n)
{
    switch (s)
    {
    case UP:
        for (int i = 0; i < n; i++)
        {
            if(mas[i])
        }
    }
}
void step(int* mas,int n)
{
    system("clear");
    Cub c;
    if (mas[c.getX() * c.getY()] == 0)
    {
        mas[c.getX() * c.getY()] = c.getNum();
    }  
    

    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
        {
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
        if (mas[i] != 0)
        {
            std::cout << std::setw(4) << mas[i];
        }
    }

}


