#include<stdio.h>
void printt(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void merge(int a[],int low,int mid,int high)
{
	int i,j,k,p;
	int b[high+1];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high){
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
		}
	}while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(p=low;p<=high;p++)
	{
		a[p]=b[p];
	}
}

void mergeSort(int a[],int low,int high,int n)
{
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(a,low,mid,n);
		mergeSort(a,mid+1,high,n);
		printf("\nAfter each partition: ");
		printt(a,n);
		merge(a,low,mid,high);
	}
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
	mergeSort(a,0,n-1,n);
	printf("\nAfter sorting: ");
	printt(a,n);
}
