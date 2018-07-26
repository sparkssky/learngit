/*************************************************************************
    > File Name: sqr.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Wed 21 Mar 2018 03:37:26 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int num = 0;

    scanf("%d",&num);
    printf("the input num is %d\n",num);
    for(int i=1;i<=num;++i)
    {
        for(int j=1;j<=num;++j)
        {
            printf("%dx%d=%d ",i,j,i*j);
            if(j==num)
                printf("\n");
        }
    }
    return 0;
}

