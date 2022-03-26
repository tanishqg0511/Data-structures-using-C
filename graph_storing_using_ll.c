#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct graph
{
    int numv;
    struct node **adjlist;
};
struct node* createnode(int v)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=v;
    newnode->next=NULL;
    return newnode;
}
struct graph* creategraph(int vert)
{
    struct graph* graph=malloc(sizeof(struct graph));
    graph->numv=vert;
    graph->adjlist=malloc(vert*sizeof(struct node));
    for(int i=0;i<vert;i++)
    {
        graph->adjlist[i]=NULL;
    }
    return graph;
}
void addedge(struct graph *graph,int s,int d)
{
    struct node* new=createnode(d);
    //adding edge from s to d
    new->next=graph->adjlist[s];
    graph->adjlist[s]=new;

    //adding edge from d to s
    new=createnode(s);
    new->next=graph->adjlist[d];
    graph->adjlist[d]=new;
}
void printgraph(struct graph *graph)
{
    for(int i=0;i<graph->numv;i++)
    {
        struct node *temp=graph->adjlist[i];
        printf("vertex %d:\n",i+1);
        while (temp)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    struct graph *graph=creategraph(5);
    addedge(graph,0,1);
    addedge(graph,0,2);
    addedge(graph,0,3);
    addedge(graph,1,2);
    addedge(graph,3,4);

    printgraph(graph);
}