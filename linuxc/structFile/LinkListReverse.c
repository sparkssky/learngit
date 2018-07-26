#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ERROR -1
typedef int ElementType;
typedef struct Node* PtrToNode;

struct Node{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

//函数声明
List Read();//初始化链表并生成
void Print(List L);//打印链表

List Reverse(List L);//链表逆序

int Length( List L );//求链表长度
ElementType FindKth( List L, int K );//找到并返回链式表的第K个元素
List merge(List l1,List l2);//合并两个链表，最终返回一个


List merge(List l1,List l2)
{
    List pa,pb,pc,l;
    pa = l1->Next;
    pb = l2->Next;
    l = (List)malloc(sizeof(struct Node));
    pc=l;

    while(pa&&pb)
    {
        if(pa->Data <= pb->Data)
        {
            pc->Next = pa;//pc-》next指向当前的小值节点
            pc = pa;//然后pc指针移动到当前节点
            pa = pa->Next;

        }else{
            pc->Next = pb;
            pc = pb;
            pb = pb->Next;
        }
    }

    pc->Next = pa?pa:pb;
    l1->Next = NULL;
    l2->Next = NULL;
    return l;
}





//初始化链表,并插入元素
List Read(){
	//创建头结点
	List head=(List)malloc(sizeof(struct Node));
	head->Next=NULL;
	int nodenum=0;
	scanf("%d",&nodenum);
	getchar();
	//第一个节点
	List first=(List)malloc(sizeof(struct Node));
	scanf("%d",&first->Data);
	getchar();
	first->Next=head->Next;
	head->Next=first;
	List p = first;//指向最后一个节点

	//尾插法
	for(int i=1;i<nodenum;i++){
		List s=NULL;
		s=(List)malloc(sizeof(struct Node));
		if(s!=NULL){
			scanf("%d",&s->Data);
			getchar();
			s->Next=p->Next;
			p->Next=s;
			p=s;
		}
	}

	//头插法
	/*
	for(int i=0;i<nodenum;i++){
		List s=NULL;
		s=(List)malloc(sizeof(struct Node));
		if(s!=NULL){
			scanf("%d",&s->Data);
			getchar();
			s->Next=head->Next;
			head->Next=s;
		}
	}
	*/
	return head;
}

void Print(List l)
{
	List p=l->Next;
	while(p){
		printf("%d ",p->Data);
		p=p->Next;
	}
	printf("\n");
}
List Reverse(List l)
{
    //空链或者只有一个节点
	if(l->Next==NULL||l->Next->Next==NULL)
		return l;

	List t=NULL;//指向q->Next,保存
	List p=l->Next;
	List q=l->Next->Next;

	while(q!=NULL){
		t=q->Next;//保存q-->next,后面的q->Next会指向新的地址
		q->Next=p;

		p=q;
		q=t;
	}
	l->Next->Next=NULL;//第一个节点指向NULL,新链表尾部
	l->Next=p;//头结点指向最后一个节点,新链表头部
	return l;
}
int Length( List L )//求链表长度
{
	int sum=0;
	List p=L->Next;
	while(p)
	{
		sum+=1;
		p=p->Next;
	}
	return sum;
}

ElementType FindKth(List L, int k)//找到并返回链式表的第K个元素
{
	ElementType res=0;
	List p=L->Next;

	printf("222222222222222\n");
	int len=Length(L);
	printf("len=%d\n",len);
	if(k>len||k<0)
		return ERROR;
	int i=0;
	printf("333333333333333\n");
	while(p&&i<(k-1))
	{
		p=p->Next;
		i++;
	}
	res=p->Data;
	return res;
}


int main(){
	int N,K;
	int X;
	List l1;
	l1=Read();
	Print(l1);
	scanf("%d",&N);
	getchar();
	printf("111111111111\n");
	while(N--)
	{
		scanf("%d",&K);
		getchar();
		X=FindKth(l1,K);
		if(X!=ERROR)
			printf("%d ",X);
		else
			printf("Na ");
	}
	return 0;
}
