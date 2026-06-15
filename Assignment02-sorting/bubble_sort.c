#include <stdio.h>

int main() {
  int arr[500];
  int n,temp,choice;
  
  do{
 
   printf("\nEnter array size :- ");
   scanf("%d",&n);
   printf("\nEnter %d array elements :- ",n);
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
   }
   printf("\nThe sorted array is :- ");
   for(int i=0;i<n;i++){
       printf("%d  ",arr[i]);
   }
   printf("\n\n      MENU\n      1.Continue\n      0.Exit\n");  
   scanf("%d",&choice);
   }while(choice==1);
   printf("\nExiting the progran");

     return 0;
 }