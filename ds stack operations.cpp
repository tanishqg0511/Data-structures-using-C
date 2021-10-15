#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int top;
	int *a;
};
int isFull(struct stack *ptr)
{
	if(ptr->top == ptr->size-1)
	return 1;
	else
	return 0;
}
int isEmpty(struct stack *ptr)
{
	if(ptr->top==-1)
	return 1;
	else
	return 0;
}
void push(struct stack *ptr)
{
	if(isFull(ptr))
		printf("STACK OVERFLOW!!");
	else
	{
		printf("enter value to be pushed:");
		scanf("%d",ptr->a[ptr->top++]);
	}
}
void pop(struct stack *ptr)
{
	if(isEmpty(ptr))
	printf("STACK UNDERFLOW!!");
	else
	{
		int val=ptr->a[ptr->top];
		ptr->top--;
		printf("%d was poped from stack",val);
	}
}
void peek(struct stack *ptr)
{
	int i;
	printf("enter position of element");
	scanf("%d",&i);
	int arrind=ptr->top-i+1;
	if(arrind<0)
	printf("not a valid postion of stack");
	else
	printf("The data on %d position is %d",i,ptr->a[arrind]);
}

int main()
{
	printf("______TANISHQGUPTA______\n");
	struct stack *s=(struct stack *)malloc(sizeof(struct stack));
	s->size=20;
	s->top=-1;
	s->a=(int*)malloc(s->size*sizeof(int));
	int c;
	printf("1.PUSH\n2.POP\n3.PEEK\n0.EXIT\n");
	do{
	printf("enter your choice\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:push(s);
			   break;
		case 2:pop(s);
		       break;
		case 3:peek(s);
			   break;
		default:printf("enter a valid choice");	
				break;
	}}while(c!=0);
	printf("THANK YOU");
	free(s->a);
	free(s);
}