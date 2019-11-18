#include <stdio.h>
#include<stdlib.h>
int bin_rec(int a[],int first,int last,int z);
int sort(int a[],int n);
void main()
{
 int a[20],n,s,e;
 printf("Enter no of elements :");
 scanf("%d",&n);
 printf("Enter array elements :");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Enter element to be searched :");
 scanf("%d",&s);
 printf("Recursive Binary Search\n");
 sort(a,n);
 e=bin_rec(a,0,n,s);
 if(e==-1)
   printf("The given number isn't present.\n");
 else
   printf("The given element %d is present at position %d\n",s,e+1);

}

int bin_rec(int a[],int first,int last,int z)
{
  int middle;
  middle=(last+first)/2;
  if(first>last)
    return -1;
  if(a[middle]==z)
    return middle;
  else if(a[middle]<z)
    bin_rec(a,middle+1,last,z);
  else
    bin_rec(a,first,middle-1,z);
}

int sort(int a[],int n)
{
 int i,j,temp;
 for (i=0;i<n;++i) 
  {
   for (j=i+1;j<n;++j)
    {
     if (a[i]>a[j]) 
      {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
      }
    }
  }
printf("The numbers arranged are given below :\n");
for (i=0;i<n;++i)
printf("%d\n",a[i]);
}
