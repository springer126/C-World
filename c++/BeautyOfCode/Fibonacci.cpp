#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//template <typename T>
//void Print(ostream &out,const Matrix<T> &m);

template <typename T>
class Matrix
{

template <typename TT>
friend void Print(ostream &out,const Matrix<TT> &m);

public:
	Matrix():row(0),col(0)
	{
		data = NULL;
	}

	Matrix(int r,int c):row(r),col(c)
	{
		data = new T*[row];
		for(int i = 0;i<row;i++)
		{
			data[i] = new T[col];
			for(int j=0;j<col;j++)
				data[i][j] = 0;
		}
		//memset(data,0,row*col);
	}

	Matrix(const Matrix &m)
	{
		this->row = m.row;
		this->col = m.col;
		data = new T*[row];
		for(int i=0;i<row;i++)
		{
			data[i] = new T[col];
			for(int j=0;i<col;j++)
				data[i][j] = m.Get(i,j);
		}
		//memcpy()
	}
	
	Matrix& operator=(const Matrix<T> &m)
	{
		if(this == &m)
			return *this;
		if(data!=NULL && (row!=m.row || col!=m.col))
		{
			for(int i=0;i<row;i++)
				delete [] data[i];
			delete[] data;
			this->row = m.row;
			this->col = m.col;
			data = new T*[row];
			for(int i=0;i<row;i++)
				data[i] = new T[col];
		}
		else if(data==NULL)
		{
			this->row = m.row;
			this->col = m.col;
			data = new T*[row];
			for(int i=0;i<row;i++)
				data[i] = new T[col];
		}
	//	cout << "1" <<endl;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				data[i][j] = m.Get(i,j);
		}
	//	cout << "2" <<endl;
		return *this;
	}

	void Power(int n)
	{
		if(row!=col || n<2)
			return ;
		T **temp,**result;	
		temp = new T*[row];
		result = new T*[row];
		for(int i = 0;i<row;i++)
		{
			temp[i] = new T[col];
			result[i] = new T[col];
			for(int j=0;j<col;j++)
			{
				temp[i][j] = 0;
				result[i][j] = data[i][j];
			}
		}
	//	cout << "Hello World" << endl;
		while((--n)>0)
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					for(int k=0;k<row;k++)
					{
						temp[i][j] += result[i][k]*data[k][j];
					}
				}
			}
			for(int i=0;i<row;i++)
			{
				memcpy(result[i],temp[i],col*sizeof(T));
				memset(temp[i],0,col*sizeof(T));
			}
		}

		for(int i=0;i<row;i++)
			memcpy(data[i],result[i],col*sizeof(T));

		for(int i=0;i<row;i++)
		{
			delete[] temp[i];
			delete[] result[i];
		}
		delete[] temp;
		delete[] result;
	}

	T Get(int m,int n) const
	{
		if(0<=m<row && 0<=n<col)
			return data[m][n];
	}

	void Set(T t)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				 data[i][j] = t;
			}
		}
	}
	
	void Set(int m,int n,T t)
	{
		if(0<=m<row && 0<=n<col)
			data[m][n] = t;
	}
	
	void Set()
	{
		srand(time(NULL));
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				 data[i][j] = rand()%10;
			}
		}
	}

	virtual ~Matrix()
	{
		for(int i=0;i<row;i++)
			delete[] data[i];
		
		delete[] data;
	}
private:
	int row;
	int col;
	T **data;
};

template <typename T>
void Print(ostream &out,const Matrix<T> &m)
{
	out << "Row : "<<m.row<<" , col : "<<m.col<<endl;
	for(int i=0;i<m.row;i++)
	{
		for(int j=0;j<m.col;j++)
		{
			out << m.data[i][j]<< " ";
		}
		out <<endl;
	}
}


int main()
{
	/*
	Matrix<int> m(4,4);
	m.Set();
	Print(std::cout,m);
	m.Power(2);
	Print(std::cout,m);
	m.Power(2);
	Print(std::cout,m);
	*/

	Matrix<int> m(3,3);
	m.Set(0,0,1);
	m.Set(0,1,1);
	m.Set(0,2,0);

	m.Set(1,0,1);
	m.Set(1,1,0);
	m.Set(1,2,1);
	
	m.Set(2,0,1);
	m.Set(2,1,0);
	m.Set(2,2,0);
	Print(cout,m);
	int n;
	Matrix<int> mm;
	while(cin>>n)
	{
		if(n==0)
			cout << "A(0) = 1" << endl;
		else if(n==1)
			cout << "A(1) = 2" << endl;
		else if(n==2)
			cout << "A(2) = 2" << endl;
		else
		{
			mm = m;
			mm.Power(n-2);
			Print(cout,mm);
			cout << "A("<<n<<") = "<<2*mm.Get(0,0)+2*mm.Get(1,0)+mm.Get(2,0)<<endl;
		}
	}
	return 0;
}
