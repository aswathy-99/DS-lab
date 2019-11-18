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
  printf("enter 1 for pushing\n2 for poping\n3 for displaying the stack ");
  scanf("%d",&n);
  switch(n)
  { 
   case 1:printf("enter the data to be pushed");
          scanf("%d",&x);
          push(x); 
          break;
   case 2 :printf("the value popped is %d",pop());
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
 int n;
 if (top==NULL)
 { printf("stack empty");
  exit(0);
}
 struct node* newnode=top;
 top=top->link;
 
 free(newnode);
 return n;
 }
void push(int n)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
   {
     printf("no space");
     return;
   }
  else 
  {   
  newnode->link=top;
  newnode->data=n;
  top=newnode;
  }
}
void display()
{
 struct node* temp;
 printf("\nThe linked list is\n");
 for(temp=top;temp!=NULL;temp=temp->link)

 printf("%d->",temp->data);
} 
  







