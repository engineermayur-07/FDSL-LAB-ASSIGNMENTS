#include <stdio.h>
int main(){
    int choice =-1,n,temp;
    int arr[100];
    while(1){

        printf("\n\n\tMENU\n");
        printf("\t1. Continue\n");
        printf("\t2. Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter size of the array to sort :- ");
            scanf("%d",&n);
            
            for(int i = 0 ; i < n ; i++){
                printf("Enter %dth array element :- ",i);
                scanf("%d",&arr[i]);
            }

            for(int i = 0 ; i < n ; i++){
                
                for( int j = i ; j < n ; j++ ){
                    temp = arr[j];

                    while(arr[j] < arr[j-1] && j > 0){
                        arr[j] = arr[j-1];
                        j--;
                     }

                     arr[j] = temp;

                }
                 
            }

            printf("\n The sorted array is :- ");
            for ( int i = 0; i < n; i++){
                printf("%d ",arr[i]);
            }

            break;
        case 2:
            return 0;

        default:
            printf("Invalid Choice");
            break;
        }
    }
}