#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int n;
int index;
stringstream ss;
string str;

void f(int a,int b,int k)
{
    ss << a << b;
    ss >> str;
    if(str.length()>=k)
    {
        cout <<"Case #"<<index<<": "<<str.at(k-1)<<endl;
    }
    else
    {
        ss.clear();
        ss << a;
        ss>>str;
        f(b,a+b,k-str.length());
    }
}

int main()
{
    int a,b,k;
    if(cin>>n)
    {
        index = 1;
        while(n-- > 0)
        {
            if(cin >> a>> b>>k)
            {
                f(a,b,k);
                index++;
            }
        }
    }
}