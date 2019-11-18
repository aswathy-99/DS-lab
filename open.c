#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{  int data;
   struct node *link;
};

struct node *head[size];
 void insert()
{   int key;
    printf("\nEnter the value to be inserted:");
    scanf("%d",&key);
    int i=key%size;
    struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->link=NULL;
    if(head[i]==NULL)
        head[i]=newnode;
    else
    {   struct node *c=head[i];
        while(c->link!=NULL)
            c=c->link;
        c->link=newnode;
    }
}

void display()
{  
   for(int i=0;i<size;i++)
   {  printf("\nAt index %d :",i);
      if(head[i]==NULL)
      {    printf("No elements"); }
      else 
      {  struct node *c=head[i];
         while(c!=NULL)
         {  printf("%d ->",c->data);
            c=c->link;
         }
      }
      
   }
}

void search()
{   int key,flag=0;
    printf("\nEnter the element to be searched:");
    scanf("%d",&key);
    int index=key%size;
    if(head[index]==NULL)
       printf("\nEmpty Table");
    else
    {  struct node *c=head[index];
       while(c!=NULL)
       {   if(c->data==key)
           {  flag=1;
              break;
           }
           c=c->link;
       }
    }
    if(flag==0)
       printf("\nElement not found");
    else
       printf("\nElement found");

}
 
void main()
{  int ch,item;
   
   for(int i=0;i<size;i++)
   { head[i]=NULL; }
   do
   {
      printf("\n\t1.Insert\n2.Display\n3.Search\n4.Exit\nEnter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {   case 1:insert();
                 break;
          case 2:display();
                 break;
          case 3:search();
                 break;
          case 4:exit(0);
          default:printf("\nWrong Choice!");
      }
   }while(ch!=4);
}
   

																																																																																																																																																									
