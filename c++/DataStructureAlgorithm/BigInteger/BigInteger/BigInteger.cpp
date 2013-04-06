// BigInteger.cpp : Defines the entry point for the console application.
//
// BigInteger.cpp : 定义控制台应用程序的入口点。
// Author:wen hui
// Time: 2012-11-15
// Description: Big integer computing
#pragma comment(lib,"boost_regex-vc80-mt.lib");
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
boost::regex expression("[1-9]*");

class BigInteger
{	
public:
	BigInteger():length(0){}
	BigInteger(string &str):data(str),length(str.length()){}
	int Length(){return data.size();}
	void Input()
	{	
		string s;
		smatch sm;
		getline(std::cin,s);
		data = s;
		/*if(boost::regex_match(s,sm,expression))
		{
			data = s;
		}*/
	}
	BigInteger& Add(BigInteger &integer)
	{
		int carry,i,j,k,add1,add2;
		i = this->Length();
		j = integer.Length();
		k = i>j?i:j;
		string result(k,'\0');
		result[k]='\0';
		for(carry=0;k>0;k--,i--,j--)
		{
			add1=i>0?data[i-1]-'0':0;
			add2=j>0?integer.data[j-1]-'0':0;
			result[k-1]=(add1+add2+carry>=10?add1+add2+carry-10:add1+add2+carry)+'0';
			carry=add1+add2+carry<10?0:1;		
		}
		data = result;
		return *this;
	}
	
	int Compare(BigInteger &integer)
	{
		int i = this->Length();
		int j = integer.Length();
		if(i>j)
		{
			return 1;
		}
		else if(i<j)
		{
			return -1;
		}
		else
		{
			int k;
			for (k=0;k<i;k++)
			{
				if(this->data[k]>integer.data[k])
					return 1;
				else if(this->data[k]<integer.data[k])
					return -1;
				else
					continue;
			}
			if(k==i-1)
				return 0;
		}
	}

	BigInteger& Sub(BigInteger &integer)
	{
		if(this->Compare(integer)==1)
		{
			int carry,i,j,k,add1,add2;
			i = this->Length();
			j = integer.Length();
			k = i>j?i:j;
			string result(k,'\0');
			result[k]='\0';
			for(carry=0;k>0;k--,i--,j--)
			{
				add1=i>0?data[i-1]-'0':0;
				add2=j>0?integer.data[j-1]-'0':0;
				result[k-1]=(add1-add2-carry>=0?add1-add2-carry:add1+10-add2-carry)+'0';
				carry=add1-add2-carry<0?1:0;		
			}
			data = result;
			return *this;
		}
		else if(this->Compare(integer)==-1)
		{
			integer.Sub(*this);
			return integer;
		}
		else
		{
			string s(1,'\0');
			data = s;
			return *this;
		}
		
	}

	void Output(){std::cout << data << std::endl;}
private:

	string data;
	int length;
};

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bigInteger;
	bigInteger.Input();
	bigInteger.Output();
	BigInteger bigInteger2;
	bigInteger2.Input();
	bigInteger2.Add(bigInteger);
	bigInteger2.Output();
	bigInteger2.Sub(bigInteger);
	bigInteger2.Output();

	BigInteger bigInteger3;
	bigInteger3.Input();
	bigInteger3.Sub(bigInteger2);
	bigInteger3.Output();
	return 0;
}

