#include <stdio.h>
#define max 5
int front = -1;
int rear = -1;
int queue[max];

void enqueue(){

    if( ( rear+1)%max == front ){
        printf("\tQUEUE OVERFLOW\n");
        printf("\n The Queue is now full\n");
        return;
    }
    if( rear == -1){
        front = ( front + 1) % max;
    }
    rear = (rear + 1) % max;
    printf("\n Enter the element to enqueue :- ");
    scanf("%d",&queue[rear]);
    printf("\n The element %d is enqueued successsfully\n",queue[rear]);

}

void dequeue(){

    if( front == -1 ){
        printf("\n\tQUEUE UNDERFLOW\n");
        printf("\n There is no element in the queue to dequeue\n");        
        return;
    }
    printf("\n The element %d is dequeued successfully\n",queue[front]);
    if( front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = ( front +1 ) % max;
    }
}

void display(){
    if( rear == -1 ){
        printf("\n The queue is empty\n");
        return ;
    }
    int temp = front;
    printf("\n\tQUEUE\t\n");
    while( temp != rear){
        printf(" %d ",queue[temp]);
        temp = (temp + 1) % max;
    }
    printf(" %d ",queue[temp]);
}

int main(){
    int choice = -1;
    printf("-------- QUEUE Using Array -----------\n");

    while(1){
        printf("\n\tMENU\t\n");
        printf("\t1. ENQUEUE\t\n");
        printf("\t2. DEQUEUE\t\n");
        printf("\t3. DISPLAY\t\n");         
        printf("\t4. Exit\t\n");


        printf("\n Enter the choice no :- ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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