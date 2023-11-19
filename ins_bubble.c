//Gudimetla Balajisai
//Reg no:20223102
//Date:8-08-2023
//Objective:apply the insertion sort and bubble sort by reading the array and by reading by  file
#include<stdio.h>

//insertion sort
int* insertion_sort(int a[],int n)
{
int i,j;
for(i=1;i<n;i++)//apply the for loop from 2 to n by assuming i as start from 0
{
int key=a[i];//tranfor the i th element into key
j=i-1;
while(j>=0 && a[j]>key)  //the while loop stop when j=-1 and jth index element in array not greater than key
{
a[j+1]=a[j];//if it is big the increase it index
j--;
}
a[j+1]=key;//final position of the key to on intial bigger number place
}
return a;
}


//bubble sort
int* bubble_sort(int a[],int n)//taking arguments as array and size of array
{
int i,j;
for(i=0;i<n;i++)//running the for loop from o to n-1 that is total array
{
for(j=n-1;j>i;j--)//running the for loop from n-1 to i+1 that is one element greater index with i
{
if(a[j-1]>a[j])//if j-1 element is then swapping the elements
{
int temp=a[j-1];//stroing the element in the temperoy variable
a[j-1]=a[j];
a[j]=temp;
}}}
return a;//return the array
}

int main()
{
int k,n,i;
printf("\nEnter the size of the array:");
scanf("%d",&n); //scaning the size of the array
int a[n];
printf("\nEnter the array elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);//scanning the elements of the array
}

printf("Enter the number_key for following sorts\n 1.Inserton sort\n 2.Bubble sort\n");
scanf("%d",&k);
if(k==1){
printf("Sorting the elements by inserton sort:\n");
insertion_sort(a,n);
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}}else
{
printf("Sorting the elements by bubble sort:\n");
bubble_sort(a,n);
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}

return 0;
}


