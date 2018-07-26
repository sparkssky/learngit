/*************************************************************************
    > File Name: Build.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Mon 09 Jul 2018 06:04:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_LENGTH 100

typedef char TELemType;

typedef struct BiTNode
{
    TELemType data;
    struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;



int main()
{
    printf("ceshi!\n");
    return 0;
}
