#include <stdio.h>  
#define size 5 
int deq[size];  
int f=-1,r=-1;  
void enq_front()  
{  
	printf("enter a number");
	int x;
	scanf("%d",&x);
    if((f==0 && r==size-1) || (f==r+1))  
        printf("deque is full\n");   
    else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deq[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deq[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deq[f]=x;  
    }  
}  
void enq_rear()  
{  
	printf("enter a number");
	int x;
	scanf("%d",&x);
    if((f==0 && r==size-1) || (f==r+1))  
        printf("dEque is full\n");  
    else if((f==-1) && (r==-1))  
    {  
        r=0;  
        deq[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deq[r]=x;  
    }  
    else  
    {  
        r++;  
        deq[r]=x;  
    }  
}  
void display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
    while(i!=r)  
    {  
        printf("%d ",deq[i]);  
        i=(i+1)%size;  
    }  
     printf("%d",deq[r]);  
}  
void deq_front()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("DEque is empty\n");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d\n",deq[f]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(f==(size-1))  
     {  
         printf("\nThe deleted element is %d\n",deq[f]);  
         f=0;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d\n",deq[f]);  
          f=f+1;  
     }  
}  
void deq_rear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("DEque is empty\n");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d\n",deq[r]);  
        f=-1;  
        r=-1;  
    }  
     else if(r==0)  
     {  
         printf("\nThe deleted element is %d\n",deq[r]);  
         r=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d\n",deq[r]);  
          r=r-1;  
     }  
}  
int main()  
{  
	printf("______TANISHQGUPTA______\n");
    int c;
    printf("1.enqueue from front\n2.enqueue from rear\n3.dequeue from front\n4.dequeue from rear\n5.display\n6.exit\n");
    do
    {
    	printf("enter your choice");
    	scanf("%d",&c);
    	switch(c)
    	{
    		case 1:enq_front();
    				break;
    		case 2:enq_rear();
    				break;
    		case 3: deq_front();
    				break;
    		case 4: deq_rear();
    				break;
    		case 5: display();
    				break;
    		default:printf("enter a valid choice\n");
    				break;
		}
	}while(c!=6);
}  