#include<stdio.h>
#include<stdlib.h>
//quick_sort
int* Quick_sort(int arr[],int lb,int ub)
{
if(lb<ub)//condition to stop the recursion
{
int q;
q=partition(arr,lb,ub);//partion of two side corresponding to pivot
Quick_sort(arr,lb,q-1);//less than pivot quick_Sort recursion
  Quick_sort(arr,q+1,ub);//greater than pivot quick_sort recursion
  } 
  return arr;
  }

  int partition(int arr[],int lb,int ub)
  {
  int pivot=arr[ub];//pivot element
  int lp=lb-1;
  int moving;
  for(moving=lb;moving<ub;moving++)
  {
  if(arr[moving]<pivot)
  {
  lp++;
  int temp=arr[moving];//swaping the elements
  arr[moving]=arr[lp];
  arr[lp]=temp;
  }}
  lp++;
  int temp=arr[lp];//swap the pivot element with lp element
  arr[lp]=pivot;
  arr[ub]=temp;
  return lp;
  }

  int main()
  {
   int arr[5]={2,8,4,5,1};
  int *ptr=Quick_sort(arr,0,4);
  int j;
  for(j=0;j<5;j++)
  {
  printf("%d ",ptr[j]);
  }
return 0;
 
  }

