#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;
void createnode(int x ,struct node *ptr)
{
	struct node *ptr2=(struct node *)malloc(sizeof(struct node));
	ptr2->data=x;
	ptr2->left=NULL;
	ptr2->right=NULL;
	if(root==NULL)
	{
		root=ptr2;
		return;
	}
	while(1)
	{	
		if(ptr->data>=x)
		{
			if(ptr->left!=NULL)
				ptr=ptr->left;
			else
			{
				ptr->left=ptr2;
				return;
			}
		}
		else{
			if(ptr->right!=NULL)
				ptr=ptr->right;
			else
			{
				ptr->right=ptr2;
				return;
			}
		}
	}
}
void display(struct node *ptr)
{
	if(ptr==NULL)
		return;
	display(ptr->left);
	printf("| %d ",ptr->data);
	display(ptr->right);
}
void search(struct node *ptr,int x)
{
	while(1)
	{
		if(ptr==NULL)
		{
			printf("not found\n\n");
			return;
		}
		if(x<ptr->data)
		{
			ptr=ptr->left;
			continue;
		}
		if(x>ptr->data)
		{
			ptr=ptr->right;
			continue;
		}
		if(x==ptr->data)
		{
			printf("found\n\n");
			return;
		}
	}
}
int main()
{
	int x,c;
	while(1){
	printf("1.insert\n3.search\n4.display\n0.exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:	printf("enter element to be inserted: ");
				scanf("%d",&x);
				createnode(x,root);
				break;
		case 3: printf("enter element to be searched: ");
				scanf("%d",&x);
				search(root,x);
				break;
		case 4: display(root);
				printf("|\n\n");
				
				break;
		case 0: goto end;
	}
	}
	end:;
}
