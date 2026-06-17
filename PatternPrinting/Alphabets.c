#include <stdio.h>

void pattern01( int n ){
    /*
        n = 4 ;
        A A A A
        B B B B
        C C c C
        D D D D
    */

    for( int i = 1 ; i <= n ; i ++ ){

        for( int j = 1 ; j <= n ; j++){
            printf("%c ", ('A' + i - 1) ) ;
        }
        printf("\n");
    }
    return ;
}

    
void pattern02( int n ){
    /*
        n = 4 ;
        A B C D
        B C B E
        C D E F
        D E F G
    */

    for( int i = 1 ; i <= n ; i ++ ){

        for( int j = 1 ; j <= n ; j++){
            printf("%c ", ('A' + i +j - 2 ) ) ;
        }
        printf("\n");
    }
    return ;
}
    

void pattern03( int n ){
    /*
        n = 4 ;
        A 
        B C 
        D E F
        G H I J
    */
    char count = 'A';

    for( int i = 1 ; i <= n ; i ++ ){

        for( int j = 1 ; j <= i ; j++){
            printf("%c ", count );
            count ++ ;
        }
        printf("\n");
    }
    return ;
}


void pattern04( int n ){
    /*
        n = 4 ;
        D
        C D 
        B C D
        A B C d
    */
    char count = 'A';

    for( int i = 1 ; i <= n ; i ++ ){

        for( int j = 1 ; j <= i ; j++){
            printf("%c ",( 'A' + n - i + j - 1 ) );
            count ++ ;
        }
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
    default:
        printf("\n There are only 8 patterns, enter no from 1 to 8");
        break;
    }
    return 0 ;
}