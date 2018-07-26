/*************************************************************************
    > File Name: strstr_my.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 28 Mar 2018 01:50:58 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *s1=(char*)malloc(20);
    char *s2=(char*)malloc(20);


    char* des=NULL;
    scanf("%s",s1);
    printf("\n");
    scanf("%s",s2);
    printf("\n");

    des = strstr(s1,s2);
    printf("the  des is %s\n",des);

    free(s1);
    s1 =NULL;
    free(s2);
    s2=NULL;

}


