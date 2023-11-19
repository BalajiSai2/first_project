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

int* srrQuicksort(int arr[], int lb, int ub) 
{
 while (lb < ub) 
 {
  int q ;
  q=partition(arr, lb, ub);
  if((q-lb)<(ub-q))
  {
  srrQuicksort(arr, lb, q - 1);
  lb=q+1;
  }
  // fast element to element before the pivot quicksort
  else
   {
    srrQuicksort(arr, q + 1, ub);
    ub=q-1;
   }
 } // element after the pivot to last quicksort
  return arr;
}


int main()
{
  int arr[]={2,7,4,1,4,7,9,85,45,30,85,74,435,27,573,285,34,6,0,2,7,46,9};
   clock_t t;
   t = clock();
  int *ptr=srrQuicksort(arr,0,22);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
   printf("fun() took %f seconds to execute \n", time_taken);
  for(int i=0;i<23;i++)
  {
     printf("%d ",ptr[i]);
  } 
return 0;
}