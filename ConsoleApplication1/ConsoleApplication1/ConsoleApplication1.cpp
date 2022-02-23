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

void step(int **mas,int n, int m);
void move(int **mas, int s, int n, int m);

int main()
{
    int N = 13;
	int M = 13;
    int** m = new int*[N];
    for (int i = 0; i < N; i++)
    {
		m[i] = new int[M];
    }
	
    for(int i=0;i<N;i++)
	{
		for(int t=0;t<M;t++)
		{
			m[i][t]=0;
		}
	}
   
    step(m, N, M);
    while (true)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 72: //UP
                step(m, N, M);
                move(m, UP, N, M);
                break;
            case 80: //DOWN
                step(m, N, M);
                move(m, DOWN, N, M);

                break;
            case 75: //LEFT
                step(m, N, M);
                move(m, LEFT, N, M);

                break;
            case 77: //RIGHT
                step(m, N, M);
                move(m, RIGHT, N, M);

                break;
            }
        }
    }

    /*
    
    */
}
void move(int **mas, int s, int n, int m)
{
    switch (s)
    {
    case DOWN:
        for (int xy = 0; xy < n * m; xy++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int t = 0; t < m; t++)
                {
                    if (mas[i][t] != 0)
                    {
                        if (t + 1 <= m && mas[i][t + 1] == 0)
                        {
                            mas[i][t + 1] = mas[i][t];
                            mas[i][t] = 0;
                        }
                    }
                }
            }			
        }
    case UP:
        for (int i = 0; i < n; i++)
        {
            for (int t = 0; t < m; t++)
            {
                if (t >= 1 && mas[i][t - 1] == 0)
                {
                    mas[i][t-1] = mas[i][t];
                    mas[i][t] = 0;
                }
            }

        }
    case LEFT:
        for (int i = 0; i < n; i++)
        {
            for (int t = 0; t < m; t++)
            {
                if (i >= 1 && mas[i-1][t] == 0)
                {
                    mas[i - 1][t] = mas[i][t];
                    mas[i][t] = 0;
                }
            }

        }
    case RIGHT:
        for (int i = 0; i < n; i++)
        {
            for (int t = 0; t < m; t++)
            {
                if (i < n-1 && mas[i+1][t] == 0)
                {
                    mas[i + 1][t] = mas[i][t];
                    mas[i][t] = 0;
                }
            }

        }
    }
}

void step(int **mas,int n, int m)
{
    system("CLS");
    Cub c;
    if (mas[c.getX()][c.getY()] == 0)
    {
        mas[c.getX()][c.getY()] = c.getNum();
    }  
    

    for (int i = 0; i < n; i++)
    {
		for(int t=0;t<m;t++)
		{			
			if (mas[i][t] != 0)
        	{
				std::cout<<mas[i][t];
            	//std::cout << std::setw(4);
        	}
            else
            {
                std::cout << 'C';// << std::setw(4);
            }
		}
        std::cout << std::endl;
    }

}


