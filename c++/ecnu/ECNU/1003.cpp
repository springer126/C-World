#include <iostream>
#include <string>
using namespace std;

char expression[4000];
char temp[400000];
int next[4000];
int stack[4000];
int top;

//�����startλ�ÿ�ʼ��stopλ�õı��ʽ��ֵ
int cal(int start,int stop);

//������ʽ�Ķ�ջ�ṹ
//next��ǰ�ַ�����ƥ�����ŵ�λ�ã�������ڣ�
//stackά������
void prefix()
{
	int i;top=-1;
	for (i=0;expression[i];++i)
	{
		next[i]=-1;
		if (expression[i]=='(') {stack[++top]=i;}
		if (expression[i]==')') {next[stack[top--]]=i;}
	}
}

//��ô�Nowλ�ÿ�ʼ������
int getnum(int &Now)
{
	int ans=0;
	if (expression[Now]=='(') 
	{ 
		ans= cal(Now+1,next[Now]-1);
		Now=next[Now]+1;
	}
	else
	{
		if (expression[Now]=='!')
		{
			Now++;
			ans=1-getnum(Now);
		}
		else
		{
			if (expression[Now]=='V') ans=1;
			if (expression[Now]=='F') ans=0;
			Now++;
		}
	}
	return ans;
}

//����򵥱��ʽ
void process(int &a,int b,char operation)
{
	if (operation=='&') a*=b;
	if (operation=='|') a=(a==1 || b==1 ? 1 : 0);
	return ;
}


int cal(int start,int stop)
{
	int a,b,c;
	char op1,op2;
	if (next[start]==stop) return cal(start+1,stop-1);
	if (expression[start]=='!' && next[start+1]==stop) return 1-getnum(++start);

	a=0;op1='|';
	for (b=getnum(start);start<stop;)
	{
		op2=expression[start++];
		c=getnum(start);
		//�����һ�������Ϊ+,-����ǰ��һ�������Ϊ*/��ôǰһ��������ؿ�������
		if (op2=='|' || op1=='&')
		{
			process(a,b,op1);b=c;op1=op2;
		} 
		else
		{
			process(b,c,op2);
		}
	}
	process(a,b,op1);
	return a;
}

int main()
{
	int i,j,k,l;
	char c;
	
	i=0;
	while (cin.getline(temp,200000,'\n'))
	{
		i++;
		k=0;
		j=strlen(temp);
		for (l=0;l<j;++l) if (temp[l]!=' ') expression[k++]=temp[l];
		prefix();
		c= cal(0,k)==1 ? 'V' : 'F';
		cout<<"Expression "<<i<<": "<<c<<endl;
	}

	return 0;
}




