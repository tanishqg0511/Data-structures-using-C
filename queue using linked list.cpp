#include<stdio.h>   
#include<stdlib.h> 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;
void display(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
void dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
        printf("value dequeued");
    }
}
int main ()  
{  
    int choice;   
    while(choice != 4)   
    {
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:printf("enter value");
                    int val;
                    scanf("%d",&val);
                    enqueue(val);  
                    break;  
            case 2:dequeue();  
                    break;  
            case 3:display(f);  
                    break;
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
  
