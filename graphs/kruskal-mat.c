#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,parent[9];
int find(int);
int uni(int,int);
void main()
{
	printf("Enter the no. of vertices : ");
	scanf("%d",&n);
	int cost[n][n];
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=INT_MAX;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne<n)
	{
		for(i=0,min=INT_MAX;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=i;u=i;
					b=j;v=j;

				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("\n%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=INT_MAX; cost[b][a]=INT_MAX;
	}
	printf("\nMinimum cost = %d\n",mincost);
}

int find(int i)
{
	while(parent[i])
	{
		i=parent[i];
	}
 	return i;
}

int uni(int i,int j)
{
	if(i!=j)
 	{
  		parent[j]=i;
  		return 1;
 	}
 	return 0;
}
