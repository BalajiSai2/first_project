//implementation of queue with stack 
//taking two stacks and by performing pop and push operation enque and dequeue
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int arr[20];
    int top;
};
typedef struct stack STACK;

void create_stack(struct stack *s)
{
    s->top=-1;
}

void push(struct stack *s)
{
    if(s->top==20)
    {
        printf("The stack is full\n");//overflow
    
    }else{
        s->top++;
      
        printf("Enter the number that want to go in stack at top\n");
        scanf("%d",&(s->arr[s->top]));
    }
}

int pop(struct stack *s)
{
    if(s->top==-1){

        printf("Underflow\n");
       return 0;
    }else{
        int a;
        a=s->arr[s->top];
        s->top--;
        return a;
    }
}

void denqueue(STACK *s1,STACK *s2)
{
  if(pop(s1)==0)
  {
    printf("The queue is empty\n");
  }else
  {
     int i,n;
     //tranfromation from s1 stack to other stack s2
    n=s1->top;
    for(i=0;i<=n;i++)
    {
      
        s2->arr[i]=pop(s1);
    }
    s2->top=n;
   printf("the denqueue element is %d \n",pop(s2)); 
     //tranfromation from s2 stack to other stack s1
     if((n-1)!=-1)
   { for(i=0;i<=n-1;i++)
    {
        s1->arr[i]=pop(s2);
    }
    s1->top=n-1;}
  }
}
void display(struct stack *s)
{
    if(s->top==-1){
        printf("Empty stack\n");
    }else{
        for(int i=0;i<=s->top;i++)
        {printf("The element at %d position is %d\n",i+1,s->arr[i]);}
     
    }
}

int main()
{
    int entry;
    STACK s1,s2;
    create_stack(&s1);
    create_stack(&s2);
      do
    {
        printf("=======================================\n");
    printf("Enter the operation from the following\n");
    printf("1.ENQUEUE\n2.DEQUEUE\n3.Display\n4.Exit\n");
    scanf("%d",&entry);
        if(entry==1)
        {
          push(&s1);
        }else if(entry==2)
        {
          denqueue(&s1,&s2);
        }else if(entry==3)
        {
            display(&s1);
        }else if(entry==4)
        {
            printf("******************Thank you************************\n ");
            
        }else{
            printf("Wrong entry\n");
        }
    }while(entry!=4);
return 0;
}