#include<stdio.h>
void swap(int* a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int* arr,int l,int h)
{
	int pivot=arr[h];
	int i=(l-1);
	for(int j=l;j<h;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return (i+1);
}
void quicksort(int * arr,int l,int h)
{
	if(l<h)
	{
		int p=partition(arr,l,h);
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,h);
	}
}
void printarr(int * arr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[]={4,3,5,9,7,3,2,0};
	int n=sizeof(arr)/sizeof(int);
	printf("unsorted array\n");
	printarr(arr,n);
	quicksort(arr,0,7);
	printf("sorted array\n");
	printarr(arr,n);
}