#include<stdio.h>

void inverse(char*p)
{
	if(*p=='\0')
		return;
	inverse(p+1);
	printf("%c",*p);

}
int main()
{
	inverse("abc\0");
	return 0;
}
