/*
Name:Gauri Desai
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int info;
    struct stack *next;
};

struct stack *top;
struct stack* getnode(void){
    return (( struct stack* ) malloc (sizeof(struct stack)));
}

void freenode(struct stack *p){
    free(p);
}

void push(int x){
    struct stack* newnode;
    newnode=getnode();
    newnode->info=x;
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==NULL){
        printf("\nList is empty");
    }
    else{
        struct stack* temp;
        temp=top;
        int x=top->info;
        printf("%dElement deleted succesfully",x);
        top=top->next;
        freenode(temp);
    }
}

void display()
{
    struct stack *temp;
    temp=top;
    printf("\nTop");
    while(temp!= NULL){
        printf("->%d",temp->info);
        temp=temp->next;
    }
}


void main()
{
    struct node *getnode;
    int ch,n1;
    
    while(1){
        printf("\n --------Stack Operation using Linked List -----------");
        printf("\n 1.Push an element into the stack");
        printf("\n 2.Pop an element from the stack");
        printf("\n 3.Display an element from the stack");
        printf("\n 4.Exit");
        
        printf("\n Enter your choice");
        scanf("%d",&ch);
        
        switch(ch){
            case 1 : printf("Enter the element to be pushed into the stack:");
                    scanf("\n %d",&n1);
                    push(n1);
                    break;
            case 2 : pop();
                    break;
            case 3 : display();
                    break;
            case 4 : exit(1);
            default : printf("\nWrong Choice");
            
        }
    }
}
