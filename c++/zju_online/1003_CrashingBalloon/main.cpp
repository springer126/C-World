#include <iostream>
#include <cstring>
using namespace std;

const int NUM = 100;
int s1,s2;
int mark[NUM+1];

//指示两个报分是否合法
int flag1,flag2;

//溢出
bool upheld()
{
    int minS = min(s1,s2);
    int temp = s1*s2;
    int i;
    for(i=100;i>=1;i--)
    {
        if(minS%i==0)
            minS = minS/i;
    }
    if(minS!=1)
        return false;

    for(i=100;i>=1;i--)
    {
        if(temp%i==0)
            temp = temp/i;
    }

    return temp==1?false:true;
}


//ensure: x>y
void dfs(int x,int y,int fact)
{
    if(flag1)
        return;
    if(x ==1 && y==1)
    {
        flag1 = flag2 = 1;
    }
    else
    {
        if(y==1)
            flag2 = 1;
        if(fact<2)
            return;
        if(y%fact==0)
            dfs(x,y/fact,fact-1);
        if(x%fact==0)
            dfs(x/fact,y,fact-1);
        dfs(x,y,fact-1);
    }
}

int main()
{
    int result;
    while(cin>>s1>>s2)
    {
        flag1 = flag2 = 0;
        if(s1<s2)
        {
            s1 = s1^s2;
            s2 = s1^s2;
            s1 = s1^s2;
        }
        dfs(s1,s2,100);
        if(flag1 || !flag2)
            result = s1;
        else
            result = s2;
        cout << result <<endl;
    }
    return 0;
}
