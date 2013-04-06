#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000
#define  MODULO (unsigned int)12345678910
//unsigned int s[MAX/2];

struct stack
{
	unsigned int s[MAX/2];
	int pos;
};

unsigned int pop(struct stack &st)
{
	return st.s[st.pos];
	st.pos--;
}

void push(struct stack &st,unsigned int value)
{
	st.pos++;
	st.s[st.pos]=value;
}

unsigned int top(struct stack &st)
{
	return st.s[st.pos];
}

void setTop(struct stack &st,unsigned int value)
{
	st.s[st.pos]=value;
}

int main()
{
	int N;
	int flag;
	int i,j=0,temp;
	
	struct stack s;
	memset(s.s,0,sizeof(s.s));
	s.pos=0;

	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&flag);
		if(flag==0)
			push(s,0);
		else
		{
			temp=top(s);
			j=s.pos-1;
			if(temp==0)//zheg
			{
				setTop(s,1);
			}
			else
			{
				pop(s);
				setTop(s,2*temp%MODULO);
			}

			while(s.s[j]!=0)
			{
				temp=s.s[j+1];
				s.s[j]=(s.s[j]+temp)%MODULO;
				j--;
				pop(s);
			}
		}			
	}

	printf("%d\n",s.s[0]);
	return 0;
}