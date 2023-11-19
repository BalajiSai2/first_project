#include<stdio.h>
#include<stdio.h>
void swap(int *a,int *b)
{
int c=*a;
*a=*b;
*b=c;
}

void max_heap(int arr[],int i,int hs)
{
    int left_child=2*i+1;
    int right_child=2*i+2;
    // int hs=(sizeof(arr)/sizeof(arr[0]))-1;
    //  int hs= *(&arr + 1) - arr-1;
    int largest;
    if((left_child<=hs) && (arr[left_child]>arr[i]))
    {
      largest=left_child;
    }
    else
    {
       largest=i;
    }
    if((right_child<=hs) && arr[right_child]>=arr[largest])
    {
        largest=right_child;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        max_heap(arr,largest,hs);
   }
    }
  //complexcity log^n/2 

void Build_max_heap(int arr[],int hs)
{
    // int hs=(sizeof(arr)/sizeof(arr[0]))-1;
    //  int hs = ((*(&arr + 1) - arr)-1);
    for(int i=(hs)/2;i>=0;i--)
    {
        max_heap(arr,i,hs);
    }
}
//complexity less than n
void heap_sort(int arr[],int hs)
{
    Build_max_heap(arr,hs);
    // int hs=(sizeof(arr)/sizeof(arr[0]))-1;
   
    int t=hs;
    for(int i=t;i>0;i--)
    {
        swap(&arr[0],&arr[hs]);
        hs--;
        max_heap(arr,0,hs);
    
    }
    hs=t;
  
}

int main()
{
    int arr[]={3,7,0,5,8,4,9,8};
    int hs=(sizeof(arr)/sizeof(arr[0]))-1;
    heap_sort(arr,hs);
  
    for(int i=0;i<=hs;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}