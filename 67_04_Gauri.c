/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>
#define size 10

int queue[size];
int front=-1;
int rear=-1;

int isFull(){
    return ((front==0 && rear==size-1) || (front==rear+1));
}

int isEmpty(){
    return (front==-1);
}

void insertFront(int value){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front=size-1;
    }
    else{
        front--;
    }
    queue[front]=value;
}

void insertRear(int value){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==size-1){
        rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=value;
}

int deleteFront(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int value=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==size-1){
        front=0;
    }
    else{
        front++;
    }
    return value;
}

int deleteRear(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int value=queue[rear];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=size-1;
    }
    else{
        rear--;
    }
    return value;
}

void display(){
    int i;
    if(rear==-1 && front==-1){
        printf("\nQueue underflow");
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
    int n1;
    
    while(1){
        printf("\n---DoubleEnded Queue Operation---");
        printf("\n1. Insert an element at front in the queue");
        printf("\n2. Insert an element at rear in the queue");
        printf("\n3. Delete an element at front in the queue");
        printf("\n4. Delete an element at rear in the queue");
        printf("\n5. Display the queue elements");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: printf("Enter the element to be enqueued: ");
                    scanf("%d",&n1);
                    insertFront(n1);
                    break;
            
            case 2: printf("Enter the element to be enqueued: ");
                    scanf("%d",&n1);
                    insertRear(n1);
                    break;
                    
            case 3: deleteFront();
                    break;
                    
            case 4: deleteRear();
                    break;
            
            case 5: display();
                    break;
            
            case 6: exit(1);
            
            default: printf("\nWrong choice");
                    break;
        }
    }
}