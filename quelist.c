#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node 
{
 int data;
 struct node* link;
 };
struct node* top=NULL;

int pop();
void push(int);
void display();
void main()
{
 int i,n,x; 
 do
 {
  printf("enter 1 for enque\n2 for deque\n3 for displaying the queue ");
  scanf("%d",&n);
  switch(n)
  { 
   case 1:printf("enter the data to be pushed");
          scanf("%d",&x);
          push(x); 
          break;
   case 2 :printf("the value dequed is %d",pop());
           break;
   case 3 :display();
           break;
   default :printf("\ninvalid entry");
 }
 printf("\nenter 1 to continue");
 scanf("%d",&i);
}while(i==1);

}

 int pop()
{ 
 int n=top->data;
 if (top==NULL)
 { printf("que empty");
  exit(0);
 }
 struct node* newnode=top;
 top=top->link;
 free(newnode);
 return n;
}
void push(int n)
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
       
        temp->data=n;
        temp->link =NULL;
        if(top==NULL)
        {
                top=temp;
        }
        else
        {
                ptr=top;
                while(ptr->link !=NULL)
                {
                        ptr=ptr->link ;
                }
                ptr->link =temp;
        }
}
void display()
{
 struct node* temp;
 printf("\nThe que is\n");
 for(temp=top;temp!=NULL;temp=temp->link)
 printf("%d->",temp->data);
} 
  
