#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node* insertatend(struct Node *head,int x)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=x;
	if(head==NULL)
	{
	    head=ptr;
	    head->next=NULL;
	    return head;
	 }
	struct Node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	return head;
}
void deleteAlt(struct Node *head)
{
	if (head == NULL)
		return;
	struct Node *prev=head;
	struct Node *node=head->next;
	while (prev != NULL && node != NULL)
	{
		prev->next=node->next;
		free(node);
		prev=prev->next;
		if (prev!=NULL)
			node =prev->next;
	}
}
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
int main()
{
	struct Node* head = NULL;
	head=insertatend(head, 5);
	head=insertatend(head, 4);
	head=insertatend(head, 3);
	head=insertatend(head, 2);
	head=insertatend(head, 1);

	printf("\nList before calling deleteAlt() \n");
	printList(head);

	deleteAlt(head);

	printf("\nList after calling deleteAlt() \n");
	printList(head);
}
