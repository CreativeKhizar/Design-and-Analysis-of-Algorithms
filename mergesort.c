#include<stdio.h>

void merge(int arr[],int l,int r)
{
	int mid=(l+r)/2;
	
	int len1=mid-l+1;
	
	int len2=r-mid;
	
	int arr1[len1],arr2[len2];
	
	int i,j,k;
	k=l;
	for(i=0;i<len1;i++)
	{
		arr1[i]=arr[k++];
	}
	
	k=mid+1;
	
	for(i=0;i<len2;i++)
	{
		arr2[i]=arr[k++];
	}
	
	i=0,j=0;
	
	k=l;
	
	while(i<len1 && j<len2)
	{
		if(arr1[i]<arr2[j])
		{
			arr[k++]=arr1[i++];
		}
		else
		{
			arr[k++]=arr2[j++];
		}
	}
	while(i<len1)
	{
		arr[k++]=arr1[i++];
	}
	while(j<len2)
	{
		arr[k++]=arr2[j++];
	}
}
void mergesort(int arr[],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	
	int mid=(l+r)/2;
	
	mergesort(arr,l,mid);
	
	mergesort(arr,mid+1,r);
	
	merge(arr,l,r);
}
int main()
{
	int arr[20];
	
	int i,n;
	
	printf("Enter the total  number of elements\n");
	scanf("%d",&n);

	printf("Enter the elements \n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Elements Before Merge Sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	mergesort(arr,0,n-1);
	printf("\nElements After Merge Sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}
