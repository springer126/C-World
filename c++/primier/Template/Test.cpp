#include "Test.h"
#include <iostream>


template <typename Type>
Test<Type>::Test(Type tt)
{
	t = tt;
}

template <typename Type>
Test<Type>::~Test()
{
}

template <typename Type>
void Test<Type>::PrintSelf()
{
	std::cout << t << std::endl;
}