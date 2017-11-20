#include<stdio.h>
#include<malloc.h>
int queue[50],r=-1,f=-1,queue1[50],f1=-1,r1=-1,stack[50],top=0;
int visit[50];
struct adjlistnode{
int dest;
struct adjlistnode* next;
};

struct adjlist{
struct adjlistnode* head;
};

struct graph{
int v;
struct adjlist* array;
};

struct adjlistnode* createnode(int dest)
{
struct adjlistnode* newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
newnode->dest=dest;
newnode->next=NULL;
return newnode;
} 

struct graph* creategraph(int v)
{
int i;
struct graph* newgraph=(struct graph*)malloc(sizeof(struct graph));
newgraph->v=v;
newgraph->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
for(i=0;i<v;i++)
{
newgraph->array[i].head=NULL;
}
return newgraph;
}

void createdge(struct graph* newgraph,int src, int dest)
{
struct adjlistnode* newnode=createnode(dest);
newnode->next=newgraph->array[src].head;
newgraph->array[src].head=newnode;

newnode=createnode(src);
newnode->next=newgraph->array[dest].head;
newgraph->array[dest].head=newnode;
}

void print(struct graph* newgraph)
{
	int i;
	struct adjlistnode* p;
	for(i=0;i<newgraph->v;i++)
	{
		printf("vertex:%d\nhead",i);
		p=newgraph->array[i].head;
		while(p)
		{
			printf("->%d",p->dest);
			p=p->next;
		}
		printf("\n");
	}
}

void enq(int x)
{
	queue[++r]=x;
}

int deq()
{
	if(f>r || (f==-1 && r==-1))
	{ f=-1; r=-1;
	return -1;}
	return queue[++f];
}


void visited(int v)
{
	int i;
	for(i=0;i<v;i++)
		visit[i]=0;
}

void bfs(struct graph* g, int s,int v)
{
int i;
struct adjlistnode *ptr;
printf("%d ",s);
check:;
visit[s]=1;
ptr=g->array[s].head;
while(ptr)
{
	if(visit[ptr->dest]==0)
	{
		printf("%d ",ptr->dest);
		visit[ptr->dest]=1;
		enq(ptr->dest);
	}
	ptr=ptr->next;
}
s=deq();
while(s!=-1)
	goto check;
}
void dfs(struct graph* g,int s)
{
	int x;
	struct adjlistnode* ptr;
	printf("%d ",s);
	visit[s]=1;
	ptr=g->array[s].head;
	while(ptr)
	{
		if(visit[ptr->dest]==0)
			dfs(g,ptr->dest);
		ptr=ptr->next;
	}
	return;}

		
int main()
{
int c,v,src,dest;
printf("no. of vertices : ");
scanf("%d",&v);
struct graph* Graph=creategraph(v);
while(1)
{
printf("1.insert 2.bfs 3.dfs 4.exit: ");
scanf("%d",&c);
switch(c)
{
	case 1:	
		printf("enter source and destination : ");
		scanf("%d%d",&src,&dest);
		createdge(Graph,src,dest);
		break;
	case 2: printf("enter source vertex : ");
		scanf("%d",&src);
		visited(v);
		bfs(Graph,src,v);
		printf("\n");
		break;
	case 3: printf("enter source vertex : ");
		scanf("%d",&src);
		visited(v);
		dfs(Graph,src);
		printf("\n");
		break;
	case 4: goto end;
}

}
end:;

}
