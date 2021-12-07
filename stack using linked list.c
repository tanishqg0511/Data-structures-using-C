#include <stdio.h>  
#include <stdlib.h>  
struct node   
{  
    int val;  
    struct node *next;  
};
struct node* push(struct node *head)  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val=val;  
            ptr->next=NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
        }
    }
    return head;
}  
  
struct node* pop(struct node *head)  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");
    }  
    return head;
}  
void display(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ",p->val);
		p=p->next;
	}
}
int main ()  
{  
    struct node *head=NULL; 
    int choice=0;     
    printf("\nStack operations using linked list");  
    while(choice != 4)  
    {  
        printf("\nenter your choice");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:
                head=push(head);  
                break;
            case 2:
                head=pop(head);  
                break;
            case 3:
                display(head);  
                break;
            case 4:
                printf("Exiting....");  
                break;
            default:printf("Please Enter valid choice "); 
        };  
    }  
}  
 
