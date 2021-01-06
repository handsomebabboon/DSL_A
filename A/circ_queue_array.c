#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front = -1;

int rear = -1;

void enqueue(int x){
   
    if(front == -1 && rear == -1){
        front=0;
        rear =0;
        queue[rear] = x;
    }
    else if((rear + 1)%N == front){

        printf("Queue is full!");

    }
    else{
        rear = (rear + 1)%N;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Empty");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        printf("%d removed",queue[front]);
        front = (front+1)%N;
    }
}

void display(){
   int i=front;
   if(front == -1 && rear == -1){
       printf("Queue is empty");
   }else{
       printf("Queue is:");
       while(i != rear){
           printf("%d \t",queue[i]);
           i=(i+1)%N;
       }
       printf("%d",queue[rear]);
   }
}

void main()
{
    int choice;
   int temp;
    while(1){
        
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("Ente r integer to enter");
            scanf("%d",&temp);
            enqueue(temp);
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: exit(1);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }

    
}