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

struct node *list;
struct node* getnode(){
    return (( struct node* ) malloc (sizeof(struct node)));
}
void freenode(struct node *p){
    free(p);
}

void display(){
    int i;
    struct node *t;
    t=list;
    if(t== NULL){
        printf("\n The Linked List is Empty");
	}
    else{
        printf("\n The Linked List elements are:");
        while(t!= NULL){
            printf(" -> %d", t->info);
            t=t->next;
            
        }
    }
}

void insertbeg(int x){
    struct node *newnode;
    newnode=getnode();
    newnode->info = x;
    newnode->next = list;
    list=newnode;
    display();
    
}

void insertend(int x){
    struct node *newnode, *temp;
    newnode=getnode();
    newnode->info = x;
    newnode->next = NULL;
    
    temp=list;
    if(temp==NULL){
        list=newnode;
	}
    else{
        while(temp->next!=NULL){
            temp= temp->next;
            
        }
        temp->next=newnode;
        
    }
    display();
}

void insertloc(int p,int x){
    struct node *newnode, *temp;
    int i;
    temp=list;
    
    if (temp= NULL){
        insertbeg(x);
	}
    else{
        for(i=1;i<p-1;i++){
            if(temp->next == NULL){
                printf("There are less than %d elements in the list so inserted element at the end",p);
                break;
            }
            temp=temp->next;
        }
        newnode =getnode();
        newnode->info=x;
        newnode->next=temp->next;
        temp->next=newnode;
        display();
    }
    
}

void delbeg(){
    struct node *temp;
    temp=list;
    if(list ==NULL){
        printf("List is already Empty");
	}
    else{
        printf("Element %d is successfully deleted",temp->info);
        list=temp->next;
        freenode(temp);
        display();
        
    }
}

void delend(){
    int x;
    struct node *temp, *ptr;
    temp=list;
    if(list == NULL){
        printf("List is already Empty");
	}
    else{
        if(temp->next == NULL){
            x= temp->info;
            list= NULL;
        }
        else{
            while(temp->next != NULL){
                ptr= temp;
                temp= temp=temp->next;
            
            }
            x=temp->info;
            ptr->next= NULL; 
        }
        printf("Element %d successfully deleted",x);
        freenode(temp);
        display();
    }
}

void delloc(int p){
    int x,i;
    struct node *temp, *ptr;
    temp=list;
    if(list == NULL){
        printf("List is already Empty");
	}
    else{
        if(p==1){
            list=list->next;
        }
        else{
            for(i=1;i<p;i++){
                if(temp->next == NULL){
                    printf("There are less than %d elements int the List",p);
                    break;
                }
                ptr=temp;
                temp=temp->next;
            }
            
        }
        if(temp->next != NULL){
            printf("Element %d successfully deleted",temp->info);
            ptr->next = temp->next;
            freenode(temp);
        }
        display();
        
    }
}

void search(int x){
    int i;
    struct node *temp;
    temp= list;
    if(list == NULL){
        printf("List is Empty");
	}
    else{
        i=1;
        while(temp->next != NULL){
            if(temp->next != NULL){
                printf("Position of element %d is %d",x,i);
                break;
                
                
            }
            temp=temp->next;
            i++;
            
        }
        if(temp->next == NULL && temp->info==x){
            printf("Position of Element %d is %d",x,i);
		}
        if(temp->next == NULL && temp->info!=x){
            printf("\n Elemet not found");
		}   
    }
}

void reverse(){
    struct node *temp,*newnode,*list2;
    temp=list;
    list2= NULL;
    if(temp==NULL){
        printf("List id Empty. Connot Reverse");
	}
    else{
        while(temp!= NULL){
            newnode=getnode();
            newnode->info =temp->info;
            newnode->next=list2;
            list2=newnode;
            temp=temp->next;
            
        }
        temp=list2;
        while(temp!= NULL){
            printf("->%d",temp->info);
            temp=temp->next;
        }
        
    }
}

void count(){
    struct node *temp;
    int i=0;
    temp=list;
    if (list == NULL){
        printf("Count is %d",i);
	}
    else{
        while(temp != NULL){
            i++;
            temp= temp->next;
        }
        printf("Count is %d",i);
    }
}

void main(){
    struct node *getnode;
    int ch,p,x;
    
    int ans;
    do{
        printf("\n --------Linked List -----------");
        printf("\n 1.Insert at Beginning");
        printf("\n 2.Insert at end");
        printf("\n 3.Insert at location");
        printf("\n 4.Delete at Beginning");
        printf("\n 5.Delete at end");
        printf("\n 6.Delete at location");
        printf("\n 7.Search an element");
        printf("\n 8.Display List");
        printf("\n 9.Reverese");
        printf("\n 10.Count");
        printf("\n 11.Exit");
        
        printf("\n Enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter the node value:");
                    scanf("\n %d",&x);
                    insertbeg(x);
                    break;
            case 2 : printf("Enter the node value:");
                    scanf("\n %d",&x);
                    insertend(x);
                    break;
            case 3 : printf("Enter the node value:");
                    scanf("\n %d",&x);
                    printf("\n Enter the position for element %d:",x);
                    scanf("\n %d ", &p);
                    insertloc(p,x);
                    break;
            case 4 : delbeg(); 
                    break;
            case 5 : delend();
                    break;
            case 6 : printf("Enter the node to be deleted:");
                    scanf("%d",&p);
                    delloc(p);
                    break;
            case 7 : printf("Enter the node value");
                    scanf("%d",&x);
                    search(x);
                    break;
            case 8 : display();
                    break;
            case 9 : reverse();
                    break;
            case 10 : count();
                    break;
            case 11 : exit(1);
            default : printf("\nWrong Choice");
            
        }
        printf("Do you want to continue (1 = yes / 0 = no)?");
        scanf("%d",&ans);
        
        
    }while(ans ==1);
}
