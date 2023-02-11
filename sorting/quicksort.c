#include<stdio.h>
void quickSort(int a[],int low,int high,int n)
{
	int partitionIndex;
	if(low<high){
		partitionIndex=partition(a,low,high);
		printf("\nAfter each partition: ");
		printt(a,n);
		quickSort(a,low,partitionIndex-1,n);
		quickSort(a,partitionIndex+1,high,n);
	}
}
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	int temp;
	do{
	while(a[i]<=pivot)
		i++;
	while(a[j]>pivot)
		j--;
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	}while(i<j);
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
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
	printf("\nBefore sorting: ");
	printt(a,n);
	quickSort(a,0,n,n);
	printf("\nAfter sorting: ");
	printt(a,n);
}
