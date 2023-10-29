/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    int priority;
    struct node *next;
};

struct node *front;

void init(){
    front=NULL;
}

struct node* getnode(){
    return (( struct node* ) malloc (sizeof(struct node)));
}

void freenode(struct node *p){
    free(p);
}

void enqueue(int v,int p){
    struct node *newnode,*temp;
    newnode=getnode();
    newnode->info=v;
    newnode->priority=p;
    
    if(front==NULL || front->priority > newnode->priority){
        newnode->next=front;
        front=newnode;
    }
    else{
        temp=front;
        while(temp->next!=NULL && temp->next->priority <= newnode->priority){
            temp=temp->next;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

int dequeue(){
    int x;
    struct node* temp;
    temp=front;
    x=temp->info;
    front=front->next;
    freenode(temp);
    return x;
}

void display(){
    struct node *temp;
    if(front==NULL){
        printf("\nQueue is empty");
    }
    else{
        temp=front;
        printf("\nElements are: ");
        printf("\n\tElements \t Priority");
        while(temp!=NULL){
            printf("\n\t %d \t\t %d",temp->info,temp->priority);
            temp=temp->next;
        }
    }
}

void main(){
    int ch,x,p,i,ans;
    init();
    do{
        printf("\n --------Priority Queue Operation using Linked List -----------");
        printf("\n 1.Insert/Enqueue");
        printf("\n 2.Delete/Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        
        printf("\n Enter your choice");
        scanf("%d",&ch);
        
        switch(ch){
            case 1 : printf("Enter the value to be inserted: ");
                    scanf("\n %d",&x);
                    printf("\nEnter the priority of value inserted: ");
                    scanf("%d",&p);
                    enqueue(x,p);
                    break;
            case 2 : if(front==NULL){
                        printf("Queue is empty");
                    } 
                    else{
                        x=dequeue();
                        printf("\n%d is deleted",x);
                    }
                    break;
            case 3 : display();
                    break;
            case 11 : exit(1);
            default : printf("\nWrong Choice");
            
        }
        printf("Do you want to continue (1 = yes / 0 = no)?");
        scanf("%d",&ans);
    }while(ans ==1);
}
