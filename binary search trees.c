#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
}*root=0;	

struct node *newnode(int num) 
{
	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
  	temp->data=num;
  	temp->left=temp->right=0;
  	return temp;
}

struct node *insert(struct node *root, int num)
{
  	if (root == 0) 
  		return newnode(num);

  	if (num < root->data)
    	root->left = insert(root->left, num);
  	else
    	root->right = insert(root->right, num);

  	return root;
}

void preorder(struct node *root)
{
	if (root==0)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if (root==0)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(struct node *root)
{
	if (root==0)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

void mirror(struct node *root)
{
	struct node *temp;
	
	if ((root->left==0 && root->right==0) || root==0)
		return;
	else
	{
	mirror(root->left);
	mirror(root->right);	
	
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	}
}

void main()
{
	int num,choice,trvch;
	printf("Binary Search Tree");
	while (choice!=0)
	{
		printf("\n**************************");
		printf("\nWhat do you want to do?\n");
		printf("1. Insert a node\n");
		printf("2. Traverse\n");
		printf("3. Mirror\n");
		printf("0. Quit\n");
		
		printf("Your choice: ");
		scanf("%d", &choice);
	
		switch (choice){
			case 1:
				printf("Enter Element you want to insert: ");
				scanf("%d", &num);
				root=insert(root, num);
				break;
				
			case 2:
				printf("1. Inorder\n");
				printf("2. Preorder\n");
				printf("3. Postorder\n");
				printf("Your Choice: ");
				scanf("%d", &trvch);
				if (trvch==1){
					printf("\nInorder is: ");
					inorder(root);}
				else if (trvch==2){
					printf("\nPreorder is: ");
					preorder(root);}
				else if (trvch==3){
					printf("\nPostorder is: ");
					postorder(root);}
				else{
					printf("Invalid choice\n");}
				break;	
			
			case 3:
				mirror(root);
				printf("Tree is mirrored\n");
				
			case 0:
				break;
			
			default:
				printf("\nInvalid choice\n");	
				break;
		}
	}
}
	
