#include<stdio.h>
#define max 10
static int a[max],p=-1;	
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
   case 3 :display(a);
           break;
   default :printf("\ninvalid entry");
 }
 printf("\nenter 1 to continue");
 scanf("%d",&i);
}while(i==1);

}

 
 
void push(int x)
{ 
 if(p<max){  
  a[++p]=x ;}
 else
 printf("not sufficient space");
}
int pop()
{

 return a[p--];
}
void display() 
{
 int q;
 if(p<0)
 printf("stack empty");
else
{
 for(q=0;q<=p;q++)
 printf("%d",a[q]); 



}
}

