#include<stdio.h>
#include<string.h>
#include <ctype.h>
char stack[50];
int top=-1;
void push(char elem)
{
    stack[++top]=elem;
}
char pop()
{
	if(top==-1)
	return 0;
	else
    return(stack[top--]);
}
char* reverse(char *arr)
{
	char temp[50];
	int j=0;
	for(int i=strlen(arr)-1;i>=0;i--)
	{
		temp[j++]=arr[i];
	}
	strcpy(arr,temp);
	return arr;
}
int prcd(char c)
{
   if(c=='+' || c=='-')
   return 1;
   else if(c=='*' || c=='/')
   return 2;
   else 
   return 0;
}
int main()
{
	printf("TANISHQGUPTA");
    char infix[50],prfix[50],c,x;
    int i=0,k=0;
    printf("\nEnter the infix expression");
    scanf("%s",infix);
    push('#');
    reverse(infix);
    while((c=infix[i++]) != '\0')
    {
        if(c == ')') 
		push(c);
        else
        {
            if(isalnum(c)) 
			prfix[k++]=c;
            else
                if(c == '(')
                {
                    while(stack[top] != ')')
                        prfix[k++]=pop();
                    x=pop();
                }
                else
                { 
                    while(prcd(stack[top]) >= prcd(c))
                        prfix[k++]=pop();
                    push(c);
                }
    	}
    }
    while(stack[top] != '#')
        prfix[k++]=pop();
    prfix[k]='\0';
    reverse(prfix);
    printf("the prefix expression is: %s\n",prfix);
}