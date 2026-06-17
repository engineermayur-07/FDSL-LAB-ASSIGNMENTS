#include <stdio.h>

void pattern01(int n){
    /* 
        n = 4 ;

        1 2 3 4
        1 2 3 4 
        1 2 3 4
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= n ; j++){
            printf("%d ",j);
        }
        printf("\n");
   }
   return ;
}


void pattern02(int n){
    /*
        n = 4 ;

        1  2  3  4 
        5  6  7  8
        9 10 11 12
        13 12 15 16
    */
   int count = 1 ;
   for( int i = 1 ; i <= n ; i++){
    
        for( int j = 1 ; j <= n ; j++){
            printf("%d  ", count);
            count ++ ;
        }
        printf("\n");

   }
   return ;
}


void pattern03(int n){
    /*
        n = 4 ;
        1
        2 2
        3 3 3
        4 4 4 4
    */
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= i ; j++ ){
            printf("%d ",i);
        }
        printf("\n");

   }
   return ;
}


void pattern04( int n ){
    /*
        n = 4
        1
        2 3
        4 5 6
        7 8 9 10    
    */
   int count = 1 ;
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= i ; j++ ){
            printf("%d ",count);
            count ++;
        }
        printf("\n");

   }
   return ;
}


void pattern05( int n ){
    /*
        n = 4
        1
        2 3
        3 4 5 
        4 5 6 7
    */
    
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= i ; j++ ){
            printf("%d ", i + j -1 );
         
        }
        printf("\n");

   }
   return ;
}


void pattern06( int n ){
    /*
        n = 4
        1
        2 1
        3 2 1
        4 3 2 1    
    */
    
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = i ; j >= 1 ; j-- ){
            printf("%d ", j );
            
        }
        printf("\n");

   }
   return ;
}


void pattern07( int n ){
    /*
        n = 4
            1
          1 2 1
         1 2 3 2 1
        1 2 3 4 3 2 1    
    */
    
   for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= n - i  ; j++ ) printf(" ");
        
        for ( int k = 1 ; k <= i ; k++ ) printf("%d ", k );

        for ( int l = i-1 ; l > 0 ; l-- ) printf("%d ", l) ;

        printf("\n");

   }
   return ;
}


void pattern08( int n ){
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

}

int main(){
    pattern08(4) ;
}