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
    newnode -> data = x;
    newnode -> next = NULL;

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
        front -> next = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
        rear -> next = front;
    }
}

int search(int key)
{
	int index = 1;
    struct Node *current = front;

    // Iterate till end of list
    do 
    {
		// Nothing to look into
		if (current == NULL)
			return;
		
		if (current->data == key)
			return index;

        current = current->next;
		index++;
    } while (current != front);

    // Element not found in list
    printf("Element not found-");
    return key;
    
}

void dequeue(){

    Node* temp;
    temp = front;
    if(front ==NULL && rear == NULL){
        printf("Underflow");
    }

    else if(front == rear){
        printf("%d was popped\n",temp -> data);
        front = rear = NULL;
    
        
    }

    else{
        printf("%d popped\n",temp -> data);
        front = front -> next;
        rear -> next = front;
        free(temp);
        temp = NULL;
    }

}

void peek(){
    if(front == NULL && rear == NULL){
        printf("Emtpy!");
    }
    else{
    printf("%d",front-> data);
    }
}

void display(){
    Node* temp = front;
    
    if(front == NULL && rear == NULL){
        printf("Empty!");
    }
    else{
        do{
            printf("%d\t",temp -> data);
            temp = temp->next;
        }while(temp !=front);
    }
}

void isEmpty(){
    if(front == NULL && rear == NULL){
        printf("Empty stack!");
    }
    else{
        printf("Not empty");
    }
}



void main(){
    int temp;
    int ch;
    int data;
    while(1){
        printf("\nEnter 1)Enqueue \n 2)dequeue \n 3)peek \n 4)display \n 5)check if empty \n 6)search \n -1)exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter a number");
                scanf("%d",&data);
                enqueue(data);
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

            case 5:
                isEmpty();
                break;

            case 6:
                
                printf("Enter element to search");
                scanf("%d",&temp);
                int x= search(temp);
                printf("%d",x);
                break;
            case -1:
                exit(0);
                break;

            default:
                printf("Invalid option!");
        }
    }

  
}