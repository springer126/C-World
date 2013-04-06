#include <iostream>
#include <string>
#include <list>

using namespace std;

int count;

template<class T>
void Swap(T &t1,T &t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template<class T>
void perm(T list[],int k,int m)
{
	int i;
	if(k==m)
	{
		count ++;
		cout <<count <<" : ";
		for (i=0;i<=m;i++)
			cout <<list[i]<<" ";
		cout <<endl;
	}
	else
	{
		for(i=k;i<=m;i++)
		{
			Swap(list[k],list[i]);
			perm(list,k+1,m);
			Swap(list[k],list[i]);
		}
	}
}

int main(int argc,char *argv[])
{
	int len;
	count = 0;
	cout << "Input length of number:" <<endl;
	cin >> len;
	int* list = new int[len];
	for (int i=0;i<len;i++)
	{
		cin>>list[i];
	}
	perm(list,0,len-1);

	cout << "Whole Number is "<<count << endl;
	return 0;
}