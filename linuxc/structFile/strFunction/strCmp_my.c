/*************************************************************************
    > File Name: strcat_my.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 28 Mar 2018 01:08:38 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21
int main(void)
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    printf("input the s1\n");
    scanf("%s",s1);

    printf("input the s2\n");
    scanf("%s",s2);

    int res=strcmp(s1,s2);
    printf("the res is %d\n",res);
}



