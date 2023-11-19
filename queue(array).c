#include<stdio.h>
struct queue{
    int arr[20];
    int front;
    int rear;
};
void create_queue(struct queue *q)
{
q->front=-1;
q->rear=-1;
}
void enqueue(struct queue *q)
{
    if(q->rear==-1)
    {
        q->front++;
        q->rear++;
      printf("enter the number\n");
      scanf("%d",&(q->arr[q->rear]));
    }else
    if(q->rear==20)
    {
    printf("queue is full\n");
    }else 
    {
         q->rear++;
     printf("enter the number\n");
      scanf("%d",&(q->arr[q->rear]));
    }

}

void dequeue(struct queue *q)
{
    if(q->rear==-1)
    {
        printf("The queue empty\n");
    }else if((q->front%20)==q->rear)
    {
        printf("The dequeue element is %d\n",q->arr[q->rear]);
        q->front=q->rear=-1;
    }else{
       printf("The dequeue element is %d\n",q->arr[q->rear]);
       q->front++; 
    }
}

void display(struct queue *q)
{
    if(q->front==-1){
        printf("empty queue\n");
    }else{
        for(int i=q->front;i<=q->rear;i++)
        {printf("the element is %d\n",q->arr[i]);}
     
    }
}
int main()
{
    int entry;
    struct queue q1;
    //we can also define as 
    //typedef struct queue s;
    //s s1;
    create_queue(&q1);
   
    do
    {
    printf("enter the operation from the following\n");
    printf("1.ENQUEUE\n2.DEQUEUE\n3.Display\n4.Exit\n");
    scanf("%d",&entry);
        if(entry==1)
        {
            enqueue(&q1);
        }else if(entry==2)
        {
           dequeue(&q1);
        }else if(entry==3)
        {
            display(&q1);
        }else if(entry==4)
        {
            printf("Thank you\n ");
            
        }else{
            printf("wrong entry");
        }
    }while(entry!=4);
return 0;
}