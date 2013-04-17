#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char plainText[70];
char decrptText[70];
int plainCode[70];
int decrptCode[70];
int len;
int key;
//_' = 0, 'a' = 1, 'b' = 2, ..., 'z' = 26, and '.' = 27

int code(char c)
{
	if(c=='_')
		return 0;
	else if(c=='.')
		return 27;
	else if(c<='z' && c>='a')
		return c-'a'+1;
	else 
		return -1;
}

char getChar(int code)
{
	if(code==0)
		return '_';
	if(code==27)
		return '.';
	if(code>=1 && code <=26)
		return 'a'+code-1;
	return '\0';
}

void decrpt()
{
	int i,j;
	//decrptCode[i] = (plaincode[ki mod n] - i) mod 28.
	for(i = 0;i<len;i++)
	{
		decrptCode[i] = code(decrptText[i]);
		j = (decrptCode[i]+i)%28;
		plainCode[(key*i)%len] = j;
	}
	for(j=0;j<len;j++)
	{
		plainText[j] = getChar(plainCode[j]);
	}
	plainText[j] = '\0';
}

int main()
{
	while(scanf("%d",&key) && key!=0)
	{
		scanf("%s",decrptText);
		len = strlen(decrptText);
		decrpt();
		printf("%s\n",plainText);
	}
}
