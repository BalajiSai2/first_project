#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int arr[], int lb, int ub)
 {
  int pivot = arr[ub];
  int lp = lb - 1;
  for (int moving = lb; moving < ub; moving++) {
       if (arr[moving] < pivot) {
        ++lp;
        int temp = arr[lp];
         arr[lp] = arr[moving];
         arr[moving] = temp;
 }
}
 arr[ub] = arr[++lp];
 arr[lp] = pivot;
 return lp;
 }

int rpartition(int arr[],int lb,int ub)
{

  srand(time(0));
 int r=(rand()%(ub-lb+1))+lb;
  int temp = arr[r];
  arr[r] = arr[ub];
  arr[ub] = temp;
  return partition(arr,lb,ub);
}

int* rQuicksort(int arr[], int lb, int ub) 
{
 if (lb < ub) 
 {
  int q ;
  q=partition(arr, lb, ub);
  rQuicksort(arr, lb, q - 1);
  // fast element to element before the pivot quicksort
   rQuicksort(arr, q + 1, ub);
 } // element after the pivot to last quicksort
  return arr;
}


int main()
{
  int arr[]={2,7,8,1,4,7,9};
  int *ptr=rQuicksort(arr,0,6);
  for(int i=0;i<7;i++)
  {
     printf("%d ",ptr[i]);
  } 
return 0;
}