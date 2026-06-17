#include <stdio.h>

void pattern01( int n ){
    /*
        n = 4 ;

        *
        * *
        * * *
        * * * *
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= i ; j++ ) printf("* ");

        printf("\n");
   
    }
    return ;
}



void pattern02( int n ){
    /*
        n = 4 ;

              *
            * *
          * * *
        * * * *
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = ( n - i ) ; j >= 1 ; j-- ) printf("  ");

        for( int k = 1 ; k <= i ; k++ ) printf("* ");

        printf("\n");
   
    }
    return ;
}



void pattern03( int n ){
    /*
        n = 4 ;

        * * * *
        * * *
        * * 
        * 
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= ( n - i + 1) ; j++ ) printf("* ");

        printf("\n");
   
    }
    return ;
}



void pattern04( int n ){
    /*
        n = 4 ;

        * * * *
         * * *
          * *
           *
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= i ; j++ ) printf(" ");

        for( int k = 1 ; k <= ( n - i + 1) ; k ++ ) printf("* ");

        printf("\n");
   
    }
    return ;
}



void pattern05( int n ){
    /*
        n = 4 ;

        * * * *
          * * *
            * *
              *
    */
   for( int i = 1 ; i <= n ; i++ ){
 
        for( int j = 1 ; j <= i ; j++ ) printf("  ");

        for( int k = 1 ; k <= ( n - i + 1) ; k ++ ) printf("* ");

        printf("\n");
   
    }
    return ;
}



void pattern06( int n ){
    /*
        n = 4 ;
        1 2 3 4 4 3 2 1
        1 2 3 * * 3 2 1
        1 2 * * * * 2 1
        1 * * * * * * 1
    */
    for ( int i = 0 ; i < n ; i++ ){

        for( int j = 1 ; j <= ( n - i ) ; j++ ) printf("%d ", j );

        for( int k = 0 ; k < ( 2 * i ) ; k++ ) printf("* ");

        for ( int l = ( n - i ) ; l > 0 ; l-- ) printf("%d ", l );

        printf("\n");
    }
    return ;
}

 
int main(){
    int choice = -1 , n = 4 ;
    printf("\n\n Enter pattern no :-  ");
    scanf("%d", &choice ) ;

    printf("\n\n Enter n :-  ");
    scanf("%d", &n ) ;
    switch (choice)
    {
    case 1:
        pattern01(n);
        break;
    case 2:
        pattern02(n);
        break;
    case 3:
        pattern03(n);
        break;
    case 4:
        pattern04(n);
        break;
    case 5:
        pattern05(n);
        break;
    case 6:
        pattern06(n);
        break;
    default:
        printf("\n There are only 8 patterns, enter no from 1 to 8");
        break;
    }
    return 0 ;
}