#include<stdio.h>
void insertion(int arr[30],int num)
{
int i;
    for(i=1;i<num;i++)
	{
		
		int hole=i;
		int element=arr[i];
		while(hole>0 & arr[hole-1]>element)
		{
		 arr[hole]=arr[hole-1];
		 hole=hole-1;
		}
		arr[hole]=element;
}


}
int main()
{
int num,i,j,arr[30],no;
printf("enter the number of elements in the array\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
	printf("enter the element\n\n");
	scanf("%d",&no);
	arr[i]=no;
}
printf("\n\n");
insertion(arr,num);
for(j=0;j<num;j++)
{
	printf("%d\n",arr[j]);
}
return 0;
}
