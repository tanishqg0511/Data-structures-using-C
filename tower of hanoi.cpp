#include<stdio.h>
void TOH(int n,char A,char B,char C)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c \n",A,B);
		return;
	}
	TOH(n-1,A,C,B);
	printf("move disk %d from %c to %c\n",n,A,B);
	TOH(n-1,C,B,A);
	return ;
}
int main()
{
	int n;
	char a='A',b='B',c='C';
	printf("enter number of disks :");
	scanf("%d",&n);
	TOH(n,a,c,b);
}