#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void linkedlisttraversal(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
struct node* insertatfront(struct node *head,int x)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=head;
	return ptr;
}
struct node* insertatend(struct node *head,int x)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	struct node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	return head;
}
struct node* insertatindex(struct node *head,int x,int index)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	int i=0;
	struct node *p=head;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	ptr->next=p->next;
	p->next=ptr;
	return head;
}
struct node* deleteatfront(struct node *head)
{
	struct node *p=head;
	head =head->next;
	free(p);
	return head;
}
struct node* deleteatend(struct node *head)
{
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return head;
}
struct node* deleteatindex(struct node *head,int index)
{
	struct node *p=head;
	struct node *q=head->next;
	for(int i=0;i<index-1;i++)
	{
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
 } 
int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	struct node *two=(struct node*)malloc(sizeof(struct node));
	struct node *three=(struct node*)malloc(sizeof(struct node));
	struct node *four=(struct node*)malloc(sizeof(struct node));
	
	head->data=4;
	head->next=two;
	
	two->data=3;
	two->next=three;
	
	three->data=8;
	three->next=four;
	
	four->data=2;
	four->next=NULL;
	
	printf("Printing Linked List after creation!!! \n");
	linkedlisttraversal(head);
	
	int c,c1,c2;
	do
	{
		printf("\n\n1.INSERTION\n2.DELETION\n3.EXIT\n");
		printf("Enter your choice ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: do
					{
						printf("INSERTION AT\n1.Front\n2.end\n3.index\n4.exit\n");
						printf("Enter your choice ");
						scanf("%d",&c1);
						if(c1==4)
						break;
						int x;
						printf("enter data to be inserted");
						scanf("%d",&x);
						switch(c1)
						{
							case 1:head=insertatfront(head,x);
								    break;
							case 2:head=insertatend(head,x);
									break;
							case 3:printf("enter index");
								   int index;
								   scanf("%d",&index);
								   head=insertatindex(head,x,index);
								   break;
							case 4: break;
							default:printf("enter a valid choice");
									break;
						}
					}while(c1!=4);
					break;
			case 2: do
					{
						printf("\nDELETION AT\n1.front\n2.end\n3.at a index\n4.exit");
						printf("\nenter your choice");
						scanf("%d",&c2);
						switch(c2)
						{
							case 1: head=deleteatfront(head);
									break;
							case 2: head=deleteatend(head);
									break;
							case 3: printf("enter index");
									int index;
									scanf("%d",&index);
									head=deleteatindex(head,index);
									break;
							case 4: break;
							default:printf("enter valid choice");
									break;
						}					
					}while(c2!=4);
					break;
			case 3: break;
			default: printf("enter valid choice");
					 break;
		}
	}while(c!=3);
	printf("Linked List after operations\n");
	linkedlisttraversal(head);
	free(head);
	free(two);
	free(three);
	free(four);
}