#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert_by_priority(int*,int*,int*);
void delete_by_priority(int,int *,int*,int*);
void create(int *,int*);
void check(int,int *,int *);
void display_pqueue(int*,int*,int*);
 

 
int main()
{
	printf("TANISHQGUPTA");
    int pri_que[MAX];
	int f,r;
	int n, ch;
    printf("\n1)Insert an element into queue");
    printf("\n2)Delete an element from queue");
    printf("\n3)Display queue elements");
    printf("\n4)Exit");
    create(&f,&r);
    while (1)
    {
        printf("\nEnter your choice:");    
        scanf("%d", &ch);
        switch(ch)
        {
	        case 1: 
	            printf("\nEnter value to be inserted : ");
	            insert_by_priority(pri_que,&f,&r);
	            break;
	        case 2:
	            printf("\nEnter value to delete : ");
	            scanf("%d",&n);
	            delete_by_priority(n,pri_que,&f,&r);
	            break;
	        case 3: 
	            display_pqueue(pri_que,&f,&r);
	            break;
	        case 4: 
	            exit(0);
	        default: 
	            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
void create(int *f,int *r)
{
    *f=*r=-1;
}
void insert_by_priority(int *pri_que,int *f,int *r)
{
    int add_item;  
    if (*r==MAX-1)  
    printf("Queue Overflow \n");  
    else  
    {  
        if (*f == -1)  
        *f=0;  
        printf("Insert the element in queue : ");  
        scanf("%d",&add_item);    
        pri_que[++*r]=add_item;  
    }  
}
void check(int data,int *pri_que,int *r)
{
    int i,j;
    for(i=0;i<=*r;i++)
    {
        if(data>=pri_que[i])
        {
            for(j=*r+1;j>i;j--)
            {
                pri_que[j] = pri_que[j-1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
void delete_by_priority(int data,int *pri_que,int *f,int *r)
{
    int i;
    if((*f==-1) && (*r==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for(i=0;i<=*r;i++)
    {
        if(data==pri_que[i])
        {
            for(;i<*r;i++)
            {
                pri_que[i]=pri_que[i+1];
            }
        pri_que[i] = -99;
        *r--;
        if (*r == -1) 
            *f = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
void display_pqueue(int *pri_que,int *f,int *r)
{
    if((*f==-1) && (*r==-1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; *f<=*r;*f++)
        printf(" %d ", pri_que[*f]); 
    f = 0;
}