//Gudimetla Balaji Sai
//20223102
//29-08-2023
//object:heap_sort
#include<stdio.h>
#include<stdlib.h>
void max_heap(int arr[],int i,int hs)//max heap
{
	int l=2*i;
	int r=2*i+1;
	int largest=0;
	if(l<=hs && arr[l]>arr[i])
	 	largest=l;
	else
		largest=i;
	
    	if(r<=hs && arr[r]>arr[largest])
		largest=r;
	
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=arr[i];
		max_heap(arr,largest,hs);
	}
}

void build_heap(int arr[],int hs)//build heap
{
	int i;
	for(i=hs/2;i>0;i--)
	{
		max_heap(arr,i,hs);
	}

}

void heap_sort(int arr[],int hs)
{
	build_heap(arr,hs);
	int t,i;
        t=hs;
	for(i=t;i>1;i++)
	{
		int temp=arr[1];
		arr[1]=arr[hs];
		arr[hs]=arr[1];
		hs--;
		max_heap(arr,1,hs);
	}
	hs=t;
}

int main()
{
	int i,hs;
	printf("\nenter the length of array:");
	scanf("%d",&hs);
	int arr[hs];
	printf("\nenter the elements of array:");
	for(i=1;i<=hs;i++)
		scanf("%d",&arr[i]);
	heap_sort(arr,hs);
        for(i=1;i<=hs;i++)
		printf("%d ",arr[i]);
	return 0;
}



