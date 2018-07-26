/*************************************************************************
    > File Name: PreOrderTraverse_1.c
    > Author:yupeng
    > Mail: yupeng_199019@163.com
    > Created Time: Tue 10 Jul 2018 01:58:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <glib.h>


#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char TELemType;
typedef int SElemType;

typedef struct SqStack
{
    int stacksize;
    SElemType *base;
    SElemType *top;
}SqStack,*SqStackPointer;

typedef struct BinTNode
{
    char data;
    struct BinTNode *lchild,*rchild;
}*BiTree;

//初始化一个空栈
void InitStack(SqStackPointer s)
{
    s->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}
//push stack
void Push(SqStackPointer s,SElemType e)
{
    if((s->top-s->base)>s->stacksize)
    {

        s->base = (SElemType*)realloc(s->base,(s->stacksize+STACKINCREMENT*sizeof(SElemType)));
        //更改栈顶指针，此时已经申请完毕新空间，栈满的情况下，top指针
        //应该是源栈大小加上s.base == s.top
        s->top = s->base+s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    (s->top)++;
    *(s->top) = e;
}

//pop stack
int Pop(SqStackPointer s,SElemType* e)
{
    if(s->top == s->base)
    {
        return -1;
    }
    else
    {
        --(s->top);
        *e = *(s->top);
    }
    return OK;
}

//empty
int StackEmpty(SqStackPointer s)
{
    if(s->top == s->base)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*
 * 函数名：CreateBiTree
 * 输入：BiTree 类型的指针地址
 * 输出：int
 * 功能: 先序遍历递归创建二叉树
 * */
BiTree CreateBiTree()
{
    BiTree T;
    char ch;
    scanf("%c",&ch);

    if(ch=='#')
    {
        T = NULL;// 若是空格字符，则令指针为空
    }
    else
    {
        T=(BiTree)malloc(sizeof(struct BinTNode));
        T->data = ch;//生成根节点
        T->lchild = CreateBiTree();//生成左子树
        T->rchild = CreateBiTree();//生成右子树
    }
    return T;//返回二叉树指针
}

/*
 * 函数名：PreOrderTraverse
 * 输入：BiTree T
 * 输出：int
 * 功能：先序遍历已知的二叉树
 * */
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

/*
 * 函数名：InOrderTraverse
 * 输入：BiTree T
 * 输出：int
 * 功能：中序遍历已知的二叉树
 * */
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%c",T->data);
        InOrderTraverse(T->rchild);
    }
}

/*
 * 函数名：PostOrderTraverse
 * 输入：BiTree T
 * 输出：int
 * 功能：后序遍历已知的二叉树
 * */
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
}

/*
 * 函数名：PreOrderTraverse_1
 * 输入：BiTree T
 * 输出：int
 * 功能：先序非递归遍历已知的二叉树
 * */

/*
void PreOrderTraverse_1(BiTree T)
{
    SqStackPointer s=NULL;
    s = (SqStackPointer)malloc(sizeof(struct SqStack));
    InitStack(s);
    BiTree p=NULL;
    p=T;
    while(p||!StackEmpty(s))
    {
       if(p)
       {
           printf("%c",p->data);
           int *temp =(int*)&p;
           Push(s,int(*temp));
           p=p->lchild;
       }
       else
       {
           int* temp=NULL;
           Pop(s,temp);
           p =(BiTree)temp;
           p=p->rchild;
       }
    }
}
*/

/*
 * 函数名：InOrderTraverse_1
 * 输入：BiTree T
 * 输出：int
 * 功能：中序非递归遍历已知的二叉树
 * */
void InOrderTraverse_1(BiTree T)
{
}
/*
 * 函数名：PostOrderTraverse_1
 * 输入：BiTree T
 * 输出：int
 * 功能：后序非递归遍历已知的二叉树
 * */
void PostOrderTraverse_1(BiTree T)
{

}
int main()
{
    BiTree T;
    T=CreateBiTree();
    printf("create tree end\n");
    printf("%c\n",T->data);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    getchar();
    return 0;
}
