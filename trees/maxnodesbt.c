#include<stdio.h>
#include<math.h>
int main()
{
	int h,k;
	printf("enter height of binary tree: ");
	scanf("%d",&h);
	k=pow(2,h+1)-1;
	printf("maximum number of nodes: %d\n",k);
}
