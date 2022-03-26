#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int *a,int l,int h)
{
	int pivot=a[h];
	int i=l-1;
	for(int j=l;j<h;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[h]);
	return (i+1);
}
void quicksort(int *a,int l,int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}
void print(int * a,int n)
{
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
int main()
{
	int a[]={4,3,5,9,7,3,2,0};
	int n=sizeof(a)/sizeof(int);
	printf("unsorted array\n");
	print(a,n);
	quicksort(a,0,n-1);
	printf("sorted array\n");
	print(a,n);
}