#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left, *right;
};
struct node *root=NULL;
void insert(struct node *ptr)
{
	int x,i,j;
	printf("enter element: ");
	scanf("%d",&x);
	struct node *ptr2=(struct node*)malloc(sizeof(struct node));
	ptr2->data=x;
	ptr2->left=NULL;
	ptr2->right=NULL;
	if(root==NULL){
		root=ptr2;
		return;}
		while(1){
		printf("left of %d (0) or right of %d (1): ",ptr->data,ptr->data);
		scanf("%d",&j);
		switch(j)
		{
			case 0: if(ptr->left==NULL)
					{
						ptr->left=ptr2;
						return;
					}
					ptr=ptr->left;
					break;
			case 1: if(ptr->right==NULL)
					{
						ptr->right=ptr2;
						return;
					}
					ptr=ptr->right;
					break;
		}
	}
}
void inorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	inorder(ptr->left);
	printf("| %d ",ptr->data);
	inorder(ptr->right);
}
int main()
{
	int c;

	while(1)
	{
		printf("1.insert\n2.display\n3.exit");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	insert(root);
					break;
			case 2:	inorder(root);
					printf("|\n");
					break;
			case 3: goto end;
		}
	}
	end:;
}
