#include<stdio.h>
#include<stdlib.h>
typedef struct newnode
{
	int data;
	newnode *left;
	newnode *right;
}node;
newnode* insert(int i)
{
	newnode* temp=(node*)malloc(sizeof(node));
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
int main()
{
	node *root=(node*)malloc(sizeof(node));
	/*     9
	      / \
	     7   10
	    /\   / \
	   4  N N   12     */
	root->data=9;
	root->left=insert(7);
	root->right=insert(10);
	root->left->left=insert(4);
	root->left->right=NULL;
	root->right->left=NULL;
	root->right->right=insert(12);
	  
	printf("PREORDER traversal : ");
	preorder(root);
	
	printf("\nPOSTORDER traversal : ");
	postorder(root);
	
	printf("\nINORDER traversal : ");
	inorder(root); 
}