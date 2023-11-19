#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
struct node *parent;
int size;
int height;
}*root=NULL;

int Node_height(struct node *p)
{
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    if(p==NULL&&p->lchild==NULL)
    return 0;
    return hl>=hr?hl+1:hr+1;
}

int Balance_factor(struct node *p)
{
    int hl,hr;
     hl=(p&&p->lchild)?p->lchild->height:0;
     hr=(p&&p->rchild)?p->rchild->height:0;
     return (hl-hr);
}

struct node* LLrotation(struct node *p)
{
    struct node* pl=p->lchild;
    p->lchild=pl->rchild;
    pl->rchild=p;
    p->height=Node_height(p);
    pl->height=Node_height(pl);
    if(p==root)
    root=pl;
    return pl;   
}

struct node *RRrotation(struct node *p)
{
struct node* pr=p->rchild;
p->rchild=pr->lchild;
pr->lchild=p;
p->height=Node_height(p);
pr->height=Node_height(p);
if(p==root)
root=pr;
return pr;
}

struct node *LRrotation(struct node *p)
{
    struct node *plr=p->lchild->rchild;
    struct node *pl=p->lchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    p->height=Node_height(p);
    plr->height=Node_height(plr);
    pl->height=Node_height(pl);
    if(p==root)
    root=plr;
    return plr;
}
    
    struct node *RLrotation(struct node *p)
    {
        struct node *pr=p->rchild;
        struct node *prl=p->rchild->lchild;
        pr->lchild=prl->rchild;
        p->rchild=prl->lchild;
        prl->rchild=pr;
        prl->lchild=p;
        p->height=Node_height(p);
        pr->height=Node_height(pr);
        prl->height=Node_height(prl);
        if(p==root)
        root=prl;
        return prl;

    }
struct node* AVL(struct node *p,int key)
{
    if(p==NULL)
    {
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->parent=NULL;
        t->height=0;
        t->size=0;
        return t;
    }
    if(p->data>key)
    {
        p->lchild=AVL(p->lchild,key);
        // p->lchild->parent=p;
    }
    else if(p->data<key)
    {
        p->rchild=AVL(p->rchild,key);
        // p->rchild->parent=p;
    }
    p->height=Node_height(p);
    if(Balance_factor(p)==2&&Balance_factor(p->lchild)==1)
    {
        return LLrotation(p);
    }else
    if(Balance_factor(p)==2&&Balance_factor(p->lchild)==(-1))
    {
        return LRrotation(p);  
    }else 
    if(Balance_factor(p)==(-2)&&Balance_factor(p->rchild)==(-1))
    {
        return RRrotation(p);
    }else
    if(Balance_factor(p)==(-2)&&Balance_factor(p->rchild)==1)
    {
        return RLrotation(p);
    }
return p;
}
int SA(struct node *p)
{
    if(p==NULL)
    return 0;
    int ls,rs;
    ls=SA(p->lchild);
    rs=SA(p->rchild);

p->size=ls+rs+1;
return p->size;
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    root=AVL(root,100);
    AVL(root,200);
    AVL(root,300);
    AVL(root,10);
    AVL(root,20);
    AVL(root,30);
    AVL(root,90);
    AVL(root,5);
    AVL(root,280);
    AVL(root,240);
    preorder(root);
    SA(root);
    return 0;
}
