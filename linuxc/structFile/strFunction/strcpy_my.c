/*************************************************************************
    > File Name: strcpy_my.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 28 Mar 2018 12:15:05 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcpy_my(char* des,const char* src);
char* strcpy_my(char* des,const char* src)
{
    if(des == NULL||src == NULL)
        return -1;
    char* temp = des;
    while((*des++ = * src++)!='\0');
    return temp;

}


int main()
{
    char source[] = "abcdefsdfs";
    char des[50];
    if(strncpy(des,source,sizeof(des)))
        printf("success!\n");

    printf("%d,%d\n",sizeof(source),strlen(source));
    printf("%d,%d\n",sizeof(des),strlen(des));
}
