#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *next;
    int data;
};

struct node *head = NULL;

struct node *CreateNode(){
    struct node * newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    return newnode;
}

void InsertAtStart(){
    struct node *newnode;
    newnode = CreateNode();
    
    if(newnode == NULL){
        printf("\n No memory to insert newnode \n");
        return;
    }

    else{
        printf("\n Enter the integer data to insert in the newnode :- ");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        

        printf("\n The data %d is inserted successfully \n", head->data);

    }

}

void InsertionAtLast(){

    if(head == NULL){

            char choice [20];
            printf("\n There are no nodes in the list, do you want to add the first node (yes/no) ");
            scanf("%s", &choice);
            
            if(strcmp(choice,"no") == 0 || strcmp(choice,"No") == 0 || strcmp(choice,"NO") == 0){
                printf("\n Returning \n");
                return;
            }

            else{
                InsertAtStart();
            }

        }

    struct node *newnode;
    newnode = CreateNode();

    if(newnode == NULL){
        printf("\n The memory is no more, spend some amount and get few GB of space");
    }

    else{
        
        struct node *temp=head;
        printf("\n Enter the data to push in the node :- ");
        scanf("%d",&newnode->data);

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newnode;
        temp=temp->next;

        printf("\n The data %d is inserted successfully \n",temp->data );

    }

}

void InsertAtPosition(){

    if(head == NULL){

        char choice[20];

        printf("\n There is no node in the in the list ");
        printf("\n Do you want to create a new node (yes/no) :- ");
        scanf("%s",&choice);

        if(strcmp(choice,"no") == 0 || strcmp(choice,"No") == 0 || strcmp(choice,"NO") == 0 ){
                printf("\n Returning \n");
                return;
            }

            else{
                InsertAtStart();
            }

    }

    else{
        struct node *temp;
        
        
        int count = 0;
        int position=0;

        temp=head;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        printf("\n There are total %d nodes\n", count+1);

        printf("\n Enter the position at which the node is to be inserted :- ");
        scanf("%d", &position);

        if( position < 1 || position > (count+2) ){
            printf("\n The position %d is invalid, escaping the function ",position);
            return ;
        }

        else{
            if( position == 1){
                InsertAtStart();
            }

            else if ( position == (count+2) ){
                InsertionAtLast();
            }
            else{
                struct node *newnode;
                newnode = CreateNode();
                if( newnode == NULL ){
                    printf("Out of Memory");
                    return ;
                }
                count = 0;
                temp=head;
                while( count < (position-2) ){
                    temp = temp->next;
                    count++;
                }
                printf("\n Enter data to push in the node :- ");
                scanf("%d", &newnode->data);

                newnode->next = temp->next;
                temp->next = newnode;
                
                printf("\n The element %d is inserted successfully \n",newnode->data);

            }
        }
        
    }
}

void DeleteAtFirst(){

    if (head == NULL){
        printf("\n There are no nodes to delete \n");
        return;
    }

    else {

        if( head->next == NULL){
            char choice[20] = "0";
            printf("\n There is only one node in the list. \n");
            printf("\n Do you want to delete the node(yes/no) :- ");
            scanf("%s", &choice);

            if(strcmp(choice,"no") == 0 || strcmp(choice,"NO") == 0 || strcmp(choice,"No") == 0 ){
                printf("Escaping");
                return;
            }
        }

        struct node *temp=head;
        head=head->next;
        printf("\n The first node with data %d is deleted successfully", temp->data);
        free(temp);

    }

}

void DeleteAtLast(){
    if (head == NULL){
        printf("\n There are no nodes to delete \n");
        return;
    }

    else{
        struct node *temp = head;
        if( head->next == NULL){
            char choice[20]="0";
            printf("\n There is only one node in the list. \n");
            printf("\n Do you want to delete the node(yes/no) :- ");
            scanf("%s", &choice);

            if(strcmp(choice,"no") == 0 || strcmp(choice,"No") == 0 || strcmp(choice,"NO") == 0 ){
                printf("Escaping");
                return;
            }
            else{
                temp = head;
                printf("\n The data %d at last position is deleted successfully\n",temp->data);
                free(temp);
                head = NULL;
                return;
            }    
        }
        
        struct node *previous = temp;
        while(temp->next != NULL){
            previous = temp;
            temp = temp->next;
        }
        previous->next =NULL;
        printf("\n The data %d at last position is deleted successfully\n",temp->data);
        free(temp);


    }

}

void DeleteAtPosition(){
    if(head == NULL){
        printf("\n No node in the list, escaping the function\n");
        return ;
    }

    else{
        struct node *temp;

        int count = 0;
        int position=0;

        temp=head;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        printf("\n There are total %d nodes\n", count+1);

        printf("\n Enter the position of the node to be deleted :- ");
        scanf("%d", &position);

        if( position < 1 || position > (count+1) ){
            printf("\n The position %d is invalid, escaping the function ",position);
            return;
        }

        else{
                if( position == 1){
                    DeleteAtFirst();
                }

                else if ( position == (count+1) ){
                    DeleteAtLast();
                }
                else{

                    struct node *previous;
                    count = 0;
                    temp=head;
                    while( count < (position-1) ){
                        previous = temp;
                        temp = temp->next;
                        count++;
                    }
                    previous->next = temp->next;
                    
                    printf("\n The element %d is deleted successfully \n",temp->data);
                    free(temp);

                }
        }
    }
}

void display(){
    printf("-------- Linked List -----------\n");
    struct node *temp = head;
    if(head == NULL){
        printf("\n No data to display, list is empty ");
        return;
    }
    printf("\tData :\n");
    int position = 1;
    while( temp !=NULL ){
        printf("\tV\n");
        printf(" position : %d data : %d\n",position,temp->data);
        temp = temp->next;
        position++;
    }

}

int main(){
    int choice = -1;
    printf("-------- Linked List -----------\n");

    while(1){
        printf("\tMENU\t\n");
        printf("\t1. Insert At First\t\n");
        printf("\t2. Insert At Last\t\n");
        printf("\t3. Insert At Position\t\n");
        printf("\t4. Delete At First\t\n");
        printf("\t5. Delete At Last\t\n");
        printf("\t6. Delete At Position\t\n");
        printf("\t7. Display\t\n");
        printf("\t8. Exit\t\n");


        printf("\n Enter the choice no :- ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            InsertAtStart();
            break;
        case 2:
            InsertionAtLast();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtFirst();
            break;
        case 5:
            DeleteAtLast();
            break;
        case 6:
            DeleteAtPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\nExiting the program");
            return 0;
        default:
            printf("Invalid Choice");
            break;
        }
    }


}