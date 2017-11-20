#include<stdio.h>
#include<stdlib.h>
struct list
{
  struct node* head;
};
struct node
{
  int data;
  struct node* next;
};
struct graph
{
  int v;
  struct list* array;
};
void createlist(struct graph *g, int l, int r)
{
  struct node* new=(struct node*)malloc(sizeof(struct node));
  new->data=r;
  new->next=g->array[l].head;
  g->array[l].head=new;
  struct node* new1=(struct node*)malloc(sizeof(struct node));
  new1->data=l;
  new1->next=g->array[r].head;
  g->array[r].head=new1;
}
void display(struct graph *g)
{
  int i;
  for(i=0;i<g->v;i++)
  {
    struct node* new=g->array[i].head;
    while(new)
    {
       printf("%d->",new->data);
       new=new->next;
    }
    printf("\n");
  }
} 

int main()
{
  int v,i,choice,l,r;
  printf("enter the no of nodes in the graph\n");
  scanf("%d",&v);
  struct graph* g=(struct graph*)malloc(sizeof(struct graph));;
  g->v=v;
  g->array=(struct list*)malloc(sizeof(struct list)*v);
  for(i=0;i<v;i++)
   g->array[i].head=NULL;
  
  while(1)
  {
     printf("menu:\n1.insert\n2.display\n3.exit\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1: printf("enter the 2 edges\n");
                scanf("%d%d",&l,&r);
                createlist(g,l,r);
                break;
        case 2: display(g);
                break;
        case 3: goto l;
     }
  }
  l:;
}

