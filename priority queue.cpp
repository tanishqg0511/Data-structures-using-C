#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert_by_priority();
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
 
int pri_que[MAX];
int front, rear;
 
int main()
{
	printf("TANISHQGUPTA");
    int n, ch;
    printf("\n1)Insert an element into queue");
    printf("\n2)Delete an element from queue");
    printf("\n3)Display queue elements");
    printf("\n4)Exit");
    create();
    while (1)
    {
        printf("\nEnter your choice:");    
        scanf("%d", &ch);
        switch(ch)
        {
	        case 1: 
	            printf("\nEnter value to be inserted : ");
	            insert_by_priority();
	            break;
	        case 2:
	            printf("\nEnter value to delete : ");
	            scanf("%d",&n);
	            delete_by_priority(n);
	            break;
	        case 3: 
	            display_pqueue();
	            break;
	        case 4: 
	            exit(0);
	        default: 
	            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
void create()
{
    front=rear=-1;
}
void insert_by_priority()
{
    int add_item;  
    if (rear==MAX-1)  
    printf("Queue Overflow \n");  
    else  
    {  
        if (front == -1)  
        front=0;  
        printf("Insert the element in queue : ");  
        scanf("%d",&add_item);    
        pri_que[++rear]=add_item;  
    }  
}
void check(int data)
{
    int i,j;
    for(i=0;i<=rear;i++)
    {
        if(data>=pri_que[i])
        {
            for(j=rear+1;j>i;j--)
            {
                pri_que[j] = pri_que[j-1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
void delete_by_priority(int data)
{
    int i;
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for(i=0;i<=rear;i++)
    {
        if(data==pri_que[i])
        {
            for(;i<rear;i++)
            {
                pri_que[i]=pri_que[i+1];
            }
        pri_que[i] = -99;
        rear--;
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
void display_pqueue()
{
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front<=rear;front++)
        printf(" %d ", pri_que[front]); 
    front = 0;
}