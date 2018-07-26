/*************************************************************************
    > File Name: createList.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: Fri 11 May 2018 01:56:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct Inode{
    int data;
    struct Inode* next;
} node;


struct Inode* insert_head_list()
{
    node* p=NULL;
    node* q=NULL;

    //init head node
    node* head=(struct Inode*)malloc(sizeof(struct Inode)); if(head!=NULL) {
        head->data="";
        head->next=NULL;
    }

    node* first=(struct Inode*)malloc(sizeof(node));
    first->data='a';
    first->next=NULL;
    head->next=first;
    p=first;


    //insert the new node
    int len='z'-'b';
    int i=0;
    while(i<=len)
    {
        node* temp=(struct Inode*)malloc(sizeof(node));
        temp->data='b'+i;
        temp->next=NULL;
        q=temp;
        head->next=temp;
        temp->next=p;
        p=q;

        i++;
    }
    return head;
}
int main()
{

    node* res=insert_head_list();
    printf("%s\n",res->next->data);
}
