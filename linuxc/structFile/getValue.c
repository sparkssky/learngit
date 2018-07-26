#include <stdio.h>
#include <stdlib.h>

double getValue()
{
	double res=0;
	int i =2;
	while(i<42)
	{
		res+=1/i;
		i+=2;
	}
	return res;
}
