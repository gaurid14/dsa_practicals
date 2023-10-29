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
    if((front==0 && rear==size-1) || front==rear+1){
        printf("\nQueue overflow");
    }
    else{
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%size;
            queue[rear]=item;
        }
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        printf("\nCircular queue is empty");
    }
    else if(rear==front){
        printf("\n%d is deleted",queue[front]);
        rear=-1;
        front=-1;
    }
    else{
        printf("\n%d deleted",queue[front]);
        front=(front+1)%size;
    }
}

void display(){
    int i;
    if(rear==-1 && front==-1){
        printf("Queue underflow");
    }
    else{
        i=front;
        while(i!=rear){
            printf("\n%d",queue[i]);
            i=(i+1)%size;
        }
        printf("\n%d",queue[i]);
    }
}

void main(){
    int ch;
    int x;
    init();
    
    while(1){
        printf("\n---Circular Queue Operation---");
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