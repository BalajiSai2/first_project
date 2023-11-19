#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int size;
    struct node *lchild;
    struct node *rchild;
    struct node *pa;//parent
}*root=NULL;

struct node* Binary_tree(struct node *p,int key)
{
struct node *t;
if(p==NULL)
{
    t=(struct node*)malloc(sizeof(struct node));
    t->lchild=t->rchild=NULL;
    t->data=key;
    t->pa=NULL;
    t->size=0;
    return t;
}
if(p->data>key)
{
    p->lchild=Binary_tree(p->lchild,key);
    //parent
    p->lchild->pa=p;
    
}
else if(p->data<key)
{
      p->rchild=Binary_tree(p->rchild,key);
    //parent
     p->rchild->pa=p;
}
return p;
}
void post_order(struct node *p)
{
    if(p!=NULL)
    {
        post_order(p->lchild);
        post_order(p->rchild);
        printf("%d ",p->data);
    }
}
//size
int sa(struct node *ptr)
{
    if(ptr==NULL)
    return 0;
    int ls=sa(ptr->lchild);
    int rs=sa(ptr->rchild);
    root->size=ls+rs+1;
    return (root->size);
}
int ptrtoi(struct node *p,struct node* ptr)
{
int cr=ptr->lchild->size+1;
while(ptr!=root)
{
    if(ptr->pa->rchild==ptr)
    cr+=sa(ptr->pa->lchild);
    ptr=ptr->pa;
}
return cr;
}


int main()
{
root=Binary_tree(root,100);
Binary_tree(root,20);
Binary_tree(root,80);
Binary_tree(root,30);
Binary_tree(root,70);
post_order(root);
sa(root);
// printf("\n%d  %d",root->lchild->pa->data,root->size);
// printf("%d",root->lchild->rchild);
printf("\n%d",ptrtoi(root,root->lchild->rchild));
return 0;
}