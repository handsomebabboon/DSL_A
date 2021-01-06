#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(){
    int x;
    printf("Enter a number to insert\n");
    scanf("%d",&x);
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = x;
    temp ->next = top;
    top = temp;
}

void pop(){

    Node* temp;
    if(top == NULL){
        printf("Empty!\n");
    }
    else{
    temp = top;
    top = top -> next;
    printf("%d was deleted\n",temp->data);
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

    while(temp != NULL){
        count++;
        temp = temp-> next;
    }
    printf("%d\n",count);
}

void printstack(){

    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{

        Node* temp = top;
        printf("Top -> ");
        while(temp -> next != NULL){
            printf("%d ->",temp -> data);
            temp = temp-> next;
        }
        printf("%d",temp -> data);
        printf("\n");
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

                
        }
    }
}