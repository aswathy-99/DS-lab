#include <stdio.h>
#include <stdlib.h>
#define max 5
int Queue[max],rear=-1,front=-1;

void enqueue(int e)
{
	if(front==(rear+1)%max)
	printf("Queue is full\n");

	else
	{
	if(rear==-1)
	rear=front=0;
	else
	rear=(rear+1)%max;

	Queue[rear]=e;
	}   
}

void dequeue()
{
if(front==-1)
printf("Empty queue\n");
else
{
printf("The element deleted :%d\n",Queue[front]);
if(front==rear)
front=rear=-1;
else
front=(front+1)%max;
}
}

void display()
{

if(front==-1)
printf("Empty Queue\n");

else if(front<rear)
{
for(int i=front;i<=rear;i++)
printf("%d\t",Queue[i]);
}

else if(rear<front)
{
for(int n=0;n<=rear;n++)
printf("%d\t",Queue[n]);

for(int m=front;m<=(max-1);m++)
printf("%d\t",Queue[m]);
}

else;
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
