#include <cstdlib>
#include <iostream>

using namespace std;

/*
*compute 1's between from 1 and N
*
*
*/

int numberOf1(const char *str);
int power(int n);

int numberOf1Between1AndN(int n)
{
    if(n<=0)
        return 0;
    char str[50];
    sprintf(str,"%d",n);
    return numberOf1(str);
}

int numberOf1(const char *str)
{
    if(!str || *str<'0' || *str>'9' || *str=='\0')
        return 0;
    
    int first = *str-'0';
    unsigned int len = static_cast<unsigned int>(strlen(str));
    
    if(len==1 && first==0)
        return 0;
    if(len==1 && first>0)
        return 1;
    
    int numberOfFirst = 0;
    if(first>1)
        numberOfFirst = power(len-1);
    else
        numberOfFirst = atoi(str+1)+1;
    
    int numberOfOther = first*(len-1)*power(len-2);
    int numberRecursive = numberOf1(str+1);
    return numberOfFirst+numberOfOther+numberRecursive;
}

int power(int n)
{
    int ret = 1;
    for(int i=0;i<n;i++){
         ret = ret*10;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int n = 10;
    cout << numberOf1Between1AndN(n) << endl;
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
