// AReCollection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include "Stack.h"

class Position
{
public:
	int x;
	int y;
};

const int Max = 10;
int tag[Max];
int length;
int sum;


int **maze;
int row,col;
Position offset[4];


int lastoption = 3;


Stack<Position> *path;
//幂集
template <class T>
void Solve(T *p,int i)
{
	if (i == length)
	{
		for (int i=0;i<length;i++)
		{
			if(tag[i])
				std::cout << p[i];
		}
		std::cout <<std::endl;
		sum++;
	}
	else
	{
		tag[i] = 0;
		Solve(p,i+1);
		tag[i] = 1;
		Solve(p,i+1);
	}
}


//迷宫
bool FindPath(int i,int j)
{
	int option = 0;
	offset[0].x = 0;offset[0].y = 1;
	offset[1].x = 1;offset[1].y = 0;
	offset[2].x = 0;offset[2].y = -1;
	offset[3].x = -1;offset[3].y = 0;
	Position here;
	here.x = i;
	here.y = j;
	int r,c;
	if(i==row && j==col)
	{
		return true;
	}
	else
	{
		maze[i][j] = 1;
		while (option<=lastoption)
		{
			r= i+offset[option].x;
			c= j+offset[option].y;
			if(maze[r][c]==0 && FindPath(r,c))
			{
				path->Add(here);
				return true;
			}
			option++;
		}
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *str = "ABCDE";
	sum = 0;
	length = strlen(str);
	std::cout << length <<std::endl;
	memset(tag,1,sizeof(tag)/sizeof(int));
	Solve(str,0);
	std::cout << sum <<std::endl;
	
	std::cout << "Input row and col:";
	if(std::cin >> row >> col)
	{
		maze  = new int*[row+2];
		for (int i=0;i<row+2;i++)
		{
			maze[i] = new int[col+2];
			for (int j =0;j<col+2;j++)
			{
				maze[i][j] = -1;
			}
		}
		
		for (int i=1;i<=row;i++)
		{
			for (int j=1;j<=col;j++)
			{
				std::cin >> maze[i][j];
			}
		}

		//offset[0].x = 0;offset[0].y = 1;
		//offset[1].x = 1;offset[1].y = 0;
		//offset[2].x = 0;offset[2].y = -1;
		//offset[3].x = -1;offset[3].y = 0;

		path = new Stack<Position>(row*col);
		//Position here;
		//here.x = 1;
		//here.y = 1;
		//maze[here.x][here.y] = 1;
		//int option = 0;
		//while (here.x !=row || here.y!=col)
		//{
		//	int r,c;
		//	while (option<=lastoption)
		//	{
		//		r= here.x+offset[option].x;
		//		c= here.y+offset[option].y;
		//		if(maze[r][c]==0)
		//			break;
		//		option++;
		//	}

		//	if(option<=lastoption)
		//	{
		//		path->Add(here);
		//		here.x = r;
		//		here.y = c;
		//		maze[r][c] = 1;
		//		option = 0;
		//	}
		//	else                          //如果here表示的当前位置无可通路径且不为终点，则回溯
		//	{
		//		if (path->IsEmpty())
		//		{
		//			std::cout << "No path"<< std::endl;
		//		}
		//		Position next;
		//		path->Delete(next);
		//		if(next.x == here.x)
		//			option=2+next.y-here.y;
		//		else
		//			option = 3+next.x-here.x;
		//		here = next;
		//	}
		//}

		FindPath(1,1);

		Position here;
		if (!path->IsEmpty())
		{
			while(!path->IsEmpty())
			{
				std::cout <<"(" <<path->Top().x<<","<<path->Top().y<<")";
				path->Delete(here);
			}
		}
		else
		{
			std::cout << "No path.";
		}
		std::cout <<std::endl;
	}

	return 0;
}

