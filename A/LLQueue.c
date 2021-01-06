#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

    Node* front = NULL;
    Node* rear = NULL;

void enqueue(int x){
    Node* newnode = (Node*)malloc(sizeof(Node));
        newnode -> next = NULL;
        newnode -> data = x;
    if(front == NULL && rear == NULL){
       
        front = newnode;
        rear = newnode;
    }
    else{
        
        rear -> next = newnode;
        rear = newnode;

    }
}

void dequeue(){
    Node* temp = front;
    if(front == NULL){
        printf("Empty!\n");
    }
    else if(front == rear){ // resets both front and rear to null once theyre pointing to same node
        front = rear = NULL;
        free(temp);
    }
    else{
      
      front = front -> next;
      free(temp);
    }
}

void peek(){
    if(front == NULL){
        printf("Empty!");
    }
    else{
    printf("%d\n",front -> data);
    }
}

void display(){

    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        if(front == NULL && rear == NULL){
            printf("Empty!");
        }

        else{
        Node* temp = front;

        printf("front ->");
        while(temp != NULL){
            printf("%d -> ",temp ->data);
            temp = temp ->next;
        }
        
        printf("rear");
        }
    }
}
void main(){
    int n,p;
    while(1){
        printf("\n Enter \n 1) enqueue \n 2)dequeue \n 3)peek \n 4)display \n -1) exit \n");
        scanf("%d",&n);
        switch(n){
            case 1:
                
                printf("Enter an integer to enqueue\n");
                scanf("%d",&p);
                enqueue(p);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case -1:
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }
}