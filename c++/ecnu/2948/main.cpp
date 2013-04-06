#include "iostream"
#include "string"
using namespace std;

#define N 100

struct telephone
{
	char tele[10];
	int time;
};

struct telephone s[N];


char judge(char ch)
{
	if(ch=='A' || ch=='B' || ch=='C')
		return '2';
	else if(ch=='D' || ch=='E' || ch=='F')
		return '3';
	else if(ch=='G' || ch=='H' || ch=='I')
		return '4';
	else if(ch=='J' || ch=='K' || ch=='L')
		return '5';
	else if(ch=='M' || ch=='N' || ch=='O')
		return '6';
	else if(ch=='P' || ch=='Q' || ch=='R' || ch=='S')
		return '7';
	else if(ch=='T' || ch=='U' || ch=='V')
		return '8';
	else if(ch=='W' || ch=='X' || ch=='Y'|| ch=='Z')
		return '9';
	
	else
		return ch;
}

void isExist(char* tel)
{
	int i;
	for(i=0;i<N && s[i].time!=0;i++)
	{
		if(strcmp(s[i].tele,tel)==0)
		{
			s[i].time++;
			break;
		}
	}
	
	if(s[i].time==0)
	{
		strcpy(s[i].tele,tel);
		s[i].time=1;
	}	
}

int main()
{
	int T;
	int i,j,k;
	struct telephone temp;
	char tel[10];
	string str;

	memset(s,0,sizeof(s));

	cin>>T;
	while(T--)
	{
		k=0;
		cin>>str;
		j=str.length();
		for(i=0;i<j;i++)
		{
			if(k==4)
					tel[k++]='-';
			if(str[i]!='-')
			{
				tel[k++]=judge(str[i]);
			}
		}
		tel[9]='\0';
		isExist(tel);
	}

	k=0;
	while(s[k].time!=0)
		k++;
	
	k--;
	for(i=0;i<k;i++)
		for(j=0;j<k-i;j++)
			if(s[j].time<s[j+1].time)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}

	
	for(i=0;i<=k;i++)
	{
		printf("%s %d\n",s[i].tele,s[i].time);
	}
	
	return 0;
}