#include<stdio.h>
void insertionSort(int a[],int n)
{
	int j,i,key;
	for(i=1;i<=n-1;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void printArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void main(){
	int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Before sorting: ");
	printArray(a,n);
	insertionSort(a,n);
	printf("\nAfter sorting: ");
	printArray(a,n);
}
