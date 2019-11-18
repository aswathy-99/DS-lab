#include<stdio.h>
void sort (int[],int);
void main()
{ 
 int a[15],n;
 printf("Enter the limit:");
 scanf("%d",&n);
 printf("Enter elements in the array:");
 for (int i=0;i<n;i++)
 scanf("%d",&a[i]);
 sort(a,n);
 printf("Sorted array\n");
 for(int i=0;i<n;i++)
 printf("%d\t",a[i]);
 }
void sort(int a[],int n)
{
 int i,j,t,min;
for(i=0;i<n;i++)
{
min=i;
for(j=i+1;j<n;j++)
if(a[min]>a[j])
min=j;
if(a[i]>a[min])
{
t=a[i];
a[i]=a[min];
a[min]=t;
}
}
}



 
