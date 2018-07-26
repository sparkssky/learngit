#include <stdio.h>
#include <stdlib.h>
int pop(int *);
int push(int);
void combination(int,int);
void combination(int m,int n)
{
	int temp=n;
	push(temp)
	while(1)
	{
		if(temp==1)
		{
			if(pop(&temp)&&stack[0]==n)
				break;
		}
		else if(push(--temp))
		{
			printf("%d%d%d",stack[0],stack[1],stack[2]);
			pop(&temp);
		}
	}
}
int push(int i)
{
	stack[++top]=i;
	if(top<2)
		return 0;
	else
		return 1;
}
int pop(int* i)
{
	*i = stack[top--];
	if(top>=0)
		return 0;
	else
		return 1;
}

