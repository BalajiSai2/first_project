#include<stdio.h>
#include<stdlib.h>
struct queue{
    int arr[20];
    int front;
    int rear;
};
typedef struct queue QUEUE;
void create(QUEUE *Q)
{
    Q->front=-1;
    Q->rear=-1;
}
void enqueue(QUEUE *q,int k)
{
    if(q->front==19)
    {
        printf("Overflow\n");
        
    }
    else
    if(q->front==-1)
    {
      q->front++;
      q->rear++;
      
     (q->arr[q->front])=k;
    }else
    {
        q->front++;
    (q->arr[q->front])=k;
    }
   
}
int dequeue(QUEUE *q)
{
    int k;
    if(q->rear==-1)
    {
        printf("underflow\n");
    }else 
    if(q->front==q->rear)
    {   
        k=q->arr[q->rear];
        q->rear=q->front=-1;
    }else
    {
        k=q->arr[q->rear];
       q->rear++;  
    }
    return k;
}
int main()
{
 QUEUE q1,q2;
 create(&q1);
 create(&q2);
 int entry;
do
    {
    printf("\nenter the operation from the following\n");
    printf("1.PUSH\n2.POP\n4.Exit\n");
    scanf("%d",&entry);
        if(entry==1)
        { 
            printf("\nenter the element:");
            int l;
            scanf("%d",&l);
           enqueue(&q1,l);//no change in push  operation

        }else if(entry==2)
        {
            int k;
          if(q1.rear!=q2.front)
         { for(int i=q1.rear;i<q1.front;i++)
          {
            k=dequeue(&q1);
            enqueue(&q2,k);
          }}
          
          printf("The pop element is %d",dequeue(&q1));
          
          if(q1.rear!=q2.front)
          { for(int i=(q2.rear);i<=q2.front;i++)
          {
            k=dequeue(&q2);
            enqueue(&q1,k);
          }}
        }else if(entry==4)
        {
            printf("Thank you\n ");
            
        }else{
            printf("wrong entry");
        }
    }while(entry!=4);
return 0;
}