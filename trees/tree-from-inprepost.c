#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search (char in[],int f,int r,char x);
int i,k;
struct node
{
  	char data;
  	struct node *left,*right;
};

struct node *tree(char in[],char pre[],int f,int r)
{
	if(f>r)
		return NULL;
  	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=pre[i++];
  	temp->right=NULL;
  	temp->left=NULL;
	
	if(f==r)
   		return temp;
  	
  	int j=search(in,f,r,temp->data);
  	temp->left=tree(in,pre,f,j-1);
  	temp->right=tree(in,pre,j+1,r);
  	return temp;
}

struct node *tree1(char in[],char post[],int f,int r)
{
	if(f>r)
		return NULL;
  	struct node *temp=(struct node *)malloc(sizeof(struct node *));
  	temp->data=post[k--];
  	temp->right=NULL;
  	temp->left=NULL;
  	
	if(f==r)
  	 	return temp;
  	int j=search(in,f,r,temp->data);
  	temp->right=tree1(in,post,j+1,r);
  	temp->left=tree1(in,post,f,j-1);
  	return temp;
}
   
int search (char in[],int f,int r,char x)
{
	int m;
  	for(m=f;m<=r;m++)
  	{
  	 	if(in[m]==x)
      			return m;
  	}
}  

void preorder(struct node *tree)
{
    	if (tree != NULL)
    	{
        	printf("%c", tree->data);
        	preorder(tree->left);
        	preorder(tree->right);
    	}
}

void postorder(struct node *tree)
{
    	if (tree != NULL)
    	{
        	postorder(tree->left);
        	postorder(tree->right);
        	printf("%c", tree->data);
    	}
}    

int main()
{
  	int choice;
  	char in[100],pre[100],post[100];
  	while(1)
  	{
     		printf("menu\n1.enter inorder and preorder\n2.enter inorder and postorder\n3.display postorder\n4.display preorder\n5.exit\n");
     		scanf("%d",&choice);
     		switch(choice)
     		{
         		case 1: scanf("%s",in);
                 		scanf("%s",pre);
				i=0;
                 		struct node *root=tree(in,pre,0,strlen(in)-1);
                 		break;
         
			case 2: scanf("%s",in);
                 		scanf("%s",post);
                 		k=strlen(in)-1;
                 		struct node *root1=tree1(in,post,0,strlen(in)-1);
                 		break;
         
			case 3: postorder(root);
                 		break;
         
			case 4: preorder(root1);
                 		break;
         
			case 5: goto l;
     		}
  	}
  	l:;
}
