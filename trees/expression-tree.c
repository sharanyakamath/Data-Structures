#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct tree
{
	char data;
  	struct tree *left;
  	struct tree *right;
}*pos;

pos stack[30];
int top=-1,top1=-1;
char stack1[30],b[30];

pos newnode(char b)
{
  	pos temp;
  	temp = (struct tree*)malloc(sizeof(struct tree));
  	temp->data = b;
  	temp->left = NULL;
  	temp->right = NULL;
 	return temp;
}

void push(pos temp)
{
  	stack[++top]=temp;
}

pos pop()
{
  	pos p;
  	p = stack[top--];
  	return p;
}

void preorder(pos t)
{
  	if(t!=NULL)
   	{
     		printf("%c",t->data);
     		preorder(t->left);
     		preorder(t->right);
	}
}

void main()
{
  	char a[20];
  	pos temp,t;
  	int i,j;
  	printf("enter infix expression: ");
  	scanf("%s",a);
  	infixtopostfix(a);
  	for(i=0;b[i]!='\0';i++)
  	{
       		if(b[i]=='*' || b[i]=='+' ||b[i] == '/' || b[i]=='-')
		{
             		temp = newnode(b[i]);
             		temp->right = pop();
             		temp->left = pop();
             		push(temp);
         	}
       		else
         	{
           		temp = newnode(b[i]);
           		push(temp);
         	}
   	}
      preorder(temp);
}

void push1(char x)
{
    	stack1[++top1] = x;
}

char pop1()
{
    	if(top1 == -1)
        	return -1;
    	else
        	return stack1[top1--];
}

int priority(char x)
{
    	if(x == '(')
        	return 0;
    	if(x == '+' || x == '-')
        	return 1;
    	if(x == '*')
		return 2;
	if(x == '/')
        	return 3;
}

infixtopostfix(char a[])
{
  	char *e = a;
  	int i=0;
  	char x;
    	while(*e != '\0')
    	{
        	if(isalnum(*e))
            		b[i++]=*e;
        	else if(*e == '(')
 			push1(*e);
        	else if(*e == ')')
        	{
            		while((x = pop1()) != '(')
                		b[i++]=x;
        	}
        	else
        	{
            		while(priority(stack1[top1]) >= priority(*e))
                		b[i++]=pop1();
            		push1(*e);
        	}
        	e++;
    	}
    	while(top1 != -1)
    	{
        	b[i++]=pop1();
    	}
  	b[i]='\0';
}
