#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct temp
{
	char c;
	int n;
}tmp;

struct temp getMaxCount(char*str)
{
	char* ps=str;
	char c = '\0';
	
	size_t counts[256]={0};
	for(const char*p= ps;*p;++p)
	{
		++counts[*p];
		if(counts[*p]>counts[c])
			c=*p;
	}
	tmp.c=c;
	tmp.n=counts[c];
		
	return tmp;
}

int main()
{
	struct temp tmp;
	int n=0;
	char* ps="hello woorld";
	tmp=getMaxCount(ps);
	printf("%c %d\n",tmp.c,tmp.n);
}
