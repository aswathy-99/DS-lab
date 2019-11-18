#include<stdio.h>
#include<stdlib.h>
void linear(int[],int,int);
void binary(int a[],int k,int n);
void sort(int a[],int n);
void main()
{
int a[30],n,k,c;
printf("enter the limit:");
scanf("%d",&n);
printf("enter the elements");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the element to be searched:");
scanf("%d",&k);
printf("enter 1 for linear and 2 for binary search");
scanf("%d",&c);
switch(c)
{
case 1:linear(a,k,n);break;
case 2:binary(a,k,n);break;
default:printf("invalid choice");
}
}
void linear(int a[],int k,int n)
{
int f=0;
for(int i=0;i<n;i++)
{
if(a[i]==k)
{
f=i+1;
}
}
if(f>0)
{
printf("element is present in the %dth position",f);
}
else
{
printf("element not found");
}

}
void sort(int a[],int n)
{
int temp;
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++)
if(a[i]>a[j+1])
{
temp=a[i];
a[i]=a[j+1];
a[j+1]=temp;
}
}
void binary(int a[],int k,int n)
{
int first,last,mid;
sort(a,n);
first=0;
last=n-1;
mid=(first+last)/2;
while(first<last)
{
if(a[mid]<k)
first=mid+1;
else if (a[mid]==k)
{
printf("element is found at %d",mid);
exit(0);
}
else
last=mid-1;
mid=(first+last)/2;
}

printf("element not found");
}

