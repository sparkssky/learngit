#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(ini[] height);

int solution(char* height)
{
	if(height == NULL||strlen(height)<=2)
		return 0;

	int maxL=height[0];
	int len=strlen(height);
	int maxRs[strlen(height)];
	int watersum=0;

	int maxR=0;

	for(int i=len-1;i>=0;i--)
	{
		if(height[i]>maxR)
		{
		}
	}
}
