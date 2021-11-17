#define size 5    
#include <stdio.h>  
int deque[size];  
int f=-1, r=-1;  
//  enqueue_front function will insert the value from the front  
void enq_front(int x)  
{  
    if((f==0 && r==size-1) || (f==r+1))  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deque[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deque[f]=x;  
    }  
}  
  
// enqueue_rear function will insert the value from the rear  
void enq_rear(int x)  
{  
    if((f==0 && r==size-1) || (f==r+1))  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else  
    {  
        r++;  
        deque[r]=x;  
    }  
}  
  
// display function prints all the value of deque.  
void display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
      
    while(i!=r)  
    {  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
     printf("%d",deque[r]);  
}  
// dequeue_front() function deletes the element from the front  
void deq_front()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(f==(size-1))  
     {  
         printf("\nThe deleted element is %d", deque[f]);  
         f=0;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[f]);  
          f=f+1;  
     }  
}  
  
// dequeue_rear() function deletes the element from the rear  
void deq_rear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(r==0)  
     {  
         printf("\nThe deleted element is %d", deque[r]);  
         r=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[r]);  
          r=r-1;  
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
                    	  case 2: deq_rear();
                        		  break;
                         case 3: deq_front();
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
                         case 3: deq_front();
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
