#include <stdio.h>

int main()
{
	typedef struct A{
		char t;
		char k;
		unsigned short i;
		unsigned long m;
	} temp;

	temp tmp;
	char t;
	char k;
	unsigned short i;
	unsigned int l;
	long n;
	unsigned long m;
	printf("the size if %d %d %d %d %d %d\n",sizeof(t),sizeof(k),sizeof(i),sizeof(l),sizeof(n),sizeof(m));
	printf("the size is %d\n",sizeof(tmp));

	printf("the long is %d %d %d\n",sizeof(short int),sizeof(long),sizeof(double));
}
