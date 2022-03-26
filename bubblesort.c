#include<stdio.h>
void printarray(int *a,int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void bubblesort(int *a,int n)
{
	int temp,f=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				f=1;
			}
		}
		if(f==0)
		return ;
	}
}
int main()
{
	//int a[]={1,2,3,4,5,6,7};
	int a[]={23,3,54,40,0,29,1};
	int n=7;
	
	printarray(a,n);
	bubblesort(a,n);
	printf("\n");
	printarray(a,n);
}