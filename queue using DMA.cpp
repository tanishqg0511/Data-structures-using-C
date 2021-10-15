#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int size;
	int f;
	int r;
	int *a;
};
int isfull(struct queue *q)
{
	if(q->r==q->size-1)
	return 1;
	else
	return 0;
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
	return 1;
	else 
	return 0;
}
void enqueue(struct queue *q)
{
	if(isfull(q))
	printf("The queue is full\n");
	else
	{
		printf("enter a value to be pushed");
		q->r++;
		scanf("%d",&q->a[q->r]);
	}
}
void dequeue(struct queue *q)
{
	if(isempty(q))
	printf("the queue is empty");
	else
	{
		q->f++;
		int val=q->a[q->f];
		printf("%d was dequeued from queue\n",val);
	}
}
int main()
{
	printf("______TANISHQGUPTA______\n");
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->size=10;
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