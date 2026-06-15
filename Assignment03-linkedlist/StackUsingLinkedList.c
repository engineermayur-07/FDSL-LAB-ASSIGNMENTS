#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *next;
    int data;
};

struct node *top = NULL;

struct node *CreateNode(){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    return newnode;
}


void display(){
    printf("-------- Linked List -----------\n");
    struct node *temp = top;
    if(top == NULL){
        printf("\n No data to display, list is empty ");
        return;
    }
    printf("\tData :\n");
     
    while( temp !=NULL ){
        printf("\tV\n");
        printf("\tdata : %d\n", temp->data);
        temp = temp->next;
    }

}

void POP(){

    if (top == NULL){
        printf("\n There is no element to delete \n");
        return;
    }
    else {

        struct node *temp = top;
        if( top->next == NULL ){
            temp = top;
            printf("\n Popped %d element", temp->data); 
            free(temp);
            top = NULL;
            return;

        }
        top = top->next;
        printf("\n Popped %d element\n\n", temp->data);
        free(temp);

    }

}

void PUSH(){
    struct node *newnode;
    newnode = CreateNode();
    
    if(newnode == NULL){
        printf("\n No memory to insert newnode \n");
        return;
    }

    else{
        printf("\n Enter the integer data to push in the stack :- ");
        scanf("%d", &newnode->data);
        newnode->next = top;
        top = newnode;
        

        printf("\n The data %d is pushed successfully \n\n", top->data);

    }

}

int main(){
    int choice = -1;
    printf("-------- Linked List -----------\n");

    while(1){
        printf("\tMENU\t\n");
        printf("\t1. PUSH\t\n");
        printf("\t2. POP\t\n");
        printf("\t3. DISPLAY\t\n");         
        printf("\t4. Exit\t\n");


        printf("\n Enter the choice no :- ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
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