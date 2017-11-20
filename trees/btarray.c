#include<stdio.h>
#include<math.h>
void insert(int arr[],int l)
{
	int x,i,j;
	printf("enter element: ");
	scanf("%d",&x);
	for(i=0;i<l;i++)
	{
		if(arr[i]==0)
			{
			arr[i]=x;
			return;}
		printf("left of %d (0) or right of %d (1): ",arr[i],arr[i]);
		scanf("%d",&j);
		switch(j)
		{
			case 0: i=2*i;
					break;
			case 1: i=2*i +1;
					break;
		}
	}
}
void display(int arr[],int l)
{
	int i;
	for(i=0;i<l;i++)
		printf("| %d ",arr[i]);
	printf("|\n");
}
void
int main()
{
	int h,l,i,j,k,c;
	printf("enter height of binary tree: ");
	scanf("%d",&h);
	l=pow(2,h+1)-1;
	int arr[l];
	for(i=0;i<l;i++)
		arr[i]=0;
	while(1)
	{
		printf("1.insert\n2.display\n3.exit");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	insert(arr,l);
					break;
			case 2:	display(arr,l);
					break;
			case 3: goto end;
		}
	}
	end:;
}
