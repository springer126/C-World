#include "iostream"
using namespace std;

int main()
{
	int A,B,C;
	int ret;

	while(true)
	{
		ret=1;
		cin>>A>>B>>C;
		if(A==0 && B==0 && C==0)
			break;

		while(B)
		{
			if(B&1)
				ret=(ret*A)%C;
			A=(A%C)*(A%C);
			A%=C;
			B=B>>1;
		}

		cout<<ret<<endl;
	}

	return 0;
}

