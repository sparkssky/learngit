#include<stdio.h>

int main(void)
{
    char* p = NULL;

    int a = 0x1234;

    p = (char*)(&a);
   printf("the 低地址位的值为 %x\n",p[0]);
    if(p[0]==0x12)
        printf("big\n");
    if(p[0] == 0x34)
        printf("small\n");
}
