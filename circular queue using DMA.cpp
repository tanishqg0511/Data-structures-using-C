#include<stdio.h>
#include<stdlib.h>
struct cirqueue
{
	int size;
	int f;
	int r;
	int *a;
};
int isfull(struct cirqueue *q)
{
	if((q->r+1)%q->size==q->f)
	return 1;
	else
	return 0;
}
int isempty(struct cirqueue *q)
{
	if(q->f==q->r)
	return 1;
	else
	return 0;
}
void enqueue(struct cirqueue *q)
{
	if(isfull(q))
	printf("the queue is full\n");
	else
	{
		int val;
		printf("enter a value to be pushed");
		scanf("%d",&val);
		q->r=(q->r+1)%q->size;
		q->a[q->r]=val;
	}
}
void dequeue(struct cirqueue *q)
{
	if(isempty(q))
	printf("the queue is empty\n");
	else
	{
		q->f=(q->f+1)%q->size;
		int val=q->a[q->f];
		printf("%d was dequeued from the queue\n",val);
	}
}
int main()
{
	printf("_______TANISHQGUPTA_______\n");
	struct cirqueue *q=(struct cirqueue*)malloc(sizeof(struct cirqueue));
	q->size=5;
	q->f=0;
	q->r=0;
	q->a=(int*)malloc(q->size*sizeof(int));
	int c;
	printf("1.enqueue\n2.dequeue\n3.exit\n");
	do
	{
		printf("enter your choice");
		scanf("%d",&c);
		switch(c)
		{
			case 1: enqueue(q);
					break;
			case 2: dequeue(q);
					break;
			default:printf("enter valid choice\n");
					break;
		}
	}while(c!=3);
	free(q->a);
	free(q);
}