#include<stdio.h>
#define MAX 50
int arr[MAX];
int r=-1;
int f=-1;
void insert()
{
    int add;
    if (r==MAX-1)
    printf("Queue Overflow \n");
    else
    {
        if (f==-1)
            f=0;
        printf("Insert the element in queue : ");
        scanf("%d",&add);
        r=r+1;
        arr[r]=add;
    }
} 
void del()
{
    if (f==-1 || f>r)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", arr[f]);
        f++;
    }
} 
void display()
{
    int i;
    if (f==-1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i=f;i<=r;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
} 

int main()
{
	printf("_______TANISHQGUPTA______");
    int f=1;
    int choice=0;
    do
    {
        printf("1.enqueue 2.dequeue 3.Display 4.Quit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            	insert();
            	break;
            case 2:
            	del();
            	break;
            case 3:
            	display();
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