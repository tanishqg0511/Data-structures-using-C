#include<stdio.h>
int binary(char* a)
{
   char a1[20];
   int j=0;
   for(int i=0;a[i]!='\0';i++)
   { 
       if(a[i]=='0')
       {
          a1[j]=a[i];
          j++;
        }
  }
  for(int i=0;a[i]!='\0';i++)
   { 
       if(a[i]=='1')
       {
          a1[j]=a[i];
		  j++;
    	}
  }
  printf("%s",a1);
}
int main()
{
  char a[20];
  printf("enter binary number");
  scanf("%s",a);
  binary(a);
return 0;
}