#include <stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
};
void createnode(int a,int b,struct node **temp)
{
    struct node *x,*y;
    x=*temp;
    if(x==NULL)
    {
        y=malloc(sizeof(struct node));
        y->coeff=a;
        y->power=b;
        *temp=y;
        y->next=malloc(sizeof(struct node));
        y=y->next;
        y->next=NULL;
    }
    else
    {
        y->coeff=a;
        y->power=b;
        y->next=malloc(sizeof(struct node));
        y=y->next;
        y->next=NULL;
    }
}
void polyadd(struct node *p1,struct node *p2,struct node *p)
{
    while(p1->next && p2->next)
    {
        if(p1->power > p2->power)
        {
            p->coeff=p1->coeff;
            p->power=p1->power;
            p1=p1->next;
        }
        else if(p2->power > p1->power)
        {
            p->coeff=p2->coeff;
            p->power=p2->power;
            p2=p2->next;
        }
        else
        {
            p->coeff=p1->coeff+p2->coeff;
            p->power=p1->power;
            p1=p1->next;
            p2=p2->next;
        }
        p->next=malloc(sizeof(struct node));
        p=p->next;
        p->next=NULL;
    }
    while(p1->next || p2->next)
    {
        if(p1->next)
        {
            p->coeff=p1->coeff;
            p->power=p1->power;
            p1=p1->next;
        }
        else if(p2->next)
        {
            p->coeff=p2->coeff;
            p->power=p2->power;
            p2=p2->next;
        }
        p->next=malloc(sizeof(struct node));
        p=p->next;
        p->next=NULL;
    }
}
void showpoly(struct node *p)
{
    while(p->next!=NULL)
    {
        printf("%dx^%d",p->coeff,p->power);
        p=p->next;
        if(p->coeff >= 0)
        {
            if(p->next!=NULL)
            printf("+");
        }
    }
    printf("\n");
}
int main()
{
    struct node *p1=NULL,*p2=NULL,*p=NULL;

    createnode(5,2,&p1);
    createnode(5,1,&p1);
    createnode(5,0,&p1);
    showpoly(p1);

    createnode(2,1,&p2);
    createnode(3,0,&p2);
    showpoly(p2);

    p=malloc(sizeof(struct node));
    polyadd(p1,p2,p);
    showpoly(p);
}