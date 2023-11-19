#include<stdio.h>
#include<stdlib.h>
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
    FILE *in_file=fopen("integer_upto_1000","r");
    FILE *out_file=fopen("New_integer_upto_1000","w");
    if(in_file==NULL)
    {
        printf("cannot read the file\n");
        exit (-1);
    }
    int a[1000];
    int i=0,k;
    while(i<1000 && fscanf(in_file,"%d ",&a[i])==1)
    {
        i++;
    }

    //sorting part
printf("Enter the number_key for following sorts\n 1.Inserton sort\n 2.Bubble sort\n");
scanf("%d",&k);
if(k==1){
insertion_sort(a,1000);//Sorting the elements by inserton sort
}else
{
bubble_sort(a,1000);//Sorting the elements by bubble sort
}
for(int j=0;j<1000;j++)
{
    fprintf(out_file,"%d ",a[j]);
}
fclose(in_file);
fclose(out_file);
  return 0;  
}