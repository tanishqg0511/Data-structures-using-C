#include<stdio.h>
#define size 10
int que[size];
int r=0,f=0;
void enq_rear(int val)
{   
    if(f==size/2)
    {
    	printf("\nQueue is full!");
        return;
    }
	else
    {
        printf("\nEnter the value to be inserted:");
        scanf("%d",&val);
        que[f]=val;
        f++;
	}
}

void enq_front(int val)
{   
     if(f==size/2)
      {
            printf("\nQueue is full");
            return;
      }
      else{
        printf("\nEnter the value to be inserted:");
        scanf("%d",&val);
        r--;
        que[r] = val;
	}
}
int deq_rear()
{
     int deleted;
     if(f==r)
     {
    	printf("\nQueue is Empty!");
        return 0;
     }
     f--;
     deleted = que[f+1];
     return deleted;
}
int deq_front()
{
     int deleted;
     if(f==r)
     {
        printf("\nQueue is Empty!");
        return 0;
     }
     r++;
     deleted = que[r-1];
     return deleted;
}
void display()
{
     int i;
     if(f==r)
        printf("\nQueue is Empty!");
     else{
        printf("\nThe Queue elements are:");
        for(i=r;i<f;i++)
        {
           printf("%d  ",que[i]);
        }
     }
}
int main()
{
    int c1,c2,val;
    printf("______TANISHQGUPTA______\n");
    do
    {
        printf("1.Input-restricted deque \n");
        printf("2.output-restricted deque \n");
        printf("3.exit\n");
        printf("Enter your choice");
        scanf("%d",&c1);
        switch(c1)
        {
            case 1: 
                  printf("1.Insert\n2.Delete from Rear\n3.Delete from Front\n4. Display\n5.exit");
                  do
                  {
  	                printf("\nEnter your choice");
                    scanf("%d",&c2);
                    switch(c2)
                    {   
                        case 1: enq_rear(val);
                      		    break;
                    	  case 2: val=deq_rear();
                        		  printf("\nThe value deleted is %d",val);
                        		  break;
                         case 3: val=deq_front();
                       	          printf("\nThe value deleted is %d",val);
                       	          break;
                         case 4: display();
                                  break;
                          default:printf("Wrong choice");
                          			break;
                    }
                 }while(c2!=5);
                    break; 
               case 2 :
                   printf("1. Insert at Rear\n2. Insert at Front\n3. Delete\n4. Display\n5.exit\n");
                   do
                   {
                      printf("\nEnter your choice");
                      scanf("%d",&c2);
                      switch(c2)
                      {   
                         case 1: enq_rear(val);
                                 break;
                         case 2: enq_front(val);
                                 break;
                         case 3: val=deq_front();
                                 printf("\nThe value deleted is %d",val); 
                                 break;
                         case 4: display();
                                 break;
                         default:printf("Wrong choice");
                         			break;
                       }
                    } while(c2!=5);
                    break ;
            }
      }while(c1!=3);
}
