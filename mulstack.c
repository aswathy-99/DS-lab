#include <stdio.h>
#include <stdlib.h>
int arr[5],top1=-1,top2=5;
void push(int n,int elem){
    if(n==1){
        top1++;
        if(top1<top2){
            arr[top1]=elem;
        }
        else{
            printf("Stack overflow!!\n");
            return;
        }
    }
    else{
        top2--;
        if(top2>top1){
            arr[top2]=elem;
        }
        else{
            printf("Stack overflow!!\n");
            return;
        }
    }
}
int isempty(int n){
    if(n==1){
        if(top1==-1){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(n==2){
        if(top2==5){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int pop(int n){
    if(n==1){
        if(top1>-1){
            printf("%d",arr[top1]);
top1=top1-1;
        }
        else{
            printf("Stack empty!!\n");

        }
    }
    else{
        if(top2<5){
            printf("%d",arr[top2]);
top2++;
        }
        else{
            printf("Stack empty!!\n");
        }
    }
}
void traversal(int n){
    int t;
    if(n==1){
        if(isempty(n)){
            for(t=top1;t>-1;t--){
                printf("%d\t",arr[t]);
            }
        }
        else{
            printf("Stack empty!\n");
        }
    }
    else{
        if(isempty(n)){
            for(t=top2;t<5;t++){
                printf("%d\t",arr[t]);
            }
        }
        else{
            printf("Stack empty!\n");
        }
    }
}
void main(){
    int ch,n,elem;
    while(1){
        
        printf("Enter your choice: 1.Push\n 2.Pop\n 3.Traversal\n 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the stack to be pushed:\n");
            scanf("%d",&n);
            if(n==1 || n==2){
                printf("Enter the element to be pushed:\n");
                scanf("%d",&elem);
                push(n,elem);
            }
            else{
                printf("Invalid choice!!\n");
                continue;
            }
            break;
        case 2:
            printf("Enter the stack to be popped:\n");
            scanf("%d",&n);
            if(n==1 || n==2){
                pop(n);
            }
            else{
                printf("Invalid choice!!\n");
                continue;
            }
            break;
        case 3:
            printf("Enter the stack to be traversed:\n");
            scanf("%d",&n);
            if(n==1 || n==2){
                traversal(n);
            }
            else{
                printf("Invalid choice!!\n");
                continue;
            }
            break;
        case 4:
            exit(0);
        default:
            printf("You have entered a wrong choice!!!\n");
            break;
        }
    }
}
