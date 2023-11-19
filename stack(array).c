#include<stdio.h>
struct stack
{
    int arr[20];
    int top;
};
 //if structure is define in the out side we have to use pointer other wise it cannot work
//because it is a funtion we have to pass address
void create_stack(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s)
{
    if(s->top==20)
    {
        printf("the stack is full\n");//overflow
    
    }else{
        s->top++;
      
        printf("enter the number that want to go in stack at top\n");
        scanf("%d",&(s->arr[s->top]));
    }
}
void pop(struct stack *s)
{
    if(s->top==-1){
        printf("underflow\n");
       
    }else{
        printf("the pop element  is %d\n",s->arr[s->top]);
        s->top--;
    }
}
void display(struct stack *s)
{
    if(s->top==-1){
        printf("empty stack\n");
    }else{
        for(int i=0;i<=s->top;i++)
        {printf("the element at %d position is %d\n",i+1,s->arr[i]);}
     
    }
}
int main()
{
    int entry;
    struct stack s1;
    //we can also define as 
    //typedef struct stack s;
    //s s1;
    create_stack(&s1);
   
    do
    {
    printf("enter the operation from the following\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&entry);
        if(entry==1)
        {
            push(&s1);
        }else if(entry==2)
        {
            pop(&s1);
        }else if(entry==3)
        {
            display(&s1);
        }else if(entry==4)
        {
            printf("Thank you\n ");
            
        }else{
            printf("wrong entry");
        }
    }while(entry!=4);
return 0;
}