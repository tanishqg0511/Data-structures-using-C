#include<stdio.h>
#include<stdlib.h>
typedef struct newnode
{
	int data;
	struct newnode *left;
	struct newnode *right;
}node;
node* createnode(int i)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=i;
	temp->left=temp->right=NULL;
	return temp;
}
void preorder(node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int isBST(node* root)
{
	static node* prev=NULL;
	if(root!=NULL)
	{
		if(!isBST(root->left))
		return 0;
		if(prev!=NULL && root->data<= prev->data)
		return 0;
		prev=root;
		return isBST(root->right);
	}
	else
	return 1;
}
int main()
{
	node *root=(node*)malloc(sizeof(node));
	/*     9
	      / \
	     7   11
	    /\   / \
	   4  8 10   12     */
	root->data=9;
	root->left=createnode(7);
	root->right=createnode(11);
	root->left->left=createnode(4);
	root->left->right=createnode(8);
	root->right->left=createnode(10);
	root->right->right=createnode(12);
	  
	printf("PREORDER traversal : ");
	preorder(root);
	
	printf("\nPOSTORDER traversal : ");
	postorder(root);
	
	printf("\nINORDER traversal : ");
	inorder(root);
	if(isBST(root))
	printf("yes, it is a BST");	 
	else
	printf("no,its not a BST");
}