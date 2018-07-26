/*************************************************************************
    > File Name: strtok_my.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 28 Mar 2018 02:25:54 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char* p1 =(char*)malloc(20);
    char* p2 =(char*)malloc(20);

    scanf("%s",p1);
    printf("\n");
    scanf("%s",p2);
    printf("\n");


    char* des=strtok(p1,p2);//first
    while(des)
    {
        printf("%s\n",des);
        des=strtok(NULL,p2);
    }
    free(p1);
    p1=NULL;
    free(p2);
    p2=NULL;
}


