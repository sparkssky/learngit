#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定义多项式节点结构体
typedef struct term{
	float coef;//多项式系数
	int expn;//多项式指数
	struct term* next;
}term,*LinkList;

typedef LinkList polynomial;

//比较项的指数大小 1 大于 0 等于 -1 小于
int cmp(LinkList qa,LinkList qb){
	if(qa->expn > qb->expn)
		return 1;
	else if(qa->expn == qb->expn)
		return 0;
	else
		return -1;
}
//查找链表中是否存在某个指数项
//若有序链表L中存在与项t的指数相等的元素，则指针q指向L中第一个指数为t->expn的节点位置
//否则，q指向第一个指数满足与t->expn相比大于0的节点的前驱位置
bool locateElem(LinkList L,LinkList  t,LinkList &q){
	LinkList p1=L->next;
	LinkList p2=L;//p2指向p1的前驱
	
	while(p1){
		if(t->expn > p1->expn){//项t的指数大于当前项的指数,继续后移
			p1=p1->next;
			p2=p2->next;
		}
		else if(t->expn == p1->expn){//找到
			q=p1;
			return true;
		}
		else{//L是有序表，如果程序到这一步，说明没有找到t的指数相等的节点元素
			//返回q的前驱节点
			q=p2;
			return false;
		}
	}
	if(!p1){//t->expn比L链表中最大的指数都大，while循环会p2指向了尾节点，p1指向了null
		q=p2;
		return false;
	}
}

//初始化和创建一个一元多项式带有头结点的有序链表
//尾插法
void createPolyn(polynomial &p,int m)
{
	//创建带头结点的空链表，初始化操作
	p=(polynomial)malloc(sizeof(term));
	if(p)
		p->next=NULL;

	LinkList r=p;//r指针总是指向当前线性表最后一个元素,即尾节点

	printf("输入系数，指数，如2x^5则输入(2,5):\n");
	for(int i=0;i<m;i++){//依次输入m个非零项节点元素
		LinkList t=(LinkList)malloc(sizeof(term));
		t->next=NULL;
		
		LinkList q;
		scanf("%f,%d",&t->coef,&t->expn);
		if(!locateElem(p,t,q)){//当前链表中不存在该指数项，尾插法，此时q为链表中第一个指数\
		//t->expn节点的前驱节点
			t->next=q->next;
			q->next=t;
		}else{//已经存在相同的指数,本次输入无效，重新输入
			i--;
		}
	}
}

//打印多项式链表
void printPolynomial(polynomial p){
	LinkList q=p->next;//因为带头结点
	printf("打印多项式链表:[");
	while(q){
		printf("(%.2f,%d)  ",q->coef,q->expn);
		q=q->next;
	}
	printf("]\n\n");
}
//多项式相加pa=pa+pb,利用多项式的节点构成和多项式
void addPolyn(polynomial &pa,polynomial &pb){
	LinkList qa=pa->next;
	LinkList qb=pb->next;
	LinkList qc=pa;//pc指向和多项式的最后一个节点,做比较用

	float sumofcoef;
	while(qa&&qb){
		switch(cmp(qa,qb)){
			case 1://当前qa->expn > qb->expb
				qc->next=qb;
				qc=qb;
				qb=qb->next;	
				break;
			case 0://指数相同,
				sumofcoef=qa->coef+qb->coef;
				if(sumofcoef!=0.0){//不为0，修改qa所指节点的系数，同时释放qb指向的节点
					LinkList s=qb;//s即将被free
					qa->coef=sumofcoef;	
					
					qc->next=qa;
					qc=qa;
					qa=qa->next;
					qb=qb->next;
					free(s);
				}else{
					LinkList s1=qa;
					LinkList s2=qb;
					//qc位置不变，qa，qb向后移动
					qa=qa->next;
					qb=qb->next;

					free(s1);
					free(s2);
				}
				break;
			case -1:
				qc->next=qa;
				qc=qa;
				qa=qa->next;
				break;
		}//end switch
	}//end while
	qc->next= qa?qa:qb;//插入剩余端
	free(pb);//释放pb的头结点
}

int main(){
	polynomial pa;
	createPolyn(pa,4);
	printPolynomial(pa);
	
	polynomial pb;
	createPolyn(pb,3);
	printPolynomial(pb);


	printf("执行多项式相加\n");
	addPolyn(pa,pb);
	printPolynomial(pa);
}
