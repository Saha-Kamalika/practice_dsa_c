#include<stdio.h>
#include<stdlib.h>
int maximum(int a[],int n) //finding the maximum element in a
{
	int max=a[0],i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
void countSort(int a[],int n)
{
	int max=maximum(a,n);
	int* count=(int *)malloc((max+1)*sizeof(int)); //create a count array of size (max+1)
	int i,j;
	for(i=0;i<max+1;i++)
	{
		count[i]=0;  //initializing 0 to all indexes of count
	}
	for(i=0;i<n;i++)
	{
		count[a[i]]=count[a[i]]+1; //incrementing the value for each elememt in a
	}
	i=0;
	j=0;
	while(i<=max){
		if(count[i]>0){
			a[j]=i;
			count[i]=count[i]-1;
			j++;
		}
		else i++;
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
	countSort(a,n);
	printf("\nAfter sorting: ");
	printt(a,n);
}
//time complexity: O(m+n) = O(n)...not recommended as countsort occupies larger space
