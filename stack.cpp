#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int top;
	int *a;
};
 struct stack* newStack(int capacity)
{
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
 
    ptr->size = capacity;
    ptr->top = -1;
    ptr->a = (int*)malloc(sizeof(int) * capacity);
 
    return ptr;
}
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
void push(struct stack *ptr,int x)
{
	if(isFull(ptr))
		printf("STACK OVERFLOW!!");
	else
		ptr->a[++ptr->top]=x;
}
int pop(struct stack *ptr)
{
	if(isEmpty(ptr))
	{
		printf("STACK UNDERFLOW!!");
		return -1;
	}
	else
	{
		int val=ptr->a[ptr->top];
		ptr->top--;
		return val;
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
void display(struct stack *ptr)
{
	/*while(!isEmpty(ptr))
    {
        int data=pop(ptr);
        printf("%d\n",data);
    }*/
    if(isEmpty(ptr))
	printf("The stack is empty.");
	else{
    for(int i=ptr->top;i>=0;i--)
    printf("%d\n",ptr->a[i]);
}}
int main()
{
	printf("TANISHQGUPTA__\n");
    int c,x,r;
    struct stack *ptr = newStack(20);
	printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n0.EXIT\n");
	do
	{
		printf("enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter number to be pushed");
	                scanf("%d",&x);
	                push(ptr,x);
				   break;
			case 2:
	               r=pop(ptr);
	               printf("%d was poped from the stack",r);
			       break;
			case 3:peek(ptr);
				   break;
			case 4:display(ptr);
				   break;
			default:printf("THANK YOU");
			        break;
	    }
	}while(c!=0);
	free(ptr->a);
	free(ptr);
}