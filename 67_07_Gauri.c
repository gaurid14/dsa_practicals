/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *front,*rear;

void init(){
    front=rear=NULL;
}

struct node* getnode(){
    return (( struct node* ) malloc (sizeof(struct node)));
}

void freenode(struct node *p){
    free(p);
}

int empty(){
    if(rear==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int v){
    struct node *newnode;
    newnode=getnode();
    newnode->info=v;
    if(empty()){
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
    }
    else{
        newnode->next=rear->next;
        rear->next=newnode;
        rear=newnode;
    }
}

int dequeue(){
    int x;
    struct node* temp;
    temp=front;
    x=front->info;
    if(front==rear){
        init();
    }
    else{
        front=front->next;
    }
    freenode(temp);
    return x;
}

void display(){
    struct node *temp;
    if(empty()){
        printf("\nQueue is empty");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("->%d",temp->info);
            temp=temp->next;
        }
    }
}

void main(){
    int ch,x,i,ans;
    init();
    do{
        printf("\n --------Queue Operation using Linked List -----------");
        printf("\n 1.Insert/Enqueue");
        printf("\n 2.Delete/Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        
        printf("\n Enter your choice");
        scanf("%d",&ch);
        
        switch(ch){
            case 1 : printf("Enter the value to be inserted: ");
                    scanf("\n %d",&x);
                    enqueue(x);
                    break;
            case 2 : if(!empty()){
                        x=dequeue();
                        printf("\n%d is deleted",x);
                    }
                    else{
                        printf("\nQueue is empty",x);
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
