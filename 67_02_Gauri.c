/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int front,rear;
void init();
void enqueue(int item);
void dequeue();
void display();

void init(){
    front = -1;
    rear = -1;
}

void enqueue(int item){
    if(rear==size-1){
        printf("Queue overflow");
    }
    else{
        rear=rear+1;
        queue[rear]=item;
    }
}

void dequeue(){
    if(rear<front){
        printf("\nQueue is empty");
    }
    else{
        printf("\n%d is deleted",queue[front++]);
    }
}

void display(){
    int i;
    if(rear<front){
        printf("Queue underflow");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("\n%d",queue[i]);
        }
    }
}

void main(){
    int ch;
    int x;
    init();
    
    while(1){
        printf("\n---Queue Operation---");
        printf("\n1. Enqueue element");
        printf("\n2. Dequeue element");
        printf("\n3. Display the queue elements");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: printf("Enter the element to be enqueued: ");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            
            case 2: dequeue();
                    break;
                    
            case 3: display();
                    break;
            
            case 4: exit(1);
            
            default: printf("\nWrong choice");
                    break;
        }
    }
}