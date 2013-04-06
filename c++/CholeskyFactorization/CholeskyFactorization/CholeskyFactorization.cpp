// CholeskyFactorization.cpp : Defines the entry point for the console application.
#include <iostream>
#include <math.h>
#include <process.h>
using namespace std;

int main()
{
	int order;
	double *diag;
	double **matrix,**answer;
	cin>>order;
	matrix = new double*[order];
	answer = new double*[order];
	diag = new double[order];

	for (int i=0;i<order;i++)
	{
		matrix[i] = new double[order];
		answer[i] = new double[order];
		diag[i] = 0;
		for(int j=0;j<order;j++)
		{
			cin >> matrix[i][j];
			answer[i][j] = 0.0;
		}
	}

	for (int i=0;i<order;i++)
	{
		for (int j=i;j<order;j++)
		{
			if (matrix[i][j]!=matrix[j][i])
			{
				cout << "非对称矩阵..."<<endl;
				exit(-1);
			}
		}
	}

	
	for (int i=0;i<order;i++)
	{
		
		if(matrix[i][i]<=0)
		{
			cout << "非正定矩阵..."<<endl;
			exit(-1);
		}
		diag[i] = sqrt(matrix[i][i]);
		answer[i][i] = diag[i];
		for (int j=i+1;j<order;j++)
		{
			answer[j][i] = matrix[j][i]/diag[i];
		}

		for (int m=i+1;m<order;m++)
		{
			for (int n=i+1;n<order;n++)
			{
				matrix[m][n] -= answer[m][i]*answer[n][i];
			}
		}
	}

	//output result
	for (int i=0;i<order;i++)
	{
		for (int j=0;j<order;j++)
		{
			cout << answer[i][j]<< " ";
		}
		cout << endl;
	}
	cout << endl;
	
	
	for (int i=0;i<order;i++)
	{
		delete matrix[i];
		delete answer[i];
	}
	delete diag;
	delete matrix;
	delete answer;

	return 0;
}
