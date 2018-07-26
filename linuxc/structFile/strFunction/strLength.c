/*************************************************************************
    > File Name: strLength.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Tue 27 Mar 2018 11:29:29 PM PDT
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[] = "To be or not to be";
    char str2[] = "To be or not to be !!!";
    unsigned int count = 0;

    while(str1[count]!='\0')
        ++count;
    printf("the count is %u\n",count);

    while(str2[count]!='\0')
        ++count;
    printf("the count is %u\n",count);
}


