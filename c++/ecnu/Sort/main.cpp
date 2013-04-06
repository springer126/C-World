#include <iostream>
#include <algorithm>              
using namespace std;
      
int main()
{
    char s[101];
	while(gets(s))
	{
		int n = strlen(s);
		sort(s,s+n);
		puts(s);
		while(next_permutation(s, s+n))
            puts(s);

	}
	return 0;
}