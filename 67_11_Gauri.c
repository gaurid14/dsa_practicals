/*
Name:Gauri Desai
SE IT
Roll no:67
Batch:2023-24
*/
#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,temp,i,j,a[20];
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("\nAfter sorting: ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}

bubblesort(int *a,int n){
    int i,j,k,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        printf("\nPass %d: ",n-i-1);
        for(k=0;k<n;k++){
            printf("%d",a[k]);
        }
    }
}
