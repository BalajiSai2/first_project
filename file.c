//Gudimetla Balajisai
//Reg no:20223102
//Date:8-08-2023
//objective:creating the file
#include<stdio.h>
#include<stdlib.h>
int main()
    {
     int i;
     FILE *fptr;
     fptr=fopen("integer_upto_1000","w");
     if(fptr==NULL)
     {
        printf("error !there is no space\n");
        exit (-1);
     }
    //  char k[]="Balaji Sai";
    for(i=1000;i>=1;i--)
        {
        fprintf(fptr,"%d ",i);
        }
        fclose(fptr);
        return 0;
    }
