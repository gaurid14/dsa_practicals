/*
Name:Gauri Desai
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int stack[5];
int top=-1;
void push(int item);
void pop();
void display();
void main(){
    int ch;
    int n1;
    
    while(1){
        printf("\n---Stack Operation---");
        printf("\n1. Push an element into stack");
        printf("\n2. Pop out an element from the stock");
        printf("\n3. Display the stack elements");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: printf("Enter the element to be pushed into the stack: ");
                    scanf("%d",&n1);
                    push(n1);
                    break;
            
            case 2: pop();
                    break;
                    
            case 3: display();
                    break;
            
            case 4: exit(1);
            
            default: printf("\nWrong choice");
                    break;
        }
    }
}

void push(int item){
    if(top==4){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top] = item;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty");
    }
    else{
        int a = stack[top];
        top--;
        printf("\n%d element popped out of the stack",a);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("\nElements in the stack are:");
        for(i=top;i>=0;i--){
            printf("\n%d",stack[i]);
        }
    }
}
