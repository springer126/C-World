#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

#define MAX 100

string src;
string dst;

int len;

char path[2*MAX];
stack<char> s;
/*
cur: src当前入栈位置
clen:s当前pop的元素个数
opi:当前的操作步骤数
*/
void dfs(int cur,int clen,int opi)
{
    int i;
    char c;
    if(clen==len)
    {
        for(i=0;i<2*len;i++)
            cout << path[i] <<" ";
        cout <<endl;
        return ;
    }

    if(cur < len)
    {
        s.push(src.at(cur));
        path[opi] = 'i';
        dfs(cur + 1, clen, opi + 1);
        s.pop();
    }

    if(!s.empty() && (c = s.top())==dst.at(clen))
    {
        s.pop();
        path[opi] = 'o';
        dfs(cur,clen+1,opi+1);
        s.push(c);
    }
}

int main()
{
    while(cin >> src >> dst)
    {
        while(!s.empty())
            s.pop();
        cout << "["<<endl;
        if(src.length()==dst.length())
        {
            len = src.length();
            dfs(0,0,0);
        }
        cout << "]"<<endl;
    }


    return 0;
}
