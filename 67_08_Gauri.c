/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>
#define size 100

char stack[size];
int top=-1;
void push(char item);
char pop();

int ischaracteradigit(char a){
    if(a>='0' && a<='9'){
        return 1;
    }
    else{
        return 0;
    }
}

int evaluateexp(int p1,int p2,char opr){
    if(opr=='+'){
        return(p1+p2);
    }
    if(opr=='-'){
        return(p1-p2);
    }
    if(opr=='*'){
        return(p1*p2);
    }
    if(opr=='/'){
        return(p1/p2);
    }
    if(opr=='%'){
        return(p1%p2);
    }
}

void push(char x){
    if(top==size-1){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top]=x;
        printf("\n%d inserted in stack",x);
    }
}

char pop(){
    char x;
    x=stack[top--];
    printf("\n%d element popped out of the stack",x);
    return x;
}

void main(){
    char op1,op2,x;
    int val;
    
    printf("\n---Postfix Evaluation---");
    printf("Enter the expression");
    
    while((x=getchar())!='n'){
        if(ischaracteradigit(x)){
            push(x-'0');
        }
        else{
            if(top==-1){
                printf("\nStack is empty");
            }
            else{
                op2=pop();
                op1=pop();
                val=evaluateexp(op1,op2,x);
                printf("\nEvaluation ans: %d",val);
                push(val);
            }
        }
    }

val=pop();
printf("\nValue of Expression: %d",val);
}