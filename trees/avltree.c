#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   int height;
   struct node *left, *right;
};
struct node *root=NULL;
struct node* createnode( int x)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->height=1;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int max(int a,int b)
 {
    return (a>b)?a:b;
}
int balancecheck(struct node *ptr)
{
     return(height(ptr->left)-height(ptr->right));
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
struct node *minimum(struct node *ptr)
{
  while(ptr->right!=NULL)
    ptr=ptr->right;
  return ptr;
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
int height(struct node *ptr)
{
  if(ptr==NULL)
    return 0;
  else
    return ptr->height;
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
     			struct node* temp=minimum(ptr->right);
        		ptr->data=temp->data;
        		ptr->right=delete(ptr->right,temp->data);
  		}
	}  
   	if(ptr==NULL)
          	return ptr;
   	ptr->height=1+max(height(ptr->left),height(ptr->right));
   	balance=balancecheck(ptr);
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

struct node *insert(struct node *ptr, int x)
{
   	int balance;
   	if(ptr==NULL)
    		return createnode(x);
   	else if(x<ptr->data)
    		ptr->left=insert(ptr->left,x);
   	else if(x>ptr->data)
    		ptr->right=insert(ptr->right,x);
   
	ptr->height=1+max(height(ptr->left),height(ptr->right));
   	balance=balancecheck(ptr);
       
	if(balance>1&& x<ptr->left->data)	//left left
           	return rightrotate(ptr);
       	
	else if(balance<-1 && x>ptr->right->data)	//right right
           	return leftrotate(ptr);    
       	
	else if(balance>1 && x>ptr->left->data)	//left right
        {
           	ptr->left=leftrotate(ptr->left);      
           	return rightrotate(ptr);
        }
        
	else if(balance<-1 && x<ptr->right->data)	//right left
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
inorder(ptr->left);
	printf("| %d ",ptr->data);
	
	inorder(ptr->right);
}
struct node * search(struct node *ptr, int x)
{
   if(ptr==NULL||ptr->data==x)
       return ptr;
   else if(x<ptr->data)
      return search(ptr->left,x);
   else
      return search(ptr->right,x);
}
int main()
{
   int choice,x,c=0;
   while(1)
   {
      printf("menu\n1.insert\n2.display\n3.search\n4.delete\n5.exit\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1: printf("enter elements\n");
                  scanf("%d",&x);
                  root=insert(root,x);
                  break;
         case 2:  preorder(root);
		inorder(root);
                  break;
         case 3:  printf("enter the element to be searched\n");
                  scanf("%d",&x);
                  if(search(root,x))
                    printf("key found\n");
                  else
                    printf("key not found\n");
                  break;
         case 4:  printf("enter the element to be deleted\n");
                  scanf("%d",&x);
                  delete(root,x);
                  break;
         case 5:  goto l;
     }
   }
   l:;
}
