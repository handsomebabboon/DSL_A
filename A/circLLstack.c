#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;
Node* bottom = NULL;
void push(){ 
    int x;
    printf("Enter a number to insert\n");
    scanf("%d",&x);
    Node* temp = (Node*)malloc(sizeof(Node)); 
    
    if(top == NULL && bottom == NULL){
        top =temp;
        bottom = temp;
        temp -> data = x;
        temp -> next = temp;
    }
    else{
        temp-> next = top;
        top = temp;
        bottom -> next = top;
        top -> data = x;
    }
}

void pop(){

    Node* temp;
    if(top == NULL){
        printf("Empty!\n");
    }
    else if(top == bottom){
        top = NULL;
        bottom = NULL;
    }
    else{
    temp = top;
    top = top -> next;
    bottom -> next = top;
    printf("%d was  deleted\n",temp->data);
    free(temp);
    }
}

void isEmpty(){

    if(top == NULL){
        printf("Stack is empty!\n");
    }
    else{
        printf("Not empty!\n");
    }

}

void peek(){
    if(top != NULL){
        printf("%d \n",top -> data);
    }
    else{
        printf("Stack is empty\n");
    }
}

void checkSize(){
    int count = 0;
    Node* temp = top;
    if(top == NULL && bottom == NULL){
        printf("Stack is empty!");
    }
    else{
        /* while(temp != NULL){
            count++;
            temp = temp-> next;
        }
        printf("%d\n",count);
        */
        do{
            count++;
            temp = temp -> next;
        }while(temp != top);
        printf("%d\n",count);
    }
}

void printstack(){

    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{

        Node* temp = top;
        /*printf("Top -> ");
        while(temp -> next != NULL){
            printf("%d ->",temp -> data);
            temp = temp-> next;
        }
        printf("%d",temp -> data);
        printf("\n");
        */

        do{
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }while(temp != top);
    }
}



void main(){
    int n;
    

    while(1){
        printf("Enter\n 1-push \n 2- pop \n 3-peek"
        " \n 4-checkSize \n 5-isEmpty \n 6-print stack \n -1-exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                push();
                break;

            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                checkSize();
                break;
            case 5:
                isEmpty();
                break;

            case 6:
                printstack();
                break;
            case -1:
                exit(0);
                break;

            default:
                printf("Invalid option!");
        }
    }
}