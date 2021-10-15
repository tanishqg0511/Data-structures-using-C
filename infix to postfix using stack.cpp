#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	if(top == -1)
	return -1;
	else
	return stack[top--];
}
int precedence(char c)
{
	if(c == '(')
	return 0;
	if(c == '+' || c == '-')
	return 1;
	if(c == '*' || c == '/')
	return 2;
	return 0;
}
int main()
{
	printf("______TANISHQGUPTA______");
	char exp[100];
	printf("enter expression :");
	scanf("%s",exp);
	char *e,x;
	e=exp;
	while(*e != '\0')
	{
		if(isalnum(*e))
		printf("%c",*e);
		else if(*e == '(')
		{
			push(*e);
		}
		else if(*e == ')')
		{
			while((x=pop()) != 	'(')
			printf("%c",x);
		}
		else
		{
			while(precedence(stack[top]) >= precedence(*e))
			printf("%c",pop());
			push(*e);
		}
		e++;
	}
	while(top != -1)
	printf("%c",pop());
}