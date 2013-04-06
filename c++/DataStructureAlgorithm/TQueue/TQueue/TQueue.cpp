// TQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <memory>
using namespace std;


class Position
{
public:
	Position(int i=0,int j=0):x(i),y(j){}
	int x;
	int y;
};



int **maze;
int row,col;
Position offset[4];
int lastoption = 3;

//迷宫问题+最短路径
bool FindPath(Position start,Position finish,int &pathLen,Position * &path)
{
	if(start.x == finish.x && start.y== finish.y)
	{
		pathLen = 0;
		return true;
	}
	
	int numOfBbrs = 4;
	Position here,nbr;
	here.x = start.x;
	here.y = start.y;
	maze[start.x][start.y] = 2;
	Queue<Position> Q(row*col);
	do 
	{
		for (int i=0;i<numOfBbrs;i++)
		{
			nbr.x = here.x + offset[i].x;
			nbr.y = here.y + offset[i].y;
			if(maze[nbr.x][nbr.y]==0)
			{
				maze[nbr.x][nbr.y] = maze[here.x][here.y]+1;
				if(nbr.x == finish.x && nbr.y == finish.y)
				{
					break;
				}
				Q.Add(nbr);
			}
		}

		if(nbr.x == finish.x && nbr.y == finish.y)
			break;
		if(Q.IsEmpty())
			return false;
		Q.Delete(here);
	} while (true);
	
	pathLen = maze[finish.x][finish.y]-2;
	path = new Position[pathLen];

	here = finish;
	for (int j = pathLen-1;j>=0;j--)
	{
		path[j] = here;
		for (int i =0;i<numOfBbrs;i++)
		{
			nbr.x = here.x+offset[i].x;
			nbr.y = here.y + offset[i].y;
			if(maze[nbr.x][nbr.y]==j+2)
				break;
		}
		here = nbr;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if(std::cin >> row >> col)
	{
		maze = new int*[row+2];
		for (int i=0;i<row+2;i++)
		{
			maze[i] = new int[col+2];
		}
	}
	for (int i=1;i<=row;i++)
	{
		memset(maze[i],-1,sizeof(maze[i])/sizeof(int));
		for (int j=1;j<=col;j++)
		{
			std::cin >> maze[i][j];
		}
	}
	
	offset[0].x = 0;offset[0].y = 1;
	offset[1].x = 1;offset[1].y = 0;
	offset[2].x = 0;offset[2].y = -1;
	offset[3].x = -1;offset[3].y = 0;
	
	Position start(1,1),finish(row,col);
	int len;
	Position *path;
	if (FindPath(start,finish,len,path))
	{
		for (int i = 0;i<len;i++)
		{
			std::cout << "("<<path[i].x<<","<<path[i].y<<")";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout <<"No path" <<std::endl;
	}

	for (int i=1;i<=row;i++)
	{
		for (int j=1;j<=col;j++)
		{
			std::cout << maze[i][j];
		}
		std::cout<< std::endl;
	}
	return 0;
}

