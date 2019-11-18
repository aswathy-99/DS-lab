#include<stdio.h>
#define max 5
int partition(int[],int,int);
void quicksort(int[],int,int);
void main()
{
int n,left,right;
int a[50];
printf("enter the limit \n");
scanf("%d",&n);
printf("enter the elements\n");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
left=0;
right=n-1;
quicksort(a,left,right);
printf("the sorted array is \n");
for(int i=0;i<n;i++)
{
printf( "%d",a[i]);
}
}
int partition(int a[],int left,int right)
{
int pivot,lb,ub,t;
lb=left;
ub=right;

pivot=a[lb];
while(left<right)
{
while((a[left]<=pivot )&& (left<=right))
{
left++;
}
while((a[right]>pivot)&& (left<=right))
{
right--;
}
if(left<right)
{
t=a[left];
a[left]=a[right];
a[right]=t;
}
}
t=a[lb];
a[lb]=a[right];
a[right]=t;

return right;
}
void quicksort(int a[],int left,int right)
{
int lb,ub,p,q,r;
lb=left;
ub=right;
if(lb<ub)
{
p=partition(a,lb,ub);
printf("p=%d",p);
quicksort(a,lb,p-1);
quicksort(a,p+1,ub);
}
}
	






	



	
















