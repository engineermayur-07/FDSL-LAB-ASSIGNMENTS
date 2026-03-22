#include <stdio.h>
int main()
{
  int choice,n,key,high,low,mid,flag=0;
  int arr[400];
    for(;;){
      printf("\n\n        MENU      \n");
      printf("\n1.Continue  \n2.Exit\n");
      scanf("%d",&choice);
      if(choice==1){
        printf("\n1.Linear Search\n2.Binary Search\n");
        scanf("%d",&choice);
        switch(choice){
          case 1:{
            printf("\nEnter array size:- ");
            scanf("%d",&n);
            printf("\nEnter %d array elements\n",n);
            for(int i=0;i<n;i++){
              scanf("%d",&arr[i]);
            }
            printf("\nEnter element to be searched :- ");
            scanf("%d",&key);
            for(int i=0;i<n;i++){
              if(arr[i]==key){
                flag=1;
                printf("\nThe element %d is found at %d position",key,i+1);
                break;
              }
            }
            if(flag==0){
              printf("\nElement not found\n");
            }
            break;
          }
          case 2:{
            printf("\nEnter array size:- ");
            scanf("%d",&n);
            printf("\nEnter %d sorted array elements\n",n);
            for(int i=0;i<n;i++){
              scanf("%d",&arr[i]);
            }
            printf("\nEnter element to be searched :- ");
            scanf("%d",&key);   
            for(low=0,high=n-1;low<=high;){
              mid=(low+high)/2;
              if(arr[mid]==key){
                printf("\nThe element %d is found at %d position",key,mid+1);
                flag=1;
                break;
              }
              else if(key<arr[mid]){
                high=mid-1;
              }
              else{
                low=mid+1;
              }
            }
            if(flag==0){
              printf("\nElement not found\n");
            }
            break;
          }
          default:{
            printf("\nYou entered wrong choice\n");
          }
        }
      }
    
      else if(choice==2){
        printf("\nExiting the program\n");
        return 0;
      }
      else{
        printf("\nYou entered wrong choice\n");
      }
    }
    return 0;
}