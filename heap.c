#include<stdio.h>
void heapify(int[],int,int);
void heapsort(int[],int);
void main()
{
int a[20],n;
printf("enter the limit");
scanf("%d",&n);
printf("enter array elements");
for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
heapsort(a,n);
printf("sorted array is\n");
for(int i=0;i<n;i++)
	printf("%d ",a[i]);	
}
void heapify(int a[],int n,int i)
{
	int largest=i,l=2*i+1,r=2*i+2,t;
	if((l<n)&&(a[l]>a[largest]))
	largest=l;
	if((r<n)&&(a[r]>a[largest]))
	largest=r;
    if(largest!=i)
	{
	t=a[i];
	a[i]=a[largest];
	a[largest]=t;	
	}
	heapify(a,n,largest);
}
void heapsort(int a[],int n)
{  
   int t;
	for(int i=n/2-1;i>=0;i--)
	heapify(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		heapify(a,i,0);
		
	}
}
