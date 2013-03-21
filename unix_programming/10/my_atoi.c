#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

//如果是0 或者出错都是返回0 如何区分呢？
//
int myatoi(const char* ptr)
{
	assert(ptr!=NULL);
	int neg_flag = 1;
	int res = 0;
	while(*ptr==' ')
		ptr++;
	if(*ptr=='+' || *ptr=='-')
		neg_flag = (*ptr++)=='+'?1:0;
	
	if(!isdigit(*ptr))
	{
		printf("Invalid arguments\n");
		//errno = -1;
	}
	
	while(isdigit(*ptr))
		res = 10*res+(*ptr++ - '0');
		
	return neg_flag==1?res:0-res;
}


int main()
{
	printf("%d,%d\n",myatoi("  1091"),errno);
	printf("%d,%d\n",myatoi("981"),errno);
	printf("%d,%d\n",myatoi("o91"),errno);
	printf("%d,%d\n",myatoi(" +91"),errno);
	printf("%d,%d\n",myatoi("   -9981"),errno);
	printf("%d,%d\n",myatoi("   -+9981"),errno);
	printf("%d,%d\n",myatoi("   -+9981"),errno);
	printf("%d,%d\n",myatoi("   -0"),errno);
	printf("%d,%d\n",myatoi("0"),errno);
	
	int i=0;
	for(i=0;i<255;i++)
	{
		printf("%d,%s\n",i,strerror(i));
	}
	return 0;
}
