#include <stdio.h>
#include <stdlib.h>
#define max 5
int Queue[max],rear=-1,front=-1;
void enqueue(int e)
{
if(rear==(max-1))
printf("Queue is full\n");
else
{
if(front==-1 && rear==-1)
front=rear=0;
else 
rear=rear+1;

Queue[rear]=e;
}
}

void dequeue()
{
int d;
if(rear==-1)
printf("Empty queue\n");
else
{
printf("The element deleted:%d\n",Queue[front]);

if(front==rear)
front=rear=-1;
else
front=front+1;
}
}

void display()
{
if (rear==-1)
printf("Empty Queue\n");
else
{
for(int i=front;i<=rear;i++)
printf("%d\t",Queue[i]);
}
}

void main(void)
{
int c,e;
while(1)
{
printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("Enter the element to be inserted:");
scanf("%d",&e);
printf("\n");
enqueue(e);
break;

case 2:
dequeue();
break;

case 3:
display();
break;

case 4:
exit(0);
    
default:
printf("Wrong Choice");
break;
}
}
}
