#include <iostream>

using namespace std;

int cols[8];
//queue行坐标
int queueList[8];
//棋盘
int matrix[8][8];

int count = 0;

bool isSafe(int col,int row,int ql[])
{
    for(int i=0;i<col;i++)
    {
        if(ql[i]==row)
            return false;
        if(i==col)
            return false;
        if (ql[i]-i == row - col || ql[i] + i == row + col)
        {
            return false;
        }
    }

    return true;
}
/*
bool dfs(int col,int ql[])
{
    int row = 0;
    bool foundSafePos = false;
    if(col==8)
    {
        foundSafePos = true;
        for(int i=0;i<8;i++)
            cout << queueList[i]<<" ";
        cout << endl;
        count ++;
    }
    else
    {
        while(row<8  && !foundSafePos)
        {
            if(isSafe(col,row,ql))
             {
                  ql[col] = row;
                  foundSafePos = dfs(col+1,ql);
                   if (!foundSafePos)
                   {
                        row++;
                   }
             }
             else
             {
                  row++;
             }
        }
    }

    return foundSafePos;
}
*/
void dfs2(int col,int ql[])
{
    int row = 0;
    if(col==8)
    {
        cout << "========================"<<endl;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(queueList[j]==i)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
        cout << "========================"<<endl;
        count ++;
    }
    else
    {
        while(row<8)
        {
            if(isSafe(col,row,ql))
             {
                  ql[col] = row;
                  dfs2(col+1,ql);


             }
             row++;
        }
    }
}

int main()
{

    count = 0;
    dfs2(0,queueList);
    cout << count  << endl;
    return 0;
}
