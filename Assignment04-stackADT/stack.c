#include <stdio.h>
#define max 5
int top = -1;
int stack[max];

void push(){

    if( top == max-1){
        printf("\tSTACK OVERFLOW\n");
        printf("\n The Stack is now full\n");
        return;
    }
    top ++;
    printf("\n Enter the element to push :- ");
    scanf("%d",&stack[top]);
    printf("\n The element %d is pushed successsfully\n",stack[top]);

}

void pop(){

    if(top == -1){
        printf("\tSTACK UNDERFLOW\n");
        printf("\n There is no element in the stack to pop\n");
        
        return;
    }
    printf("\n The element %d is popped successfully\n",stack[top]);
    top--;

}

void display(){
    if( top == -1 ){
        printf("\n No element in the stack to display\n");
        return ;
    }
    int temp = 0;
    printf("\n\tSTACK\t\n");
    while( temp <= top){
        printf(" %d ", stack[temp]);
        temp++;
    }
}

int main(){
    int choice = -1;
    printf("-------- Stack Using Array -----------\n");

    while(1){
        printf("\n\tMENU\t\n");
        printf("\t1. PUSH\t\n");
        printf("\t2. POP\t\n");
        printf("\t3. DISPLAY\t\n");         
        printf("\t4. Exit\t\n");


        printf("\n Enter the choice no :- ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program ");
            return 0;
        default :
            printf("Invalid Choice");
        }
    }
    return 0;
}