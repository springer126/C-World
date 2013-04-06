// BigIntAdd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int main(){	char a[501], b[501], c[501];	int carry,i,j,k,add1,add2;	while(scanf("%s %s",a,b)!=EOF)	{		i=strlen(a);		j=strlen(b);		k=i>j?i:j;		c[k+1]='\0';		for(carry=0;k>=0;k--,i--,j--)		{			add1=i<0?0:a[i]-'\0';			add2=j<0?0:b[j]-'\0';			c[k]=(add1+add2+carry>=10?add1+add2+carry-10:add1+add2+carry)+'0';			carry=add1+add2+carry<10?0:1;				}	    if(carry) printf("1");		printf("%s\n",c);	}	return 0;}