#include<stdio.h>
void selectionSort(int a[],int n)
{
	int index,temp,i,j;
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[index])
				index=j;
		}
		temp=a[i];
		a[i]=a[index];
		a[index]=temp;
		printf("\nAfter %dth pass: ",i);
		printt(a,n);
	}
}
void printt(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main(){
	int n,i;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Before sorting: ");
	printt(a,n);
	selectionSort(a,n);
	printf("\nAfter sorting: ");
	printt(a,n);
}
