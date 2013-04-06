/*
 * Î´ÃüÃû.c
 * 
 * Copyright 2013 superadministator <superadministator@SPRINGER>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <wait.h>

void printEnv()
{
	
	}

int main(int argc, char **argv)
{
	time_t t;
	struct tm *tt;
	char buf[50];
	size_t len;
	int i;
	for(i=0;i<10;i++)
	{
		time(&t);
		printf("%ld",t);
		tt = localtime(&t);
		if((len = strftime(buf,50," %a %b %d %X %Z %Y\n",tt))!=0)
			printf(buf);
		
	}
	
	printf("%s \n",getenv("HOME"));
	return 0;
}

