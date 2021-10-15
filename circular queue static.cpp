#include<stdio.h>
#define size 10
int arr[size];
int r=-1;
int f=-1;
void enqueue()
{
    int val;
    printf("Enter Value to be inserted: ");
    scanf("%d",&val);
    if ((f==0 && r==size-1) ||(r==(f-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
    else if (f==-1) 
    {
        f=r=0;
        arr[r]= val;
    }
    else if (r==size-1 && f!=0)
    {
        r=0;
        arr[r]=val;
    }
    else
    {
        r++;
        arr[r] = val;
    }
}
void dequeue()
{
    if (f==-1)
    {
        printf("\nQueue is Empty");
        return;
    }
    int data=arr[f];
    arr[f]=-1;
    if (f==r)
    {
        f=-1;
        r=-1;
    }
    else if (f==size-1)
        f=0;
    else
        f++;
  printf("Deleted element: %d",data);
}
void displayqueue()
{
    if (f==-1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (r>=f)
    {
        for (int i=f;i<=r;i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i=f;i<size;i++)
            printf("%d ",arr[i]);
 
        for (int i=0;i<=r;i++)
            printf("%d \n",arr[i]);
    }
}
int main()
{
    printf("______TANISHQGUPTA_____");
    int f=1;
    int choice=0;
    do
    {
        printf("Circular Queue\n1.enqueue 2.Dequeue 3.Display 4.Quit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: displayqueue();
            		break;
            case 4:
             printf("End\n");
            default:
            printf("Wrong choice \n");
        } 
        printf("Continue: Yes(1)/No(0)");
        scanf(" %d",&f);
    } while(f==1);
}