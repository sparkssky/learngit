#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[]="ABCDEF123gh";
	int len = strlen(str);
	char* p1 = str;//字符串首地址
	char* p2 = str+len-1;//字符串结尾

	//循环逆序赋值
	while(p1<p2)
	{
		char c = *p1;
		*p1= *p2;
		*p2= c;
		++p1;
		--p2;
	}
	printf("str now is %s\n",str);
	return 0;
}
