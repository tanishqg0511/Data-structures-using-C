#include<stdio.h>
void printarray(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insertionsort(int *a,int n)
{
    int key,j;
    for (int i = 1; i <= n-1; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j] > key)
        {
            a[j+1]=a[j];
            j--;            
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[]={39.25,1,89,36,20};
    int n=6;
    printarray(a,n);
    insertionsort(a,n);
    printf("\n");
    printarray(a,n);
}