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
node* searchinBST(node* root,int key)
{
	if(root==NULL)
	return NULL;
	if(root->data==key)
    return root;
	else if(key<root->data)
	return searchinBST(root->left,key);
	else
	return searchinBST(root->right,key);
}
void insert(node* root,int key)
{
	node* prev=NULL;
	while(root!=NULL)
	{
		prev=root;
		if(root->data==key)
		return;
		else if(key<root->data)
		root=root->left;
		else
		root=root->right;
	}
	node* p=createnode(key);
	if(key<prev->data)
	prev->left=p;
	else
	prev->right=p;
}
node* inorderpredecessor(node* root)
{
	root=root->left;
	while(root->right!=NULL)
	root=root->right;
	return root;
}
node* deletenode(node *root,int key)
{
	node *ipre;
	if(root==NULL)
	return NULL;
	if(root->left==NULL && root->right==NULL)
	{
		free(root);
		return NULL;
	}
	if(key<root->data)
	root->left=deletenode(root->left,key);
	else if(key>root->data)
	root->right=deletenode(root->right,key);
	else
	{
		ipre=inorderpredecessor(root);
		root->data=ipre->data;
		root->left=deletenode(root->left,ipre->data);
	}
	return root;
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
	insert(root,13);
	insert(root,1);
	insert(root,5);
	  
	printf("PREORDER traversal : ");
	preorder(root);
	printf("\n");
	printf("\nPOSTORDER traversal : ");
	postorder(root);
	printf("\n");
	printf("\nINORDER traversal : ");
	inorder(root);
	printf("\n");
	
	if(isBST(root))
	printf("yes, it is a BST\n");	 
	else
	printf("no,its not a BST\n");
	
	node* ptr=searchinBST(root,10);
	if(ptr!=NULL)
	printf("key found: %d",ptr->data);
	else
	printf("key not found");
	
	deletenode(root,7);
	printf("\nINORDER traversal : ");
	inorder(root);
}