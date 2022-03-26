#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int getheight(struct node *n)
{
    if(n==NULL)
    return 0;
    return n->height;
}
struct node *createnode(int key)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;

    return temp;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int getbalancefactor(struct node* n)
{
    if(n==NULL)
    return 0;
    return getheight(n->left)-getheight(n->right);
}
struct node* rightrotation(struct node *y)
{
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    return x;
}
struct node* leftrotation(struct node *x)
{
    struct node *y=x->right;
    struct node *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    return y;
}
struct node* insert(struct node *root,int key)
{
    if(root==NULL)
    return createnode(key);
    if(key<root->data)
    root->left=insert(root->left,key);
    else if(key>root->data)
    root->right=insert(root->right,key);

    root->height=1+max(getheight(root->left),getheight(root->right));
    int bf=getbalancefactor(root);
    //left left
    if(bf>1 && key<root->left->data)
    return rightrotation(root);

    //right right 
    if(bf<-1 && key>root->right->data)
    return leftrotation(root);

    //left right 
    if(bf>1 && key>root->left->data)
    {
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
    
    //right left
    if(bf<-1 && key<root->right->data)
    {
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    preorder(root);
}