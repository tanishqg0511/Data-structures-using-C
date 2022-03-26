#include<stdio.h>
void selectionsort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[index])
			index=j;
		}
		int temp=a[i];
		a[i]=a[index];
		a[index]=temp;
	}
}
void printarray(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int a[]={20,15,45,3,9,0};
	int n=6;
	printarray(a,n);
	selectionsort(a,n);
	printarray(a,n);
}