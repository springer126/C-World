// �����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

//int a[3] = {0};
int *a;
int n,k;
int sum = 0;

//n������k������ϵ��Ƶ���n-1������k-1������ϣ�
//n-2������k-1������ϣ�����,ֱ��k-1������k-1������ϡ�����n-k-1�εݹ�
//�ݹ��ֹͣ������k=1

void combine(int n,int k)
{
	if(n<1 || k<1)
		return;
	if(k>n)
		return;

	for (int i=n;i>=k;i--)
	{
		a[k-1] = i;
		if(k>1)
			combine(i-1,k-1);
		else
		{
			for (int j=0;j<3;j++)
			{
				printf("%d ",a[j]);
			}
			printf("\n");
		}
	}
}

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quanxu(int *a,int m,int r)
{
	if(m<1 || r<1)
		return;
	if(r>m)
		return;
	
	if(r>1)
	{
		for (int i=0;i<m;i++)
		{
			swap(a[i],a[m-1]);
			quanxu(a,m-1,r-1);
			swap(a[i],a[m-1]);
		}
	}
	else
	{
		for (int i = 0;i<m;i++)
		{
			swap(a[i],a[m-1]);
			for (int j=n-1;j>n-1-k;j--)
			{
				printf("%d ",a[j]);
			}
			printf("\n");
			sum++;
			swap(a[i],a[m-1]);
		}
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//combine(5,3);


	scanf("%d %d",&n,&k);
	a = (int *)malloc(sizeof(int) * n);
	for (int i=0;i<n;i++)
	{
		a[i] = i+1;
	}

	sum = 0;
	quanxu(a,n,k);
	printf("%d ",sum);
	return 0;
}

