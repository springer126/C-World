// ReplaceBlankspace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

void replace(char *s,int len)
{
	assert(s!=NULL && len>0);
	int numOfBlank = 0;
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			numOfBlank++;	
		}
		i++;
	}
	
	int afterlen = i+1+numOfBlank*2;
	if(afterlen>len)
		return;

	char *p1 = s+i,*p2 = s+i+numOfBlank*2;
	while (i>=0)
	{
		if(*p1==' ')
		{ 
			*p2 = '0';
			*(--p2) = '2';
			*(--p2) = '%';
			p2--;
			p1--;
		}
		else
		{
			*p2 = *p1;
			p1--;
			p2--;
		}
		i--;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char c[100] = "wen hui 123";
	printf("%d\n",sizeof(c));
	printf("%s\n",c);
	replace(c,sizeof(c));
	printf("%s\n",c);
	return 0;
}

