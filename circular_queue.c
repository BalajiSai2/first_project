#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int a[20];
    int front;
    int rear;
};
typedef struct Queue queue;
void create(queue *q)
{
    q->front=-1;
    q->rear=-1;
}
void enqueue(queue *q)
{
    if((q->front+1)%20==q->rear)
    printf("\noverflow");
    else 
    {
        if(q->front==-1)
    {
        q->front++;
        q->rear++;
       
    }else {
       q->front=(q->front+1)/20;
    }
     printf("\nEnter the number:");
    scanf("%d",&q->a[q->front]);
    }
}

void dequeue(queue *q)
{
    if(q->front==-1)
    {
        printf("\n underflow");
    }else
    if(q->front==q->rear)
    {
            printf("the dequeue element :%d",q->a[q->rear]);
            q->rear=-1;q->front=-1;
    }else {
        printf("the dequeue element :%d",q->a[q->rear]);
        q->rear=(q->rear+1)/20; 
    }
    
}
int main()
{
int entry;
     queue q1;
    //we can also define as 
    //typedef struct queue s;
    //s s1;
    create(&q1);
   
    do
    {
    printf("\nenter the operation from the following\n");
    printf("1.ENQUEUE\n2.DEQUEUE\n4.Exit\n");
    scanf("%d",&entry);
        if(entry==1)
        {
            enqueue(&q1);
        }else if(entry==2)
        {
           dequeue(&q1);
        }else if(entry==4)
        {
            printf("Thank you\n ");
            
        }else{
            printf("wrong entry");
        }
    }while(entry!=4);
    return 0;
}