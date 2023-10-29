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
    printf("Enter total no of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printf("After sorting: ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}

insertionsort(int *a,int n){
    int i,j,k,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=j-1;
        while((temp<a[j]) && (j>=0)){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        printf("\nPass %d: ",i);
        for(k=0;k<n;k++){
            printf("%d",a[k]);
        }
    }
}
