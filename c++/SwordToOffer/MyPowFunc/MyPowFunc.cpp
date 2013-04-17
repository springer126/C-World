// MyPowFunc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cmath>

bool g_InvalidInput = false;


double powerWithUnsignedInt(double base,unsigned int exponent);
double power(double base,int exponent)
{
	g_InvalidInput = false;
	if(abs(base-0.0) <= 0.000000001 && exponent<0)
	{
		g_InvalidInput = true;
		return 0;
	}

	double result = powerWithUnsignedInt(base,(unsigned int)(exponent>=0?exponent:-exponent));
	if(exponent<0)
		result =  1.0/result;
	
	return result;
}

double powerWithUnsignedInt(double base,unsigned int exponent)
{
	if(exponent==0)
		return 1;
	else if(exponent==1)
		return base;
	else
	{
		double result = powerWithUnsignedInt(base,exponent>>1);
		result = result*result;
		if(exponent & 0x1==1)
			result*=base;
		return result;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%lf\n",power(8,-5));
	
	return 0;
}

