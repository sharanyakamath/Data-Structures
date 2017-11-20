#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *left,*right;
	int height;
};
struct node *root=NULL;
int c=0;
int height(struct node *ptr)
{
	if(ptr==NULL)
		return 0;
	return ptr->height;
}

int max(int a,int b)
{
	return a>b?a:b;
}

struct node * leftrotate(struct node *z)
{
   struct node *y=z->right;
   struct node *T3=y->left;
   y->left=z;
   z->right=T3;
   y->height=max(height(y->left),height(y->right))+1;
   z->height=max(height(z->left),height(z->right))+1;
   return y;
}
struct node * rightrotate(struct node *z)
{
   struct node *y=z->left;
   struct node *T3=y->right;
   y->right=z;
   z->left=T3;
   y->height=max(height(y->left),height(y->right))+1;
   z->height=max(height(z->left),height(z->right))+1;
   return y;
}

int getbalance(struct node *ptr)
{
	
	return (height(ptr->left)-height(ptr->right));
}

struct node* insert(struct node* ptr,int key)
{
	struct node *ptr2;
	ptr2=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		{
		ptr=ptr2;
		ptr2->data=key;
		ptr2->left=NULL;	
		ptr2->right=NULL;
		ptr2->height=1;
		return ptr2;
		}
	else if(key>ptr->data)
		ptr->right=insert(ptr->right,key);
	else if(key<ptr->data)
		ptr->left=insert(ptr->left,key);
	else
		{
		printf("element exists\n");
		return ptr;
		}

	ptr->height=1+max(height(ptr->left),height(ptr->right));

	int b=getbalance(ptr);
	 if(b>1&& key<ptr->left->data)
           return rightrotate(ptr);
       else if(b<-1 && key>ptr->right->data)
           return leftrotate(ptr);    
       else if(b>1 && key>ptr->left->data)
        {
           ptr->left=leftrotate(ptr->left);      
           return rightrotate(ptr);
        }
        else if(b<-1 && key<ptr->right->data)
        {
           ptr->right=rightrotate(ptr->right);      
           return leftrotate(ptr);
        }
       return ptr; 
}
struct node* maxelem(struct node* ptr)
{
while(ptr->left!=NULL)
{
	ptr=ptr->left;
}

return ptr;
}

struct node *delete(struct node *ptr, int x)
{
  int balance;
  if(ptr==NULL)
    return ptr;
  else if(x<ptr->data)
   ptr->left=delete(ptr->left,x);
  else if(x>ptr->data)
   ptr->right=delete(ptr->right,x);
  else
  {
    if(ptr->left==NULL||ptr->right==NULL)
    {
      struct node *temp=(struct node*)malloc(sizeof(struct node));
      temp=ptr->left?ptr->left:ptr->right;
      if(temp==NULL)
      {
         temp=ptr;
         ptr=NULL;
      }
      else
         *ptr=*temp;
      free(temp);
  }
  else
  {
     struct node* temp=maxelem(ptr->right);
        ptr->data=temp->data;
        ptr->right=delete(ptr->right,temp->data);
  }
}  
   if(ptr==NULL)
          return ptr;
   ptr->height=1+max(height(ptr->left),height(ptr->right));
   balance=getbalance(ptr);
       if(balance>1&& x<ptr->left->data)
           return rightrotate(ptr);
       else if(balance<-1 && x>ptr->right->data)
           return leftrotate(ptr);    
       else if(balance>1 && x>ptr->left->data)
        {
           ptr->left=leftrotate(ptr->left);      
           return rightrotate(ptr);
        }
        else if(balance<-1 && x<ptr->right->data)
        {
           ptr->right=rightrotate(ptr->right);      
           return leftrotate(ptr);
        }
       return ptr; 
}


void preorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("| %d ",ptr->data);
	preorder(ptr->left);
	preorder(ptr->right);
}
void inorder(struct node *ptr)
{
	if(ptr==NULL)
		return;
	
	preorder(ptr->left);
	printf("| %d ",ptr->data);
	preorder(ptr->right);
}
int main()
{
	int c,d;
	while(1)
	{
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("enter element: ");
				scanf("%d",&d);
				root=insert(root,d);
				break;
			case 2: printf("enter element: ");
				scanf("%d",&d);
				delete(root,d);
				break;
			case 3: printf("preorder: ");
				preorder(root);
				printf("\ninorder: ");
				inorder(root) ;
				break;
			case 4: goto end;
		}
	}
	end:;
	return 0;
}
	










