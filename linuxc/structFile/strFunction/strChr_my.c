/*************************************************************************
    > File Name: strChr_my.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 28 Mar 2018 01:42:03 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "abcdef";
    char c;
    char * p = NULL;
    printf("input the need serach char\n");
    scanf("%c",&c);
    p=strchr(str,c);

    printf("the find character is %c\n",*p);



}


